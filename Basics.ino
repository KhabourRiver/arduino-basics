//Learning the basics of arduino code and using the actual arduino and breadboard

//Global Variables
bool repeat = true;
int LEDR = 2; // Digital pin 2
int LEDB = 3; // Digital pin 3
int LEDG = 7; //Digital pin 7

//Initialized the LEDs to their respective digital pins 
void setup() {
  // put your setup code here, to run once:
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
  

}


void loop() {
  // put your main code here, to run repeatedly:
  //Control statement
  if(repeat){

  //Turns on the red LED (R)
  digitalWrite(LEDR, HIGH);
  delay(100);
  //Turns off R and turns B on
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDB, HIGH);
  delay(100);
  //Turns B off and G on
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDG, HIGH);
  delay(100);
  //Turns G off
  digitalWrite(LEDG, LOW);


  //Stops the loop
  delay(1000);
  repeat = false;
  }
}
