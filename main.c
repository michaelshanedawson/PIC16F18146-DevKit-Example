/*
 * File:   main.c
 * Author: Mike Dawson
 *
 * Created on March 21, 2024, 11:41 AM
 */

#include "globals.h" //A single header file to store references to all necessary headers and other relevant information for simplicity


/*
 *  All ports are represented as a bit mask of 8 bits.
 *  The bit order is for example of Port B:
 *  RB7 | RB6 | RB5 | RB4 | RB3 | RB2 | RB1 | RB0
 *   0     1     0     0     0     0     0     0 
 *  This would resolve to hex 0x40 or a bit value of 0b01000000
 *  Both 0x40 or 0b01000000 will work for enabling port RB6
 */
#define LED_BLUE 0b01000000 //Port RB6, 0x40 would work as well
#define LED_RED 0x80 //Port RB7

#define DELAY_TIME 500 //A simple variable for holding a delay value, in milliseconds

void main(void) {
    /* Here we will initialize the UART port */
    CONSOLE_SETUP();
    CONSOLE_SEND_STRING("Entering main function. \n\n\r");
    
    
    PORTB = 0x00; //Clear port B
    LATB = 0x00; //Clear port B data latch
    ANSELB = 0x00; //Enable digital drivers for port B
    TRISB = 0x00; //Set all of port B to output mode    
    
    //The following example will set the blue LED to high
    //LATB = LED_BLUE; //Sets port RB6 to high
    //This will also set the blue LED to high
    //LATBbits.LATB6 = 1;
    //This will also set the blue LED to high
    //RB6 =1;
    
    //The following example will set the red LED to high
    //LATB = LED_RED; //Sets port RB7 to high
    //This will also set the red LED to high
    //LATBbits.LATB7 = 1;
    //This will also set the red LED to high
    //RB7 = 1;
    
    //The following example will set both LEDs to high
    //LATB = LED_BLUE | LED_RED;  
    //This will also set both LEDs to high
    //LATBbits.LATB6 = 1; //This allows individual ports to be selected without using bit masking
    //LATBbits.LATB7 = 1;
    //The following will also turn on the LEDs, directly calling the port as needed
    //RB6 = 1;
    //RB7 = 1;
    
    while(1)
    {
        //This example code alternatively flashes the two LEDs at a set interval
        RB6 = 1;
        RB7 = 0;
        __delay_ms(DELAY_TIME);
        RB6 = 0;
        RB7 = 1;
        __delay_ms(DELAY_TIME);
    }
}
