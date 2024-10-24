#include "exceptions.h"
#include "system_sam3x.h" 
#include "at91sam3x8.h"


unsigned int lightsecond= 0;
unsigned int LEDlight = 0;
unsigned int darklight= 0;

void ledSetting();

void lightPeriod(){ //16 hours of light and 8 hours of darkness 
  
if(hh < 16 ){
  lightsecond++;
  
if(one  < 0.6 && second <0.6){ //if there is sunlight
  *AT91C_PIOD_CODR = (1<<3); //turn off the lamp
} 

else {
  *AT91C_PIOD_SODR = (1<<3); //turn on
  LEDlight++;
  darklight++;
 } 
}

else {
  *AT91C_PIOD_CODR = (1<<3); // lamp is off
  turnServo(0);
  darklight++;
}
  
if(newday==1){
  LEDlight =0;
  lightsecond =0;
  darklight =0;
  newday=0;
 }
}