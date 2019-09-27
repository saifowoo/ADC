/***********************************************
 *  Module:ADC
 *
 *  File Name:ADC_PBCfg.c
 *
 *  Description: User configurations
 *
 *  Created on : 26/9/2019
 *
 *  Author: Ahmed Ekram
 ***********************************************/


#include "ADC.h"
/*User configuration*/
ADC_Configuration_Struct ADC_Cfg_Struct={
		Internal_Vref_Off,
		ADLAR_OFF,
		ADC_Channel_0,
		ADC_Auto_Triggering_Disabled,
		ADC_Interrupt_Disabled,
		ADC_Dvision_64,
		Free_Running_Mode
};
/*Pointer to structure to be passed to the user*/
ADC_Configuration_Struct *Cfg_Ptr_Struct=&ADC_Cfg_Struct;
