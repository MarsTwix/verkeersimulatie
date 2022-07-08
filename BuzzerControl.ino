const int BUZZERPIN = 7;
const int TONE = 1000;
const int BUZZERONTIME = 50;
boolean timerSet = false;
boolean timerOnSet = true;
boolean isBuzzerOn = false;
boolean ticced = false;

void buzzerSetup(){
  pinMode(BUZZERPIN, OUTPUT);
}

void buzzerOn(){
  tone(BUZZERPIN, TONE);
}

void buzzerOff(){
 noTone(BUZZERPIN);
}

void buzzerTic(int buzzerTime, int buzzerOnTime){
    if(!timerSet){
      startBuzzerTimer();
      timerSet = true;
    }

    if(!timerOnSet){
      startBuzzerTimer();
      timerOnSet = true;
    }
    
    if(getBuzzerTimer() >= buzzerTime && !isBuzzerOn){
      buzzerOn();
      timerOnSet = false;
      isBuzzerOn = true;
    }
    else if(getBuzzerTimer() >= buzzerOnTime && isBuzzerOn){
      buzzerOff();
      isBuzzerOn = false;
      timerSet = false;
      ticced = true;
    }
}

void setIsTicced(boolean b){
  ticced = b;
}

boolean isTicced(){
  return ticced;
}

int getBuzzerOnTime(){
  return BUZZERONTIME;
}
