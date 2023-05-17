// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1)
      ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  doorbell(); 



  delay(250);
}
/*
 controlls the doorbell(crash button) activates Piezo 
 @params none
 @return none 
 */

void doorBell() {
   
}

/*
 checks PIR and then using potetionemeter adjusts brightness of LEDS 
 @params
 @return
 */
void lightSystem() {
  
}
/*
 If sonar detects movment then lock the door and keep it shut 
 @params
 @return
 */

void lockDoorSecurity() {
}

/* checks to see if infared is infact there then 
  @params
  @return
 */
void PIRSensor() {

}


/* using line sensor it detects when somebody is near by 
 @params
 @return
 */
void doorOpener() {
} 
