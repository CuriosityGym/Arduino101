
#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define SERVO_PIN 4 //Pin the servo signal pin is connect to 

int servoPosition;// Global variable to hold servo angle position

 
int distancemm; //global variable to hold distance in mm
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Servo myservo; // servo object

void setup() {
   myservo.attach(SERVO_PIN);// attach a servo in code to pin SERVO_PIN
}

void loop() {
  
  delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  
  unsigned int uS = sonar.ping_median(3); // Find median values of three pings, makes servo movement much smoother
  // sound moves 0.34 mm in 1 us, which is the the roundtrip distance the sound travelled, so we divide by 2 to find out distance between sensor and obstruction
  
  distancemm=uS *0.17; 
  
  
  
  /*
  50mm is the minimum range the sensor can sense due to size of cone of sound emanated from the sensor.
  A servo moves 180 degrees only. Each degree to servo is mapped to each mm of distance, so 50mm +180mm=230mm
  so we choose 230mm as upper bound for sensing distance  */
  
  if(distancemm>=50 && distancemm<230) 
  {
    /*
    only when the distance is within 50 mm and 230mm, should we update servoPosition variable
    if not, then the servoPosition variable will hold its old value in its last iteration and the servo would not go back to its reset position */
    

     servoPosition=map(distancemm, 50,230, 0,180);
   
  } 
  
  myservo.write(servoPosition);
  
}
