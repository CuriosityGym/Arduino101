//CG Excercise 2 for Reacting to Button Input

int Button1=6;//Set Switch 1 on Pin 6
int Button2=7;// Set Switch 2 on Pin 7

int LED0=2;//Connect LED0 on Pin 2
int LED1=3;//Connect LED1 on Pin 3
int LED2=4;//Connect LED2 on Pin 4

boolean Button1State=LOW;//Button Defaults to LOW State
boolean Button2State=LOW;//Button Defaults to LOW State

void setup()
{
   pinMode(LED0, OUTPUT); //Set LED0 pin as output
  pinMode(LED1, OUTPUT); //Set LED1 pin as output
  pinMode(LED2, OUTPUT); //Set LED2 pin as output
  
  pinMode(Button1, INPUT); //Set Button 1 as Input
  pinMode(Button2, INPUT); // Set Button 2 as Input
  
}


void loop()
{
  //Read state of two buttons
  Button1State=digitalRead(Button1);
  Button2State=digitalRead(Button2);
  
//  If Both the buttons are pressed
  
  if(Button1State==LOW && Button2State==LOW)
  {
    generateLEDPattern(30);
    
  }
  
  //  If Button 1 is pressed, 
  
  if(Button1State==LOW && Button2State==HIGH)
  {
     generateLEDPattern(50);
    
  }
  
   //  If Button 2 is pressed, 
  
  if(Button1State==HIGH && Button2State==LOW)
  {
    generateLEDPattern(100);
    
  }
  
   //  If none of the buttons are pressed
  
   if(Button1State==HIGH && Button2State==HIGH)
  {
    generateLEDPattern(200);
    
  }
  

  
  
}

void generateLEDPattern(int delayTime)
{
  
  digitalWrite(LED0, LOW);
  delay(delayTime);
  digitalWrite(LED1, LOW);
  delay(delayTime);
  digitalWrite(LED2, LOW);
  delay(delayTime);
  
  
  digitalWrite(LED0, HIGH);
  delay(delayTime);
  digitalWrite(LED1, HIGH);
  delay(delayTime);
  digitalWrite(LED2, HIGH);
  delay(delayTime);
  
  
}


