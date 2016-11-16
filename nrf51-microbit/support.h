/*
The MIT License (MIT)

Copyright (c) 2016 British Broadcasting Corporation.
This software is provided by Lancaster University by arrangement with the BBC.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/
#ifndef SUPPORT_H
#define SUPPORT_H

DigitalOut led1(P0_13); // top left-most LED
DigitalOut led2(P0_14); // mid right-most LED
DigitalOut led3(P0_15); // mid bottom-most LED
DigitalOut col(P0_4, 0);
#define ACTIVITY 0

void blink(uint8_t led, int n, float delay=0.1, uint8_t activity = ACTIVITY) // 1: active high
{
    int i = 0;
    uint8_t on = 1-activity;
    uint8_t off = activity;

    printf("Blinking LED%d %d time(s)..\n\r", led, n);
    led1=off;
    led2=off;
    led3=off;

    while (i < n)
    {
        switch (led)
        {
          case 1:
            led1 = on;
            wait(delay);
            led1 = off;
            wait(delay);
            break;
          case 2:
            led2 = on;
            wait(delay);
            led2 = off;
            wait(delay);
            break;
          case 3:
            led3 = on;
            wait(delay);
            led3 = off;
            wait(delay);
            break;
          default: break;
        }
        i++;
    }
}

#endif
