/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */
int buttonPin=2;
int buttonState;
int pressCount;
int lastButtonState;

int led = 9;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  lastButtonState=buttonState;
  buttonState=digitalRead(buttonPin);
  
  if (lastButtonState==LOW){
    if (buttonState==HIGH){
      pressCount=pressCount+1;
    }    
  }
  
  /*
  Serial.print("pressCount : ");
  Serial.print(pressCount);
  Serial.print("  fadeAmount : ");
  Serial.print(fadeAmount);
  Serial.print("  brightness : ");
  Serial.println(brightness);
  */

  
  //fading up
  if (pressCount==1){

      fadeAmount=5;
    
    if (brightness==255){
      //if the light reaches full brightness, stay in full brightness
    fadeAmount=0;
    }
      
    brightness=brightness+fadeAmount; 
    analogWrite(led,brightness);
    
  }
  
  //fading down
  if (pressCount==2){
   
      fadeAmount=-5;
    
    brightness=brightness+fadeAmount; 
    analogWrite(led,brightness);
    
    if (brightness==0){
      pressCount=0;
    }
     
  }
  
  if (pressCount>2){
      pressCount=1;
    }
  
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}

