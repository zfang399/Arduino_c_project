const int knobPin=A0;
const int motorPin=3;
int knobnum;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(knobPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 knobnum=analogRead(knobPin); 
 int PWMnum=map(knobnum,0,1023,0,255);
 analogWrite(motorPin, PWMnum);
 Serial.println(knobnum);
}
