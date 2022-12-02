/**
 ******************************************************************************
 * @file    pwm.c
 * @author  ELO301
 * @date    Dec 1, 2022
 * @brief   
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
#include "pwm.h"

/*- PRIVATE_TUNABLES ---------------------------------------------------------*/

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Macros -----------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

/*- PRIVATE_Functions --------------------------------------------------------*/

/*- PRIVATE_Data -------------------------------------------------------------*/

/*- PUBLIC_API ---------------------------------------------------------------*/
/*
 * API: pwm_init
 */
void pwm_init(t_pwm *pwm, TIM_HandleTypeDef *tim, uint32_t channel, uint16_t counter_period_value)
{
  pwm->tim = tim;
  pwm->channel = channel;
  pwm->counter_period_value = counter_period_value;
}

/*
 * API: pwm_open
 */
t_pwm_status pwm_open(t_pwm *pwm)
{
  /* Sanity check */
  if (pwm->tim == NULL)
  {
    return PWM_OPEN_FAILURE;
  }

  /* Init variables */

  /* Start peripherals */
  HAL_TIM_PWM_Start(pwm->tim, pwm->channel);

  return PWM_SUCCESS;
}

t_pwm_status pwm_update(t_pwm *pwm, uint8_t rate)
{
  uint16_t pwm_value;

  if (rate > 100)
  {
    return PWM_UPDATE_FAILURE;
  }

  pwm_value = ((uint32_t)rate * pwm->counter_period_value) / 100UL;
  __HAL_TIM_SET_COMPARE(pwm->tim, pwm->channel, pwm_value);

  return PWM_SUCCESS;
}

/*- PRIVATE_Functions --------------------------------------------------------*/
