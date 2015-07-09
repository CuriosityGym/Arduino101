
/* Curiosity Gym Excercise 1 */
// Blink an LED
int D1=2;//Connect D! on Pin 2
int D2=3;//Connect D2 on Pin 3
int D3=4;//Connect D3 on Pin 4
int onTime=60;
int offTime=60;
void setup()
{
  pinMode(D1, OUTPUT); //Set LED pin as output
  pinMode(D2, OUTPUT); //Set LED pin as output
  pinMode(D3, OUTPUT); //Set LED pin as output
  
}


void loop()
{
  digitalWrite(D1, LOW);
  delay(onTime);
  digitalWrite(D2, LOW);
  delay(onTime);
  digitalWrite(D3, LOW);
  delay(onTime);
  
  
  digitalWrite(D1, HIGH);
  delay(offTime);
  digitalWrite(D2, HIGH);
  delay(offTime);
  digitalWrite(D3, HIGH);
  delay(offTime); 
  
}
