int tempSensorPin=A3;// LM35 Temperature Sensor connector to analog Pin 3

void setup()
{

  Serial.begin(9600);// start serial terminal on 9600bps
}

void loop()
{
  int temperatureReading=analogRead(tempSensorPin);//Read sensor value from ADC

  float celsiusTemperature=temperatureReading*5/(1023*0.01); //do multiplication, ADC resolution is 1023 bits for 5v, sensor sends 10mV/C value.
  Serial.print("Temperature is: ");
  
  Serial.print(celsiusTemperature,2);//Print Temperature
  
  Serial.println(" C ");

  delay(1000);
  
  
}
