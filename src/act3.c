/**
 * @file act3.c
 * @author NIVESH (you@domain.com)
 * @brief Used to analyze the output of the ADC
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#include<avr/io.h>
#include <avr/interrupt.h>


void delay(void)
{
    TCCR0B|=(1<<CS00);
    TCNT0=0;
    sei();
        if(TCNT0 >=191){
            TCNT0=0;
        }
}

void InitPWM(void)
{
    
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);

    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);

    DDRB|=(1<<PB1);

}
char OutPWM(uint16_t ADC_value)
{ char temp; // temperature
    if((ADC_value>=0) && (ADC_value<=200)){

        OCR1A = 205; //20% DC
        temp=20;

        delay();
    }
    else if((ADC_value>=210) && (ADC_value<=500)){

        OCR1A = 410; //40% DC
        temp=25;

       delay();
    }
    else if((ADC_value>=510) && (ADC_value<=700)){

        OCR1A = 717;//70% DC
        temp=29;

        delay();
    }
    else if((ADC_value>=710) && (ADC_value<=1024)){

        OCR1A = 973; //95% DC
        temp=33;

        delay();
    }
    else{
        OCR1A = 0;
        temp=0;

    }
    return temp;
}
