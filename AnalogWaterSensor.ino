//Pins
#define signalPin A5
#define powerPin 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(powerPin, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(powerPin, LOW);
  delay(1000);
  digitalWrite(powerPin, HIGH); // Every 1 second, the arduino sents an electric current
  int value = analogRead(signalPin); //The sensor reads how much water is on it
  Serial.println(value); //Prints the value

}
