/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>
 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int go_switch = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int center = 90;
int ramp = 90;


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(center);  
  Serial.begin(9600);
  Serial.println("it uploads!");
  delay(1000);  
  Serial.println(ramp);
}

void loop() {
  val = analogRead(go_switch);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.print("val = ");
  Serial.println(val);
  
  if (val > 900 && ramp >= 2) {
  myservo.write(ramp); 
  Serial.print("ramp down ");
  Serial.println(ramp);
  delay(10);
  ramp--; 
  }

if (val < 900 && ramp <= 89){
  myservo.write(ramp); 
  Serial.print("ramp up ");
  Serial.println(ramp);
  delay(10);
  ramp++; 
  }
delay (50);
myservo.write(ramp);
  Serial.print("ramp ");
  Serial.println(ramp);
}
