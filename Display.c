#include "system_sam3x.h" 
#include "at91sam3x8.h" 
#include "at91sam3x8.h"

void delay(unsigned int value) {
    for (int i = 0; i < value; i++) {
        asm("nop");
    }
}

void setDisplayPins() {
    *AT91C_PIOC_PER =  0x3fc;           // enable pioc 2-9
    *AT91C_PIOC_PER =  0xFF000;         // enable pioc 12_19
    
    *AT91C_PIOC_ODR = 0x3fc;            // //set pins as input
    *AT91C_PIOC_OER = 0xFF000;          //set as output
    
    *AT91C_PIOC_SODR = AT91C_PIO_PC12;  //set pins 12 to 1
    *AT91C_PIOC_SODR = AT91C_PIO_PC15;  //set pins 15 to 1
    *AT91C_PIOC_SODR = AT91C_PIO_PC16;  //set pins 16 to 1
    *AT91C_PIOC_SODR = AT91C_PIO_PC17;  //set pins 17 to 1
    *AT91C_PIOD_PER = AT91C_PIO_PD0;    //enable pin 0 piod
    *AT91C_PIOD_OER = AT91C_PIO_PD0;    //set pin 0 as output
}

unsigned char readStatusDisplay() {
unsigned char temp;
    
    *AT91C_PIOC_ODR =0x3fc;             //Set databus pins as input.
       
    *AT91C_PIOC_SODR = AT91C_PIO_PC13;  // Set DIR pin as input and set it to 1.
    *AT91C_PIOC_CODR = AT91C_PIO_PC12;  // Set the ENABLE pin as input and clear
                                        
    *AT91C_PIOC_SODR = AT91C_PIO_PC14;  // Set the C/D pin.
    *AT91C_PIOC_CODR = AT91C_PIO_PC15;  // Clear the CE pin.
    *AT91C_PIOC_CODR = AT91C_PIO_PC16;  // Clear the RD pin.

    delay(10);                          // Delay.

    temp = (*AT91C_PIOC_PDSR >> 2);     // Read databus and save the output to temp

    *AT91C_PIOC_SODR = AT91C_PIO_PC15;  // Set the CE pin.
    *AT91C_PIOC_SODR = AT91C_PIO_PC16;  //set read control (RD).

    *AT91C_PIOC_SODR = AT91C_PIO_PC12;  // disable the OE.
    *AT91C_PIOC_CODR = AT91C_PIO_PC13;  // set dir pin to low.

    return temp;
}

void writeCommandDisplay(unsigned char command) {
    while (~(readStatusDisplay() & (1 << 0)) == (1 << 0)) {
        asm("nop");
    }
    
    *AT91C_PIOC_CODR = 0x3fc;            // Clear databus 2-9.

    *AT91C_PIOC_SODR = (command << 2);  // Set the command in databus
    *AT91C_PIOC_CODR = AT91C_PIO_PC13;  // Set DIR to 0
    *AT91C_PIOC_CODR = AT91C_PIO_PC12;  // Enable Output

    // Enable databus
    *AT91C_PIOC_OER = 0x3fc;
       
    *AT91C_PIOC_SODR = AT91C_PIO_PC14;  // Set C/D to 1
    *AT91C_PIOC_CODR = AT91C_PIO_PC15;  // Clear the CE pin
    *AT91C_PIOC_CODR = AT91C_PIO_PC17;  // Clear WR and set RD to 1

    delay(10);  // Delay

    *AT91C_PIOC_SODR = AT91C_PIO_PC15;  // Chip enable display and write display
    *AT91C_PIOC_SODR = AT91C_PIO_PC17;

    *AT91C_PIOC_SODR = AT91C_PIO_PC12;  // Disable output

    *AT91C_PIOC_ODR = 0x3fc; 
}

