// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// Traffic Lights - LED Outputs
#define ledRed A0
#define ledYellow A1 
#define ledGreen A2

// DC Motor & Motor Module - L298N
#include <L298N.h>

// Pin definition
const unsigned int IN1 = 7;
const unsigned int IN2 = 8;
const unsigned int EN = 9;

// Servo
#include <Servo.h>
Servo myservo;

// Create one motor instance
L298N motor(EN, IN1, IN2);

// SD Card - Confirm Pin
#define SDpin 10

//Potentiometer
#define pot A3

// Piezo Buzzer
#define piezoPin 8

// Sonar - HC-SR04
#define echoPin 6 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin A4 //attach pin D3 Arduino to pin Trig of HC-SR04

// Line Sensor
#define lineSensorPin 3

// Crash Sensor / Button
#define crashSensor 7

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
  // Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
  logEvent("System Initialisation...");

// Traffic Lights - LED Outputs
pinMode(ledRed, OUTPUT);
pinMode(ledYellow, OUTPUT);
pinMode(ledGreen, OUTPUT);

// DC Motor & Motor Module - L298N
motor.setSpeed(70);

// Servo
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

//Potentiometer
pinMode(pot, INPUT);

// Piezo Buzzer
pinMode(piezoPin,OUTPUT);

// Sonar - HC-SR04
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

// Line Sensor
pinMode(lineSensorPin, OUTPUT);

// Crash Sensor / Button
pinMode(crashSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  doorBell();
  lightSystem();
  lockDoorSecurity();
  PIRSensor();
  doorOpener();

  delay(250);
}
/*
  controlls the doorbell(crash button) activates Piezo
  @params none
  @return none
*/

void doorBell() {
tone(piezoPin, 1000);
delay(100);
noTone(piezoPin);
}

/*
  checks PIR and then using potetionemeter adjusts brightness of LEDS
  @params
  @return
*/
void lightSystem() {
digitalWrite(ledRed, HIGH);
digitalWrite(ledRed, LOW);

int potValue = analogRead(pot);

}
/*
  If sonar detects movment then lock the door and keep it shut
  @params
  @return
*/

void lockDoorSecurity() {
int servoPos= 100
myservo.write(servoPos);

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
long duration = pulseIn(echoPin, HIGH);
// Calculating the distance
int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
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
motor.forward();
delay(1000);
motor.stop();
delay(1000);
motor.backward();
delay(1000);


}
