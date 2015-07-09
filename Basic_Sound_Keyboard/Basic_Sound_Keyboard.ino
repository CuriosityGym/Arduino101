//CG Sound Example for Reacting to Button Input


int Buzzer=5;//Connect Buzzer on Pin 5
int SW1=6;//Set Switch 1 on Pin 6
int SW2=7;// Set Switch 2 on Pin 7




boolean SW1State=LOW;//Button Defaults to LOW State
boolean SW2State=LOW;//Button Defaults to LOW State

void setup()
{
  
  //Serial.begin(9600);
  pinMode(SW1, INPUT); //Set Button 1 as Input
  pinMode(SW2, INPUT); // Set Button 2 as Input
  
}


void loop()
{
  //Read state of two buttons
  SW1State=digitalRead(SW1);
  SW2State=digitalRead(SW2);
  
//  If Both the buttons are pressed
  //Serial.print(SW1State);
    //Serial.println(SW2State);
  // return; 
  if(SW1State==LOW && SW2State==LOW)
  {
    tone(Buzzer,100);
//    delay(1000);
    
  }
  
  //  If Button 1 is pressed, 
  
  if(SW1State==LOW && SW2State==HIGH)
  {
    tone(Buzzer,200);
    
  }
  
   //  If Button 2 is pressed, 
  
  if(SW1State==HIGH && SW2State==LOW)
  {
    tone(Buzzer,400);
    
  }
  
   //  If none of the buttons are pressed
  
   if(SW1State==HIGH && SW2State==HIGH)
  {
    noTone(Buzzer);
    
  }
  
  
  
  
}




