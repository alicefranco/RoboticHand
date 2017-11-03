
#include <VarSpeedServo.h>

//defining motor pin (3 to 12)
#define pinBegin 2

//declares motors
VarSpeedServo motor[10];

//stores data received from serial
int pos[10];
int n;

void setup(){
  n = 0;

  //attaches motors to pins

  for(int i=0; i<10; i++){
    motor[i].attach(pinBegin+i);
  }

  //init serial port
  Serial.begin(9600);
}

void loop() {

  //acquires number of motors
  while(Serial.available()) {
    n = Serial.read();

    //writing back to python
    Serial.write(n);
  }


  //waiting for motor angle data
  while (Serial.available()<n) {

  }

  //reading motor angle data
  for(int i=0; i<n; i++){
    pos[i] = Serial.read();
  }


  //writing back to python
  for(int i=0; i<n; i++)
    Serial.write(pos[i]);

  //executing motion
  for(int i=0; i<n; i++){
    moveJoint(pos[i], i);
  }
  delay(1000);

  //init
  for(int i=0; i<n; i++)
    pos[i] = 0;
  n = 0;
}

//moves one of all motors at a time
void moveJoint(int pos, int num){
  motor[num].write(pos, 255, false);
}
