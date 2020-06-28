/*
 * Project GarageDoorControlSoftware
 * Description: control my garage door
 * Author: Matthew Glazer
 * Date: 6/27/2020
 */

#include <Wire.h>
#include "SparkFun_VL53L1X.h"
#include "application.h"
#include "dotstar.h"

#define NUMPIXELS 30

#define DATAPIN   D12
#define CLOCKPIN  D13
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN);

SFEVL53L1X distanceSensor;
//Uncomment the following line to use the optional shutdown and interrupt pins.
//SFEVL53L1X distanceSensor(Wire, SHUTDOWN_PIN, INTERRUPT_PIN);

#define LEDPOWERPIN  D5
#define RELAY_CTRL   D8
#define REED_SW1     D7
#define REED_SW2     D6
#define LED1         A3
#define LED2         A4
#define GARAGEDOORSTATE 0

// setup() runs once, when the device is first turned on.
void setup() 
{
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP

  pinMode(RELAY_CTRL, OUTPUT);
  pinMode(REED_SW1, INPUT);
  pinMode(REED_SW2, INPUT);
  pinMode(LEDPOWERPIN, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  digitalWrite(RELAY_CTRL, LOW);
  digitalWrite(LEDPOWERPIN, LOW);
  digitalWrite(LED1, HIGH);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() 
{
  // The core of your code will likely live here.
  LEDRangeFind(GARAGEDOORSTATE);
}





void LEDRangeFind(GARAGEDOORSTATE)
{
  if (GARAGEDOORSTATE = CLOSED)
  {
    digitalWrite(LEDPOWERPIN, LOW);
  }
  else if (GARAGEDOORSTATE = OPEN)
  {
    digitalWrite(LEDPOWERPIN, HIGH);
  }

  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  while (!distanceSensor.checkForDataReady())
  {
    delay(1);
  }
  int distance = distanceSensor.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();

  float distanceInches = distance * 0.0393701;
}