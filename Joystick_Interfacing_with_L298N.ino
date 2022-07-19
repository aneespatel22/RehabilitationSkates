int enA=9;
int int1=7;
int int2=6;
int int3=5;
int int4=4;
int enB=3;
int joystickVertical=A1;
int joystickHorizontal=A0;
int joystickVerticalPosition=512;
int joystickHorizontalPosition=512;
int motorSpeedA=0;
int motorSpeedB=0;

void setup()
{
  pinMode(enA,OUTPUT);
  pinMode(int1,OUTPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  pinMode(enB,OUTPUT);

  //Check if necessary
  /*digitalWrite(enA,LOW);
  digitalWrite(int1,HIGH);
  digitalWrite(int2,LOW);
  digitalWrite(int3,HIGH);
  digitalWrite(int4,LOW);
  digitalWrite(enB,LOW);*/
}
void loop() 
{
  joystickVerticalPosition=analogRead(joystickVertical);
  joystickHorizontalPosition=analogRead(joystickHorizontal);

  //564 and 460 used considering 10% tolerance in Joystick (Can use 512 if you wish)
  //Check position using if-elseif-else block
  //Forward Direction
  if(joystickVerticalPosition>564)
  {
    motorSpeedA=map(joystickVerticalPosition,564,1023,0,255);
    motorSpeedB=map(joystickVerticalPosition,564,1023,0,255);

    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW);
  }
  //Reverse Direction
  else if(joystickVerticalPosition<460)
  {
    joystickVerticalPosition=joystickVerticalPosition-460;
    joystickVerticalPosition*=-1;

    motorSpeedA=map(joystickVerticalPosition,0,460,0,255);
    motorSpeedB=map(joystickVerticalPosition,0,460,0,255);

    digitalWrite(int1,LOW);
    digitalWrite(int2,HIGH);
    digitalWrite(int3,LOW);
    digitalWrite(int4,HIGH);      
  }
  else
  {
    motorSpeedA=0;
    motorSpeedB=0;
  }

  //Left Direction
  if(joystickHorizontalPosition<460)
  { 
    joystickHorizontalPosition=joystickHorizontalPosition-460;
    joystickHorizontalPosition*=-1;

    joystickHorizontalPosition=map(joystickHorizontalPosition,0,460,0,255);

    //Left Motor(Motor A) slower than Right Motor(Motor B)
    motorSpeedA=motorSpeedA-joystickHorizontalPosition;
    motorSpeedB=motorSpeedB+joystickHorizontalPosition;

    if(motorSpeedA<0)
      motorSpeedA=0;
    if(motorSpeedB>255)
      motorSpeedB=255;
  }

  //Right Direction
  else if(joystickHorizontalPosition>564)
  {
    joystickHorizontalPosition=map(joystickHorizontalPosition,564,1023,0,255);
    
    //Left Motor(Motor A) faster than Right Motor(Motor B)
    motorSpeedA=motorSpeedA+joystickHorizontalPosition;
    motorSpeedB=motorSpeedB-joystickHorizontalPosition;

    if(motorSpeedA>255)
      motorSpeedA=255;
    if(motorSpeedB<0)
      motorSpeedB=0;
      
  }
  //To remove buzzing sound of motors
  if(motorSpeedA<8)
    motorSpeedA=0;
  if(motorSpeedB<8)
    motorSpeedB=0;

   //Writing Speed to motors
   analogWrite(enA,motorSpeedA);
   analogWrite(enB,motorSpeedB); 
}
