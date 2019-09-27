/***********************************************
 *  Module:Application
 *
 *  File Name:main.c
 *
 *  Description: Applications
 *
 *  Created on : 26/9/2019
 *
 *  Author: Ahmed Ekram & Saif El-Deen
 ***********************************************/

#define F_CPU 8000000
#include "ADC.h"
#include "LCD.h"
uint16 ADC_Reading=0;
/**************************************************************************
 * Function Name : ADC_Get_Value_ISR
 *
 * Description	 : Reading ADC value after interrupt occurrence due to Analog to digital conversion
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
	uint16 tempvalue = 0;
	/*Initializing ADC channel 0 as input pin  */
	DIO_SetPinDirection(PinA0,INPUT);
	/*Setting global interrupt pin high if needed*/
	Set_Bit(SREG,I);
	/*Initializing LCD*/
	LCD_init();
	/*Initializing ADC*/
	ADC_init(Cfg_Ptr_Struct);
	/*Clearing Screen*/
	LCD_clearScreen();
	/*Choosing to operate either polling or interrupt for ADC operations in this example i used polling*/
#if (INTERRUPT_ENABLED==1)
	ADC_SetCallback(ADC_Get_Value_ISR);
#endif
	LCD_displayString("Digital= ");
	while(1)
	{
		LCD_goToRowColumn(0,9);
#if (INTERRUPT_ENABLED==1)
		ADC_Read_Channel(0,Cfg_Ptr_Struct);
#else
		/*Responsible for getting ADC reading*/
		ADC_Read_Channel(&ADC_Reading,Cfg_Ptr_Struct);
#endif
		tempvalue = (((uint32)ADC_Reading)*150*5)/(1023*1.5);
		/*Displaying on LCD*/
		LCD_intgerToString(tempvalue);
		/*To clear the values that is no in the number we are currently displaying*/
		if(tempvalue<100)
		{
			LCD_goToRowColumn(0,11);
			LCD_displayCharacter(' ');
			LCD_goToRowColumn(0,12);
			LCD_displayCharacter(' ');
		}
		if(tempvalue<10)
		{
			LCD_goToRowColumn(0,10);
			LCD_displayCharacter(' ');
			LCD_goToRowColumn(0,11);
			LCD_displayCharacter(' ');
		}
	}
}
