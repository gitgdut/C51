#include <REGX52.H>
#include "main.h"

#define FOSC 11059200L //�ⲿ11.0592MHz
//  ��Ϊ1/100=10ms=0.01s
#define TIME (65536-FOSC/12/100) //��ʱ��0��ʱ10����ĳ�ʼ�
void main()
{
	TMOD = 0x01; //��ʱ��0������ģʽ1,16bit����
	TL0  = TIME; //��ʱ��0��ʼֵ��8λ
	TH0  = TIME>>8;//��ʱ��0��ʼֵ��8λ
	ET0  = 1;    //���ж�ʱ��0��1������ж�
	TR0  = 1;    //������ʱ��0��ʼ��ʱ
	EA   = 1;    //���������ж�
	while(1)
	{
		
	}
}

//10ms�ж�һ��
void tm0_isr() interrupt 1 using 1
{
    static unsigned int  timeMs=0;
		static unsigned int num=0x01;
		TL0  = TIME;   //��һ��10����ĳ�ֵ��װ
		TH0  = TIME>>8;
		P2=~num;
			if(++timeMs>=200)//����
			 {
				timeMs=0;
				 num*=2;
				 if(num>0x80)
				 {
						num=0x01;
				 }
			 }		 			 
}