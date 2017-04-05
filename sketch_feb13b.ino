void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  static int index=1;
  static int last=0;
  static bool ended=false;
  char sentence[500]="We shall always place education side by side with instruction; the mind will not be cultivated at the expense of the heart.";
  char sub[500];
  int pointer=findspace(sentence, index);
  if(!ended){
   if(pointer==-1){
    for(int i=last;i<strlen(sentence);i++){
      Serial.print(sentence[i]);
    }
    Serial.println("");
    ended=true;
    }
    else{
      for(int i=last;i<pointer;i++){
        Serial.print(sentence[i]);
      }
      Serial.println("");
      last=pointer;
      index++;
    } 
  }
}

int findspace(char sentence[], int ind)
{
  for(int i=0;i<=strlen(sentence)-1;i++){
    if(sentence[i]==' '){
      ind--;
      if(ind==0) return i+1;
    }
  }
  return -1;
}

