#include <regx52.h>
#include "timer.h"
#include "LCD1602.h"

unsigned char sec=52,min=12,hour=23;
void main()
{
	
	Timer009();
	LCD_Init();
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :");
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,sec,2);
	}
}

void Timer0_Routine() interrupt 1 
{
	static unsigned int count=0;
	TL0 = 0x66;		
	TH0 = 0xFC;		
	count++;
	if(count>=1000)
	{
		count=0;
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{
				min=0;
				hour++;
				if(hour>=60)
				{
					hour=0;
				}
			}
		}
	}
}