// simple analog input reader.
// it reads 0-5 analog inputs and send out to serial communication
// implmented for wearable workshop by KOBAKANT
// www.KOBAKANT.at

  
int led = 13;    //LED, it lights up when it is ready 
int count = 0;    // counter
int value0 = 0;  //analog input 0 value goes in here
int value1 = 0;  //analog input 1 value goes in here
int value2 = 0;
int value3 = 0;



void setup(){  

//teke off the following comment out to enable the internal pull up resistor.
//for more detail about pull up poins, read here http://www.arduino.cc/en/Tutorial/AnalogInputPins
/*  
// declaration of pin modes. do not forget to comment these out when you do not use internal pull ups.
  pinMode(14, OUTPUT); 
  pinMode(15, OUTPUT); 
  pinMode(16, OUTPUT); 
  pinMode(17, OUTPUT); 
  pinMode(18, OUTPUT); 
  pinMode(19, OUTPUT); 
  
// declaration of pin states
  digitalWrite(14, HIGH);  // set pullup on analog pin 0 
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
*/

// pull up for A0 and A3


  pinMode(led, OUTPUT);  // define led pin as output
  digitalWrite(led, HIGH); // turn the led pin on when setup is ready
  

 
 //sets serial communication baudrate
  //Serial.begin(115200); 
  Serial.begin(9600); 
} 


void loop () { 
  
 if (Serial.available() > 0) //it sends out data only if serial communication is available.
  {  
    value0 = analogRead(A0);
    value1 = analogRead(A3);
    value2 = analogRead(A1);
    value3 = analogRead(A2);


//sending analog input value to computer------------------------------------------------------------------

     Serial.write(1); // sensor input number indicator binary
    Serial.print(value0,DEC); // sensor input data
    Serial.write(20); //breaker
    
   Serial.write(2); 
    Serial.print(value1,DEC); 
    Serial.write(20); 
    
   Serial.write(3); 
    Serial.print(value2,DEC); 
    Serial.write(20); 
    
    Serial.write(4); 
    Serial.print(value3,DEC); 
    Serial.write(20);
//--------------------------------------------------------------------------------------------------------
    delay (10);
  }
}
