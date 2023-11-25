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
 * @file gpio.c
 *
 * @brief Minimalistic GPIO commands and functions to work with the Raspberry Pi 5.
 * 
 * This contains the minimalistic commands and functions to work with the Raspberry Pi 5
 * which you can build upon to make larger projects.
 *
 * @author Kevin Thomas
 * @date   11/25/2023
 */

#include "gpio.h"

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
const char *GPIO14_BUTTON = "gpioget -B pull-up /dev/gpiochip4 14";
const char *GPIO17_SET = "gpioset gpiochip4 17=1";
const char *GPIO17_CLEAR = "gpioset gpiochip4 17=0";
const char *GPIO11_SET = "gpioset gpiochip4 11=1";
const char *GPIO11_CLEAR = "gpioset gpiochip4 11=0";

/**
 * @brief  Opens a command as a FILE stream using popen.
 *
 *         This function opens a command specified by the given string using the
 *         popen function with read-only mode ("r"). It returns a pointer to the
 *         FILE stream associated with the command. If the command execution
 *         fails, it prints an error message using perror and exits the program.
 *
 * @param  cmd: The command to be executed and opened.
 * @retval FILE pointer to the stream associated with the command.
 */
static FILE *open_cmd(const char *cmd);

/**
 * @brief  Closes the FILE stream associated with a command using pclose.
 *
 *         This function closes the FILE stream associated with a command using
 *         the pclose function. If the closure fails, it prints an error message
 *         using perror and exits the program.
 *
 * @param  fp: FILE pointer to the stream associated with the command.
 * @retval None
 */
static void close_cmd(FILE *fp);

static FILE *open_cmd(const char *cmd) {
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("failed to run command");
        exit(1);
    }
    return fp;
}

static void close_cmd(FILE *fp) {
    if (pclose(fp) == -1) {
        perror("failed to close command");
        exit(1);
    }
}

uint8_t read_gpio_state(const char *gpio_cmd) {
    const size_t MAX_BUF_SIZE = 1024;
    char buf[MAX_BUF_SIZE];
    FILE *fp = NULL;

    fp = open_cmd(gpio_cmd);
    if (fp == NULL) {
        printf("failed to open command\n");
        return 0; // Return 0 in case of an error
    }
    while (fgets(buf, sizeof(buf) - 1, fp) != NULL) {
        printf("GPIO State: %s", buf);
        close_cmd(fp);
        return (uint8_t)(buf[0] == '1');
    }
    close_cmd(fp);
    return 0;
}

