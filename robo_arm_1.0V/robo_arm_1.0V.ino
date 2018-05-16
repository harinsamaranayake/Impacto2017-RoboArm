#include <Servo.h>
#include <Stepper.h>

const int stepsPerRevolution =360;

//servo mg90
int servoAngle = 0;   // servo position in degrees
int servoAngelOne = 0;

int servoPinLeft = 10;
int servoPinRight =11 ;
int servoPinWrist =12 ;
int servoPinWristUD =13 ;
int servoPin996r =40 ;
int servoPin995 =42 ;

Servo servoLeft;
Servo servoRight;
Servo servoWrist;
Servo servoWristUD;
Servo servo996r;
Servo servo995;


Stepper nema17(stepsPerRevolution, 46, 48, 50, 52);

//colour
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int frequency = 0;
int frequencyB = 0;
int frequencyG = 0;
int frequencyR = 0 ;

void setup() {
  //colour
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  //servo
  servoLeft.attach(servoPinLeft);
  servoRight.attach(servoPinRight);
  servoWrist.attach(servoPinWrist);
  servoWristUD.attach(servoPinWristUD);
  servo996r.attach(servoPin996r);
  servo995.attach(servoPin995);
    
  Serial.begin(9600);


  //stepper Nema17

  nema17.setSpeed(5);
}

void loop() {
  
//returnWithoutBall();  

//nemaClockWise();
//nemaAntiClockwise(); 

//getBallB();
//returnWithBallB();
//returnWithoutBallA();
//returnWithBallB();
//delay(2000);
//putBallBToA();

//nema17.step(-40.5);
//delay(500);

//getBallA();
//returnwithoutBall();
  
//int i=color();
//Serial.println(i);

//armOpen();
//delay(1000);
//armClose();
//delay(1000);

//towerPro995();

//wristServoUD();

//delay(5000);  

//nemaClockWise();
//delay(10000);
//nemaAntiClockwise();
//delay(10000);

getBallA();
delay(5000);
  
}

void returnWithBallA(){
   armClose();
   
//   for(servoAngle = 135; servoAngle <= 200; servoAngle++){
//      servoWristUD.write(servoAngle);        
//      delay(50);                  
//   }
//  
//   delay(100);

  for(servoAngle = 130; servoAngle <= 180; servoAngle++){           
      servo995.write(servoAngle);          
      delay(50);                  
  }
  
  delay(100);  

   for(servoAngle = 65; servoAngle >=0; servoAngle--){           
      servo996r.write(servoAngle);          
      delay(50);                  
  } 
  
   delay(100);  
}



void returnWithBallB(){  
  armClose();
  delay(100);

  for(servoAngle = 69; servoAngle >= 20; servoAngle--){           
      servo996r.write(servoAngle);          
      delay(50);                  
  } 
   
   delay(100);

   for(servoAngle = 69; servoAngle < 200; servoAngle++){
      servoWristUD.write(servoAngle);        
      delay(50);                  
  } 
  
  delay(100);

  for(servoAngle = 55; servoAngle <= 170; servoAngle++){           
      servo995.write(servoAngle);          
      delay(50);                  
  } 
  
  delay(100);  

  for(servoAngle = 20; servoAngle >= 0; servoAngle--){           
      servo996r.write(servoAngle);          
      delay(50);                  
  } 
    
   delay(100); 

   servoWristUD.write(100); 

   delay(100); 

   servoWristUD.write(200); 

   delay(100); 
}





void returnWithoutBall(){
  
  servo996r.write(0);
   

  servoWristUD.write(200); 

   servo995.write(180); 

   servoWrist.write(10);

   armOpen();

   delay(5000);
  
  
}


void returnWithoutBallA(){


  armOpen();
  delay(2000);
  //servoWrist.write(80);
  //delay(2000);
  


  for(servoAngle = 130; servoAngle <= 180; servoAngle++){           
      servo995.write(servoAngle);          
      delay(50);                  
  }
  delay(5000);

   for(servoAngle = 65; servoAngle >=0; servoAngle--){           
      servo996r.write(servoAngle);          
      delay(50);                  
  } 
   delay(10000);
   

   

//  armOpen();
//  delay(2000);
//  servoWrist.write(80);
//  delay(2000);
//  servoWristUD.write(200);
//  delay(2000);
//  servo995.write(180); 
//  delay(2000); 
  //servo996r.write(0);
   
  // delay(5000);
  
  
}



void returnWithoutBallB(){


  armOpen();
  delay(2000);
  //servoWrist.write(80);
  //delay(2000);
  


  for(servoAngle = 130; servoAngle <= 180; servoAngle++){           
      servo995.write(servoAngle);          
      delay(50);                  
  }
  delay(5000);

   for(servoAngle = 65; servoAngle >=0; servoAngle--){           
      servo996r.write(servoAngle);          
      delay(50);                  
  } 
   delay(5000);
   

   

//  armOpen();
//  delay(2000);
//  servoWrist.write(80);
//  delay(2000);
//  servoWristUD.write(200);
//  delay(2000);
//  servo995.write(180); 
//  delay(2000); 
  //servo996r.write(0);
   
  // delay(5000);
  
  
}


