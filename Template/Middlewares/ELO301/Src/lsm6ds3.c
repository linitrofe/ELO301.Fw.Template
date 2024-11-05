/**
 ******************************************************************************
 * @file    lsm6ds3.c
 * @author  ELO301
 * @date    Dec 1, 2022
 * @brief   Driver for LSM6DS3 IMU sensor
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

#include <stdlib.h>
#include "lsm6ds3.h"
#include "main.h"
#include "i2c.h"

/*- PRIVATE_TUNABLES ---------------------------------------------------------*/

/*- PRIVATE_Definitions ------------------------------------------------------*/
#define TIMEOUT_100MS 100

/*- PRIVATE_Macros -----------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

/*- PRIVATE_Functions --------------------------------------------------------*/

/*- PRIVATE_Data -------------------------------------------------------------*/

/*- PUBLIC_API ---------------------------------------------------------------*/
/*
 * API: pwm_init
 */
void lsm6ds3_init(void)
{
  uint8_t who_am_i = 0;
  HAL_StatusTypeDef status;

  /* Test I2C interface by reading known value (WHO AM I) using HAL interface */
  status = HAL_I2C_Mem_Read(&hi2c1, LSM6DS3_I2C_ADDR, LSM6DS3_WHO_AM_I, 1, &who_am_i, 1, TIMEOUT_100MS);
  if (status != HAL_OK)
  {
    /* I2C error */
    Error_Handler();
    return;
  }
}

/*
 * API: pwm_open
 */
bool lsm6ds3_open(void)
{
  return false;
}

bool lsm6ds3_update(void)
{
  return false;
}

/*- PRIVATE_Functions --------------------------------------------------------*/
