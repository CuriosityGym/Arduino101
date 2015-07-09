int LDRPin=A2;//Setup LDR on A2 Pin
void setup()
{
  Serial.begin(9600); //Setup Serial Terminal on 9600bps
  
}


void loop()
{
  Serial.print("Light Intensity: ");//Print a string without newline
  
  int lightIntensity=analogRead(LDRPin);// Measure Light Intensity
  Serial.println(lightIntensity);//Print light intensity to Serial Terminal
  delay(500);
}
