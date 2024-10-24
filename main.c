#include "at91sam3x8.h"
#include "Display.c"
#include "keypad.c"
#include "Tempsensor.c"
#include "system_sam3x.h"
#include "exceptions.h"
#include "LightSensor.c"
#include "Servo.c"
#include "LinkedList.c"
#include "functions.c"
#include "TimeDate.c"
#include "Temprecording.c"
#include "alarm.c"
#include "LightHours.c"
#include "motorcontrol.c"
#include "DisplaySett.c"
#include "Systick.c"


struct LinkedList *list;
int keypressed=0;
char word[100];
void SysConfig();
void initservo();
void config_digit();
double val1;
double val2;
unsigned int keyPressed;


void Systick_Handler(void);
int t1;

void main(void){
  
   SystemInit();
   SysConfig(); 
   regSett();
   iniTemp();
   ledSetting();
   initservo();
   SystemInit(); 
   initservo();
   initDisplay();                        
   clearDisplay();

while(1){
    
   alarmLimit();
   tempRecord();
   alarmsignal();
   ADCConf();  
   keypressed = func();
   setDate(keypressed);
   setTime(keypressed);
   Alarm(keypressed);
    
if(turbo()==1) {
   
if((ss %10)==0){
   menu_display();
  }
 
}
else if((ss %2)==0) menu_display();
  
  }
}