/**
 * @file act4.c
 * @author NIVESH (you@domain.com)
 * @brief Used to send the value to the Serial Monitor
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#include<avr/io.h>

void USARTInit(uint16_t ubrr_value)
{
    // Baud Rate
    UBRR0L=ubrr_value;
    UBRR0H=(ubrr_value>>8)& 0X00ff;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    //TO enable the reciever and transmitter 

    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

void USARTWriteChar(char data)
{
    

    while(!(UCSR0A & (1<<UDRE0)))
    {
        //Do Nothing
    }
    

    UDR0=data;
}



