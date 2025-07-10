//Digital pins
int trig = 7;
int echo = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //The trigger pin sends the ultrasonic wave
  pinMode(trig, OUTPUT);

  //The echo pin detects the wave when it comes back
  pinMode(echo, INPUT);

}

void loop() {

  //Sends a ultrasonic wave
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

 
  //The component being used measures the time it takes for the ultrasonic to come back in microseconds, if detected echo will change from 0 to 1
  //The pulseIn function measures the time it took the echo to change from 0 to 1 in microseconds
  double time = pulseIn(echo, HIGH);
  double speed = 0.0343; //cm per microsecond
  //Distance = speed * time
  double distance = (speed * time) / 2.0; //Divide by 2 because it measures the time it takes the wave to hit the object and come back
  
  if(time != 0){
  //The distance I've noticed is accurate within +/- 1 cm
  Serial.println(distance);
  }
  

}
