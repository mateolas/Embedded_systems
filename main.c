// Program to blink a RED LED

#include <msp430.h>         // preprocessor instruction. Adds a file. Thanks
// to it we can use "short-cut" names
// to make code easier to read

//Creating constants. Associate numerical value with names

#define RED 0x0001          // Defining the red LED

#define RED_OFF 0x00FE      // Used to turn the red LED off

#define ENABLE_RED 0xFFFE   // Used to enable MC pins

#define DEVELOPMENT 0x5A80  // Used to disable some of the security
// features

int main()
{
    WDTCTL = DEVELOPMENT;   // Disables some security features

    PM5CTL0 = ENABLE_RED;   // Enables the pins to the outside world

    P1DIR = RED;            //Make a pin an output

    long x = 0;

    while (1)
    {
        for (x = 0; x < 50000; x++)     // Count from 0 to 50000 for a delay
        {

            P1OUT = RED;                // Turn red LED light on

        }

        for (x = 0; x < 50000; x++)     // Count from 0 to 50000 for a delay
        {

            P1OUT = RED_OFF;            // Turn off the red LED light
        }
    }

}
