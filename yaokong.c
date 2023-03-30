#include "reg52.h"
#include "motor.h"
#include "delay.h"
sbit D0_B = P3^4;//B
sbit D1_A = P3^3;//A
sbit D2_D = P3^2;//D
sbit D3_C  = P3^1;//C
sbit D5 = P3^6;
sbit D6 = P3^7;
void YaoKong()
{
	
		/*if(D0_B == 0){
			zhengzhuan();
			D5 = 1;
		}
		if(D1_A == 0){
			fanzhuan();
			D5 = 0;
		}
		if(D2_D == 0){
			zuozhuan();
			Delay10ms();
			tingzhi();
			D6 = 1;
		}
		if(D3_C == 0){
				youzhuan();
			  Delay10ms();
			  tingzhi();
			D6 = 0;
		}
		
	*/
}