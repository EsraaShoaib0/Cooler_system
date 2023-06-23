/*
 * TIMER1.c
 *
 * Created: 8/20/2022 11:25:11 AM
 *  Author: safifi
 */ 
#include "TIMER1.h"

/*****************************************************************************
* Function Name: TIMER1_PWM_oc1A_init
* Purpose      :init timer1 pin oc1a PWM (fast freq, 10bit, non inverting, no prescaler)
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIMER1_PWM_oc1A_init(void){
	SETBIT(DDRD,5);
	SETBIT(TCCR1A,COM1A1); // set non inverting mode
	SETBIT(TCCR1A,WGM10);  // set FAST frq 10bit
	SETBIT(TCCR1A,WGM11);  // set FAST frq 10bit
	SETBIT(TCCR1B,WGM12);  // set FAST frq 10bit
	SETBIT(TCCR1B,CS10);   // No prescaler	
}
/*
duty = (100 / 1023) * OCR1A


*/
void TIMER1_PWM_oc1A_duty(uint8_t duty ){
	OCR1A = duty * 10.23;
}