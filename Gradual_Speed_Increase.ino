int enA=9;
int int1=7;
int int2=6;
int int3=5;
int int4=4;
int enB=3;

void setup()
{
  pinMode(enA,OUTPUT);
  pinMode(int1,OUTPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  pinMode(enB,OUTPUT);
}

void speedIncrease()
{

  //Forward Direction
  digitalWrite(int1,HIGH);
  digitalWrite(int2,LOW);
  digitalWrite(int3,HIGH);
  digitalWrite(int4,LOW);
  
  for(int i=0;i<=255;i++)
  {
    analogWrite(enA,i);
    analogWrite(enB,i);
    delay(20);
  }
}

void loop()
{
  speedIncrease();
  delay(2000);
}
