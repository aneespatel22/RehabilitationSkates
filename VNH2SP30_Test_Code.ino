int INA=7;
int INB=8;
int PWM=9;
int EN=12;

void setup()
{
  pinMode(INA,OUTPUT);
  pinMode(INB,OUTPUT);
  pinMode(EN,OUTPUT);
  pinMode(PWM,OUTPUT);
  digitalWrite(EN,HIGH);
}

void loop()
{
  digitalWrite(INA,HIGH);
  digitalWrite(INB,LOW);
  analogWrite(PWM,255);

  delay(5000);
  digitalWrite(INA,LOW);
  digitalWrite(INB,HIGH);
  analogWrite(PWM,255);
}
