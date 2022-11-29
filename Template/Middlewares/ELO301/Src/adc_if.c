/**
 ******************************************************************************
 * @file    adc_if.c
 * @author  ELO301
 * @date    Nov 28, 2022
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
#include "adc_if.h"

/*- PRIVATE_TUNABLES ---------------------------------------------------------*/
#define ADC_TIMEOUT_MS  100

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Macros -----------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

/*- PRIVATE_Functions --------------------------------------------------------*/

/*- PRIVATE_Data -------------------------------------------------------------*/

/*- PUBLIC_API ---------------------------------------------------------------*/
/*
 * API: adc_if_init
 */
void adc_if_init(t_adc_if *adc_if, ADC_HandleTypeDef *hadc)
{
  adc_if->hadc = hadc;
}

/*
 * API: adc_if_open
 */
t_adc_if_status adc_if_open(t_adc_if *adc_if)
{
  /* Sanity check */
  if (adc_if->hadc == NULL)
  {
    return ADC_IF_OPEN_FAILURE;
  }

  /* Init variables */

  /* Start peripherals */

  return ADC_IF_SUCCESS;
}

/*
 * API: adc_if_get_value
 */
t_adc_if_status adc_if_get_value(t_adc_if *adc_if, uint16_t *value)
{
  /* Start ADC convertion */
  if (HAL_ADC_Start(adc_if->hadc) != HAL_OK)
  {
    return ADC_IF_GET_VALUE_FAILURE;
  }
  /* Wait until conversion finishes or times out*/
  else if (HAL_ADC_PollForConversion(adc_if->hadc, ADC_TIMEOUT_MS) != HAL_OK)
  {
    return ADC_IF_GET_VALUE_FAILURE;
  }

  /* Get ADC converted value */
  *value = HAL_ADC_GetValue(adc_if->hadc);

  return ADC_IF_SUCCESS;
}

/*- PRIVATE_Functions --------------------------------------------------------*/
