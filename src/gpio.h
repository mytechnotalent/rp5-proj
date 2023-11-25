/**
 * MIT License
 * 
 * Copyright (c) 2023 My Techno Talent
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

/**
 * @file gpio.h
 *
 * @brief GPIO commands and function prototypes for the gpio source file.
 * 
 * This contains the GPIO commands and function prototypes for the gpio source file.
 *
 * @author Kevin Thomas
 * @date   11/25/2023
 */

#ifndef GPIO_H
#define GPIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief  GPIO Commands for Interacting with GPIO Pins.
 *
 *         This module defines a set of constants representing GPIO commands for
 *         interacting with specific GPIO pins. Each command serves a specific
 *         purpose, such as reading the state of a button or setting/clearing the
 *         state of a GPIO pin.
 *
 * @note   The GPIO commands are designed for use with the gpioget and gpioset
 *         utilities on the specified GPIO chip (/dev/gpiochip4).
 */
extern const char *GPIO14_BUTTON;
extern const char *GPIO14_BUTTON;
extern const char *GPIO17_SET;
extern const char *GPIO17_CLEAR;
extern const char *GPIO11_SET;
extern const char *GPIO11_CLEAR;

/**
 * @brief  Reads and returns the GPIO state using a specified GPIO command.
 *
 *         This function reads the GPIO state by executing the specified GPIO
 *         command using the open_cmd function. It then reads the output from the
 *         command using fgets, prints the GPIO state to the console, and returns
 *         the state as a uint8_t value (1 for high, 0 for low).
 *
 * @param  gpio_cmd: The GPIO command to be executed.
 * @retval uint8_t: The GPIO state (1 for high, 0 for low) or 0 in case of an error.
 */
uint8_t read_gpio_state(const char *gpio_cmd);

#endif // GPIO_H

