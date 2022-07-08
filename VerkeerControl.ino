boolean busy;
boolean busyHefboom;
boolean isCountdown;
boolean firstTic;
int tics = 0;
const float TICTIME = 0.2 * getMillisPerSecond();
const float QUICKTICSTIME = 0.8 * getMillisPerSecond();
const float ADDEDBREAKTIME = 0.2 * getMillisPerSecond();
int currentQuickTicsTime = QUICKTICSTIME;
const int BUZZERLOOPTIME = 2000;

void verkeerSetup(){
  hefboomSetup();
  serialSetup();
  stoplichtSetup();
  buttonSetup();
  displaySetup();
  buzzerSetup();
  StateMachineSetup();
}

void verkeerLoop(){
  ticLoop();
  quickTicsLoop();
  statusLoop();
  serialLoop();
  buttonPressedCheck();
  checkNextAction();
}

void buttonPressedCheck(){
  
  if(isButtonPressed()){
    int buttonPressed = getLastButtonPressed();
    if(!isInQueue(buttonPressed)){
      putInQueue(buttonPressed);
    }
  }
}

void checkNextAction(){
  if(!busy){
      if(getFirstInQueue() != -1){
        busySide = getFirstInQueue() - 14;
        if(busySide < 2 ){
          setStateStoplicht();
        }
        
        else if(busySide == 2) {
          setStateHefboom();
          busyHefboom = true;
          setIsTicced(false);
        }
        
        busy = true;
      }
    }
}
void ticLoop(){
  if(!busyHefboom){
    buzzerTic(BUZZERLOOPTIME,getBuzzerOnTime());
  } 
}

void quickTicsLoop(){
  if(isCountdown){
    if(isTicced()){
      tics++;
      setIsTicced(false);
    }
    if(tics == 1){
      firstTic = true;
    }
    else if(tics == 3){
      firstTic = false;
      tics = 0;
      currentQuickTicsTime += ADDEDBREAKTIME;
    }
    if(firstTic){
      buzzerTic(TICTIME, getBuzzerOnTime());
    }
    else{
      buzzerTic(currentQuickTicsTime, getBuzzerOnTime());
    }
  }
}

void resetCurrentQuickTicsTime(){
  currentQuickTicsTime = QUICKTICSTIME;
}


void setBusy(boolean b){
  busy = b;
}

void setHefboomBusy(boolean b){
  busyHefboom = b;
}

void setIsCountdown(boolean b){
  isCountdown = b;
}
