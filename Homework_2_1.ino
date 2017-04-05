void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0); //read the analog value of voltage
  reading=map(reading,0,1023,0,255); //map the value to 0-255
  if(reading>1){                //determine the condition
    analogWrite(9,reading-1);   //turn on the light
    if(reading>100){
      analogWrite(10,reading-100);
      if(reading>150){
        analogWrite(11,reading-150);
      }
      else{
        analogWrite(11,0);      //or turn off the light
      }
    }
    else{
      analogWrite(10,0);
      analogWrite(11,0);
    }
  }
  else{
    analogWrite(9,0);
    analogWrite(10,0);
    analogWrite(11,0);
  }
}
