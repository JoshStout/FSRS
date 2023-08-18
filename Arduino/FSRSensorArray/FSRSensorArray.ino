/*
  Written for the Arduino to display the number of items resting on Force Sensitive Resistor array.
  Each item is placed directly over a single FSR sensor. The analog pins of the Arduino monitor the junction 
  between the sensor in series with a 10K resistor. A 5V source is supplied to the FSR and the 10K resistor 
  is connected to ground. When the pin measures 4500mV drop across the 10K resistor, the MCU counts as 
  an item present on the sensor. 
*/

#include<FSRMonitor.h>

const int numSensors = 4; // number of sensor to monitor
const int fsrThreshold = 4500; // if the sensor reads greather than 4950mV, then the object is present
const int outputPin = 13; // pin monitored by the next stage

FSRMonitor *sensorsArray[numSensors];

void displayValues() {
  for(int i = 0; i < numSensors; i++){
    Serial.print("sensor ");
    Serial.print(i+1);
    Serial.print(" = ");
    Serial.println(sensorsArray[i]->readPinValue());
  }
}

int getQty() {
  int items = 0;
  for(int i = 0; i < numSensors; i++) {
    if(sensorsArray[i]->readPinValue() > fsrThreshold) items++;
  }
  return items;
}

void sensorsSetup(){
  for(int i = 0; i < numSensors; i++){
    sensorsArray[i] = new FSRMonitor(14 + i);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
  sensorsSetup();
}

void loop() {
  displayValues();
  Serial.print("qty: " );
  Serial.println(getQty());
  Serial.println();
  delay(500);
}
