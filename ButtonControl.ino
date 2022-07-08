const int AMOUNTBUTTONS = 3;
const int BUTTONPINS[AMOUNTBUTTONS] = {A0, A1, A2};
int lastButtonPressed;

void buttonSetup(){
  for(int i = 0; i <AMOUNTBUTTONS; i++){
    pinMode(BUTTONPINS[i], INPUT);
  }
}

boolean isButtonPressed(){
  for(int i = 0; i < AMOUNTBUTTONS; i++){
    if(digitalRead(BUTTONPINS[i])){
      lastButtonPressed = BUTTONPINS[i];
      return true;
    }
  }
  return false;
}

int getLastButtonPressed(){
  return lastButtonPressed;
}
