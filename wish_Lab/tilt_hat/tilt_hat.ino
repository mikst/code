#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4); // RX, TX

int sensorValue;
boolean stepped =false;
unsigned long lastStep=0;
long interval=0;

int offTimer;
int onTimer;

// the setup routine runs once when you press reset:
void setup() {

  mySerial.begin(9600);
  mySerial.println("Hello, world?");

  //set pull up
  pinMode(3,INPUT);
  digitalWrite(3,HIGH);

  // set the digital 0,1 pin (PWM) to output
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(3);
  int color =map(sensorValue,0,340,0,5);
  
  switch(color){
    case 0:
    digitalWrite(2,HIGH);
    analogWrite(0,50);
    analogWrite(1,250);
    break;
    
    case 1:
    digitalWrite(2,HIGH);
    analogWrite(0,250);
    analogWrite(1,50);
    break;
    
    case 2:
    digitalWrite(2,HIGH);
     analogWrite(0,50);
    analogWrite(1,50);
    break;
    
    case 3:
    digitalWrite(2,LOW);
     analogWrite(0,50);
    analogWrite(1,250);
    break;
    
    case 4:
    digitalWrite(2,LOW);
    analogWrite(0,250);
    analogWrite(1,50);
    break;
    
    case 5:
    digitalWrite(2,LOW);
    analogWrite(0,50);
    analogWrite(1,50);
    break;
  }
  
  
  
 delay(2);

}

