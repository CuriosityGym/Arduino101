
/* Curiosity Gym Excercise 1 */
// Blink an LED
int LED0=2;//Connect LED0 on Pin 2
int LED1=3;//Connect LED1 on Pin 3
int LED2=4;//Connect LED2 on Pin 4
int onTime=60;
int offTime=60;
void setup()
{
  pinMode(LED0, OUTPUT); //Set LED pin as output
  pinMode(LED1, OUTPUT); //Set LED pin as output
  pinMode(LED2, OUTPUT); //Set LED pin as output
  
}


void loop()
{
  digitalWrite(LED0, LOW);
  delay(onTime);
  digitalWrite(LED1, LOW);
  delay(onTime);
  digitalWrite(LED2, LOW);
  delay(onTime);
  
  
  digitalWrite(LED0, HIGH);
  delay(offTime);
  digitalWrite(LED1, HIGH);
  delay(offTime);
  digitalWrite(LED2, HIGH);
  delay(offTime); 
  
}
