const int BUZZERWALKTIME = 0.2 * getMillisPerSecond();
const int LINKS = 0;
const int RECHTS = 1;

const int GREEN = 0;
const int YELLOW = 1;
const int RED = 2;

const int LOPEN = 7;
const int STOP = 0;

int busySide;
int countdown = 7;

void rust_Entry(){
  stoplichtOn(LINKS, RED);
  stoplichtOn(RECHTS, RED);
  lightBitPattern(STOP);
  setBusy(false);
}

void stoplicht_Go_Entry(){
  stoplichtOff(busySide, RED);
  stoplichtOn(busySide, GREEN);
  startTimer();
}

void stoplicht_Go_Exit(){
  stoplichtOff(busySide, GREEN);
}

void stoplicht_Stop_Entry(){
  stoplichtOn(busySide, YELLOW);
  startTimer();
}

void stoplicht_Stop_Exit(){
  stoplichtOff(busySide, YELLOW);
  stoplichtOn(busySide, RED);
}

void hefboom_Startup_Do(){
  hefboomOmhoog();
}

void hefboom_Walk_Entry(){
  lightBitPattern(LOPEN);
  startTimer();
}

void hefboom_Walk_Do(){
  buzzerTic(BUZZERWALKTIME, getBuzzerOnTime());
}

void hefboom_Walk_Exit(){
  buzzerOff();
}

void hefboom_Countdown_Entry(){
  setIsCountdown(true);
  countdown--;
  lightBitPattern(countdown);
  startTimer();
}

void hefboom_Countdown_Exit(){
  setIsCountdown(false);
  resetCurrentQuickTicsTime();
}

void hefboom_Stop_Entry(){
  countdown = 7;
  buzzerOff();
  lightBitPattern(STOP);
  setHefboomBusy(false);
}

void hefboom_Stop_Do(){
  hefboomOmlaag();
}

void silence_Entry(){
  startTimer();
  removeFirstInQueue();
}
