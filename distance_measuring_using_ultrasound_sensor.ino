
#include<Mouse.h>

int led =13;
const int trigpin =8;

const int echopin =5;

long duration;
int distance ;

void setup()
{
  pinMode(trigpin, OUTPUT);

  pinMode(echopin, INPUT);

  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin ,HIGH);
  distance =duration*0.034/2;
if (distance <=50)
{
  digitalWrite(led, HIGH);
  delay(500);
}
else 
{
  digitalWrite(led, LOW);
}
  Serial.print("          ");
  Serial.println(distance);

}



