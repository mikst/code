/*
*  DisplayItems
*  
*  This class draws background color, grid and value scale 
*  according to the boolean variables in the pa_file.
*
*  This file is part of the Arduino meets Processing Project.
*  For more information visit http://www.arduino.cc.
*
*  copyleft 2005 by Melvin Ochsmann for Malm? University
*
*/

class DisplayItems{

// variables of DisplayItems object 
PFont font;
int gridsize;
int fontsize = 10;
String fontname = "Monaco-14.vlw";
String empty="";
int i;

// constructor sets font and fontsize
DisplayItems(){
  font = loadFont(fontname);
  gridsize = (width/2)/16+(height/2)/16;
  if(gridsize > 20) fontsize = 14;
  if(gridsize > 48) fontsize = 22;
  textFont(font, fontsize);
}

// draws background  
void drawBack(){
       background( (bck) ? (255) : (255)  );
}
 
// draws grid and value scale
void drawItems(){
  if(grid){  stroke( (bck) ? (0) : (64) );
             fill((bck) ? (0) : (32) );

  // vertical lines
  if(g_vert){
    for (i=0; i < width; i+=gridsize){
    line(i, 0, i, height);
    textAlign(LEFT);
    if (g_values && i%(2*gridsize)==0 && i < (width-(width/10))) text( empty+i, (i+fontsize/4), 0+fontsize);
  }}

  // horizontal lines
  if(g_horiz){
    for (int i=0; i < height; i+=gridsize){
    line(0, i, width, i);
    textAlign(LEFT); 
    if (g_values && i%(2*gridsize)==0) text( empty+(height-i), 0+(fontsize/4), i-(fontsize/4));
    }}
  }
 }
}// end class Display
