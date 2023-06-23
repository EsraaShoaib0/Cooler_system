/*
 * Cooler_Project.c
 *
 * Created: 9/8/2022 6:59:07 PM
 * Author : Esraa
 */ 
#include "COOLER.h"
#define Heat_Value   ADC_read()/3.5
int main(void)
{
	COOLER_init();
    /* Replace with your application code */
    while (1) 
    {
		
		if (COOLER_check_heat(Heat_Value)==1)
		{
			COOLER_on(Heat_Value);
		}
		else{
			COOLER_off(Heat_Value);
		}
	
    }
}

