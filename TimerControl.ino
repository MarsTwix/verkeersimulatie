const int MILLISPERSECOND = 1000;
unsigned long currentMillis = 0;
unsigned long startMillis = 0;
unsigned long startBuzzerMillis = 0;

void startTimer(){
  startMillis = millis();
}

unsigned long getTimer(){
  currentMillis = millis();
  return currentMillis - startMillis;
}

void startBuzzerTimer(){
  startBuzzerMillis = millis();
}

unsigned long getBuzzerTimer(){
  currentMillis = millis();
  return currentMillis - startBuzzerMillis;
}

int getMillisPerSecond(){
  return MILLISPERSECOND;
}
