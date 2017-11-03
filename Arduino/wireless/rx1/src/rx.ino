#include <VarSpeedServo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

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

//initialize serial communication variables
int num_motors[1];

// Store data received/motor angle
byte pos_received[10];
int pos_temp[1];

/*
MOSI is connected to the digital pin 11
MISO is connected to the digital pin 12
SCK is connected to the digital pin 13
SS (not used, but also blocks) is connected to the digital pin 10
*/
RF24 radio(7, 8); // CE, CNS

const byte address[6] = "00001";

void setup() {
  num_motors[0] = 0;
  Serial.begin(9600);

  //initiliatizing wireless communication
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  Serial.println("Aguardando dados...");
}

void loop() {
  int i = 0;
  if (radio.available()) {
    while(radio.available()){
      byte data;
      radio.read(&data, sizeof(data));
    //  if(data != 0x0){
        Serial.println(data, DEC);
    //  }
      pos_received[i] = data;
      i++;
    }
  }
  for(int j=0; j<i; j++){
    moveJoint(pos_received[j], j);
    Serial.println("Data: ");
    Serial.println(pos_received[j]);
    Serial.println(j);
  }
  i = 0;
}

void setInitPos(VarSpeedServo motor){
  motor.write(0, 0, false);
}

void moveToPos(VarSpeedServo motor, int pos){
  motor.write(pos, 0, false);
}

void moveJoint(int pos, int motor){
  VarSpeedServo curMotor;
  switch(motor){
    case 1: {
      curMotor.attach(motor1);
      break;
    }
    case 2: {
      curMotor.attach(motor2);
      break;
    }
    case 3: {
      curMotor.attach(motor3);
      break;
    }
    case 4: {
      curMotor.attach(motor4);
      break;
    }
    case 5: {
      curMotor.attach(motor5);
      break;
    }
    case 6: {
      curMotor.attach(motor6);
      break;
    }
    case 7: {
      curMotor.attach(motor7);
      break;
    }
    case 8: {
      curMotor.attach(motor8);
      break;
    }
    case 9: {
      curMotor.attach(motor9);
      break;
    }
    case 10: {
      curMotor.attach(motor10);
      break;
    }
  }
  curMotor.write(pos, 255, false);
}

void smoothMoveJoint(int pos, int motor, int step){
  VarSpeedServo curMotor;
  switch(motor){
    case 1: {
      curMotor.attach(motor1);
      break;
    }
    case 2: {
      curMotor.attach(motor2);
      break;
    }
    case 3: {
      curMotor.attach(motor3);
      break;
    }
    case 4: {
      curMotor.attach(motor4);
      break;
    }
    case 5: {
      curMotor.attach(motor5);
      break;
    }
    case 6: {
      curMotor.attach(motor6);
      break;
    }
    case 7: {
      curMotor.attach(motor7);
      break;
    }
    case 8: {
      curMotor.attach(motor8);
      break;
    }
    case 9: {
      curMotor.attach(motor9);
      break;
    }
    case 10: {
      curMotor.attach(motor10);
      break;
    }
  }
  for(int i= 0; i<pos; ){
    curMotor.write(i, 255, false);
    delay(1);
    if(i+step>=pos) i = pos - 1;
    else i+=step;
  }
}
