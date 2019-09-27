/***********************************************
 *  Module:Interrupts
 *
 *  File Name: interrupts.c
 *
 *  Description: interrupts Functions
 *
 *  Created on : 02/9/2019
 *
 *  Author: Ahmed Ekram
 ***********************************************/
#include "interrupts.h"
#include "function_macros.h"
#include "Memory_map.h"
/*Pointer to function to be called from ISR as it holds the address of callback function*/
void (*Ptr_To_Fun)(void)=NULL;
ISR(INT2_vect)
{
	if(Ptr_To_Fun!=NULL)
	{
		(*Ptr_To_Fun)();
	}
}
struct INT_config INT2_config={0x20,RISING_EDGE_2};
//uint8 flag=0;
/**************************************************************************
 * Function Name : interrupt_init
 *
 * Description	 : Function for initializing interrupt two
 *
 * INPUTS		 : void(*Ptr_Func_Auto_Trigger)(void)
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void interrupt_init(void)
{
	Set_Bit(MCUCSR,ISC2);
	GICR|=INT2_config.INT_NUMBER;
}
/**************************************************************************
 * Function Name : ADC_SetCallback_Auto_Trigger
 *
 * Description	 : Function for assigning callback function to a pointer to function and to be called by ISR
 *
 * INPUTS		 : void(*Ptr_Func_Auto_Trigger)(void)
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void ADC_SetCallback_Auto_Trigger(void(*Ptr_Func_Auto_Trigger)(void))
{
	Ptr_To_Fun=Ptr_Func_Auto_Trigger;
}
