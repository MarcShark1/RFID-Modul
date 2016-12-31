
#include <SPI.h>
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
 
LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=1000;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}


/*
 This method will display the characters for the
 word "Arduino" one after the other on digit 0. 
 */
void writeArduinoOn7Segment() {
  lc.setChar(0,0,'a',false);
  delay(delaytime);
  lc.setRow(0,0,0x05);
  delay(delaytime);
  lc.setChar(0,0,'d',false);
  delay(delaytime);
  lc.setRow(0,0,0x1c);
  delay(delaytime);
  lc.setRow(0,0,B00010000);
  delay(delaytime);
  lc.setRow(0,0,0x15);
  delay(delaytime);
  lc.setRow(0,0,0x1D);
  delay(delaytime);
  lc.clearDisplay(0);
  delay(delaytime);
} 

/*
  This method will scroll all the hexa-decimal
 numbers and letters on the display. You will need at least
 four 7-Segment digits. otherwise it won't really look that good.
 */
void scrollDigits() {
  for(int i=0;i<13;i++) {
    lc.setDigit(0,4,i,false);
    lc.setDigit(0,3,i+1,false);
    lc.setDigit(0,2,i+2,false);
    lc.setDigit(0,1,i+3,false);
    delay(delaytime);
  }
  lc.clearDisplay(0);
  delay(delaytime);
}

void welcomeMsg(){
  lc.setChar(0,7,'H',false);
  lc.setChar(0,6,'E',false);
  lc.setRow(0,5,6);
  delay(3000);
  lc.clearDisplay(1);
  for (int i = 0; i < 50; i++){
    lc.setRow(0,0,i);
    delay(delaytime);
  }
  /*
  delay(delaytime);
  lc.setRow(0,0,0x05);
  delay(delaytime);
  lc.setChar(0,0,'d',false);
  delay(delaytime);
  lc.setRow(0,0,0x1c);
  delay(delaytime);
  lc.setRow(0,0,B00010000);
  delay(delaytime);
  lc.setRow(0,0,0x15);
  delay(delaytime);
  lc.setRow(0,0,0x1D);
  delay(delaytime);
  lc.clearDisplay(0);
  delay(delaytime)
  */
}


void countDown(int negCount, int posCount){
  lc.setRow(0,2,1);
  for( int i=negCount; i +1 > 0 ; i--){
     lc.setDigit(0,0,i,false);
     delay(1000);
  }
  
  lc.setRow(0,2,0);
  for (int i=posCount; i+1 > 0; i--){
     lc.setDigit(0,0,i,false);
     delay(1000);
  }
  
  lc.setRow(0,0,0);
  lc.setChar(0,2,'H',false);
  lc.setChar(0,1,'E',false);
  lc.setRow(0,0,6);
  delay(300);
  lc.clearDisplay(0);
  
}


void loop() {
  countDown(3,5);
}
