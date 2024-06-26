#include <SoftwareSerial.h>

const int enA = 5;
const int in1 = 2; 
const int in2 = 4;  
const int enB = 6; 
const int in3 = 7;  
const int in4 = 8; 

// led pins
const int l1 = 10;
const int l2 = 11;
const int l3 = 12;
const int l4 = 13;

SoftwareSerial mySerial(0, 1); // RX, Tx

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  digitalWrite(l1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,HIGH);
  
  if (mySerial.available() > 0) {
    
     Serial.println(mySerial.read());

     int command = mySerial.read();  // Read the command character
     Serial.println(command);
     
     executeCommand(command);
     
  }
  
}

void executeCommand(int command) {

  // Serial.println(command);

  if (command == 70 || command == 102){ // F or f
    forward();
  }
  else if(command == 66 || command == 98){ // B or b
    backward();
  }
  else if(command == 82 || command == 114){ // R or r
    right();
  }
  else if(command == 76 || command == 108){ // L or l
    left();
  }
  else if(command == 83 || command == 115){ // S or s
    stop();
  }
  
  Serial.flush();
}
void forward() {
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 200);
  digitalWrite(enB, 200);
}

void backward() {
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 200);
  digitalWrite(enB, 200);
}

void left() {
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 200);
  digitalWrite(enB, 200);
}

void right() {
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, 200);
  digitalWrite(enB, 200);
}

void stop() {
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enA, 0);
  digitalWrite(enB, 0);
}