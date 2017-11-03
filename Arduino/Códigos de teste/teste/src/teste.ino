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

//declares motor
VarSpeedServo motor1;
VarSpeedServo motor2;
VarSpeedServo motor3;
VarSpeedServo motor4;
VarSpeedServo motor5;
VarSpeedServo motor6;
VarSpeedServo motor7;
VarSpeedServo motor8;
VarSpeedServo motor9;
VarSpeedServo motor10;

//stores data received from serial
int data[10];
int n[1];

int state = 1;
void setup(){
  n[0] = 0;

  motor1.attach(pin1);
  motor2.attach(pin2);
  motor3.attach(pin3);
  motor4.attach(pin4);
  motor5.attach(pin5);
  motor6.attach(pin6);
  motor7.attach(pin7);
  motor8.attach(pin8);
  motor9.attach(pin9);
  motor10.attach(pin10);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  //moveJoint(0, 1);
  //delay(1000);
  /*
  moveJoint(180, 1);
  delay(1000);*/


  switch(state){
    case 1:
    {
      digitalWrite(13, HIGH);
      //recebe o número de motores
      while(Serial.available()) {
        n[0] = Serial.read();
        //Serial.println("num");
        Serial.write(n[0]);
        state = 2;
      }
      break;
    }
    case 2:
    {
      //espera pela posicao dos motores
      while (Serial.available()<n[0]) {

      }

      //le a posição dos motores
      for(int i=0; i<n[0]; i++)
        data[i] = Serial.read();

      for(int i=0; i<n[0]; i++)
        Serial.write(data[i]);

      state = 3;
      break;
    }
    case 3:
    {
      moveJoint(0, 1);
      delay(1000);
      moveJoint(0, 2);
      delay(1000);

      //execution
      for(int i=0; i<n[0]; i++)
        moveJoint(data[i], i+1);
      delay(1000);

      //init
      for(int i=0; i<n[0]; i++)
      data[i] = 0;

      n[0] = 0;

      state = 1;
      break;
    }
  }

/*
  //recebe o número de motores
  while(Serial.available()) {
    n[0] = Serial.read();
    //Serial.println("num");
    Serial.write(n[0]);
  }



  delay(10);

  //espera pela posicao dos motores
  while (Serial.available()<n[0]) {

  }

  //le a posição dos motores
  for(int i=0; i<n[0]; i++)
    data[i] = Serial.read();

  for(int i=0; i<n[0]; i++)
    Serial.write(data[i]);

  //Serial.write(0);

  //execution
  for(int i=0; i<n[0]; i++)
    moveJoint(data[i], i+1);
  delay(1000);

  //init
  for(int i=0; i<n[0]; i++)
  data[i] = 0;

  n[0] = 0;

    /*int index = data.indexOf(';');
    String strMotor = data.substring(0, index);
    String strPos = data.substring(index+1, data.length());

    pos = strPos.toInt();
    motor = strMotor.toInt();

    Serial.println(pos);
    Serial.println(motor);*/
  //}

  //moveJoint(pos, motor);
  //delay(1000);


/*
  setInitPos(motor1);
  setInitPos(motor2);
  setInitPos(motor3);
  setInitPos(motor4);
  setInitPos(motor5);
  setInitPos(motor6);
  setInitPos(motor7);
  setInitPos(motor8);
  setInitPos(motor9);
  setInitPos(motor10);
*/

/*
  moveToPos(motor1, 180);
  moveToPos(motor2, 180);
  moveToPos(motor3, 180);
  moveToPos(motor4, 180);
  moveToPos(motor5, 180);
  moveToPos(motor6, 180);
  moveToPos(motor7, 180);
  moveToPos(motor8, 180);
  moveToPos(motor9, 180);
  moveToPos(motor10, 180);
*/
}
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

  if(num == 1){
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
}
