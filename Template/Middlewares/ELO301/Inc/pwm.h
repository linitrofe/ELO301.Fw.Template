/**
 ******************************************************************************
 * @file    pwm.h
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
#ifndef _ELO301_INC_PWM_H_
#define _ELO301_INC_PWM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "tim.h"

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/
/**
 * 
 */
typedef struct
{
    TIM_HandleTypeDef *tim;
    uint32_t channel;
    uint16_t counter_period_value;
} t_pwm;


typedef enum
{
  PWM_SUCCESS,			/**< */
  PWM_OPEN_FAILURE,     /**< */
  PWM_UPDATE_FAILURE
} t_pwm_status;

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Init pwm data structure
 * @param pwm Pointer to pwm data structure
 * @param tim Timer data structure pointer
 * @param channel Timer channel for PWM
 * @param counter_period_value Counter period of the timer
 */
void pwm_init(t_pwm *pwm, TIM_HandleTypeDef *tim, uint32_t channel, uint16_t counter_period_value);

/**
 * @brief Open the pwm driver
 * @param pwm Pointer to pwm data structure
 * @return PWM_SUCCESS, PWM_OPEN_FAILURE otherwise
 */
t_pwm_status pwm_open(t_pwm *pwm);

/**
 * Update PWM value
 * @param pwm Pointer to pwm data structure
 * @param rate from 0 to 100 percent
 * @return PWM_SUCCESS, PWM_UPDATE_FAILURE otherwise
 */
t_pwm_status pwm_update(t_pwm *pwm, uint8_t rate);

#ifdef __cplusplus
}
#endif

#endif   // _ELO301_INC_PWM_H_
