/* code for ATtiny
 8 LED charlie plexing
 LEDs between pin0>pin1, pin0>pin2, pin0>pin3, pin0>pin4, pin1>pin2, pin1>pin3, pin1>pin4, pin2>pin3
 */

#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)))

boolean printimage[] = {
  0,0,1,1,0,0,0,0,
  0,1,1,1,1,0,0,0,
  1,1,0,0,1,1,1,1,
  1,1,0,0,1,1,0,0,
  1,1,1,1,1,1,1,1,
  1,1,0,0,1,1,0,0,
  1,1,0,0,1,1,1,1,
  0,1,1,1,1,0,0,0,
  0,0,1,1,0,0,0,0,
  0,0,0,0,0,0,0,0
  
};

int columnDelay;
int sizeWord = 0;

int timer = 0;
int led=0;

boolean ledState[8];

unsigned int latency;
unsigned int tcnt1;

int thresh = 100;
int counter= 0;



void SetupTimer()
{

  /* Configure timer2 in normal mode (pure counting, no PWM etc.) */
  //  TCCR0A &= ~((1<<WGM01) | (1<<WGM00));  
  //  TCCR0B &= ~(1<<WGM02);  

  /* Select clock source: internal I/O clock */
  //ASSR &= ~(1<<AS2); 

  /* Disable Compare Match A interrupt enable (only want overflow) */
  TIMSK &= ~(1<<OCIE1A);

  /* Now configure the prescaler to CPU clock divided by 1 */
  TCCR1 = 0<<CS13 | 0<<CS12 | 0<<CS11 | 1<<CS10;



  /* We need to calculate a proper value to load the timer counter. 
   * The following loads the value 131 into the Timer 1 counter register 
   * The math behind this is: 
   * (CPU frequency)8MHz / (prescaler value)2 = 8000000 Hz = 0.125us
   * (desired period) 2us / 0.125us = 16. 
   * MAX(uint8) 256 - 16 = 240; 
   */

  /* Save value globally for later reload in ISR */
  tcnt1 = 240;

  /* Finally load end enable the timer */
  TCNT1 = tcnt1;
  TIMSK |= (1<<TOIE1);
}


//Timer2 overflow interrupt vector handler //alle 512 us
//this is the light callback
ISR(TIMER1_OVF_vect) {


byte bitMask = 0;
  

switch (led){
  
  case 0:
  if (ledState[0]){
    DDRB = B00000011;
    bitMask |= B00000001;   
  }
  break;
  
  case 1:
  if (ledState[1]){
    DDRB = B00000101;
    bitMask |= B00000001;   
  }
  break;

case 2:
  if (ledState[2]){
    DDRB = B00001001;
    bitMask |= B11110111;   
  }
break;

case 3:
  if (ledState[3]){
    DDRB = B00010001;
    bitMask |= B11101111;   
  }
  break;
  
  case 4:
  if (ledState[4]){
    DDRB = B00000110;
    bitMask |= B00000010;   
  }
break;

case 5:
  if (ledState[5]){
    DDRB = B00001010;
    bitMask |= B00000010;   
  }
  break;

case 6:
  if (ledState[6]){
    DDRB = B00010010;
    bitMask |= B00000010;   
  }
  break;
 
 case 7: 
  if (ledState[7]){
    DDRB = B00001100;
    bitMask |= B00000100; 
  }
  break;
  
}


  PORTB = bitMask;

led++;
if (led>7) led=0;

  //Capture the current timer value. This is how much error we have
  //due to interrupt latency and the work in this function
  latency=TCNT1;
  //Reload the timer and correct for latency.
  TCNT1 = latency+tcnt1;
}


void setup(){

  //initTimerCounter1();
  SetupTimer();
  
   columnDelay = 10; //wait 2ms between each column flash
   sizeWord = NUM_ELEM(printimage);
   
     for (int i=0; i<8; i++){
    ledState[i]=0;
  }
  
}

void loop(){
   
printWord(printimage);
delay(10);
}

void printWord(boolean wordVar[]) {

   int numRows = sizeWord/8;
  for(int j = 0; j < numRows; j++) {
    for(int i = 0; i<8; i++) {
      ledState[i]=wordVar[i+j*8];
    }
    delay(columnDelay);
  }
} 




