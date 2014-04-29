/*
  AnalogReadSerial
 Reads an analog input on pin 0, prints the result to the serial monitor.
 Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

int sensorPin=A0;

int sensorValue=0;
int mika=0;

int led=10;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(led,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(sensorPin);

  if ( sensorValue < 500) {
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }

  // print out the value you read:
  Serial.println(sensorValue);


  delay(100);        // delay in between reads for stability
}


