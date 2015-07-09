//CG Excercise 2 for Reacting to Button Input

int Button=6;
int D1=2;
boolean LEDState=LOW;
boolean pinState=false;
void setup()
{
  pinMode(D1, OUTPUT);
  pinMode(Button, INPUT);
  
}


void loop()
{
  pinState=digitalRead(Button);
  digitalWrite(D1,pinState);
  

  
  
}


