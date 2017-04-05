void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int tmp=-1;
  tmp=tmp*(-1);
  if(tmp==1){
    digitalWrite(3,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(3,LOW);
    delay(1000);
  }
}
