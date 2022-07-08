const int GREENTIME = 7 * getMillisPerSecond();
const int YELLOWTIME = 3 * getMillisPerSecond();
const int WALKTIME = 2 * getMillisPerSecond();
const int COUNTDOWNTIME = 1 * getMillisPerSecond();
const int SILENCETIME = 5 * getMillisPerSecond();

const int RUST = 0;
const int STOPLICHT_GO = 1;
const int STOPLICHT_STOP = 2;
const int HEFBOOM_STARTUP = 3;
const int HEFBOOM_WALK = 4;
const int HEFBOOM_COUNTDOWN = 5;
const int HEFBOOM_STOP = 6;
const int SILENCE = 7;

int state;

void setState(int givenState){
  state = givenState;
  statusTransition();
}

void StateMachineSetup(){
  setState(RUST);
}

void setStateStoplicht(){
  setState(STOPLICHT_GO);
}

void setStateHefboom(){
  setState(HEFBOOM_STARTUP);
}

void statusTransition(){
  switch(state){
    case RUST:
      rust_Entry();
      break;

    case STOPLICHT_GO:
      stoplicht_Go_Entry();
      break;

    case STOPLICHT_STOP:
      stoplicht_Stop_Entry();
      break;
      
    case HEFBOOM_WALK:
      hefboom_Walk_Entry();
      break;

    case HEFBOOM_COUNTDOWN:
      hefboom_Countdown_Entry();
      break;

    case HEFBOOM_STOP:
      hefboom_Stop_Entry();
      break;
      
    case SILENCE:
      silence_Entry();
      break;
  }
}

void statusLoop(){
  switch(state){
    case STOPLICHT_GO:
      if(getTimer() >= GREENTIME){
        stoplicht_Go_Exit();
        setState(STOPLICHT_STOP);
        stoplicht_stop_entry();
      }
      break;
      
    case STOPLICHT_STOP:
      if(getTimer() >= YELLOWTIME){
          stoplicht_Stop_Exit();
          setState(SILENCE);
        }
      break;

    case HEFBOOM_STARTUP:
      hefboom_Startup_Do();
      if(isHefboomOmhoog()){
        setState(HEFBOOM_WALK);
      }
      break;

    case HEFBOOM_WALK:
      hefboom_Walk_Do();
      if(getTimer() >= WALKTIME){
        hefboom_Walk_Exit();
        setState(HEFBOOM_COUNTDOWN);
      }
      break;
      
    case HEFBOOM_COUNTDOWN:
      if(countdown == 0){
        hefboom_Countdown_Exit();
        setState(HEFBOOM_STOP);
      }
      else if(getTimer() >= COUNTDOWNTIME){
        hefboom_Countdown_Entry();
      }
      break;
      
      case HEFBOOM_STOP:
        hefboom_Stop_Do();
        if(isHefboomOmlaag()){
          setState(SILENCE);
        }
        break;
      
    case SILENCE:
      if(getTimer() >= SILENCETIME){
        setState(RUST);
      }
      break;
  }
}
