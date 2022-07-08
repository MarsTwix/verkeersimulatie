char teken;
void serialSetup(){
  Serial.begin(9600);
}

void serialLoop(){
  if (Serial.available() > 0) {
    teken = toUpperCase(Serial.read());
    sPrint("Incoming teken: ");
    sPrintln((String)teken);
  }
}

void sPrint(String text){
  Serial.print(text);
}

void sPrintln(String text){
  Serial.println(text);
}