void writeDataDisplay(unsigned char data) {
    while (~(readStatusDisplay() & (1 << 0)) == (1 << 0)) {
        asm("nop");
    }

    *AT91C_PIOC_CODR = 0x3fc;                           // Clear databus
    *AT91C_PIOC_SODR = ((unsigned int) data << 2);      // Set command to databus.
    *AT91C_PIOC_CODR = AT91C_PIO_PC13;                  // Set DIR to 0.
    *AT91C_PIOC_CODR = AT91C_PIO_PC12;                  // Enable/clear Output.
    
    *AT91C_PIOC_OER = 0x3fc;                            // Enable the databus
    
    *AT91C_PIOC_CODR = AT91C_PIO_PC14;                  // Set C/D to 1.
    *AT91C_PIOC_CODR = AT91C_PIO_PC15;                  // Clear the CE pin.
    *AT91C_PIOC_CODR = AT91C_PIO_PC17;                  // Clear WR and set RD to 1.

    delay(10);                                           // den pausar programmet i ms.

    *AT91C_PIOC_SODR = AT91C_PIO_PC15;                   // Chip enable display 
    *AT91C_PIOC_SODR = AT91C_PIO_PC17;                   // and write display.
    *AT91C_PIOC_SODR = AT91C_PIO_PC12;                   // Disable output.
    
    *AT91C_PIOC_ODR = 0x3fc;                            // Set databus pins as input
      
}

void initDisplay() {
    setDisplayPins();

    // Reset the display
    *AT91C_PIOD_CODR = ( 1 << 0 ) ;  
    delay(10);
    *AT91C_PIOD_SODR = ( 1 << 0 );

    writeDataDisplay(0x00);
    writeDataDisplay(0x00);
    writeCommandDisplay(0x40);        // Set text home address.
    writeDataDisplay(0x00);
    writeDataDisplay(0x40);
    writeCommandDisplay(0x42);        // Set graphic home address.
    writeDataDisplay(0x1e);
    writeDataDisplay(0x00);
    writeCommandDisplay(0x41);        // Set text area
    writeDataDisplay(0x1e);
    writeDataDisplay(0x00);
    writeCommandDisplay(0x43);        // Set graphic area
    writeCommandDisplay(0x80);        // Set text mode
    writeCommandDisplay(0x94);        // Text on, graphics off
}


void clearDisplay()
{
  writeDataDisplay(0x00);
  writeDataDisplay(0x00);
  writeCommandDisplay(0x24);                   
  writeDataDisplay(0x00);
  for (int i = 0; i < 16 * 30; i++) 
  {
    writeCommandDisplay(0xC0); // Increment ADP & Data Write 
  }
}
 



void printDisplay(unsigned char value) {
  
    switch (value) {
        case 11:
            value = 0x10;     // Show 0 on the display
            break;
        case 10:
            value = 0x0A;     // Show * on the display
            break;
        case 12:
            value = 0x03;     // Show # on the display
            break;
        default:
            value = ((unsigned char)0x10 + value);
            break;
    }
  writeDataDisplay(value);          // Send data
    writeCommandDisplay(0xC0);        // Send command
      
}
    void printDisplay2(unsigned char value){
    
value = ((unsigned char)0x10 + value);

 writeDataDisplay(value);          // Send data
    writeCommandDisplay(0xC0);        // Send command
}

    void printDisplay1(unsigned char value){


 writeDataDisplay(value);          // Send data
    writeCommandDisplay(0xC0);        // Send command
}
void print_string(char *ch, unsigned int row, unsigned int coloumn)//
{
  
  unsigned int add = coloumn * 30 + row;// 
  writeDataDisplay(add & 0xFF);
  writeDataDisplay(add >> 8);
  writeCommandDisplay(0x24);
  int i = 0;
  while(ch[i]!='~'){
    writeDataDisplay(ch[i]-32); // convert charecter from ascii to display table
    writeCommandDisplay(0xC0); 
    
    
    i++;
  }
}