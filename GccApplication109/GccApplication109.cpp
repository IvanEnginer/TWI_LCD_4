#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "TWI.h"
#include "LCD_I2C.h"

int n=0;

char unit[][32] =
{
	"Unit 1" ,
	"Unit 2",
	"Unit 3",
	"Unit 4",
	"Unit 5"
};

int main(void)
{
	I2C_Init();
	lcd_init();
	while(1)
	{
		if (n==5)
		{
			n=0;
		}
		lcd_putstring(unit[n]);
		_delay_ms(1000);
		n++;
		lcd_clear();
	}
}