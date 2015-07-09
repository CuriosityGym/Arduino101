
#include "U8glib.h"
#include "bitmap.h"
U8GLIB_SSD1306_128X64 u8g(4, 5, 6, 7);	// SW SPI Com: SCK = 4, MOSI = 5, CS = 6, A0 = 7 (new white HalTec OLED)
int ypos=30;
String inputString = "";         // a string to hold incoming data
const char* lines[5];
boolean stringComplete = false;  // whether the string is complete
boolean logoShown=false;
boolean timerExpired=false;
int counter=0;
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  analogReference(INTERNAL); 
  u8g.setFont(u8g_font_unifont);  // select font
  //u8g.setFont(u8g_font_courB10);  // select font
    setupTimer();
}


void loop()
{
   

  u8g.firstPage();  
  do{
        
     draw();   
  }
    while( u8g.nextPage() );

 
}

void draw()
{
        //Serial.println(logoShown);  

        if(!logoShown && !timerExpired)
        {
          drawLogo();
          logoShown=false;
          //delay(1000);
          
        } 
        else 
        {
        
        printVoltage();
        if(stringComplete)
        {
          
          drawSerialString();
          delay(10);
          
          
        }
        }
  
} 

void drawLogo()
{

  u8g.drawBitmapP( 0, 14, 16, 52, CGLOGO); //Just logo
  
}

void drawSerialString()
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
    timerExpired=true;
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
  //u8g.drawStr(0, 10, "PIN:1234");
 
 
 
 
 //u8g.drawPixel(30, 30); 
 //u8g.setPrintPos(30, 30);  // set position

//u8g.setPrintPos(30, ypos);
  
}



void setupTimer()
{
    //Serial.println("Setting Timer");
//pinMode(LEDPIN, OUTPUT);

// initialize Timer1
cli();         // disable global interrupts
TCCR1A = 0;    // set entire TCCR1A register to 0
TCCR1B = 0;    // set entire TCCR1A register to 0

// enable Timer1 overflow interrupt:
TIMSK1 |= (1 << TOIE1);
// Preload with value 3036
//use 64886 for 100Hz
//use 64286 for 50 Hz
//use 34286 for 2 Hz
TCNT1=3036;
// Set CS10 bit so timer runs at clock speed: (no prescaling)
TCCR1B =0x04; // Sets bit CS12 in TCCR1B
// This is achieved by shifting binary 1 (0b00000001)
// to the left by CS12 bits. This is then bitwise
// OR-ed into the current value of TCCR1B, which effectively set
// this one bit high. Similar: TCCR1B |= _BV(CS12);
//  or: TCCR1B= 0x04;

// enable global interrupts:
sei();
}

ISR(TIMER1_OVF_vect)
{
  //Serial.println("Interrupted");
  counter=counter+1;
  if(counter==3)
  {
    timerExpired=true;
  }  
}

