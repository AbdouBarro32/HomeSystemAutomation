#include "exceptions.h"
#include "system_sam3x.h" 
#include "at91sam3x8.h"


int flagg=0;
//int flag2=0;
double one;
double second;

void ADCConf() {
  *AT91C_PMC_PCER1 =(1<<4)|(1<<5); // Enable clock ADC
  *AT91C_PMC_PCER = ( 1 << 11 );
  *AT91C_PIOA_PER=(1<<4)|(1<<5);;
  
  *AT91C_PIOA_OER=(1<<4)|(1<<5);;
  *AT91C_PIOA_PPUDR=(1<<4)|(1<<5);;
  *AT91C_ADCC_MR &= (~(0xFF00)); //Clear prescaler
  *AT91C_ADCC_MR = (2<<8); //Set prescaler to 2
  *AT91C_ADCC_CHER = 0x6; //Enable channel 1 and 2

  *AT91C_ADCC_CR = 0X2; //Start ADC conversion
  *AT91C_ADCC_SR;
  NVIC_ClearPendingIRQ(ADC_IRQn);
  NVIC_SetPriority(ADC_IRQn, 1);
  NVIC_EnableIRQ(ADC_IRQn);
  *AT91C_ADCC_IER = (3<<1); //Enable interrupt
}

void ADC_Handler(){
 int clear = *AT91C_ADCC_SR;
 if((clear &0X2)==0X2){
 one = (*AT91C_ADCC_CDR1&0XFFF)*(3.3/4095);
 
 }
 
 if(((clear &0X4))==0X4){
 second = (*AT91C_ADCC_CDR2&0XFFF)*(3.3/4095);
 
 }
  flagg=1; 
 *AT91C_ADCC_IDR=0X6;
}