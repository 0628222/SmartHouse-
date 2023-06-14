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
#define crashSensor 4

void setup() {
  Serial.begin(9600);          // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);                   // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
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
  pinMode(piezoPin, OUTPUT);

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
  doorOpener();

  delay(250);
}
/*
  controlls the doorbell(crash button) and then activates Piezo
  @params none
  @return none
*/

void doorBell() {
  int crashSensorValue = digitalRead(crashSensor);
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
  int pirValue = digitalRead(7);
  int ledpin = 13;
  int input = A2;
  int pirState = LOW;
  int val = 0;
  int potentiometerValue = analogRead(A3);
  int brightness = potentiometerValue / 4;
  analogWrite(A0, brightness);
// checks the potetiometer value and then using that and then using that changes the brightness based upon the value of the potetiometer. the potetimeter is read after the PIR state is checked 
  int potValue = analogRead(pot);
  val = digitalRead(A3);
  if (val == HIGH) {
    digitalWrite(ledRed, HIGH);
  }
  if (pirState == LOW) {
    Serial.println("motion Detected!");
    pirState = HIGH;
  } else {
    digitalWrite(13, LOW);
  }
  if (pirState == HIGH) {
    Serial.println("Motion ended");
    pirState = LOW;
  }
}
/*
  If sonar detects movment then close and locks the door using servo
  @params
  @return
*/

void lockDoorSecurity() {
  int servoPos = 100;
  myservo.write(servoPos);

  digitalWrite(A4, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(A4, HIGH);
  delayMicroseconds(10);
  digitalWrite(A4, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(6, HIGH); 
  // Calculating the distance
  int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  for (pos = 0; pos <= 180; +=1 ) { //tells the different positions for the servo to go to
    myservo.write(pos);
    delay(15) //delays for 15 milliseconds and then goes the other way around
  }
  for (pos = 180; pos >= 0; pos -+ 1){ 
    myservo.wrtie(pos);
    delay(15); //delays for 15 milliseconds 
  }
}


/* using line sensor it detects when somebody is near by and then opens the door using a DC motor
  @params
  @return
*/
void doorOpener() {
  int lineSensorValue = digitalRead(3); //checks the value of the line sensor and then opens the door for 100 milliscond and then closes the door 
    
  motor.forward();
  delay(1000);
  motor.stop();
  delay(1000);
  motor.backward();
  delay(1000);


}
