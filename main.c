#include <msp430.h> 

#define RED_LED1 0x0001         //Sets PX.0 as an output
#define GREEN_LED2 0x0080       //Sets PX.7 as an output
#define CLEAR_RED_LED 0x0000    //Turns OFF the LED
#define BUTTON11 0x0002         //Set in DIR that P1.1 is an output
#define DEVELOPMENT 0x5A80
#define ENABLE_PINS 0xFFFE

int main()
{
    WDTCTL = DEVELOPMENT;	    //Stop watchdog timer

    PM5CTL0 = ENABLE_PINS;      //Prepare pins for I/O usage

    P9DIR = GREEN_LED2;         //Sets P9.7 as an output

    P1OUT = BUTTON11;           //Sets an pull - up resistor for P1.1 input
    P1REN = BUTTON11;           //Sets an pull - up resistor for P1.1 input
                                //P1OUT pins are also used for an output (to blink LED)

    while(1)
    {
        while((BUTTON11 & P1IN) == 0)   //when P1.1 is is connected to ground
        {
            P9OUT = P9OUT | GREEN_LED2; //turn on P9.7 output
        }

        P9OUT = P9OUT & CLEAR_RED_LED;  //if not pressed "close" all the outputs
    }
}
