#include "at91sam3x8.h"
#include "system_sam3x.h"
#include "exceptions.h"

unsigned int displayNumber = 1;
char tmp[100];
unsigned int id =0;


char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void menu_display(){
  
if(Value!=0){
  clearDisplay(); 
  delay(5000000); 
}
  
if(Value==4){
  displayNumber=1;
}

if(Value==6){
  displayNumber=2;
  
if (Value==5){
  displayNumber=1;}
}

if(Value==7){
  displayNumber=3;
  }

if(Value==8){ 
  displayNumber=4;
}
  
if(flagtime==1 || flagdate==1||flaglimit==1){
  
if (flagdate==1){
  print_string("Date Is Being Changed~", 0, 10);
  delay(50000);
  print_string("                        ~", 0, 10);
}
   
else if(flagtime==1){
  print_string("Time Is Being Changed~", 0, 10);
  delay(50000);
  print_string("                        ~", 0, 10);
}

else {print_string(" Limits Are Being Changed~", 0, 10);
  delay(50000);
  print_string("                        ~", 0, 10);
 }
}
   
  sprintf(tmp,"%02d/%02d/%04d | %02d:%02d:%02d~",day,month,year,hh,mm,ss); // an array of characters
  print_string(tmp, 0, 0);
  print_string("4.Menu~", 20, 15);
       
if(displayNumber==1){ 
  print_string("View           Change~", 0, 3);
  print_string("6.LightHours    1.Date~", 0, 5);
  print_string("7.TempNow       2.Time~", 0, 6);
  print_string("8.TempLog       3.Upp/LowLimit~", 0, 7);
  print_string("0.5 Turn off/on alarm~", 5, 8);
     
  sprintf(tmp,"Upper Limit=%d, Lower Limit=%d~", uppLimit, lowLimit);
  print_string(tmp, 0,13);
       
if(turbo()==1) {
  print_string(" Test  Mode~", 0, 15);
}

else {
  print_string("Normal Mode~", 0, 15);
 }
} 

else if(displayNumber==2){
  
if(flagtime==1 || flagdate==1||flaglimit==1){
  
if (flagdate==1){
  
  print_string("Date Is Being Changed~", 0, 10);
}

else if(flagtime==1){
  print_string("Time Is Being Changed~", 0, 10);
}
    
else if (flaglimit==1) {print_string(" Limits Are Being Changed~", 0, 10);}
}
  
  print_string("Lighthours~",1,2);
  sprintf(tmp,"Sunlight:%dhr,%dminutes~",lightsecond/3600,(lightsecond%3600)/60);
  print_string(tmp, 1, 3);
  sprintf(tmp,"LEDlight:%dhr,%dminutes~",LEDlight/3600,(LEDlight%3600)/60);
  print_string(tmp, 1,4 );
  sprintf(tmp,"Darkness:%dhr,%dminutes~",darklight/3600,(darklight%3600)/60);
  print_string(tmp, 1, 5);

if(turbo()==1) {
  print_string(" Test  Mode~", 0, 15);
}

else {
  print_string("Normal Mode~", 0, 15);
}

if(hh<16){
  sprintf(tmp,"Position:%d~",angle);
  print_string(tmp,0,12);
}

else{sprintf(tmp,"Position:%d~",0);
  print_string(tmp,0,12);
 }
}

else if(displayNumber==3){
         
if(turbo()==1) {
  print_string(" Test  Mode~", 0, 15);
}
    
else {
  print_string("Normal Mode~", 0, 15);
}
    
  print_string("Today Temp:~",0,2);
  sprintf(tmp,"Day: %d :%s The %dth ~" ,dayMax+1,days[dayMax],day);
  print_string(tmp,0,3);
  sprintf(tmp,"Max Temperature=%d~",arrMax[dayMax]);
  print_string(tmp,0,4);
  sprintf(tmp,"Captured Hour=%d ,Minute= %d~",date[dayMax]/60,date[dayMax]%60);
  print_string(tmp,0,5);
  sprintf(tmp,"Captured Hour=%d ,Minute= %d~",date1[dayMax]/60,date1[dayMax]%60);
  print_string(tmp,0,7);
  sprintf(tmp,"Min Temperature=%d~",arrMin[dayMax]);
  print_string(tmp,0,6); 
  sprintf(tmp,"Average Temperature=%d~",arrAvg[dayMax]);
  print_string(tmp,0,8); 
  sprintf(tmp,"Upper Limit=%d, Lower Limit=%d~",uppLimit,lowLimit);
  print_string(tmp,0,10);
}

else if(displayNumber==4){
  print_string("PRESS 0 Next Day~", 7, 3);
  
if(turbo()==1){
  
if(Value==11){
  Ddelay(1000);
  id++;
  id = id %7;
 }
}

else{
if(Value==11){
  Ddelay(200);
  id++;
  id = id %7;
 }
}
     
if(turbo()==1) {
  print_string(" Test  Mode~", 0, 15);
}

else {
  print_string("Normal Mode~", 0, 15);
}

  print_string("Temp:~ ",0,2);
  sprintf(tmp,"%s~",days[id]);
  print_string(tmp,6,2);
  sprintf(tmp,"Day %d~" ,id+1);
  print_string(tmp,0,3);
  sprintf(tmp,"Max Temperature=%d~",arrMax[id]);
  print_string(tmp,0,4); 
  sprintf(tmp,"Captured Hour=%d ,Minute= %d~",date[id]/60,date[id]%60);
  print_string(tmp,0,5);   
  sprintf(tmp,"Captured Hour=%d ,Minute= %d~",date1[id]/60,date1[id]%60);
  print_string(tmp,0,7);
  sprintf(tmp,"Min Temperature=%d~",arrMin[id]);
  print_string(tmp,0,6);  
  sprintf(tmp,"Average Temperature=%d~",arrAvg[id]);
  print_string(tmp,0,8); 
  sprintf(tmp,"Upper Limit=%d, Lower Limit=%d~",uppLimit,lowLimit);
  print_string(tmp,0,13);
 }
}