#include <REGX52.H>
#include "main.h"

#define FOSC 11059200L //外部11.0592MHz
//  因为1/100=10ms=0.01s
#define TIME (65536-FOSC/12/100) //定时器0定时10毫秒的初始�
void main()
{
	TMOD = 0x01; //定时器0工作在模式1,16bit计数
	TL0  = TIME; //定时器0初始值低8位
	TH0  = TIME>>8;//定时器0初始值高8位
	ET0  = 1;    //运行定时器0到1毫秒后中断
	TR0  = 1;    //启动定时器0开始计时
	EA   = 1;    //允许所有中断
	while(1)
	{
		
	}
}

//10ms中断一次
void tm0_isr() interrupt 1 using 1
{
    static unsigned int  timeMs=0;
		static unsigned int num=0x01;
		TL0  = TIME;   //下一个10毫秒的初值重装
		TH0  = TIME>>8;
		P2=~num;
			if(++timeMs>=200)//调整
			 {
				timeMs=0;
				 num*=2;
				 if(num>0x80)
				 {
						num=0x01;
				 }
			 }		 			 
}