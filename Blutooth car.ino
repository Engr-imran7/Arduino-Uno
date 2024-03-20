int pin1=2;
int pin2=4;
int pin3=7;
int pin4=8;
int pwmpin1=3;
int pwmpin2=9;

int led1=10;
int led2=11;
int led3=12;
int led4=13;


void setup()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pwmpin1, OUTPUT);
  pinMode(pwmpin2, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

}
void forward()
{
  analogWrite(pwmpin1, 200);
  analogWrite(pwmpin2, 200);

  digitalWrite(pin2, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin1,LOW);
  digitalWrite(pin3,LOW);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);

}

void backward()
{
  analogWrite(pwmpin1, 100);
  analogWrite(pwmpin2, 100);

  digitalWrite(pin2, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin1,HIGH);
  digitalWrite(pin3,HIGH);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
}

void stop()
{
  digitalWrite(pin2, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin1,LOW);
  digitalWrite(pin3,LOW);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
}
void loop()
{
  forward();
  delay(3000);
  stop();
  delay(3000);
  backward();
  delay(3000);
  stop();
  delay(3000);
}