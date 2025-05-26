//LEDS
int LEDR = 2; // Digital pin 2
int LEDB = 3; // Digital pin 3
int LEDG = 7; // Digital pin 7

// Joystick module
int sw = 11; //Digital pin 11

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(sw, INPUT_PULLUP); //Internal pull-up
  Serial.begin(9600); 

}

void loop() {

  int x = analogRead(A2);
  int y = analogRead(A4);
  int button = digitalRead(sw);
  // put your main code here, to run repeatedly:

// If joystick is pulled to the right
  if(x == 0){
    digitalWrite(LEDR, HIGH);
  } else{
    digitalWrite(LEDR, LOW);
  }

  //If joystick is pulled to the left
  if(x == 1023){
    digitalWrite(LEDB, HIGH);
  }
  else{
    digitalWrite(LEDB, LOW);
  }

  //If joystick is pressed
  if(button == LOW){
    digitalWrite(LEDG, HIGH);
  }
  else{
    digitalWrite(LEDG, LOW);
  }
  
  

}
