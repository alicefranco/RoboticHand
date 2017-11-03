
#include <VarSpeedServo.h>


//defining motor pins
#define pin1 3
#define pin2 4
#define pin3 5
#define pin4 6
#define pin5 7
#define pin6 8
#define pin7 9
#define pin8 10
#define pin9 11
#define pin10 12


VarSpeedServo motor[3];

void setup(){

  motor[1].attach(pin1);
  Serial.begin(9600);
}

void loop(){
  motor[1].write(0, 255, false);
  //motor2.write(0);
  delay(1000);
  motor[1].write(90, 255, false);
  //motor2.write(90);
  delay(1000);
  /*moveJoint(0, 1);
  moveJoint(0, 2);
  moveJoint(0, 3);
  moveJoint(0, 4);
  moveJoint(0, 5);
  moveJoint(0, 6);
  moveJoint(0, 7);
  moveJoint(0, 8);
  moveJoint(0, 9);
  moveJoint(0, 10);
  delay(1000);
  moveJoint(30, 1);
  moveJoint(30, 2);
  moveJoint(180, 3);
  moveJoint(180, 4);
  moveJoint(180, 5);
  moveJoint(180, 6);
  moveJoint(180, 7);
  moveJoint(180, 8);
  moveJoint(180, 9);
  moveJoint(180, 10);
  delay(1000);*/
}
/*
//function to move one motor only
void moveJoint1(int pos){
  motor1.write(pos, 255, false);
}

void moveJoint2(int pos){
  motor2.write(pos, 255, false);
}

void moveJoint3(int pos){
  motor3.write(pos, 255, false);
}

void moveJoint4(int pos){
  motor4.write(pos, 255, false);
}

void moveJoint5(int pos){
  motor5.write(pos, 255, false);
}

void moveJoint6(int pos){
  motor6.write(pos, 255, false);
}

void moveJoint7(int pos){
  motor7.write(pos, 255, false);
}

void moveJoint8(int pos){
  motor8.write(pos, 255, false);
}

void moveJoint9(int pos){
  motor9.write(pos, 255, false);
}

void moveJoint10(int pos){
  motor10.write(pos, 255, false);
}

//moves one of all motors at a time
void moveJoint(int pos, int num){
  //Serial.write(num);
  if(num == 1){
    //Serial.write(111);
    digitalWrite(13, HIGH);
    moveJoint1(pos);
  }
  else if(num == 2){
    moveJoint2(pos);
  }
  else if(num == 3){
    moveJoint3(pos);
  }
  else if(num == 4){
    moveJoint4(pos);
  }
  else if(num == 5){
    moveJoint5(pos);
  }
  else if(num == 6){
    moveJoint6(pos);
  }
  else if(num == 7){
    moveJoint7(pos);
  }
  else if(num == 8){
    moveJoint8(pos);
  }
  else if(num == 9){
    moveJoint9(pos);
  }
  else if(num == 10){
    moveJoint10(pos);
  }
}*/
