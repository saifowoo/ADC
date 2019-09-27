/***********************************************
 *  Module:ADC
 *
 *  File Name:ADC.h
 *
 *  Description: ADC Functions
 *
 *  Created on : 26/9/2019
 *
 *  Author: Ahmed Ekram
 ***********************************************/

#ifndef ADC_H_
#define ADC_H_
/**************************************************************************
 * 				            Included files							      *
 *************************************************************************/
#include "standard_types.h"
#include "function_macros.h"
#include "ADC_map.h"
#include "DIO_operations.h"
#include <avr/interrupt.h>
/**************************************************************************
 * 				            User Defined types							  *
 *************************************************************************/
/***Enabling or disabling Interrupt for display***/
#define INTERRUPT_ENABLED 0
/***Enums***/
/***ADMUX***/
typedef enum{
Internal_Vref_Off=0x00,External_Capacitor_Arefpin=0x40,Internal_Vref_On=0xC0
}REF_Selection_Bits;
typedef enum{
	ADLAR_OFF=0x00,ADLAR_ON=0X20
}ADLAR_Operation;
typedef enum{
	ADC_Channel_0=0x00,ADC_Channel_1=0x01,ADC_Channel_2=0x02,ADC_Channel_3=0x03,
	ADC_Channel_4=0x04,ADC_Channel_5=0x05,ADC_Channel_6=0x06,ADC_Channel_7=0x07,
}ADC_Channel;
/***ACSRA***/
typedef enum{
	ADC_Disable=0x00,ADC_Enabled=0x80
}ADC_Enable;

typedef enum{
	ADC_Srart_Conversion=0x40
}ADC_Conversion;

typedef enum{
	ADC_Auto_Triggering_Disabled=0x00,ADC_Auto_Triggering_Enabled=0x20
}ADC_Auto_Triggering;

typedef enum{
	ADC_Interrupt_Disabled=0x00,ADC_Interrupt_Enabled=0x08
}ADC_Interrtupt_Enable;

typedef enum{
	ADC_Dvision_2=0x00,ADC_Dvision_4=0x02,ADC_Dvision_8=0x03,
	ADC_Dvision_16=0x04,ADC_Dvision_32=0x05,ADC_Dvision_64=0x06,ADC_Dvision_128=0x07
}ADC_Prescaler_Select_Bits;

/***SFIOR***/
typedef enum{
	Free_Running_Mode=0x00,Analog_Comparator=0x20,External_Interrupt=0x40,
	Timer0_Compare_Match=0x60,Timer0_Overflow=0x80,Timer1_Compare_Match=0x90,
	Timer1_Overflow=0xC0,Timer1_Capture_Event=0xE0,
}ADC_Auto_Trigger_Source;

/***Structs***/
typedef struct{
	REF_Selection_Bits          Voltage_Reference_Mode ;
	ADLAR_Operation             ADLAR_Operation_Choice;
	ADC_Channel                 ADC_Channel_Choice;
	ADC_Auto_Triggering         ADC_Auto_Triggering_State;
	ADC_Interrtupt_Enable       ADC_Interrtupt_Enable_State;
	ADC_Prescaler_Select_Bits   ADC_Prescaler;
	ADC_Auto_Trigger_Source     ADC_Triggering_Source;
}ADC_Configuration_Struct;
/**************************************************************************
 * 				                Global Decalarations					  *
 *************************************************************************/
extern ADC_Configuration_Struct * Cfg_Ptr_Struct;

/**************************************************************************
 * 				                Function Prototypes						  *
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
void ADC_init(ADC_Configuration_Struct * Cfg_Ptr_Struct);
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
void ADC_Read_Channel(uint16 *ADC_Read_Value,ADC_Configuration_Struct * Cfg_Ptr_Struct);
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
void ADC_Deinit(void);
/**************************************************************************
 * Function Name : ADC_SetCallback
 *
 * Description	 : Function for assigining callback function to a pointer to function and to be call by ISR
 *
 * INPUTS		 : void (*Ptr_Func_ADC)(void)
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/

#if (INTERRUPT_ENABLED==1)
void ADC_SetCallback(void (*Ptr_Func)(void));
#endif

#endif /* ADC_H_ */
