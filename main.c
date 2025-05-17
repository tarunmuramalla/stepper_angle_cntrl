#include <reg51.h>
#include <stdio.h>
#include <LCD.h>
#include <keypad_m.h>

void rotation(int);

int a=0;

int char_to_integer(char d)
{
	if(d >= '0' && d <= '9')
	{
		  a=a*10 + (d - '0');
	}
	else if(d == '=')
	{
		char str[5];
		
		rotation(a);
		
	  sprintf(str,"%d",a);
		LCD_String(str);
	}
}

void rotation(int a)
{
	  unsigned int arr[5]={0x09,0x0c,0x06,0x03,0x09};
		int i=0;
		a=a/90;
		
		
		if(a<4)
		{
			for(i=0;i<a+1;i++)
			{
				P2=arr[i];
				delay(100);
			}
		}
		else
		{
			while(a>1)
			{
					for(i=0;i<5;i++)
					{
						P2=arr[i];
						delay(100);
					}
					a=a/4;
			}
	  }
}

void main(void)
{ 
	 unsigned int i=0;
	 char ch=0;
	 LCD_Init();
	 P2=0x00;
   while (1)
	 { 
		 ch=keypad();
		 char_to_integer(ch);
	 }
 }
