#include <Servo.h>

int servoAngle = 0;

Servo servoLeftArm;
Servo servoRightArm;
Servo servoWrist;
Servo servoWristUpDown;
Servo servo996r;
Servo servo995;

void setup() {
  servoLeftArm.attach(8);
  servoRightArm.attach(9);
  servoWrist.attach(10);
  servoWristUpDown.attach(11);
  servo996r.attach(12);
  servo995.attach(13);

  Serial.begin(9600);
}

void loop() {
  servoTurn(1,0,160,50,0,servo995);
  delay(5000); 
  servoTurn(-1,160,0,50,0,servo995);
  delay(5000);    
}

void moveWristUp(){
  servoTurn(1,0,150,10,0,servoWristUpDown);
}

void moveWristDown(){
  servoTurn(-1,150,10,10,0,servoWristUpDown);
}

void dropTurn(){
  servoTurn(-1,180,30,0,0,servoWrist);
  delay(500);
  servoTurn(1,30,180,0,0,servoWrist);
  delay(500);
}

void openArms(){
  //servoTurn(int side,double start,double halt,double stepTime,double waitTime,Servo servoName);
  servoTurn(-1,135,35,0,0,servoLeftArm);
  servoTurn(1,20,130,0,0,servoRightArm);
}

void closeArms(){
  //servoTurn(int side,double start,double halt,double stepTime,double waitTime,Servo servoName);
  servoTurn(1,35,135,0,0,servoLeftArm);
  servoTurn(-1,130,20,0,0,servoRightArm);
}

void servoTurn(int side,double start,double halt,double stepTime,double waitTime,Servo servoName){
  //side  ->  -1:anticlockwise 1:clockwise
  //start ->  start angle
  //halt  ->  halt angle
  if(side==1){
    for(servoAngle = start; servoAngle <= halt; servoAngle++){           
      servoName.write(servoAngle);          
      delay(stepTime);                  
    } 
    delay(waitTime);
  }else if(side=-1){
    for(servoAngle = start; servoAngle >= halt; servoAngle--){           
      servoName.write(servoAngle);          
      delay(stepTime);                  
    }
    delay(waitTime); 
  }
}
