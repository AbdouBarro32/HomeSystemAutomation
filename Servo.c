#include "at91sam3x8.h"
#include "system_sam3x.h"


void initservo() 
{  
  *AT91C_PMC_PCER1 = ( 1 << 4 ); // PMC for PWM! 
  *AT91C_PIOB_PDR = ( 1 << 17 ); //  peripheral controll the pin REG_PIOB_PDR!
  *AT91C_PIOB_ABMR = ( 1 << 17 ); // activate perpheral B to controll REG_PIOB_ABMR
  *AT91C_PWMC_ENA = ( 1 << 1);// Enable PWM-channel in ENA_CHID1
  *AT91C_PWMC_CH1_CMR = 5; // Set Pre-scaler to Master_CLK/32 in PWM_CMRx /vi v?ljer CH1 och master clock
}

void turnServo(int degree)
{  
  *AT91C_PWMC_CH1_CPRDR = 52500;  // hur mycket counter vi hinner g?ra i 20ms ((84 MHz/32)/1000)*20
  *AT91C_PWMC_CH1_CDTYR = 26.25*degree + 2100; 
}
