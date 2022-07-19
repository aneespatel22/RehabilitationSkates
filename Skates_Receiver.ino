#include<SPI.h>
#include<RF24.h>
#include<nRF24L01.h>

const int pwmL = 5;
const int dirL = 6;

const int pwmR = 9;
const int dirR = 10;

int motorSpeedL=0;
int motorSpeedR=0;

const byte address[6]="00001";
RF24 radio(7,8);

int xyRecArr[2];

void setup() {
 Serial.begin(9600);
 radio.begin();
 radio.openReadingPipe(0,address);
 radio.setPALevel(RF24_PA_MIN);
 radio.startListening();

 pinMode(pwmL,OUTPUT);
 pinMode(dirL,OUTPUT);
 pinMode(pwmR,OUTPUT);
 pinMode(dirR,OUTPUT);

 
}

void loop() {
  if(radio.available()){
    int receivedDataX;
    int receivedDataY;
    radio.read(&xyRecArr,sizeof(xyRecArr));  

    receivedDataX = xyRecArr[0];
    receivedDataY = xyRecArr[1];

    Serial.print("X axis: ");
    Serial.print(receivedDataX);
    Serial.print("|");
    
    Serial.print("Y axis: ");    
    Serial.print(receivedDataY);
    Serial.println("|");

    //forward direction
    if(receivedDataY>510){
      motorSpeedL = map(receivedDataY,510,1023,0,175);
      motorSpeedR = map(receivedDataY,510,1023,0,175);

      digitalWrite(dirL,HIGH);
      digitalWrite(dirR,HIGH);

      
    }
    
    else if(receivedDataY<505){
      receivedDataY=receivedDataY-505;
      receivedDataY=receivedDataY*-1;

      motorSpeedL=map(receivedDataY,0,505,0,175);
      motorSpeedR=map(receivedDataY,0,505,0,175);

      digitalWrite(dirL,LOW);
      digitalWrite(dirR,LOW);

      
    }
    else
    {
      motorSpeedL=0;
      motorSpeedR=0;
    } 

    //Right Direction
    if(receivedDataX<490){ 
      receivedDataX=receivedDataX-490;
      receivedDataX=receivedDataX *-1;

      receivedDataX=map(receivedDataX,0,490,0,255);

      //Left Motor(Motor A) faster than Right Motor(Motor B)
      motorSpeedL=motorSpeedL+receivedDataY;
      motorSpeedR=motorSpeedR-receivedDataX;

      if(motorSpeedL<0)
        motorSpeedL=0;
      if(motorSpeedR>255)
        motorSpeedR=255;
     }
     //Left Direction
     else if(receivedDataX>495)
     {
      receivedDataX=map(receivedDataX,495,1023,0,255);
    
      //Left Motor(Motor A) slower than Right Motor(Motor B)
      motorSpeedL=motorSpeedL-receivedDataX;
      motorSpeedR=motorSpeedR+receivedDataX;

      if(motorSpeedL>255)
        motorSpeedL=255;
      if(motorSpeedR<0)
        motorSpeedR=0; 
     }
     //To remove buzzing sound of motors
    if(motorSpeedL<20)
      motorSpeedL=0;
    if(motorSpeedR<20)
      motorSpeedR=0;

    //Writing Speed to motors
    analogWrite(pwmL,motorSpeedL);
    analogWrite(pwmR,motorSpeedR);           
  }
}
