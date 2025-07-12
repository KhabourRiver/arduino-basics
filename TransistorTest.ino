/* 
  Transistor basics -- Yousif Al Khaboori

    Components used:
    * Arduino UNO
    * Analog Water Sensor
    * NPN Transistor PN2222
    * 1k ohm resistor
    * LED
    * 200 ohm resistor

    This is a modified version of my AnalogWaterSensor file. I added a transistor that turns on an LED. I didn't know how to test the transistor's base threshold (I assume it's 0.7V) since I 
    lack some equipment like a multimeter. I tried using the water sensor's signal pin since it outputs a variable voltage from 0V to 1V (Not sure why it only goes to 1V), but the transistor wouldn't budge for some reason.
    This program is basically me coping with that fact by finding the voltage from the water sensor myself, and when the voltage reaches 0.7, the Arduino sends a signal to the base of the transistor to turn on. 

    TL;DR Transistorception
    
    
    */


//Pins
#define signalPin A5
#define powerPin 7
#define basePin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(powerPin, OUTPUT); 
  pinMode(basePin, OUTPUT);
  digitalWrite(basePin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Every 1 second, the arduino sents an electric current
  digitalWrite(powerPin, LOW);
  delay(1000);
  digitalWrite(powerPin, HIGH); 

  //The sensor reads how much water is on it
  int value = analogRead(signalPin); 
  double voltage = value * (5.0 / 1023.0); //converts the analog value into voltage (the Arduino UNO uses a 10-bit ADC so it goes from 0-1023)
  Serial.println(voltage); //Testing purposes

  //The coping method
  if(voltage >= 0.70){ 
    digitalWrite(basePin, HIGH);
  }
  else{
      digitalWrite(basePin, LOW);

  }


}