#include <LiquidCrystal.h>

//Pins
#define signalPin A5
#define powerPin 7

//LCD Pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(powerPin, OUTPUT); 
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Water Level:");

  digitalWrite(powerPin, LOW);
  delay(1000);
  digitalWrite(powerPin, HIGH); // Every 1 second, the arduino sents an electric current
  int value = analogRead(signalPin); //The sensor reads how much water is on it
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(value);
  
  
  
}
