
#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(4, 5, 6, 7);	// SW SPI Com: SCK = 4, MOSI = 5, CS = 6, A0 = 7 (new white HalTec OLED)
int ypos=30;
String inputString = "";         // a string to hold incoming data
const char* lines[5];
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  analogReference(INTERNAL); 
  u8g.setFont(u8g_font_unifont);  // select font
}

void loop()
{
  
  
  //Serial.println("Noy OK");
      u8g.firstPage();  
  do{
        printVoltage();
        if(stringComplete)
        {
  
          draw();
          //stringComplete=false;
          delay(100);
          
          
        }
  }
    while( u8g.nextPage() );

//Serial.println("OK");
  
}

void draw()
{
  
 u8g.drawStr(0, 28, inputString.c_str());
 //u8g.drawStr(0, 42, inputString.c_str());
  
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    if ((inChar == '\r' || inChar=='\n')&& stringComplete) 
    {
      return;
    }
      
    if ((inChar == '\r' || inChar=='\n')&& !stringComplete)  {

      stringComplete = true;


    }
    else
    {
      if(stringComplete)
      {
        inputString="";
      } 
      stringComplete=false;
      inputString += inChar;
    } 
    
    
  }
}

void formatString()
{
  String p;
  int j=0;
  for(int i=0;i<200;i++)
  {
    p=p+inputString.substring(i,i+1);
    if(i%16==0)
    {
     lines[j]=p.c_str();
      j=j+1; 
    }
  }  
  
  Serial.println(lines[1]);
  
}


void printVoltage()
{
  
  int a= analogRead(A0);
  float voltage=a*4.9*1.1*0.97/1023;
  int percentage=voltage*100/4.2;
  u8g.drawStr(10, 60, "Curiosity Gym");  
  u8g.setPrintPos(77, 10);  // set position
  u8g.print(voltage, 1);  
   //u8g.setPrintPos(70, 10);  // set position
 //u8g.drawStr(95, 10, " V");   
 u8g.drawStr(94, 10, " V");   
 
 
 
 
 //u8g.drawPixel(30, 30); 
 //u8g.setPrintPos(30, 30);  // set position

//u8g.setPrintPos(30, ypos);
  
}
