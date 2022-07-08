const int SERVOHIGHPOS = 90;
const int SERVOLOWPOS = 0;
const int SERVOPIN = 6;
const int SERVOMOVETIME = 20;

int currentServoPos = 0;
boolean isTimerStarted = false;

Servo servo;

void hefboomSetup(){
  servo.attach(SERVOPIN);
  setServoPos(0);
}

void setServoPos(int pos){
  servo.write(pos);
  currentServoPos = pos;
  
}

void hefboomOmhoog(){
  if(!isHefboomOmhoog()){
    if(isTimerStarted && getTimer() >= SERVOMOVETIME){
      setServoPos(currentServoPos+1);
      isTimerStarted = false;
    }

    else if (!isTimerStarted){
      
      startTimer();
      isTimerStarted = true;
    }
  }
}

void hefboomOmlaag(){
  
  if(!isHefboomOmlaag()){
    
    if(isTimerStarted && getTimer() >= SERVOMOVETIME){
      setServoPos(currentServoPos-1);
      isTimerStarted = false;
    }

    else if (!isTimerStarted){
      startTimer();
      isTimerStarted = true;
    }
  }
}

boolean isHefboomOmhoog(){
  return SERVOHIGHPOS <= currentServoPos;
}

boolean isHefboomOmlaag(){
  return SERVOLOWPOS >= currentServoPos;
}
