/**
 * @file act1.c
 * @author NIVESH (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include <avr/io.h>
#include "act1.h"

void act1()
{
    DDRB |= (1<<PB0);//set the bit PB0 
    DDRC &= ~(1<<PC0);//clear the bit PD0 
    DDRD &= ~(1<<PD0);//clear the bit PD1
    PORTB |= (1<<PB0);
    PORTC |= (1<<PC0);

            if(((PINB & (1<<PB0))) && ((PINC & (1<<PC0))))
            {
                PORTB &= ~(1<<PB0);
            }
            else if(((PINB & (1<<PB0))) && (!(PINC & (1<<PC0))))
            {
                PORTB &= ~(1<<PB0);
            }
            else if((!(PINB & (1<<PB0))) && ((PINC & (1<<PC0))))
            {
                PORTB &= ~(1<<PB0);
            }
            else if((!(PINB & (1<<PB0))) && (!(PINC & (1<<PC0))))
            {
                PORTB |= (1<<PB0);
            }

    }

