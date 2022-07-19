int enA=11;
int int1=10;
int int2=9;
int int3=8;
int int4=7;
int enB=6;



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
  digitalWrite(int1,HIGH);
  digitalWrite(int2,LOW);
  digitalWrite(int3,HIGH);
  digitalWrite(int4,LOW);

  analogWrite(enA,50);
  analogWrite(enB,75);
}
