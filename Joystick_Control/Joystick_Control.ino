//Curiosity Gym Code for Course


int M1A=11; //first Pin to connect to Motor driver
int M1B=10;//second Pin to connect to Motor driver
int EN=9;//enable pin to connect to motor driver
int LED=13;//Default Pin on Arduino the onboard LED is connected on.

int xPos; //Global variable to hold position of the X Joystick
int mSpeed; // Global Variable to hold value of speed
int restPosition;//Needs to be changed based on stop position of Joystick, code in setup does this.


void setup()
{

 pinMode(M1A, OUTPUT); //Set M1A as Output Pin
 pinMode(M1B, OUTPUT);//Set M1B as Output Pin
 pinMode(LED, OUTPUT);//Set LED as Output Pin
 
/*
Following code runs once, and figures out what is the rest position of the joystick. It is imperatrive
to not move the joystick during first couple of seconds to let the program callibrate the joystick.
We are adding 10 values of the joystick, then averaging to come to a standard rest position.
Delay adds to stability of readings.LED on PIN 13 used to signal callibration complete
*/
  int restPos=0;
  digitalWrite(LED, HIGH);//Turn LED ON to signal start of callibration procedure
  
  delay(100);//Wait for everything to settle
  int sumRestPos=0; // local variable to hold the sum of joystick values, set to 0.
  for(int index=0;index<10;index++)
  {
      restPos=analogRead(A0);//read joystick position
      sumRestPos= sumRestPos+restPos; //add joystick values to sumRestPos
      delay(100);//wait for 100 msec    
  }
  restPosition=sumRestPos/10; //divide sumRestPos by 10, gives us average, assign to restPosition variable
  //Turn LED OFF to signal end of callibration procedure
  digitalWrite(LED, LOW);//Turn off LED to signal callibration complete
  

  
}




void loop()
{
  
  xPos=analogRead(A0); //read joystick value from analog port 0
  if(xPos==restPosition)
 {
    stopMotor(); //if joystick is at rest position, stop motor movement
 }
 
  if(xPos>restPosition)// Joystick has been moved in direction of +5V/Vcc, we will move motor anti clockwise
 {
   mSpeed=map(xPos,521,1023,0, 255); //evaluate PWM value mapping from joystick range
   antiClockwise(mSpeed);// sets motor to be turned anticlockwise at a certain speed.
 } 
 
 if(xPos<restPosition)// Joystick has been moved in direction of GND, we will move motor clockwise
 {
  
   mSpeed=map(xPos,519,0,0, 255);//evaluate PWM value mapping from joystick range
   clockWise(mSpeed);// sets motor to be turned clockwise at a certain speed.

 } 

  
  
}

void stopMotor()
{
  // routine to stop Motor, set both M1A and M1B to LOW.
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  
}



void clockWise(int speedM)
{
  //Move Motor Clockwise, set M1A to LOW, M1B to HIGH
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  analogWrite(EN, speedM); 
  
}

void antiClockwise(int speedM)
{
  //Move Motor Clockwise, set M1A to HIGH, M1B to LOW
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  analogWrite(EN, speedM); 
  
}
