/**
 * File:   main.c
 * Author: Michael Pillon
 *
 * Created on May 11, 2020, 12:08 PM
 */


#include <xc.h>
#include <pic18f45k22.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "pragmas.h"
#include "initializeHardware.h"
#include "ledDisplay.h"

#define GO_TIME     true

/*
 main:
 Function Name: main
 Parameters: None 
 Return: None 
 Description: Uses ledDisplay.h to handle the graphics on a 52x18 LED panel
 */				
 



void main (void)
{
    initializeHardware();
    
    LedDisplay display;
    display = initializeLedDisplay(DISPLAY_COL_COUNT, DISPLAY_ROW_COUNT);

//    uint8_t buffer[7][18] = {
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }
//    };
    uint32_t helloWorld[18][2] = {
        { 0b00000000000000000000000000000000, 0b00000000000000000000000000000000 },
        { 0b00000000000000100101111010000100, 0b00011000000000000000000000000000 },
        { 0b00000000000000100101000010000100, 0b00100100000000000000000000000000 },
        { 0b00000000000000100101000010000100, 0b00100100000000000000000000000000 },
        { 0b00000000000000111101110010000100, 0b00100100000000000000000000000000 },
        { 0b00000000000000100101000010000100, 0b00100100000000000000000000000000 },
        { 0b00000000000000100101000010000100, 0b00100100000000000000000000000000 },
        { 0b00000000000000100101111011110111, 0b10011000000000000000000000000000 },
        { 0b00000000000000000000000000000000, 0b00000000000000000000000000000000 },
        { 0b00000000000000000000000000000000, 0b00100010011001110010000111000000 },
        { 0b00000000000000000000000000000000, 0b00100010100101001010000100100000 },
        { 0b00000000000000000000000000000000, 0b00101010100101001010000100100000 },
        { 0b00000000000000000000000000000000, 0b00101010100101110010000100100000 },
        { 0b00000000000000000000000000000000, 0b00101010100101001010000100100000 },
        { 0b00000000000000000000000000000000, 0b00101010100101001010000100100000 },
        { 0b00000000000000000000000000000000, 0b00010100011001001011110111000000 },
        { 0b00000000000000000000000000000000, 0b00000000000000000000000000000000 },
        { 0b00000000000000000000000000000000, 0b00000000000000000000000000000000 }
    };
    
    // Clear shift registers and set initial states
    SR_OE = SR_ENABLE;
    __delay_ms(5);
    SR_SRCLR = SR_ENABLE;
    __delay_ms(5);
    SR_SRCLR = SR_DISABLE;
    
    
    // SO Infinite Loop
    while (GO_TIME) {
        
        for(uint8_t i = 0; i < DISPLAY_ROW_COUNT; i++) {

            SR_RCLK = 0;

            for(uint8_t j = 0; j < (32); j++) {
                // 1) set serial data pin
                SR_SER_0 = (buffer[i][1] >> ii ) & 0x0001;
                // 2) serial clock pulse
                __delay_us(1); // Minimum < 100ns between pulses
                SR_SRCLK = 1;
                __delay_us(1);
                SR_SRCLK = 0;
                // 3) repeat 1-2 for all columns
            }
            
            
            
            
            
            // 4) disable shift register
            SR_OE = SR_DISABLE;
            // 5) latch shift register and increment decade counter
            SR_RCLK = 1;
            __delay_us(1);

            // 6) enable shift registers
            SR_OE = SR_ENABLE;
            // 7) repeat 1-6 for all rows
            // 8) repeat 1-7 60 times a second (60Hz)

        }
      }       // eo: Infinite loop
}//eo: main() ==================================================================

