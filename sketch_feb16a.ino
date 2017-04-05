void setup(){
  Serial.begin(9600);
  char output_string[100];
  char first_half[]="All that is gold";
  char second_half[]=" does not glitter.";

  strcpy(output_string, first_half);
  strcat(output_string, second_half);
  Serial.println(output_string);
}

void loop(){
  
}

