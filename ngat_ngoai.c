#include<p18f4520.h> 
#include<delays.h>
#pragma config OSC=HS 
#pragma config WDT=OFF 
#pragma config MCLRE=ON 
#pragma config PBADEN=OFF 
//khai b�o t�n chuong tr�nh con ph?c v? ng?t (CTCPVN) 
void ngat_ngoai(void); 
//�i?m d?t chuong tr�nh ph?c v? ng?t c� m?c uu ti�n cao //(vector 0008H) 
#pragma code uu_tien_cao = 0x08 
//T�n CTCPVN uu ti�n cao (t�y ch?n) 
void ngat_cao(void) 
{ 
 ngat_ngoai(); //g?i d?n CTCPVN 
} 
//�i?m vi?t CTCPVN 
#pragma code 
#pragma interrupt ngat_ngoai 
void ngat_ngoai(void) 
//Noi dung cua CTCPVN 
{ 
//Ki?m tra bit c? c?a ngu?n ng?t th? nh?t, n?u = 1. 
if(INTCONbits. INT0IF==1)
{ 
PORTD=2;//chan 2 sang
Delay10TCYx(2500);
//X�a c? c?a ngu?n ng?t th? nh?t 
//C�c l?nh x? l� khi c� ng?t t? ngu?n th? nh?t 
}
INTCONbits. INT0IF=0;// xoa co ngat
} 
//Chuong tr�nh ch�nh 
void main() 
{ 
ADCON1=0x0f;
TRISB=7;
TRISD=0;
INTCON=0b10010000;

INTCON2bits.INTEDG0=0;


// blink led1
while(1)
{
PORTD=1;
Delay10TCYx(250);
PORTD=0;
Delay10TCYx(250);
}

} 