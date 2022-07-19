#define DIR 6
#define PWM 5

void setup()
{
  pinMode(DIR,OUTPUT);
  pinMode(PWM,OUTPUT);
}

void loop()
{
  digitalWrite(DIR,HIGH);
  analogWrite(PWM,255);
  delay(5000);
  analogWrite(PWM,0);
  delay(1000);
  digitalWrite(DIR,LOW);
  analogWrite(PWM,255);
  delay(5000);
  analogWrite(PWM,0);
  delay(1000);
}
