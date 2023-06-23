/*
 * COOLER.c
 *
 * Created: 9/8/2022 7:01:24 PM
 *  Author: Esraa
 */ 
#include "COOLER.h"
uint8_t duty = 0;

void COOLER_init()
{
	Buzz;
	LCD_init();
	ADC_init();
	SEVEN_SEG_init();
	TIMER1_PWM_oc1A_init();
}

uint8_t COOLER_check_heat(uint8_t temprature)
{
	if (temprature>=35)
	{
		return 1;
	}
	if (temprature<35)
	{
		return 0;
	}
	return 2;
}

void COOLER_on(uint8_t temperature)
{
	LCD_write_command(first_line);
	LCD_write_number(temperature);
	LCD_write_data('C');
	SEVEN_SEG_write(temperature);
	
	Buzz_on;
	duty = 50+ (temperature-35);
	LCD_write_command(second_line);
	LCD_write_number(duty);
	LCD_write_string("  duty cycle");
	TIMER1_PWM_oc1A_duty(duty);
	
}


void COOLER_off(uint8_t temprature)
{
	Buzz_off;
	TIMER1_PWM_oc1A_duty(0);
	LCD_write_command(first_line);
	LCD_write_number(temprature);
	LCD_write_data('C');
	SEVEN_SEG_write(temprature);
	LCD_write_command(second_line);
	LCD_write_number(duty);
	LCD_write_string("  duty cycle");
	
}