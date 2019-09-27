
/***********************************************
 *  Module:PWM
 *
 *  File Name:pwm.h
 *
 *  Description: pwm functions
 *
 *  Created on : 30/8/2019
 *
 *  Author: Ahmed Ekram
 ***********************************************/

#ifndef TIMER1_REGISTERS_H_
#define TIMER1_REGISTERS_H_
#include "function_macros.h"
#include "standard_types.h"
//enum Prescaler{
//	NO_PRESCALER=0,N_1=1,N_8=2,N_64=3,N_256=4,N_1024=5,EXT_SOURCE_Falling=6,EXT_SOURCE_Rising=7
//};
//enum WGM{
//NORMAL=0x00,CTC_Normal=0x08,CTC_toggle=0x18,CTC_clear=0x28,CTC_set=0x38,PWM_PHASE_CLEAR=0x60,
//PWM_FAST_NONINVERTING=0x68,PWM_PHASE_SET=0x70,PWM_FAST_INVERTING=0x78
//};
//struct Timer0_config{
//	enum Prescaler PRE_SCALER;
//    enum WGM Wave_generation_mode;
//};
#define TIMSK    (*(volatile uint8*)(0x59))
#define TIFR     (*(volatile uint8*)(0x58))
/*---Registers Timer0---*/
#define OCR0     (*(volatile uint8*)(0x5C))
#define TCCR0    (*(volatile uint8*)(0x53))
#define TCNT0    (*(volatile uint8*)(0x52))
/*---Registers  Timer1---*/
#define OCR1AH     (*(volatile uint8*)(0x4B))
#define OCR1AL     (*(volatile uint8*)(0x4A)))
#define TIMSK    (*(volatile uint8*)(0x59))
#define TIFR     (*(volatile uint8*)(0x58))
#define TCCR1A    (*(volatile uint8*)(0x4F))
#define TCCR1B    (*(volatile uint8*)(0x4E))
#define TCNT1H    (*(volatile uint8*)(0x4D))
#define TCNT1L    (*(volatile uint8*)(0x4c))
#define ICR1H    (*(volatile uint8*)(0x47))
#define ICR1L    (*(volatile uint8*)(0x46))
/*---Registers Timer2---*/
#define TCCR2		(*(volatile uint8*)(0x45))
#define TCNT2    (*(volatile uint8*)(0x44))
#define OCR2     (*(volatile uint8*)(0x43))
/*---PINS---*/
//TIMSK
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
//TIFR
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
//TCCR0
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7
//TCCR1A
#define WGM10 0
#define WGM11 1
#define FOC1B 2
#define FOC1A 3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7
//TCCR1B
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7
//TCCR2
#define CS20 0
#define CS21 1
#define CS22 2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
#define FOC2  7
/*---Prototype---*/
void timer1_init(void);
void timer_delay(uint32 num);
void pwm_init(void);
void pwm_activate(uint8 duty);
#endif /* TIMER1_REGISTERS_H_ */
