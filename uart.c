#include "reg52.h"
#include "motor.h"
#include "string.h"
#define SIZE 50



sfr AUXR = 0x8E;
char buffer[SIZE];

void UartInit (void)
{
	AUXR = 0x01;
	SCON = 0x50;//配置串口工作方式1，REN使能接收
	TMOD &= 0xF0;
	TMOD |= 0x20;//定时器1工作方式8位自动重装
	
	TH1 = 0xFD;
	TL1 = 0xFD;     //9600波特率的初始值
	TR1 = 1;  	//启动定时器
	
	EA = 1;
	ES = 1;
}



void Uart_Handle() interrupt 4
{
	static int i = 0;
	int tmp;
	while(1){
		if(RI){
			RI = 0;
			tmp = SBUF;
			if(tmp == 'M'){
				i=0;
			}
			buffer[i++] = tmp;
			if(buffer[0] == 'M'){
				switch(buffer[1]){
					case '1':
						Af();
						Br();
						a_reversal();
						b_foreward();
						break;
					case '2':
						Ar();
						Bf();
						b_reversal();
						a_foreward();
						break;
					case '3':
						Af();
						Bf();
						b_foreward();
						a_foreward();
						break;
					case '4':
						Ar();
						Br();
						b_reversal();
						a_reversal();
						break;
					case '5':
						stop();
						break;
				}
			}
			if(i == 50){
				i=0;
				memset(buffer, 0, sizeof(buffer));
			}
		}
	}
}

/*void Uart_Handle() interrupt 4
{
	static int i = 0;     ///静态变量，被初始化第一次
	char tmp;
	while(1){
	if(RI){  		//中断处理函数，对于接受中断的响应
		  RI = 0;        //清除中断函数
		  tmp = SBUF;
		if(tmp == 'M'){
				i=0;
    }
		
		  buffer[i++] = tmp;
		
		
		if(buffer[0] == 'M'){
			//D5 = 0;
		 switch(buffer[1]){
				case '1':
					Af();
          Br();
	        a_reversal();
	        b_foreward();
				  //Delay1000ms();
				
			   //stop();

					break;
				case '2':
					Ar();
          Bf();
	        b_reversal();
	        a_foreward();
				//Delay1000ms();
		
				//stop();
					break;
				case '3':
					Af();
          Bf();
	        b_foreward();
	        a_foreward();
				//Delay1000ms();
			
				//stop();
					break;
				case '4':
					Ar();
          Br();
	        b_reversal();
	        a_reversal();
				 // Delay1000ms();
			
				//stop();
					break;
				case '5':
					stop();
				break;
      }
    }
		if(i == 15){
			i=0;
			memset(buffer, '\0',SIZE);
			}
		}
	}

}*/