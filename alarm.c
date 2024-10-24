#include "exceptions.h"
#include "system_sam3x.h" 
#include "at91sam3x8.h"

unsigned int uppLimit = 30;  
unsigned int lowLimit = 10;
unsigned int alarm = 0;
unsigned int larm_on =0;

void menu_display();

void alarmLimit(){ // alarm configuration
if(temp>=uppLimit){
  alarm = 1;
} 

else if(temp<=lowLimit){
  alarm = 1;
}

else{
  alarm = 0;
 }
}

void setLimit(int x){// setting lower limit of the alarm 
  flaglimit=1;
  flaginlimit =1;
  int tenth=0;
  int digit = 0;
   
while(Value!=0){
  x=func();
}
 
while(Value==0){
  x=func();
     
if(x==0){menu_display();}
}

while(Value!=0){
  tenth = x*10;
  uppLimit = tenth;
   
if(x == 11){
  tenth=0;
  uppLimit = tenth;
}  
  x=func();
}

while(Value==0){
  x=func();
  
if(x==0){menu_display();}
}

while(Value!=0){
  digit = x;
  uppLimit = tenth+digit;
   
if(x == 11){
  digit=0;
  uppLimit = tenth+digit;
}
  x=func();
}

while(Value!=0){
  x=func();
}
 
while(Value==0){
  x=func();
     
if(x==0){menu_display();}
}
 
while(Value!=0){
  tenth = x*10;
  lowLimit=tenth;
    
if(x == 11){
  tenth=0;
  lowLimit=tenth;
}  
  x=func();
}

while(Value==0){
  x=func();
     
if(x==0){menu_display();}
}
 
while(Value!=0){
  digit = x;
  lowLimit = tenth + digit;
    
if(x == 11){
  digit=0;
  lowLimit = tenth + digit;
}  
  x=func();
}

  lowLimit = tenth + digit;
  flaglimit=0;
  flaginlimit=0;
}

void Alarm(int x){ // alarm setting in keypad
if(x == 3 && flagdate==0 && flagtime==0&&flaginlimit==0){
  setLimit(x);}
}
void alarmsignal(){ // signal condition
if(Value==11){*AT91C_PIOD_CODR = (1<<1);
  alarm =0;
  larm_on =1;
}

if(Value==5){larm_on=0;}
if(alarm ==1 && larm_on==0){
  *AT91C_PIOD_SODR = (1<<1);
}

else {
  *AT91C_PIOD_CODR = (1<<1);}
}