/**
 ******************************************************************************
 * @file    gpio_if.c
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

#include <stdlib.h>
#include "gpio_if.h"

/*- PRIVATE_TUNABLES ---------------------------------------------------------*/

/*- PRIVATE_Definitions ------------------------------------------------------*/

/*- PRIVATE_Macros -----------------------------------------------------------*/

/*- PRIVATE_Types ------------------------------------------------------------*/

/*- PRIVATE_Functions --------------------------------------------------------*/

/*- PRIVATE_Data -------------------------------------------------------------*/

/*- PUBLIC_API ---------------------------------------------------------------*/
/*
 * API: gpio_if_init
 */
void gpio_if_init( t_gpio_if *gpio_if, t_gpio_active active, t_gpio_pin *pin, t_gpio_state initial_state )
{
  gpio_if->active = active;
  gpio_if->pin = pin;
  gpio_if->initial_state = initial_state;
}

/*
 * API: gpio_if_open
 */
t_gpio_if_status gpio_if_open(t_gpio_if *gpio_if)
{
  /* Sanity check */
  if (gpio_if->pin == NULL)
  {
    return GPIO_IF_OPEN_FAILURE;
  }

  /* Init variables */

  /* Start peripherals */
  if (gpio_if->initial_state == GPIO_IF_SET)
  {
    gpio_if_set(gpio_if);
  }
  else if (gpio_if->initial_state == GPIO_IF_CLEAR)
  {
    gpio_if_clear(gpio_if);
  }
  else
  {
    /* Nothing to do */
  }

  return GPIO_IF_SUCCESS;
}

/*
 * API: gpio_if_set
 */
void gpio_if_set(t_gpio_if *gpio_if)
{
  if (gpio_if->active == ACTIVE_HIGH)
  {
    HAL_GPIO_WritePin(gpio_if->pin->port, gpio_if->pin->pin, GPIO_PIN_SET);
  }
  else
  {
    HAL_GPIO_WritePin(gpio_if->pin->port, gpio_if->pin->pin, GPIO_PIN_RESET);
  }
}

/*
 * API: gpio_if_clear
 */
void gpio_if_clear(t_gpio_if *gpio_if)
{
  if (gpio_if->active == ACTIVE_HIGH)
  {
    HAL_GPIO_WritePin(gpio_if->pin->port, gpio_if->pin->pin, GPIO_PIN_RESET);
  }
  else
  {
    HAL_GPIO_WritePin(gpio_if->pin->port, gpio_if->pin->pin, GPIO_PIN_SET);
  }
}

/*
 * API: gpio_if_toggle
 */
void gpio_if_toggle(t_gpio_if *gpio_if)
{
  HAL_GPIO_TogglePin(gpio_if->pin->port, gpio_if->pin->pin);
}

/*
 * API: gpio_if_get
 */
t_gpio_state gpio_if_get(t_gpio_if *gpio_if)
{
  if (gpio_if->active == ACTIVE_HIGH)
  {
    if (HAL_GPIO_ReadPin(gpio_if->pin->port, gpio_if->pin->pin) == GPIO_PIN_SET)
    {
      return GPIO_IF_SET;
    }
    else
    {
      return GPIO_IF_CLEAR;
    }
  }
  else
  {
    if (HAL_GPIO_ReadPin(gpio_if->pin->port, gpio_if->pin->pin) == GPIO_PIN_SET)
    {
      return GPIO_IF_CLEAR;
    }
    else
    {
      return GPIO_IF_SET;
    }
  }
}


/*- PRIVATE_Functions --------------------------------------------------------*/
