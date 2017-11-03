
#include <VarSpeedServo.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"


//defining motor pins
#define motor1 3
#define motor2 4
#define motor3 5
#define motor4 6
#define motor5 7
#define motor6 8
#define motor7 9
#define motor8 10
#define motor9 11
#define motor10 12

int pos_int[10];
byte pos[10];
byte num_motors[1];

VarSpeedServo motor;

void setup(){
  num_motors[0] = 0;
  motor.attach(3);
  Serial.begin(9600);
}

void loop() {

  //recebe o número de motores
  while(Serial.available()) {
    Serial.readBytes(num_motors, 1);
  }

  int x = (int) num_motors[0] - 48;
  
  Serial.println("num_motors: ");
  Serial.println(x);

  delay(10);

  //espera pela posicao dos motores
  while (Serial.available()<x) {

  }

  //le a posição dos motores
  for(int i=0; i<x; i++){
  pos[i] = Serial.read();
  pos_int[i] = (int) pos[i];
  }

  Serial.println("pos");

  for(int i=0; i<x; i++)
  Serial.println(pos_int[i]);

  Serial.println(0);

  /*
  include code here
  */

 for(int i=0; i<x; i++){
    motor.write(0, 255, false);
    delay(1000);
    motor.write(pos_int[i], 255, false);
  }

  Serial.println("aqui");

/*
  moveJoint(0, 1);
  delay(1000);
  moveJoint(180, 1);
  delay(1000);
*/

  //init
  for(int i=0; i<x; i++)
  pos_int[i] = 0;

  num_motors[0] = 0;
  Serial.println("aqui2");
}

/*
void setInitPos(VarSpeedServo motor){
  motor.write(0, 0, false);
}

void moveToPos(VarSpeedServo motor, int pos){
  motor.write(pos, 0, false);
}
*/

void moveJoint(int pos, int num){
  switch(num){
    case 1: {
      motor.attach(motor1);
      break;
    }
    case 2: {
      motor.attach(motor2);
      break;
    }
    case 3: {
      motor.attach(motor3);
      break;
    }
    case 4: {
      motor.attach(motor4);
      break;
    }
    case 5: {
      motor.attach(motor5);
      break;
    }
    case 6: {
      motor.attach(motor6);
      break;
    }
    case 7: {
      motor.attach(motor7);
      break;
    }
    case 8: {
      motor.attach(motor8);
      break;
    }
    case 9: {
      motor.attach(motor9);
      break;
    }
    case 10: {
      motor.attach(motor10);
      break;
    }
  }
  motor.write(pos, 255, false);
}

void smoothMoveJoint(int pos, int num, int step){
  switch(num){
    case 1: {
      motor.attach(motor1);
      break;
    }
    case 2: {
      motor.attach(motor2);
      break;
    }
    case 3: {
      motor.attach(motor3);
      break;
    }
    case 4: {
      motor.attach(motor4);
      break;
    }
    case 5: {
      motor.attach(motor5);
      break;
    }
    case 6: {
      motor.attach(motor6);
      break;
    }
    case 7: {
      motor.attach(motor7);
      break;
    }
    case 8: {
      motor.attach(motor8);
      break;
    }
    case 9: {
      motor.attach(motor9);
      break;
    }
    case 10: {
      motor.attach(motor10);
      break;
    }
  }
  for(int i= 0; i<pos; ){
    motor.write(i, 255, false);
    delay(1);
    if(i+step>=pos) i = pos - 1;
    else i+=step;
  }
}

