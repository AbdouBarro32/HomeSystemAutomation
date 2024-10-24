#include "at91sam3x8.h"
#include "system_sam3x.h"
//#include "Systick.c"
#include "exceptions.h"


int readytoRead=0;
double t=0;
int flag1=0;
void Ddelay();

void iniTemp(){
  *AT91C_PMC_PCER = (1<<12); //activate peripeheral clock for port B
  *AT91C_PMC_PCER = (1<<27); //activate timer counter
  *AT91C_TC0_CCR = (1 << 0); //enable bit 0 in TC channel control register
  *AT91C_TC0_CCR = (1 << 2); // reset and start counter bit 2
  *AT91C_TC0_CMR = (*AT91C_TC0_CMR & 0xfff8)|(1<<17)|(1<<18); //: TIOA or TIOB External Trigger Selection
  *AT91C_PIOB_PER = (1 << 25); // Enable pin 2 
  *AT91C_PIOB_OER = (1 << 25); 
  *AT91C_PIOB_SODR = (1 << 25); 
  *AT91C_PIOB_CODR = (1 << 25); 
  Ddelay(16);
  *AT91C_PIOB_SODR = (1 << 25); 
  NVIC_ClearPendingIRQ(TC0_IRQn); //  remove the pending state from interrupt, and show which interrupt are pending.
  NVIC_SetPriority(TC0_IRQn,0); // priortiize TC0
  NVIC_EnableIRQ(TC0_IRQn); // Enable the interrupt (NVIC) with the inline declared function
}

void measure(){
  *AT91C_PIOB_OER = (1 << 25); // pin 2 as output
  *AT91C_PIOB_SODR = (1 << 25); //  set pin as high 
  *AT91C_PIOB_CODR = (1 << 25); // T-reset from high to low "Pin low"
  Ddelay(16); // REST low
  *AT91C_PIOB_SODR = (1 << 25); // T-setup
   Ddelay(1); //T-setup  rest
  *AT91C_PIOB_CODR = (1 << 25); // T-START
   Ddelay(1); // rest
  *AT91C_PIOB_SODR = (1 << 25); // stop read pulse  
  *AT91C_PIOB_ODR = (1 << 25); // disable output for pin2 "make it an input"
  *AT91C_TC0_CCR = (1 << 2); //reset counter
  *AT91C_TC0_SR; //Read status register to clear 
  *AT91C_TC0_IER =  (1 << 6); //load value to read
}

void TC0_Handler(){
  *AT91C_TC0_SR; //Read status register
  *AT91C_TC0_IDR = (1 << 6); // Disable interrupt Register
  readytoRead = 1;  // the vaule  is ready to read "flag"
}

  double readtemp()
{  
  int falling = *AT91C_TC0_RA;                     
  int rising  = *AT91C_TC0_RB;                       
  int period = rising - falling;                           
  double c = (((period/42/5))) - 273.15;// Equation from the lecture
  t = c;
return t;
}