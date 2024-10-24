#include "exceptions.h"
#include "system_sam3x.h" 
#include "at91sam3x8.h"
#define AT91C_PIO_AIMER (AT91_CAST(AT91_REG *) 0x400E14B0)
#define AT91C_PIO_IFER  (AT91_CAST(AT91_REG*)0x400E1620)
#define AT91C_PIO_DIFSR  (AT91_CAST(AT91_REG*) 0x400E1484)
#define AT91C_PIO_SCDR  (AT91_CAST(AT91_REG*)0x400E148C)


unsigned int nbutton = 0;
unsigned int  sett = 1;
unsigned int  timer = 0;
void SysTick_Handler(void);
void Set_LedOnOf();

int counter=0;

void ReadButton(unsigned int *nButton){

if((*AT91C_PIOD_PDSR & (1<<1))==(1<<1)){
  *nButton=0;  
}
 
else{
  *nButton=1;
 }
}

void Set_Led(unsigned int nLed){
if(nLed == 0){
  *AT91C_PIOD_CODR = (1<<3);
}

else{
  *AT91C_PIOD_SODR = (1<<3);
 }
}

void ledSetting(){
  *AT91C_PMC_PCER = (1<<14);
  *AT91C_PIOD_PER=(1<<3);
  *AT91C_PIOD_OER=(1<<3);
  *AT91C_PIOD_PPUDR=(1<<3);
  *AT91C_PIOD_PER=(1<<1);
  *AT91C_PIOD_OER=(1<<1);
  *AT91C_PIOD_PPUDR=(1<<1);
}

void butSetting(){
  *AT91C_PMC_PCER= (1<<14); 
  *AT91C_PIOD_PER=(1<<1);
  *AT91C_PIOD_PPUDR=(1<<1);
  *AT91C_PIOD_ODR=(1<<1);
  //*AT91C_PIOD_ODSR=(1<<1);
}

void led(){
if(counter%2==0){Set_LedOnOf();}
else{Set_Led(0);}
}

void Set_LedOnOf(){
  Ddelay(1000);
  Set_Led(1);
  Ddelay(1000);
  Set_Led(0);
}

void PIOD_Handler(void){
  counter++;
  *AT91C_PIOD_ISR;
}