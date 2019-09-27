/***********************************************
 *  Module:ADC
 *
 *  File Name:ADC.c
 *
 *  Description: ADC Functions
 *
 *  Created on : 26/9/2019
 *
 *  Author: Ahmed Ekram
 ***********************************************/

#include "ADC.h"
/**************************************************************************
 * Function Name : ISR_ADC
 *
 * Description	 : Code to be executed in case of analog to digital conversion is done and interrupt happened
 *
 * INPUTS		 : void (*Ptr_Func_ADC)(void)
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
#if (INTERRUPT_ENABLED==1)
void (*Ptr_To_Fun)(void)=NULL;
ISR(ADC_vect)
{
	if(Ptr_To_Fun!=NULL)
	{
		(*Ptr_To_Fun)();
	}
}
#endif
/**************************************************************************
 * 				                Function         						  *
 *************************************************************************/
/**************************************************************************
 * Function Name : ADC_init
 *
 * Description	 : Initilizng ADC module
 *
 * INPUTS		 : Pointer to structure to configurations struct
 *
 * 				   ADC_Configuration_Struct * Cfg_Ptr_Struct
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void ADC_init(ADC_Configuration_Struct * Cfg_Ptr_Struct)
{
	ADMUX=0;

	ADMUX|=Cfg_Ptr_Struct->Voltage_Reference_Mode|Cfg_Ptr_Struct->ADC_Channel_Choice|Cfg_Ptr_Struct->ADLAR_Operation_Choice;
	ADCSRA|=Cfg_Ptr_Struct->ADC_Auto_Triggering_State|Cfg_Ptr_Struct->ADC_Interrtupt_Enable_State|
			Cfg_Ptr_Struct->ADC_Prescaler;
	Set_Bit(ADCSRA,ADEN);
}
/**************************************************************************
 * Function Name : ADC_Read_Channel
 *
 * Description	 : Reading ADC channel and save it's value
 *
 * INPUTS		 : ADC_Configuration_Struct * Cfg_Ptr_Struct
 *
 * OUTPUTS 		 : uint16 *ADC_Read_Value to hold ADC value and save it and it's address of global variable
 *
 * Return		 : void
 **************************************************************************/
void ADC_Read_Channel(uint16 *ADC_Read_Value,ADC_Configuration_Struct * Cfg_Ptr_Struct)
{
	Cfg_Ptr_Struct->ADC_Channel_Choice&=0x07;
	ADMUX&=0xE0;
	ADMUX|=Cfg_Ptr_Struct->ADC_Channel_Choice;
	Set_Bit(ADCSRA,ADSC);
	if(Cfg_Ptr_Struct->ADC_Interrtupt_Enable_State==ADC_Interrupt_Disabled)
	{

		while(!(Get_Bit(ADCSRA,ADIF)));
		Set_Bit(ADCSRA,ADIF);
		*ADC_Read_Value=ADC;
	}
	else
	{
		/*Do Nothing*/
	}
}
/**************************************************************************
 * Function Name : ADC_Deinit
 *
 * Description	 : Disabling ADC
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void ADC_Deinit(void)
{
	ADMUX=0;
	ADCSRA=0;
}
/**************************************************************************
 * Function Name : ADC_SetCallback
 *
 * Description	 : Function for assigning callback function to a pointer to function and to be call by ISR
 *
 * INPUTS		 : void (*Ptr_Func_ADC)(void)
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
#if (INTERRUPT_ENABLED==1)
void ADC_SetCallback(void (*Ptr_Func_ADC)(void))
{
	Ptr_To_Fun=Ptr_Func_ADC;
}
#endif
