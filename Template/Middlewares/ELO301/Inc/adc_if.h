/**
 ******************************************************************************
 * @file    adc_if.h
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
#ifndef _SRC_ADC_IF_H_
#define _SRC_ADC_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "adc.h"

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/
/**
 * 
 */
typedef struct
{
    ADC_HandleTypeDef *hadc;
} t_adc_if;


typedef enum
{
  ADC_IF_SUCCESS,			/**< */
  ADC_IF_OPEN_FAILURE,     /**< */
  ADC_IF_GET_VALUE_FAILURE,
} t_adc_if_status;

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Init adc_if data structure
 * @param adc_if Pointer to adc_if data structure
 */
void adc_if_init(t_adc_if *adc_if, ADC_HandleTypeDef *hadc);

/**
 * @brief Open the adc_if driver
 * @param adc_if Pointer to adc_if data structure
 * @return ADC_IF_SUCCESS, ADC_IF_OPEN_FAILURE otherwise
 */
t_adc_if_status adc_if_open(t_adc_if *adc_if);

/**
 * @brief Capture ADC value
 * @param adc_if Pointer to adc_if data structure
 * @param value Pointer to data storage
 * @return ADC_IF_SUCCESS, ADC_IF_GET_VALUE otherwise
 */
t_adc_if_status adc_if_get_value(t_adc_if *adc_if, uint16_t *value);

#ifdef __cplusplus
}
#endif

#endif   // _SRC_ADC_IF_H_
