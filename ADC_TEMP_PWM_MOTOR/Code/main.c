/***********************************************
 *  Module:Application
 *
 *  File Name:main.c
 *
 *  Description: Applications
 *
 *  Created on : 26/9/2019
 *
 *  Author: Ahmed Ekram
 ***********************************************/

#include "ADC.h"
#include "LCD.h"
#include "pwm.h"
/*Global variable to store ADC reading*/
uint16 ADC_Reading=0;
/**************************************************************************
 * Function Name : ADC_Get_Value_ISR
 *
 * Description	 : Reading ADC value after interrupt occurence due to Analog to digital conversion
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
#if (INTERRUPT_ENABLED==1)
void ADC_Get_Value_ISR(void)
{
	ADC_Reading=ADC;
}
#endif
int main(void)
{
	uint16 Temprature=0;
	uint16 Temporary_Temp=0;
	/*Initial value for speed of the motor by 30% duty cycle 30% of 255 which indicates the maximum speed */
	uint8 duty=75;
	Temporary_Temp=Temprature;
	/*Motor pins for controlling it's direction*/
	DIO_SetPinDirection(PinC0,OUTPUT);
	DIO_SetPinDirection(PinC1,OUTPUT);
	DIO_WritePin(PinC0,HIGH);
	DIO_WritePin(PinC1,LOW);
	/*This pin is responsible for generating pwm*/
	DIO_SetPinDirection(PinB3,OUTPUT);
	Set_Bit(SREG,I);
	/*Initilizing LCD*/
	LCD_init();
	/*Initilizing ADC*/
	ADC_init(Cfg_Ptr_Struct);
	/*Initilizing PWM*/
	pwm_init();
	/*Clearing Screen*/
	LCD_clearScreen();
	/*Choosing to operate either polling or interrupt for ADC operatons in this example i used polling*/
#if (INTERRUPT_ENABLED==1)
	ADC_SetCallback(ADC_Get_Value_ISR);
#endif
	LCD_displayString("Temp Reading=");
	while(1)
	{
		LCD_goToRowColumn(0,13);
		pwm_activate(duty);
#if (INTERRUPT_ENABLED==1)
		ADC_Read_Channel(0,Cfg_Ptr_Struct);
#else
		/*Responsible for getting ADC reading*/
		ADC_Read_Channel(&ADC_Reading,Cfg_Ptr_Struct);
		/*Temprature value is calculated from the ADC reading and we made scaling operation on it*/
		Temprature=(((uint32)ADC_Reading*150*5)/(1023*1.5));
		/*If current temperature increased by more than one degree celsius of previous temprature we increase duty cycle by 1%*/
		if(Temprature>=Temporary_Temp+1)
		{
			Temporary_Temp=Temprature;
			duty=duty*1.01;
		}
		/*If current temperature decreased by less than one degree celsius of previous temprature we decrease duty cycle by 1%*/
		if(Temprature<=Temporary_Temp-1)
		{
			Temporary_Temp=Temprature;
			duty=duty*0.99;
		}
#endif
		/*Displaying*/
		LCD_intgerToString(Temprature);
		/*To clear the values that is no in the number we are currently displaying*/
		if(Temprature<100)
		{
			LCD_goToRowColumn(0,15);
			LCD_displayCharacter(' ');
		}
		if(Temprature<10)
		{
			LCD_goToRowColumn(0,14);
			LCD_displayCharacter(' ');
			LCD_goToRowColumn(0,15);
			LCD_displayCharacter(' ');
		}
	}
}
