#include "system_sam3x.h" 
#include "at91sam3x8.h" 


int func(void);
//int value;
int row ;
int col;
int Value = 0;


  

void regSett(){
 
    //Activate as input or output
  *AT91C_PMC_PCER= (1<<14);
  *AT91C_PMC_PCER = (1<<13);
   *AT91C_PIOC_ODR =(1<<2);
   *AT91C_PIOC_ODR =(1<<3);
   *AT91C_PIOC_ODR =(1<<4);
   *AT91C_PIOC_ODR =(1<<5);
    *AT91C_PIOC_OER = (1<<7);
   *AT91C_PIOC_OER = (1<<8);
   *AT91C_PIOC_OER = (1<<9);
  
   
   //pin enable register
    *AT91C_PIOC_PER = (1<<7);
    *AT91C_PIOC_PER = (1<<8);
    *AT91C_PIOC_PER = (1<<9);
    *AT91C_PIOC_PER=(1<<2);
    *AT91C_PIOC_PER=(1<<3);
    *AT91C_PIOC_PER=(1<<4);
    *AT91C_PIOC_PER=(1<<5);
    *AT91C_PIOD_PER=(1<<2);
    *AT91C_PIOD_OER =(1<<2);
      
  // Disable inner resistans
   *AT91C_PIOC_PPUDR=(1<<7);
   *AT91C_PIOC_PPUDR=(1<<8);
   *AT91C_PIOC_PPUDR=(1<<9);
   *AT91C_PIOC_PPUDR=(1<<2);
  *AT91C_PIOC_PPUDR=(1<<3);
  *AT91C_PIOC_PPUDR=(1<<4);
  *AT91C_PIOC_PPUDR=(1<<5);
  


}

int func(void){
 
 *AT91C_PIOD_CODR = (1<<2);                 //Clear OE KEY BUS (Active Low) 
//*AT91C_PIOD_CODR = (1<<3); 
*AT91C_PIOD_CODR = (1<<4); 
*AT91C_PIOD_CODR = (1<<5); 

 *AT91C_PIOC_SODR =(1<<7);       //Set all Column pin as high
       *AT91C_PIOC_SODR =(1<<8);
         *AT91C_PIOC_SODR = (1<<9);

  *AT91C_PIOC_OER = (1<<7); // make column pin as output 3 lines. 
   *AT91C_PIOC_OER = (1<<8);
   *AT91C_PIOC_OER = (1<<9);
   for(int i =0;i<3;i++){
     if(i==0){
       col=0;
 
       
    
    *AT91C_PIOC_SODR=(1<<7);
        *AT91C_PIOC_SODR=(1<<8);
         *AT91C_PIOC_CODR=(1<<9);

     } else if(i==1){
       
        *AT91C_PIOC_SODR=(1<<9);
        *AT91C_PIOC_SODR=(1<<7);

       col=1;
    *AT91C_PIOC_CODR=(1<<8);
    
   

     } else if(i==2){
       col=2;
    
   *AT91C_PIOC_CODR=(1<<7);
        *AT91C_PIOC_SODR=(1<<8);
        *AT91C_PIOC_SODR=(1<<9);

     }
   
     for(int z=0; z<4; z++){
       if(((*AT91C_PIOC_PDSR & (1<<2))!=(1<<2))){
         row=0;
       Value = row*3+col+1;
      return Value;
       }else if((*AT91C_PIOC_PDSR & (1<<3))!=(1<<3)){
         row=1;
       Value = row*3+col+1;
      return Value;
       } else if((*AT91C_PIOC_PDSR & (1<<4))!=(1<<4)){
         row=2;
       Value = row*3+col+1;
      return Value;
       }else if((*AT91C_PIOC_PDSR & (1<<5))!=(1<<5)){
         row=3;
       Value = row*3+col+1;
      return Value;
       }
     }
   }
   return Value = 0;
}