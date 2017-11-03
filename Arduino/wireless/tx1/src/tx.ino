
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//Stores data received from serial port
byte num_motors[1];
byte pos[10];



/*
MOSI is connected to the digital pin 11
MISO is connected to the digital pin 12
SCK is connected to the digital pin 13
SS (not used, but also blocks) is connected to the digital pin 10
*/
RF24 radio(7, 8); // CE, CNS

const byte address[6] = "00001";

void setup() {
  num_motors[0]=0;
  Serial.begin(9600);

  //initializing wireless communication
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  //recebe o número de motores
  while(Serial.available()) {
    Serial.readBytes(num_motors, 1);
  }

  //Serial.println("Numero de motores: ");
  Serial.write(num_motors[0]);

  delay(10);


  //espera pela posicao dos motores
  while (Serial.available()<num_motors[0]) {

  }

  //Serial.println("Motores pos: ");
  //read motor position from serial port
  for(int i=0; i<num_motors[0]; i++)
  pos[i] = Serial.read();

  for(int i=0; i<num_motors[0]; i++)
  Serial.write(pos[i]);

  //Serial.println("numero de motores");
  //Serial.println(num_motors[0]);

  Serial.write(0);

  //Sends position data
  for(int i=0; i<num_motors[0]; i++){
    int data = pos[i];
    bool ack = radio.write(&data, sizeof(data));
  }
  //if(ack) Serial.println("Data sent sucessfully.");
  //else Serial.println("Data sending failed.");
  delay(1000); //remove

  //init
  for(int i=0; i<num_motors[0]; i++)
  pos[i] = 0;

  num_motors[0] = 0;
}
