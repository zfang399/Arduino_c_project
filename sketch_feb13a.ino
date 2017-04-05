void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char sentence[500]="This is a sentence.";
  int index=1;
  int pointer=findspace(sentence, index);
  Serial.print("findspace says that space number ");
  Serial.print(index);
  Serial.print(" is in position ");
  Serial.print(pointer);
}

int findspace(char sentence[], int index)
{
  for(int i=0;i<=strlen(sentence)-1;i++){
    if(sentence[i]=' '){
      index--;
      if(index==0) return i+1;
    }
  }
  return -1;
}

