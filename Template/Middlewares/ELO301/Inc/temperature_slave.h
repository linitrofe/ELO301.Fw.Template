/**
 ******************************************************************************
 * @file    temperature_slave.h
 * @author  ELO301
 * @date    Nov 16, 2026
 * @brief   Interface for the I2C3 temperature sensor emulator
 *
 * 
 * @note    
 * @warning 
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2022 ELO301</center></h2>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 ******************************************************************************
 */

#ifndef _ELO301_INC_TEMPERATURE_SLAVE_H_
#define _ELO301_INC_TEMPERATURE_SLAVE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

/*- USER_Definitions ---------------------------------------------------------*/
#define TEMPERATURE_SLAVE_I2C_ADDR         0x48U
#define TEMPERATURE_SLAVE_REG_CONTROL      0x00U
#define TEMPERATURE_SLAVE_REG_TEMPERATURE  0x01U
#define TEMPERATURE_SLAVE_UNAVAILABLE      0x8000U

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

/*- PUBLIC_API ---------------------------------------------------------------*/
/* Call once after system clocks, ADC configuration and ADC calibration.
 * Initializes I2C3 (PC0=SCL, PC1=SDA, address 0x48) through the project HAL MSP.
 * Do not call MX_I2C3_Init() separately. No main-loop service is required.
 */
void temperature_slave_init(void);

/* Owns I2C3 EV/ER flags; do not also call HAL_I2C_*IRQHandler for I2C3. */
void temperature_slave_irq(void);

#ifdef __cplusplus
}
#endif

#endif   /* _ELO301_INC_TEMPERATURE_SLAVE_H_ */
