import serial
import time
import struct
import sys

#initializing serial communication
ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM4'
ser.timeout = 60

#opening serial port and checking if it's open
ser.open()
b = ser.is_open
print("Port: " + ser.name + "\n")

#declaring vectors for predefined moves
move = [45, 180, 90, 45, 30, 0, 75, 145, 10, 15]
thumbsup = [180, 180, 0, 0, 0, 0, 0, 0, 0, 0]
openhand = [180, 180, 180, 180, 180, 180, 180, 180, 180, 180]


#routine to send data to Arduino
while(True):

    yn = input("Usar um vetor predefinido?[Y/N/exit]\n")
    if((yn == 'Y' ) | (yn == 'y')):
        yn = input("Escolha um dos 3 movimentos[1/2/3]: ")
        if(yn == '1'):
            numvet = 10
            ser.write(struct.pack('>B', numvet))
            y = ser.read()
            print("Arduino: " + str(ord(y)) + "\n")
            for i in range(0, int(10)):
                pos = move[i]
                pos = int(pos)
                ser.write(struct.pack('>B', pos))
        elif(yn == '2'):
            numvet = 10
            ser.write(struct.pack('>B', numvet))
            y = ser.read()
            print("Arduino: " + str(ord(y)) + "\n")
            for i in range(0, int(10)):
                pos = thumbsup[i]
                pos = int(pos)
                ser.write(struct.pack('>B', pos))
        elif(yn == '3'):
            numvet = 10
            ser.write(struct.pack('>B', numvet))
            y = ser.read()
            print("Arduino: " + str(ord(y)) + "\n")
            for i in range(0, int(10)):
                pos = openhand[i]
                pos = int(pos)
                ser.write(struct.pack('>B', pos))

        z = "Arduino:"
        #reading back position from Arduino(echo)
        for i in range(0, int(10)):
            z1 = ser.read()
            z = z + " " + str(ord(z1))
        print(z + "\n")

    elif((yn == 'N') |(yn == 'n')):
        #sending number of motors
        num = input("Escreva o num de motores: \n")
        num = int(num)
        ser.write(struct.pack('>B', num))

        #reading back number of motors from Arduino (echo)
        y = ser.read()
        print("Arduino: " + str(ord(y)) + "\n")

        #sending position of motors
        print("Escreva a posição dos motores em sequencia: \n")

        for i in range(0, int(num)):
            pos = input("")
            pos = int(pos)
            ser.write(struct.pack('>B', pos))


        z = "Arduino:"
        #reading back position from Arduino(echo)
        for i in range(0, int(num)):
            z2 = ser.read()
            z = z + " " + str(ord(z2))
        print(z + "\n")
    elif((yn == 'EXIT') |(yn == 'exit')):
        sys.exit()

ser.close()

time.sleep(1);
