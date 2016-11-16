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

#include "Lpc1768.h"
#include "support.h"

Lpc1768 lpc1768;

Serial pc(USBTX,USBRX);


void blink_LED1();
void blink_LED2();
void blink_LED3();
void fiber_test(); // Check LED blinks to infer, and/or connect to serial terminal

int main()
{
    printf("*****************************************************************\n\r");
    printf("*************************** FIBER TEST **************************\n\r");
    printf("*****************************************************************\n\r");

    // Initialise the lpc1768 runtime.
    printf("Initializing lpc1768..\n\r");
    lpc1768.init();
    printf("Done!\n\r");

    // Press button A or B to start test
    printf("Press button 1 or 2 to start the fiber test\n\r");
    while(1)
    {
//        if (lpc1768.buttonA.isPressed() || lpc1768.buttonB.isPressed())
//        {
            // signal start of test
            printf("Button is pressed. Starting the startup sequence..\n\r");
            blink(1,5);
            blink(2,5);
            blink(3,5);
            wait(2);
            break;
//        }
   }

    printf("Starting the test..\n\r");
    fiber_test();

    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}


void blink_LED1()
{
    printf("Turning LED1 on for 2 seconds\n\r");
    blink(1, 1, 2);
}

void blink_LED2()
{
    printf("Turning LED1 on for 2 seconds\n\r");
    blink(2, 1, 2);
}

void blink_LED3()
{
    printf("Turning LED3 on for 2 seconds\n\r");
    blink(3, 1, 2);
}

void fiber_test()
{
    printf("Creating fiber 1..\n\r");
    create_fiber(blink_LED1);
    printf("Creating fiber 2..\n\r");
    create_fiber(blink_LED2);
    printf("Creating fiber 3..\n\r");
    create_fiber(blink_LED3);
    printf("main fiber sleeping for 15 seconds..\n\r");
    fiber_sleep(15000);
    printf("main fiber is awake..\n\r");
    blink(1,5);
    blink(2,5);
    blink(3,5);
    printf("Exitting main fiber..\n\r");
}