void getBallA(){
  servo996r.write(0);
  servoWristUD.write(200); 
  servo995.write(180); 
  servoWrist.write(10);
  armOpen();
  delay(5000);

  nema(-1);
  delay(1000);
   
  towerPro996r();
  delay(100);
  towerPro995();
  delay(100);
  wristServoUD();
  delay(100);
  
  servoWrist.write(10);
  delay(100);

  int count = 0;
  
  for(int i=0;i<10;i++){ 
    int k=color(); 
    Serial.println(k);  
    count += k;
    delay(50);
  }

  if(count > 2){ 
    armClose();
    
    //returnWithBallA();
    delay(2000);
    resetEmpty();
    
    delay(1000); 
    nema(-31.0);
    delay(1000);
    putBallAToBQuick();
    resetEmpty();
  }else{
    reset();
    delay(1000);
    nema(-31.0);
    delay(1000);
    getBallB();//go to method    
  } 
}


void getBallB(){ 
   servo996r.write(0);
   servoWristUD.write(200); 
   servo995.write(180); 
   servoWrist.write(10);
   armOpen();
   delay(5000);

    towerPro996rB();
    delay(100);
    towerPro995B();
    delay(100);
    wristServoUDB();
    delay(100);
    towerPro996rBB();

    servoWrist.write(10);
    delay(100);

    int count = 0;

    for(int i=0;i<10;i++){
      int k=color();
      Serial.println(k);
      count += k;
      delay(50);
    }

    if(count > 2){  
      armClose();
      
      //returnWithBallB();

      delay(1000);
      resetEmpty();
      
      nema(50);
      putBallBToA();
      resetEmpty();
    }else{
      reset();
    } 
}

int color(){
  //not defined->0 red->1 green->2 blue->3 
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 95,300,255,0);
  int frequencyR = frequency ; 
  delay(100);
  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 100,400,255,0);
  int frequencyG = frequency ;  
  delay(100);
  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 27,144,255,0);
  int frequencyB = frequency ;
  delay(100);
  
  //Serial.println(frequencyB);
  //Serial.println(frequencyG);
  //Serial.println(frequencyR);


  if(frequencyB > 50 || frequencyG > 50 || frequencyR > 50){
      if (frequencyB >= frequencyG){
          if(frequencyB >= frequencyR){
             //Serial.println("BLUE");
             return 3;
          }else{
             //Serial.println("RED");
             return 1;
          }
      }else{
          if(frequencyG >= frequencyR){
              //Serial.println("GREEN");
              return 2;
          }else{
              //Serial.println("RED");
              return 1;
          }
        }
  }else{
    return 0;
    //Serial.println("Not Define"); 
  }
  
  //delay(100);
  return 0;
}

void armOpen(){
    //slow turn
    //for(servoAngle = 0; servoAngle <180; servoAngle++){           
      //servoLeft.write(servoAngle);          
      //delay(50);                  
    //} 
    
   servoLeft.write(140);  
   servoRight.write(0);    
}

void armClose(){
 servoLeft.write(60);  
 servoRight.write(80);  
}

void wristServo(){
  for(servoAngle = 10; servoAngle <120; servoAngle++){           
      servoWrist.write(servoAngle);          
      delay(50);                  
  } 
}

void wristServoUD(){


for(servoAngle = 200; servoAngle >135; servoAngle--){


      servoWristUD.write(servoAngle);
      
         
      delay(50);                  
  } 
  
   //servoWristUD.write(135);
}


void wristServoUDB(){
for(servoAngle = 200; servoAngle >60; servoAngle--){
      servoWristUD.write(servoAngle);        
      delay(50);                 
  }   
}


void towerPro995(){  
  //15->parallel straight
  //150->parrallel
  for(servoAngle = 180; servoAngle > 130; servoAngle--){           
      servo995.write(servoAngle);          
      delay(50);                  
  } 
  
  
  
}


void towerPro995B(){  
  //15->parallel straight
  //150->parrallel
  for(servoAngle = 180; servoAngle > 55; servoAngle--){           
      servo995.write(servoAngle);          
      delay(50);                  
  } 
  
  
  
}


void towerPro996rB(){
  for(servoAngle = 0; servoAngle <65; servoAngle++){           
      servo996r.write(servoAngle);          
      delay(50);                  
  } 
}

void towerPro996rBB(){
  for(servoAngle = 65; servoAngle <80; servoAngle++){           
      servo996r.write(servoAngle);          
      delay(50);                  
  } 
}

void towerPro996r(){
  //75->parallel
  //15->90 straight

  
  
  for(servoAngle = 0; servoAngle <65; servoAngle++){           
      servo996r.write(servoAngle);          
      delay(50);                  
  } 

 
}





void nemaClockWise(){
  
   // step one revolution  in one direction:
  Serial.println("clockwise");
  nema17.step(-40.5);
  delay(500);

  
  
  
}


