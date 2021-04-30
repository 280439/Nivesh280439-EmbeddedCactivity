/**
 * @file main.c
 * @author NIVESH (you@domain.com)
 * @brief Accumulation of the all the activities
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#include "act1.h" // activity1
#include "act2.h" // activity2
#include "act3.h" // activity3
#include "act4.h" // activity4

uint16_t temp;
char temp_data;
int main(void)
{
InitADC();
InitPWM();
USARTInit(103);
while(1)
{
    act1();// activity1
    temp=ReadADC(1);
    temp_data=OutPWM(temp); // Temperature data
    USARTWriteChar(temp_data);
}

    return 0;
}
