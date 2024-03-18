#include <htc.h>
#define _XTAL_FREQ 8000000


void delay(unsigned int secunde)
{
while (secunde > 0)
{
  delay_ms(1000);
 
secunde--;
}
}


void main(void)
{
TRISB = 0b00010000; // Setare pin RB4 ca input TRISC = 0;	// Setare port C ca output ANSEL = 0; ANSELH = 0; // Porturile digitale

PR2 = 99;	// Valoare pentru perioada PWM CCPR1L = 70;		// Valoare pentru ciclul de lucru PWM

while(1)
{
delay(50); // Așteaptă 50 de secunde


if(RB1) // Dacă pinul RB4 este la nivel logic 1
{
TMR2ON = 1;	// Pornire Timer2
CCP1CON = 0b00001100; // Configurare pentru modul PWM


delay(45); // Așteaptă 45 de secunde


TMR2ON = 0;	// Oprire Timer2
 
CCP1CON = 0;	// Dezactivare mod PWM
}	}	}
