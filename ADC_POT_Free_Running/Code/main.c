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
	/*Initializing ADC channel 0 as input pin  */
	DIO_SetPinDirection(PinA0,INPUT);
	/*Setting global interrupt pin high if needed*/
	Set_Bit(SREG,I);
	/*Initilizing LCD*/
	LCD_init();
	/*Initilizing ADC*/
	ADC_init(Cfg_Ptr_Struct);
	/*Clearing Screen*/
	LCD_clearScreen();
	/*Choosing to operate either polling or interrupt for ADC operatons in this example i used polling*/
#if (INTERRUPT_ENABLED==1)
	ADC_SetCallback(ADC_Get_Value_ISR);
#endif
	LCD_displayString("ADC Reading=");
	while(1)
	{
		LCD_goToRowColumn(0,12);
#if (INTERRUPT_ENABLED==1)
		ADC_Read_Channel(0,Cfg_Ptr_Struct);
#else
		/*Responsible for getting ADC reading*/
		ADC_Read_Channel(&ADC_Reading,Cfg_Ptr_Struct);
#endif
		/*Displaying on LCD*/
		LCD_intgerToString(ADC_Reading);
		/*To clear the values that is no in the number we are currently displaying*/
		if(ADC_Reading<1000)
		{
			LCD_goToRowColumn(0,15);
			LCD_displayCharacter(' ');
		}
		if(ADC_Reading<100)
		{
			LCD_goToRowColumn(0,14);
			LCD_displayCharacter(' ');
			LCD_goToRowColumn(0,15);
			LCD_displayCharacter(' ');
		}
		if(ADC_Reading<10)
		{
			LCD_goToRowColumn(0,13);
			LCD_displayCharacter(' ');
			LCD_goToRowColumn(0,14);
			LCD_displayCharacter(' ');
		}
	}
}
