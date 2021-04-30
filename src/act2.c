/**
 * @file act2.c
 * @author NIVESH (you@domain.com)
 * @brief Used for the ADC value through the Potentiometer
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include <avr/io.h>

void InitADC()
{
    ADMUX = (1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);//For Enable ADC & FCPU
}


uint16_t ReadADC(uint8_t ch)
{
    //ch must be 0-7
    ADMUX &= 0Xf8;
    ch&=0b00000111;
    ADMUX|=ch;
    
    ADCSRA|=(1<<ADSC);
    
    while(!(ADCSRA & (1<<ADIF)));
    //clear

    ADCSRA|=(1<<ADIF);
    return(ADC);
}

