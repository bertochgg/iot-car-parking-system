// Arduino Car Parking System

#include <Servo.h> 

Servo myservo1;
Servo myservo2;

int IR1 = 2;
int IR2 = 4;

int IR3 = 5;
int IR4 = 6;

int Slot = 4;           //Enter Total number of parking Slots

int flag1 = 0;
int flag2 = 0;

int flag3 = 0;
int flag4 = 0;

void setup() {

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  
  myservo1.attach(3);
  myservo1.write(110);

  myservo2.attach(7);
  myservo2.write(20);
 
}

void loop(){ 

  enterParking();
  outParking();
}

void enterParking(){
  
if(digitalRead(IR1) == LOW && flag1==0){
  if(Slot>0){
    flag1=1;
  if(flag2==0){
    myservo1.write(190); 
    Slot = Slot-1;}
  }
}

if(digitalRead (IR2) == LOW && flag2==0){
  flag2=1;
  //if(flag1==0){
    //myservo1.write(0); 
    //Slot = Slot+1;
  //}
}

if(flag1==1 && flag2==1){
  delay (1000);
  myservo1.write(110);
  flag1=0, flag2=0;
}

}

void outParking(){
  if(digitalRead(IR3) == LOW && flag3==0){
  if(Slot>=0){
    flag3=1;
  if(flag4==0){
    myservo2.write(110); 
    Slot = Slot+1;}
  }
}

if(digitalRead (IR4) == LOW && flag4==0){
  flag4=1;
  //if(flag3==0){
    //myservo2.write(0); 
    //Slot = Slot+1;
  //}
}

if(flag3==1 && flag4==1){
  delay (1000);
  myservo2.write(20);
  flag3=0, flag4=0;
}
}
