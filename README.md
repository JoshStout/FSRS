  Written for the Arduino to display the number of items resting on a Force Sensitive Resistor array.
  Each item is placed directly over a single FSR sensor. The analog pins of the Arduino monitor the junction 
  between the sensor in series with a 10K resistor. A 5V source is supplied to the FSR and the 10K resistor 
  is connected to ground. When the pin measures 4500mV drop across the 10K resistor, the MCU counts as 
  an item present on the sensor. 
