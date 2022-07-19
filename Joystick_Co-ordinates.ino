int joystickHorizontal=A2;
int joystickVertical=A3;
int joystickButton=8;



void setup() 
{
  pinMode(joystickButton,INPUT);
  digitalWrite(joystickButton,HIGH);
  Serial.begin(9600);
}

void loop() 
{
  Serial.print("Joystick Button: ");
  Serial.print(digitalRead(joystickButton));
  Serial.print("|");

  Serial.print("X-axis: ");
  Serial.print(analogRead(joystickHorizontal));
  Serial.print("|");

  Serial.print("Y-axis: ");
  Serial.print(analogRead(joystickVertical));
  Serial.println("|");
}
