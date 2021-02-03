#include <Servo.h>

Servo myservo;  // create servo object to control a servo


void setup() {
  Serial.begin (9600); 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {



 
    myservo.write(87);

   delay (3800);

myservo.write(95);
Serial.println ('time');
delay (10000);

 myservo.write(102);

delay (3200);

 myservo.write(96);
 Serial.println ('time');

delay (10000);
  }
