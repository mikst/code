/*
  Button Blink
 
 Blink light emitting diode(LED) connected to digital  
 pin 9, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 9 to ground 
 * pushbutton attached to pin 2 from Ground
 
 
------
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 This example code is in the public domain.
--------

 modified by KOBAKANT for the WishLab workshop
 http://www.kobakant.at/DIY/?p=4967
 
*/


// set pin numbers:
int buttonPin = 2;     // the number of the pushbutton pin
int ledPin =  9;      // the number of the LED pin

// variables:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input and set the pull up resister:
  pinMode(buttonPin, INPUT_PULLUP);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (buttonState == LOW) {     
    // blink the LED:    
    digitalWrite(ledPin, HIGH);  
    delay(1000);
    digitalWrite(ledPin, LOW); 
    delay(1000);
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}
