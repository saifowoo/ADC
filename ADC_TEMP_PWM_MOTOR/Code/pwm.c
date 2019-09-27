/***********************************************
 *  Module:PWM
 *
 *  File Name:pwm.c
 *
 *  Description: pwm functions
 *
 *  Created on : 30/8/2019
 *
 *  Author: Ahmed Ekram
 ***********************************************/

#include "pwm.h"
#include "timer0_registers.h"
void pwm_init(void)
{
	TCNT0=0;
	OCR0=77;/*start at 30 % of speed*/
	TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00)|(1<<CS01);

}
void pwm_activate(uint8 duty)
{
	OCR0=duty;
}
