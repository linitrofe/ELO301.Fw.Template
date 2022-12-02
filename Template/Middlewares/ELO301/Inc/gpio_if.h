/**
 ******************************************************************************
 * @file    gpio_if.h
 * @author  ELO301
 * @date    Nov 24, 2022
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
#ifndef _GPIO_IF_H_
#define _GPIO_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "gpio.h"

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

/**
 *
 */
typedef enum
{
  ACTIVE_LOW, /**< Pin active when the ouput is low */
  ACTIVE_HIGH,/**< Pin active when the ouput is high */
} t_gpio_active;

typedef enum
{
  GPIO_IF_CLEAR,
  GPIO_IF_SET,
  GPIO_IF_INPUT,
} t_gpio_state;

typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;
} t_gpio_pin;

typedef struct
{
    t_gpio_active active;
    t_gpio_pin *pin;
    t_gpio_state initial_state;
} t_gpio_if;

typedef enum
{
  GPIO_IF_SUCCESS,			    /**< */
  GPIO_IF_OPEN_FAILURE,     /**< */
} t_gpio_if_status;

/*- PUBLIC_API ---------------------------------------------------------------*/

/**
 * @brief Init gpio_if data structure
 * @param gpio_if Pointer to gpio_if data structure
 * @param active Pin active mode
 * @param pin Pointer to pin data structure
 * @param initial_state State of the pin after init
 */
void gpio_if_init( t_gpio_if *gpio_if, t_gpio_active active, t_gpio_pin *pin, t_gpio_state initial_state );

/**
 * @brief Open the gpio_if driver
 * @param gpio_if Pointer to gpio_if data structure
 * @return GPIO_IF_SUCCESS, GPIO_IF_OPEN_FAILURE otherwise
 */
t_gpio_if_status gpio_if_open(t_gpio_if *gpio_if);

/**
 * @brief Set the pin
 * @param gpio_if Pointer to gpio_if data structure
 */
void gpio_if_set(t_gpio_if *gpio_if);

/**
 * @brief Clear the pin
 * @param gpio_if Pointer to gpio_if data structure
 */
void gpio_if_clear(t_gpio_if *gpio_if);

/**
 * @brief Toggle the pin
 * @param gpio_if Pointer to gpio_if data structure
 */
void gpio_if_toggle(t_gpio_if *gpio_if);

/**
 * Get pin status
 * @param gpio_if Pointer to gpio_if data structure
 * @return GPIO_IF_SET or GPIO_IF_GET
 */
t_gpio_state gpio_if_get(t_gpio_if *gpio_if);

#ifdef __cplusplus
}
#endif

#endif   // _GPIO_IF_H_
