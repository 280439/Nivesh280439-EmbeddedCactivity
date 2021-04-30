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
    DDRD &= ~(1<<PD0);//clear the bit PD0 
    DDRD &= ~(1<<PD1);//clear the bit PD1
    PORTD |= (1<<PD0);
    PORTD |= (1<<PD1);

            if(((PIND & (1<<PD0))) && ((PIND & (1<<PD1))))
            {
                PORTB &= ~(1<<PB0);
            }
            else if(((PIND & (1<<PD0))) && (!(PIND & (1<<PD1))))
            {
                PORTB &= ~(1<<PB0);
            }
            else if((!(PIND & (1<<PD0))) && ((PIND & (1<<PD1))))
            {
                PORTB &= ~(1<<PB0);
            }
            else if((!(PIND & (1<<PD0))) && (!(PIND & (1<<PD1))))
            {
                PORTB |= (1<<PB0);
            }

    }

