![image](https://github.com/mytechnotalent/rp5-proj/blob/main/rp5-proj.png?raw=true)

## FREE Reverse Engineering Self-Study Course [HERE](https://github.com/mytechnotalent/Reverse-Engineering-Tutorial)

<br>

# rp5-proj
A minimalistic GPIO command and function library to work with the Raspberry Pi 5.

<br>

# Schematic
![image](https://github.com/mytechnotalent/rp5-proj/blob/main/rp5-proj-schematic.png?raw=true)

<br>

# Setup
```bash
sudo apt install gpiod
```

<br>

# Usage
```bash
make
./rp5-proj
```

# `main.c`
```c

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

#include <stdbool.h>

#include "gpio.h"

int main(void) {
    bool exit_flag = false;
    uint8_t not_pressed = 0;

    system(GPIO17_SET);
    system(GPIO11_CLEAR);

    while (!exit_flag) {
        not_pressed = read_gpio_state(GPIO14_BUTTON);

        if (!not_pressed) {
            system(GPIO17_CLEAR);
            system(GPIO11_SET);
            exit_flag = true;
        }
    }

    return 0;
}
```

<br>

## License
[MIT](https://raw.githubusercontent.com/mytechnotalent/rp5-proj/main/LICENSE)
