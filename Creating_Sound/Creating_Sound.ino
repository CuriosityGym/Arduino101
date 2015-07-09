
/* A simple Sound creation Code By Curiosity Gym */
/*Code Generates a beep on Buzzer*/
int buzzerPin=5;
void setup()
{
  //No Setup Code Required
}

void loop()
{
  tone(buzzerPin,330);//create a 440Hz Square wave for a duration of 1 sec
  delay(1000);
  
/*
Syntax

tone(pin, frequency)
tone(pin, frequency, duration)
Parameters

pin: the pin on which to generate the tone

frequency: the frequency of the tone in hertz - unsigned int

duration: the duration of the tone in milliseconds (optional) - unsigned long 

*/



  noTone(buzzerPin);
  delay(500);
  
}
