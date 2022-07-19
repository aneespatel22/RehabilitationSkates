int enA=10;
int int1=9;
int int2=8;
int int3=7;
int int4=6;
int enB=5;

void setup()
{
  pinMode(enA,OUTPUT);
  pinMode(int1,OUTPUT);
  pinMode(int2,OUTPUT);
  pinMode(int3,OUTPUT);
  pinMode(int4,OUTPUT);
  pinMode(enB,OUTPUT);
}

void loop()
{
  //Forward
  digitalWrite(int1,HIGH);
  digitalWrite(int2,LOW);
  digitalWrite(int3,HIGH);
  digitalWrite(int4,LOW);

  analogWrite(enA,255);
  analogWrite(enB,255);
}
