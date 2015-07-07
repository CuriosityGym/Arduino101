//CG Excercise 2 for Reacting to Button Input

int Button=6;
int LED=2;
boolean LEDState=LOW;
boolean pinState=false;
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(Button, INPUT);
  
}


void loop()
{
  pinState=digitalRead(Button);
  digitalWrite(LED,pinState);
  

  
  
}


