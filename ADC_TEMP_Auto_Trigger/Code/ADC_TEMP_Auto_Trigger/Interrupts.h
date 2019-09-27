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

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "standard_types.h"
#include <avr/interrupt.h>
#define GO    0
#define READY 1
#define STOP  2
enum Interrupt_0_Sense_Control {
LOW_LEVEL_0=0,LOGICAL_CHANGE_0,FALLING_EDGE_0,RISING_EDGE_0
};
enum Interrupt_1_Sense_Control {
LOW_LEVEL_1=0,LOGICAL_CHANGE_1=0x04,FALLING_EDGE_1=0x08,RISING_EDGE_1=0x0C
};
enum Interrupt_2_Sense_Control {
FALLING_EDGE_2=0x00,RISING_EDGE_2=0x40
};

enum Interrupt_GICR {
Int2=0x20,
Int0=0x40,
Int1=0x80
};
struct INT_config{
uint8 INT_NUMBER;
uint8 INT_Control;
};
/*---Extern---*/
extern volatile uint8 state;
//extern uint8 flag;
/*---Interrupts Registers---*/

#define SREG   (*(volatile uint8*)(0x5F))
#define GICR   (*(volatile uint8*)(0x5B))
#define GIFR   (*(volatile uint8*)(0x5B))
#define MCUCR  (*(volatile uint8*)(0x55))
#define MCUCSR (*(volatile uint8*)(0x54))

/*---SREG BITS---*/
#define C 0
#define Z 1
#define N 2
#define V 3
#define S 4
#define H 5
#define T 6
#define I 7

/*---GICR BITS---*/
#define IVCE  0
#define IVSEL 1
#define INT2  5
#define INT0  6
#define INT1  7

/*---MCUCR BITS---*/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

/*---MCUCSR BITS---*/
#define ISC2   6
/*---Interrupt function---*/
//#define INTNUM 3
//#define EINT2_ISR(INTNUM) void __vector_##INTNUM (void) __attribute__ ((signal,_INTRATTRS));
//void __vector_##INTNUM (void)//ISR
//#define vector 3
//void(*ptr)(void);
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
void interrupt_init(void);
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
void ADC_SetCallback_Auto_Trigger(void(*ptr_fun)(void));
#endif /* INTERRUPTS_H_ */
