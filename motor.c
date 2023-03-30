#include "reg52.h"

sbit A1 = P1^6;
sbit A2 = P1^5;

sbit B1 = P1^7;
sbit B2 = P3^0;

sbit a1 = P1^4;
sbit a2 = P1^3;

sbit b1 = P1^2;
sbit b2 = P1^1;

void Af()
{
	A1 = 0;
	A2 = 1;
}
void Ar()
{
	A1 = 1;
	A2 = 0;
}
void Bf()
{
	B1 = 0;
	B2 = 1;
}
void Br()
{
	B1 = 1;
	B2 = 0;
}
void a_foreward()
{
	a1 = 0;
	a2 = 1;
}
void a_reversal()
{
	a1 = 1;
	a2 = 0;
}
void b_foreward()
{
	b1 = 0;
	b2 = 1;
}
void b_reversal()
{
	b1 = 1;
	b2 = 0;
}
void stop()
{
	a1 = 0;
	b1 = 0;
	a2 = 0;
	b2 = 0;
	A1 = 0;
	A2 = 0;
	B1 = 0;
	B2 = 0;
}
