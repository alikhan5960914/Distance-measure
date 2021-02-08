const int pinRedLED=11;
const int pinTrigger=6;
const int pinEcho=5;

int distanceThreshold = 0;
int cmDistance = 0;
int inches = 0;

void setup()
{
  pinMode(pinRedLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  pinMode(pinTrigger, OUTPUT);  // Clear the trigger
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  pinMode(pinEcho,INPUT);
  
  cmDistance=0.01723*pulseIn(pinEcho, HIGH);
  distanceThreshold = 350;
  
  Serial.print("\nDistance: ");
  Serial.print(cmDistance);
  Serial.print(" cm");
  
  if(cmDistance<30){
    digitalWrite(pinRedLED, HIGH);
  }
  else{
    digitalWrite(pinRedLED, LOW);
  }
  
  delay(1000);
}
