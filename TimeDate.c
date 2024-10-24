#include "exceptions.h"
#include "system_sam3x.h" 
#include "at91sam3x8.h"


void tempRecord();
unsigned int tCounter, ss, mm, hh, month, year;
unsigned int days_in_months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int week =0;
void rotateServo();
void lightPeriod();
unsigned int TimeDelay;
int sig;
int newday=0;
unsigned int day =1;
unsigned int month =1;
int flagdate = 0;
int flagtime=0;
int flaglimit =0;
int flagindate=0;
int flagintime=0;
int flaginlimit=0;
void menu_display();
unsigned int calc =0;

void SysTick_Handler(void){
if (TimeDelay>0)
  TimeDelay--;

if(tCounter>1000){
  tCounter =0;}
  tCounter+=1;

if(tCounter ==  turbo()){
  ss++; 
  lightPeriod();
  tCounter =0;
      
if(ss==60){
   mm++;
   ss=0;
   
if(mm==60){
   hh++;
   mm=0;
   
if(hh==24){
   day++;
   newday=1;
   hh=0;
   
if (day==7){week++;}

if(day==days_in_months[month-1]){
  day=1;
  month++;
  
if(month==13){
  year++;
  month=1;
     }
    }
   }        
  }
 }
}
      
if(hh<16){
  calc = calc +1;
      
if(calc ==1000){ rotateServo(one,second);
  calc =0;
 }
}

else{
  calc = calc +1;
     
if(calc ==1000){ turnServo(0);
  calc =0;
  }
 }
}

void SysConfig(){
  SysTick_Config(SystemCoreClock/1000);

}

void Ddelay(unsigned int t){ 
  TimeDelay=t;

  while(TimeDelay!=0);
}

void Date(int x ){ 
  flagdate=1;
  flagindate=1;
  int thousand = 0;
  int hundred = 0;
  int tenth=0;
  int digit = 0;

while(Value!=0){
  x=func();
} 

while(Value==0){
  x=func();

if(x==0){menu_display();}
}
 
while(Value !=0 ){
  thousand = x*1000;
  year =thousand;
  
if(x == 11){
  thousand=0;
  year =thousand;
} 
  x=func();
}

while(Value==0){
  x=func();

if(x==0){menu_display();}
}

while(Value !=0){
  hundred = x*100;
  year = thousand+hundred;
    
if(x == 11){
  hundred=0;
  year = thousand+hundred;
}
  x=func();
}
 
while(Value==0){
  x=func();
    
if(x==0){menu_display();}
}
  
while(Value!=0){ 
  tenth = x*10;
  year = thousand+hundred+tenth;
    
if(x == 11){
  tenth=0;
  year = thousand+hundred+tenth;
}
  x=func();
}

while(Value==0){
  x=func();
      
if(x==0){menu_display();}
}
  
while(Value!=0){ 
  digit = x;
  year = thousand+hundred+tenth+digit;
    
if(x == 11){
  year = thousand+hundred+tenth+digit;
  digit=0;
}
  x=func();
}
  //year = thousand + hundred + tenth +digit;
   
 while(Value!=0){
    x=func();
}

 while(Value==0){
  x=func();
     
if(x==0){menu_display();}
}

while(Value!=0){
  tenth = x*10;
  month = tenth;
   
if(x == 11){
  tenth=0;
  month = tenth;
}
  x=func();
}

while(Value==0){
  x=func();
      
if(x==0){menu_display();}
}

  while(Value!=0){
   digit = x;
   month = tenth+digit;
    
if(x == 11){
  digit=0;
  month = tenth+digit;
}
  x=func();
}
 //month= tenth+digit;

while(Value!=0){
  x=func();
}

while(Value==0){
  x=func();
    
if(x==0){menu_display();}
}

while(Value!=0){
  tenth = x*10;
  day = tenth;
    
if(x == 11){
  tenth=0;
  day = tenth;
}
   x=func();
}

while(Value==0){
  x=func();
      
if(x==0){menu_display();}
}
  
while(Value!=0){  
  digit = x;
  day = tenth+digit;
    
if(x == 11){
  digit=0;
  day = tenth+digit;
} 
  x=func(); 
}

  flagdate=0;
  flagindate=0;
  menu_display();
}

void Time(int x ){
  flagtime=1;
  flagintime=1;
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
  hh = tenth;
    
if(x == 11){
  tenth=0;
  hh = tenth;
}
  x=func();
}

while(Value==0){
  x=func();
      
if(x==0){menu_display();}
}

while(Value!=0){
  digit = x;
  hh = tenth+digit;
   
if(x == 11){
  digit=0;
  hh = tenth+digit;
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
  mm=tenth;
    
if(x == 11){
  tenth=0;
  mm = tenth;
}   
  x=func();
}

while(Value==0){
  x=func();
   
if(x==0){menu_display();}
}
  
while(Value!=0){
  digit = x;
  mm = tenth+digit;
    
if(x == 11){
  digit=0;
  mm = tenth+digit;
}
  x=func();
}
 
  mm=tenth+digit;
   
while(Value!=0){
  x=func();
}

while(Value==0){
  x=func();
     
if(x==0){menu_display();}
}

while(Value!=0){
  tenth = x*10;
  ss=tenth;
    
if(x == 11){
  tenth=0;
  ss = tenth;
}
  x=func();
}

while(Value==0){
  x=func();
     
if(x==0){menu_display();}
}
  
while(Value!=0){
  digit = x;
  ss = tenth+digit;
    
if(x == 11){
  digit=0;
  ss = tenth+digit;
}
  x=func();
}
flagtime=0;
flagintime=0;
}

void setDate(int x){
if(x == 1 &&flagtime==0 && flaglimit==0 && flagindate==0){
  Date(x);} 
}
    
void setTime(int x){
if(x == 2 && flagdate==0 && flaglimit==0&&flagintime==0){
 Time(x);
 }
}

int turbo(){
if(Value == 12){
  sig=1;}
  
else if(Value == 10){
  sig=0;}

if(sig == 1){
return 1;
}

else if(sig == 0){
return 1000;}
return 1000;
}