void nemaAntiClockwise(){
  
  // step one revolution in the other direction:
  Serial.println("counterclockwise");

  for(int r=0;r< 40.5; r++){
  nema17.step(r);
  delay(50);

  }
  
}



//........................................................................................................................................................................................ 

void putBallBToA(){
  
for(servoAngle = 0; servoAngle <30; servoAngle++){           
      servo996r.write(servoAngle);          
      delay(50);                  
}   
   
delay(1000);


for(servoAngle = 180; servoAngle > 100; servoAngle--){           
      servo995.write(servoAngle);          
      delay(50);                  
  }

delay(100);

wristServoUD();

delay(100);

wristServo();

delay(100);
 
}

void putBallAToBQuick(){
  //servo996r.write(40);
  //servo995.write(80);
  servo996r.write(50); 
  servo995.write(10);//decrease->up

  delay(1000);

  servoWristUD.write(130);
  
  delay(100);
  
  wristServo();
  
  delay(100);
}

void putBallAToB(){
  
for(servoAngle = 0; servoAngle <40; servoAngle++){           
      servo996r.write(servoAngle);          
      delay(50);                  
}   
   
delay(1000);

for(servoAngle = 180; servoAngle > 90; servoAngle--){           
      servo995.write(servoAngle);          
      delay(50);                  
} 

delay(1000);


for(servoAngle = 40; servoAngle <45; servoAngle++){           
      servo996r.write(servoAngle);          
      delay(50);                  
} 

delay(1000);

for(servoAngle = 90; servoAngle > 40; servoAngle--){           
      servo995.write(servoAngle);          
      delay(50);                  
} 

delay(1000);

wristServoUD();

delay(100);

wristServo();

delay(100);
  
}

//new

void nema(double nemaStep){
  nema17.step(nemaStep);   
}

void mg996rFixed(double servoAngle){
  servo996r.write(servoAngle);
}

void mg996rTurn(int side,double start,double stop){
  if(side==1){
    for(servoAngle = start; servoAngle < stop; servoAngle++){           
      servo996r.write(servoAngle);          
      delay(50);                  
    } 
  }else if(side=-1){
    for(servoAngle = start; servoAngle > stop; servoAngle--){           
      servo996r.write(servoAngle);          
      delay(50);                  
    } 
  }
}

void mg995Fixed(double servoAngle){
  servo995.write(servoAngle);
}










//.............................................................................................AFTER.........................................

void afterPutBtoA(){
  servoWrist.write(10);

  
  


for(servoAngle = 100; servoAngle <= 180; servoAngle++){           
      servo995.write(servoAngle);          
      delay(50);                  
  }

delay(100);



for(servoAngle = 30; servoAngle >= 0; servoAngle--){           
      servo996r.write(servoAngle);          
      delay(50);                  
}   
   
delay(1000);

nema(-30);



    towerPro996rB();
    delay(100);
    towerPro995B();
    delay(100);
    wristServoUDB();
    delay(100);
    towerPro996rBB();
    
    servoWrist.write(10);
    delay(100);


    armOpen();


    







  
  
}

















void mg995Turn(int side,double start,double stop){
  if(side==1){
    for(servoAngle = start; servoAngle < stop; servoAngle++){           
      servo995.write(servoAngle);          
      delay(50);                  
    } 
  }else if(side=-1){
    for(servoAngle = start; servoAngle > stop; servoAngle--){           
      servo995.write(servoAngle);          
      delay(50);                  
    } 
  }
}

void wristUDFixed(double servoAngle){
  servoWristUD.write(servoAngle);
}

void wristUDTurn(int side,double start,double stop){
  if(side==1){
    for(servoAngle = start; servoAngle < stop; servoAngle++){           
      servoWristUD.write(servoAngle);          
      delay(50);                  
    } 
  }else if(side=-1){
    for(servoAngle = start; servoAngle > stop; servoAngle--){           
      servoWristUD.write(servoAngle);          
      delay(50);                  
    } 
  }
}

void wristFixed(double servoAngle){
  servoWrist.write(servoAngle);
}

void wristTurn(int side,double start,double stop){
  if(side==1){
    for(servoAngle = start; servoAngle < stop; servoAngle++){           
      servoWrist.write(servoAngle);          
      delay(50);                  
    } 
  }else if(side=-1){
    for(servoAngle = start; servoAngle > stop; servoAngle--){           
      servoWrist.write(servoAngle);          
      delay(50);                  
    } 
  }
}

int colorAvg(){
  int colorCount=0;
  for(int j=0;j<10;j++){
    int k=color();
    colorCount+=k;
  }
  return colorCount;
}

void reset(){
  servo996r.write(0);
  servoWristUD.write(200); 
  servo995.write(180); 
  servoWrist.write(10);
  armOpen();
  delay(2000);
}

void resetEmpty(){
  servo996r.write(0);
  servoWristUD.write(200); 
  servo995.write(180); 
  servoWrist.write(10);
  armClose();
  delay(5000);
}

//simplified methods

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














