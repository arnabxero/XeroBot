#include <AFMotor.h>

//Motor Driver Variables
AF_DCMotor leftmotor(4);
AF_DCMotor rightmotor(3);



//All Sensor Readings

int s2 = A1;
int s3 = A2;
int s4 = A3;
int s5 = A4;

int diff = 200;

void setup() {

  Serial.begin(9600);


  leftmotor.setSpeed(255);
  rightmotor.setSpeed(255);
  leftmotor.run(RELEASE);
  rightmotor.run(RELEASE);


  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

}

void loop() {

  Serial.print(analogRead(s2));//for
  Serial.print(" - ");

  Serial.print(analogRead(s3));//back
  Serial.print(" - ");

  Serial.print(analogRead(s4));//left
  Serial.print(" - ");

  Serial.println(analogRead(s5));//right


  if(analogRead(s2)>diff){
    leftmotor.run(FORWARD);
    rightmotor.run(FORWARD);
  }
  else if(analogRead(s3)>diff){
    leftmotor.run(BACKWARD);
    rightmotor.run(BACKWARD);
  }
  else if(analogRead(s4)>diff){
    leftmotor.run(BACKWARD);
    rightmotor.run(FORWARD);
  }
  else if(analogRead(s5)>diff){
    leftmotor.run(FORWARD);
    rightmotor.run(BACKWARD);
  }
  else{
    leftmotor.run(RELEASE);
    rightmotor.run(RELEASE);
  }
}
