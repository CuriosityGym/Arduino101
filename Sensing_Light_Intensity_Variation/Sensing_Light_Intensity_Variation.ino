int LDRPin=A2;//Setup LDR on A2 Pin
int LEDPin=2; // Set LEd on Pin 2
//These values below need to be changed based on ambient conditions
int highThreshold=450;
int lowThreshold=350;
void setup()
{
  Serial.begin(9600); //Setup Serial Terminal on 9600bps
  pinMode(LEDPin, OUTPUT);
}


void loop()
{
  Serial.print("Light Intensity: ");//Print a string without newline
  
  int lightIntensity=analogRead(LDRPin);// Measure Light Intensity
  Serial.println(lightIntensity);//Print light intensity to Serial Terminal
  if(lightIntensity> highThreshold) //LDR is covered, switch LED OFF
  {
      digitalWrite(LEDPin, HIGH);
  }
  
  if(lightIntensity< lowThreshold) //LDR is Lit, switch LED On
  {
      digitalWrite(LEDPin, LOW);
  }
  
  
  
  
}
