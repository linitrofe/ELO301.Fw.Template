# Emulated temperature sensor: binary library and API

This project includes a temperature sensor emulator on I2C3. It uses the
microcontroller's internal ADC temperature sensor and presents it through an
I2C interface. The emulator has been implemented as a **binary static library**
and is already integrated into the STM32CubeIDE project.

## The library and its public interface

A binary library contains code that has already been compiled. In this
project, that code is stored in a `.a` archive. During a firmware build, the
linker takes the required code from the archive and combines it with the
application to produce the executable firmware.

The corresponding `.h` file declares the library's **application programming
interface (API)**: the public functions and definitions available to application
code. The header describes the interface; the archive supplies the compiled
implementation. Both are part of the library integration.

| Project file | Purpose |
| --- | --- |
| [libtemperature_slave.a](../Middlewares/ELO301/Lib/libtemperature_slave.a) | Compiled implementation of the emulator. |
| [temperature_slave.h](../Middlewares/ELO301/Inc/temperature_slave.h) | API reference: public definitions, function declarations, and interface comments. |

**Read [temperature_slave.h](../Middlewares/ELO301/Inc/temperature_slave.h) for
the emulator API.** Its `USER_Definitions` and `PUBLIC_API` sections identify
the public constants and entry points. Read the declarations together with
their comments to understand the interface and its constraints.

## Working with a developer API

The header is written at the level used in firmware development. Function
names, parameter lists, return types, symbolic constants, and comments are
part of the information you are expected to interpret when reading an API.
The manual provides orientation; the header remains the reference for the
library interface. This document does not reproduce the API or provide a
step-by-step usage tutorial.

Using a binary library does not require compiling its implementation as part
of the application. CubeIDE's Debug and Release configurations link the supplied
archive and exclude `temperature_slave.c` from compilation. The source is
retained for maintenance; editing it does not change the supplied archive.
Changing a declaration in the header also does not change the binary
implementation: the header and library must remain compatible.

The archive supplied here targets the STM32L452 Cortex-M4 with the project's
hard-float settings. It is a component of this firmware project, rather than
an executable program that runs independently on a computer.
