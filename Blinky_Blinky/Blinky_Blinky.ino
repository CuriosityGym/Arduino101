
/* Curiosity Gym Excercise 1 */
// Blink an LED
int LED=2;//Connect LED on Pin 2
int onTime=100; //Set On time 
int offTime=100; //Set off time
void setup()
{
  pinMode(LED, OUTPUT); //Set LED pin as output
  
}


void loop()
{
  digitalWrite(LED, LOW); //turn on LED , inversed logic on I/O Board
  delay(onTime);//keep LED on for "onTime" microseconds
  digitalWrite(LED, HIGH);//turn off LED , inversed logic on I/O Board
  delay(offTime);//keep LED off for "offTime" microseconds
  
  
}
