#include "exceptions.h"
#include "system_sam3x.h" 
#include "at91sam3x8.h"


double temp=0;
int counter1;
int flag=0;
double ces;


void light(double x,double y){                  //print light
  int x1 =x;
  int y1=y;
  int z;
    
if (x<1){ 
  printDisplay2(x1);
  printDisplay1(0xE);
  x1 = x * 10;
  printDisplay2(x1);
  x1 = x * 100;
  z = x1%10;
  printDisplay2(z );
} 

else { 
  printDisplay2(x);
  printDisplay1(0xE);
  x1 = x * 10;
  z = x1%10;
  printDisplay2(z );
}
 
  printDisplay2(0xF0);
  int b;
  
if (y<1){ 
  printDisplay2(y1);
  printDisplay1(0xE);
  y1 = y * 10;
  printDisplay2(y1);
  y1 = y* 100;
  b = y1%10;
  printDisplay2(b );
 } 

else { 
  printDisplay2(y);
  printDisplay1(0xE);
  y1 = y * 10;
  b = y1%10;
  printDisplay2(b );   
}
   
  Ddelay(30);   // Setup the display
  writeDataDisplay(0x00);
  writeDataDisplay(0x00);
  writeCommandDisplay(0x24);                   // Set the address pointer
  clearDisplay();
  writeDataDisplay(0x00);                      
  writeDataDisplay(0x00);                      
  writeCommandDisplay(0x24); 
}


int rotate(int value) {
  
switch (value) {
  case 12:
     value =120;
  return value;
  case 11:
     value = 110;     // Show 0 on the display
  return value;
  case 10:
     value = 100;     // Show 0 on the display
  return value;
  case 9:
     value = 90;     // Show 0 on the display
  return value;
  case 8:
     value = 80;     // Show 0 on the display
  return value;
  case 7:
     value = 70;     // Show 0 on the display
  return value;
  case 6:
     value = 60;     // Show 0 on the display
  return value;
  case 5:
     value = 50;     // Show 0 on the display
  return value;
  case 4:
     value = 40;     // Show 0 on the display
  return value;
  case 3:
     value = 30;     // Show 0 on the display
  return value;
  case 2:
     value = 20;     // Show 0 on the display
  return value;
  case 1:
     value = 10;     // Show 0 on the display
  return value;
  default:
     value = 0;
  return value;
 }
}

void number(int x){//print temp
  int tenth;
  int digit;
  
if(x>9){
  tenth = x/10;
  printDisplay(tenth);
  digit = x%10 ;
  printDisplay(digit);
  printDisplay1(0x23);
  //delay(2000000);
   
// Setup the display
  writeDataDisplay(0x00);
  writeDataDisplay(0x00);
  writeCommandDisplay(0x24);                   // Set the address pointer
  clearDisplay();  
  writeDataDisplay(0x00);                      
  writeDataDisplay(0x00);                      
  writeCommandDisplay(0x24); 
}

else{ printDisplay(x); printDisplay1(0x23);}

}

int read_Temp(){
  
if(!flag){
  //Ddelay(10);
  measure();
  counter1++; 
  flag=1; 
}

else if(readytoRead){
  counter1--;
  temp=readtemp();
  flag=0;
  readytoRead=0;
  //Ddelay(10);
  ces = temp;
  // number(ces);
}
  int temp;
}