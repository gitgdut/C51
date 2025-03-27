#include <REGX52.H>
#include "main.h"

#define FOSC 11059200L //Íâ²¿11.0592MHz
//  ÒòÎª1/100=10ms=0.01s
#define TIME (65536-FOSC/12/100) //¶¨Ê±Æ÷0¶¨Ê±10ºÁÃëµÄ³õÊ¼Ö
void main()
{
	TMOD = 0x01; //¶¨Ê±Æ÷0¹¤×÷ÔÚÄ£Ê½1,16bit¼ÆÊý
	TL0  = TIME; //¶¨Ê±Æ÷0³õÊ¼ÖµµÍ8Î»
	TH0  = TIME>>8;//¶¨Ê±Æ÷0³õÊ¼Öµ¸ß8Î»
	ET0  = 1;    //ÔËÐÐ¶¨Ê±Æ÷0µ½1ºÁÃëºóÖÐ¶Ï
	TR0  = 1;    //Æô¶¯¶¨Ê±Æ÷0¿ªÊ¼¼ÆÊ±
	EA   = 1;    //ÔÊÐíËùÓÐÖÐ¶Ï
	while(1)
	{
		
	}
}

//10msÖÐ¶ÏÒ»´Î
void tm0_isr() interrupt 1 using 1
{
    static unsigned int  timeMs=0;
		static unsigned int num=0x01;
		TL0  = TIME;   //ÏÂÒ»¸ö10ºÁÃëµÄ³õÖµÖØ×°
		TH0  = TIME>>8;
		P2=~num;
			if(++timeMs>=200)//µ÷Õû
			 {
				timeMs=0;
				 num*=2;
				 if(num>0x80)
				 {
						num=0x01;
				 }
			 }		 			 
}