# I2C3 temperature slave

Address: **0x48 (7 bit)**. PC0 is SCL and PC1 is SDA, AF4 open drain,
with **no internal pull-ups**. Provide external bus pull-ups. The master must
support clock stretching. I2C1 is unchanged.

| Register | Access | Format |
| --- | --- | --- |
| 0x00 | Read/write | One byte; bit 0 enables readings. Other bits read zero. Reset: disabled. |
| 0x01 | Read only | Two bytes, MSB first; signed temperature in 0.01 degrees C. |

Write `[0x00, 0x01]` to enable; write `[0x00, 0x00]` to disable.
Read temperature by writing `[0x01]`, issuing a repeated START, then reading
two bytes and NACKing the last byte. STOP between pointer selection and reading
is also supported. The pointer is retained. A read using the retained pointer
also gets a fresh conversion. Example: `09 C4` means 25.00 degrees C.

Disabled, unavailable, timed-out, or invalid readings return `80 00`.
Writes to the temperature register are ignored. Unknown registers and reads
beyond a register's length return `FF`. Registers do not auto-increment.

`temperature_slave_irq()` is called by I2C3 EV and ER handlers and owns their
flags directly; do not also dispatch those IRQs through the HAL I2C handlers.
RX register selection calls acquisition directly. The read address event also
acquires a fresh snapshot, holding ADDR/SCL until it completes, including when
there was no preceding pointer write. Both reply bytes come from one snapshot.
There is no main-loop service routine or ADC interrupt dependency.

ADC1's injected sequence samples temperature and VREFINT at 640.5 cycles each
(about 164 microseconds total at 8 MHz). Factory TS and VREFINT calibration
compensate for supply voltage. Scan mode is enabled for the two injected ranks;
the regular sequence still has only the PA0 potentiometer channel. Startup
enables both internal paths and allows stabilization before interrupts. ADC
calibration happens before enabling the slave. The old blocking temperature
helper is not used by this driver. ADC enable transitions and each conversion
wait have a 1 ms DWT cycle timeout independent of SysTick. Fault recovery may
add a further 1 ms stop wait. Do not reconfigure/calibrate ADC1 while serving
I2C requests. An interrupted ADC stop transition returns unavailable.

Build validation: STM32 GCC compile and link. Hardware acceptance checks:

1. Read control after reset (00), and temperature (80 00).
2. Enable, then read temperature using repeated START and STOP-separated reads.
3. Repeat reads without rewriting the pointer; check fresh stable readings.
4. Disable and verify 80 00. Check unknown registers and short/long reads.
5. Confirm the potentiometer/PWM still operates while reads are repeated.
6. Check SCL stretching and early NACK/STOP recovery with a logic analyzer.

The IOC records the pins, address, interrupts and injected internal channels.
CubeMX regeneration itself has not been validated; review its generated ADC
injected sequence and preserve the custom interrupt dispatch before flashing.

## Main-loop master example

The example in `main.c` uses **I2C1 as master** to access the I2C3 slave
through real bus transactions. Connect **PB8 to PC0 (SCL)** and **PB9 to
PC1 (SDA)**, with external pull-ups to 3.3 V. No internal pull-ups are enabled.
The example writes 01 to control register 00 at startup, then reads register
01 every 500 ms with `HAL_I2C_Mem_Read` (register pointer plus repeated START).
USART2 `printf` displays, for example, `I2C temperature: 25.00 C`.
Missing wiring, failed transfers, and unavailable readings print diagnostic
messages; enabling is retried after a failed transaction. The emulator itself
continues to run entirely in interrupts. The main loop is only its I2C client.
