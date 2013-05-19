/*
*  pa_Potentiometer
*  
*  Reads the values which represent the state of a potentiometer 
*  from the serial port and draws a graphical representation.
* 
*  This file is part of the Arduino meets Processing Project.
*  For more information visit http://www.arduino.cc.
*
*  copyleft 2005 by Melvin Ochsmann for Malm? University
*
*/

// modified to read multiple sensors by mika@kobakant.at
// devider is 20 in this example.


// importing the processing serial class
import processing.serial.*;

// the display item draws background and grid
  DisplayItems di;

// definition of window size and framerate
  int xWidth = 768;
  int yHeight = 512;
  int fr = 24;
  int prefix = 1;
  boolean myCatch = true;
  int[] xPosArr= {0,0,0,0,0,0}; //xPos in array, using prefix
  int i = 0;
  
// attributes of the display
  boolean bck = true;
  boolean grid = true;
  boolean g_vert = true;
  boolean g_horiz = false;
  boolean g_values = true;
  boolean output = true;
  
// variables for serial connection, portname and baudrate have to be set 
  Serial port;
  String portname = "/dev/tty.usbserial-1B1";
  // /dev/cu.usbserial-0000101D
  // "/dev/cu.usbserial-1B1";  
  int baudrate = 9600;
  int value = 0; 
  String buf=""; 
  int value1=0;  

void setup(){
  // set size and framerate
  size(xWidth, yHeight); frameRate(fr);
  // establish serial port connection      
  port = new Serial(this, portname, baudrate);
  println(port);
  // create DisplayItems object
  di = new DisplayItems();
 println(Serial.list());
 
}

void drawPotiState(){
  for (i = 0; i < xPosArr.length; i++) {
   noStroke();
   if (i == 0) fill(0, 0, 255);
   if (i == 1) fill(0, 0, 128);
   if (i == 2) fill(0, 255, 0);
   if (i == 3) fill(0, 128, 0);
   if (i == 4) fill(255, 0, 0);
   if (i == 5) fill(128, 0, 0);
   // draw rectangfle at xpos 
    rect(xPosArr[i], i*85, width/32+(xPosArr[i]/200), 85);
    //println(i+" :: " + i*85 + " ::: " + (i+1)*85);
    fill(0);
    // and xpos as text
    //text(""+xPosArr[i] , xPosArr[i], height/2);
  }
}

void serialEvent(int serial){
  // if serial event is not a line break

  if (myCatch) {
    if(serial!=20) {        
    // add event to buffer
      buf += char(serial);          
    } else {
    // if serial is line break set value1 to buff and clear it
      println("");
      value1 = int(buf);
       xPosArr[(prefix-1)] = constrain ( ( ((value1-100)*(width+100))/width )  ,0, width-12); 
       myCatch = false;
       if (prefix == 6) {
         //printXpos();
       }
      buf="";
    }
  }
  
    //myCatch is the beginging of the each sended number used to define the port
    // myCatch gets true if serial is less than 10 since header is 1-9
  if (!myCatch && serial < 20) { 
    myCatch = true;
    prefix = int(serial);
  }

}

void printXpos() {
  for (i = 0; i < xPosArr.length; i++) {
    println("xpos"+i+": "+xPosArr[i]);
  } 
}


// draw listens to serial port, draw 
void draw(){
// listen to serial port and trigger serial event  
  while(port.available() > 0){
        value = port.read();
        serialEvent(value);
    }
 // draw background, then PushButtonState and finally rest of DisplayItems   
    di.drawBack();
    drawPotiState();
    di.drawItems();  
}
