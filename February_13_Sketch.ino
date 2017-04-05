
void setup() {
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  int reading, PWM_parameter;
  boolean Caution_Flag;

  reading = analogRead(A0);

  if(reading <= 920)   // Reading at most 4 V
  {
    PWM_parameter = mymap(reading);
    Caution_Flag = LOW;
  }
  else
  {
    PWM_parameter = 204;
    Caution_Flag = HIGH;
  }
  analogWrite(10, PWM_parameter);
  digitalWrite(12, Caution_Flag);
  
}

int mymap(int reading)
{
  return (reading/920.)*204.;
}

