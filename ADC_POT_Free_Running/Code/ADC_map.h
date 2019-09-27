/*
 * ADC_map.h
 *
 *  Created on: Sep 26, 2019
 *      Author: ahmed
 */

#ifndef ADC_MAP_H_
#define ADC_MAP_H_

/**************************************************************************
 * 				            Included files							      *
 *************************************************************************/
#include "standard_types.h"
/**************************************************************************
 * 				            Registers    							      *
 *************************************************************************/
#define ADMUX  (*(volatile uint8*)0x27)
#define ADCSRA (*(volatile uint8*)0x26)
#define ADCH   (*(volatile uint8*)0x25)
#define ADCL   (*(volatile uint8*)0x24)
#define ADC	   (*(volatile uint16*)0x24)
#define SFIOR  (*(volatile uint8*)0x50)
/***SREG***/
#define SREG  (*(volatile uint8*)0x5F)
/**************************************************************************
 * 				                Pins		   							  *
 *************************************************************************/
/***ADMUX***/
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7
/***ADCSRA***/
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7
/***SFIOR***/
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7
/***SREG***/
#define I 7
/*---HIGH or LOW---*/
#define LOW 0
#define HIGH 1
#endif /* ADC_MAP_H_ */
