#include<FSRMonitor.h>

const int numSensors = 4; // number of sensor to monitor
const int fsrThreshold = 4500; // the object is present if the reading is greather than 4500mV

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
  sensorsSetup();
}

void loop() {
  displayValues();
  Serial.print("qty: " );
  Serial.println(getQty());
  Serial.println();
  delay(500);
}
