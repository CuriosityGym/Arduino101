int tempSensorPin=A3;

void setup()
{

  Serial.begin(9600);
}

void loop()
{
  int temperatureReading=analogRead(tempSensorPin);//Read sensor value from ADC

  float celsiusTemperature=temperatureReading*5/(1023*0.01); //do multiplication, ADC resolution is 1023 bits for 5v, sensor sends 10mV/C value.

  Serial.println(celsiusTemperature,2);//Print Temperature

  delay(1000);
  
  
}
