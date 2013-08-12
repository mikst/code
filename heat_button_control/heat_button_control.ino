/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
---------- 
modified for summer camp heat controlling workshop:
instead of LED, it is connected to heat element on pin 10 and 11
as you press the button it triggers a simple sequence 
2013 July eTextile summercamp
www.eTextile-summercamp.org
---------
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int heatPin1 =  10;      // the number of the LED pin
const int heatPin2 =  11;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(heatPin1, OUTPUT);      
  pinMode(heatPin2, OUTPUT);    
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {     
    // start the heat sequence. as it is using delay, while the sequence is going, it does not detect the button  
    digitalWrite(heatPin1, HIGH);
    delay(3000); // you can change the timing as you like, 1sec=1000
    digitalWrite(heatPin1, LOW);
    digitalWrite(heatPin2, HIGH);
    delay(3000); // you can change the timing as you like, 1sec=1000
    digitalWrite(heatPin2, LOW);
    
  } 
  else {
    // turn both the heating off
    digitalWrite(heatPin1, LOW);
    digitalWrite(heatPin2, LOW);
  }
}
