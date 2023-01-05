#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int angle =0;    // initial angle  for servo
int angleStep =5;
int LED_LIGHT =7;

#define BUTTON_UP 3
#define BUTTON_DOWN 2

void setup() {
  
  Serial.begin(9600);          //  setup serial
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(BUTTON_DOWN,INPUT_PULLUP); // assign pin 3 as input for Down button
  pinMode(BUTTON_UP,INPUT_PULLUP);// assing pin 2 as input for Up button
  myservo.write(angle);// send servo to the middle at 90 degrees
 Serial.println();
 pinMode(LED_LIGHT, OUTPUT);
}

void loop() {

  if(digitalRead(BUTTON_UP) == LOW){
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    if (angle > 0 && angle <= 43) {
      angle = angle - angleStep;
       if(angle < 0){
        angle = 0;
       }else{
      myservo.write(angle); // move the servo to desired angle
      digitalWrite(LED_LIGHT,HIGH);
      Serial.print("Moved to: ");
      Serial.print(angle);   // print the angle
      Serial.println(" degree");
       }
    }
    //digitalWrite(LED_LIGHT,LOW);
  delay(100); // waits for the servo to get there
  }// while
 // Servo button demo by Robojax.com

  if(digitalRead(BUTTON_DOWN) == LOW){

    // Servo button demo by Robojax.com
    if (angle >= 0 && angle <= 43) {
      angle = angle + angleStep;
      if(angle >43){
        angle =43;
       }else{
      myservo.write(angle); // move the servo to desired angle
      digitalWrite(LED_LIGHT,HIGH);
      Serial.print("Moved to: ");
      Serial.print(angle);   // print the angle
      Serial.println(" degree");
       }
    }
    
  delay(100 ); // waits for the servo to get there
  }// 
  digitalWrite(LED_LIGHT,LOW);
 }
