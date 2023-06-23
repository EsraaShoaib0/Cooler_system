/*
 * COOLER.h
 *
 * Created: 9/8/2022 7:02:03 PM
 *  Author: Esraa
 */ 


#ifndef COOLER_H_
#define COOLER_H_
#include "ADC.h"
#include "std_macros.h"
#include "LCD.h"
#include "TIMER1.h"
#include "SEVEN_SEG.h"
#define Buzz		SETBIT(DDRC,0)
#define Buzz_on		SETBIT(PORTC,0)
#define Buzz_off	CLRBIT(PORTC,0)
/*****************************************************************************
* Function Name: COOLER_init
* Purpose      : to initialize COOLER functionality
* Parameters   : void
* Return value : void
*****************************************************************************/
void COOLER_init(void);
/*****************************************************************************
* Function Name: COOLER_on
* Purpose      : to turn on the cooler and control the device by the entering heat
* Parameters   : temprature
* Return value : void
*****************************************************************************/
void COOLER_on(uint8_t temperature);
/*****************************************************************************
* Function Name: COOLER_off
* Purpose      : to turn off the cooler system if the heat is lower then 35 c
* Parameters   : void
* Return value : void
*****************************************************************************/
void COOLER_off(uint8_t temprature);
/*****************************************************************************
* Function Name: COOLER_check_heat
* Purpose      : to check heat coming from the sensor 
* Parameters   : temprature
* Return value : char
*****************************************************************************/
uint8_t COOLER_check_heat(uint8_t temprature);




#endif /* COOLER_H_ */