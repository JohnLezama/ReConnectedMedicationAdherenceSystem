/*
THE FOLLOWING CODE IS FOR DEMO ONLY!!
I worked with a partner who developed a web interface that would actually control the pill dispenser, however, he has lost the program :(
This code waits for a button to be pressed.
When pressed, an LED lights up, the stepper motor rotates 180 degrees, and a servo motor moves to dispense a pill into a cup.
*/
#include <Stepper.h>
#include <Servo.h>

#define BUTTON 3
#define restingLED 4
#define activatedLED 5

#define xIN1 6
#define xIN2 7
#define xIN3 8
#define xIN4 9
const int STEPS_PER_REV = 2048;

Stepper stepper = Stepper(STEPS_PER_REV,xIN1, xIN2, xIN3, xIN4);

Servo week1;
Servo week2;

void setup() {
  week1.attach(10);
  week2.attach(11);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(restingLED, OUTPUT);
  pinMode(activatedLED, OUTPUT);
  
  stepper.setSpeed(5);
}

void loop() {
  digitalWrite(restingLED, HIGH);
  digitalWrite(activatedLED, LOW);
  if(digitalRead(BUTTON)==LOW){
    digitalWrite(restingLED, LOW);
    digitalWrite(activatedLED, HIGH);
    stepper.step(180);
    delay(500);
    week1.write(90);
    delay(1000);
    week1.write(0);
    stepper.step(180);
  }
}
