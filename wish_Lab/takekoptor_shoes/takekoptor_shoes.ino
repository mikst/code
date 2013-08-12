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
  pinMode(2,INPUT);
  digitalWrite(2,HIGH);

  // set the digital 0,1 pin (PWM) to output
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  digitalWrite(1,LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(1);
  if (sensorValue < 80){
    digitalWrite(0,HIGH);
    onTimer++;
    if (onTimer>300){
      analogWrite (1, 0);
      mySerial.print("stopped ");
      mySerial.println();
    }
    
    
    if (!stepped){
      stepped= true;
      int long temp=millis();
      interval=temp-lastStep;
      
       mySerial.print("last step:  ");
      mySerial.print((lastStep), DEC);
      mySerial.println(); 
      mySerial.print("temp:  ");
      mySerial.print((temp), DEC);
      mySerial.println(); 
      
      lastStep=millis();  

      // print the interval of the steps
      mySerial.print("Step Intercvals are:  ");
      mySerial.print((interval), DEC);
      mySerial.println(); 

      interval=map(interval, 200, 2000, 0, 255);
      interval=constrain(interval,0,255);
      interval=abs(255-interval);
      analogWrite (1, interval);
      
      // print calculated value
//      mySerial.print("T ");
//      mySerial.print((interval), DEC);
//      mySerial.println(); 
      
      offTimer=0;
    }
  }
  else {
    digitalWrite(0,LOW);
    offTimer++;
    onTimer=0;
    if (offTimer>20){
    stepped= false;
    }
    if (offTimer>300){
    analogWrite (1, 0);
    }
  }
  
 delay(2);

}

