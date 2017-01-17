
#include <SPI.h>
#include <MFRC522.h>
#include "LedControl.h"


#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          8         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

// pin 12 is connected to the DataIn 
// pin 11 is connected to the CLK 
// pin 10 is connected to LOAD 
// We have only a single MAX72XX.
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
  // put your setup code here, to run once:
  Serial.begin(9600);   // Initialize serial communications with the PC
  Serial1.begin(9600);
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Test Running...."));
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

void dumpUID(){
  // Dump UID to Serial
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();

  // Dump UID to Serial1
  Serial1.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial1.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial1.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial1.println();
}


void loop() {
  // Look for new cards
  // Look for new cards, and select one if present
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }

  Serial.println(F("Detected a card!"));

  dumpUID();

  countDown(2,5);

  delay(1000);

}
