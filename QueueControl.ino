const int QUEUESIZE = 3;
int queue[QUEUESIZE] = {-1,-1,-1};

int getFirstInQueue(){
  return queue[0];
}

void removeFirstInQueue(){
  int save;
  queue[0] = -1; 
  for(int i = 1; i < QUEUESIZE; i++){
    if(queue[i] == -1){
      continue;
    }
    else{
      save = queue[i];
      queue[i-1] = save;
      queue[i] = -1;
    }
  }
}

boolean isInQueue(int button){
  boolean inQueue = false;
  for(int i = 0; i < QUEUESIZE; i++){
    if(queue[i] == button){
      inQueue = true;
      break;
    }
  }
  return inQueue;
}

void putInQueue(int button){
  for(int i = 0; i < QUEUESIZE; i++){
    if(queue[i] == -1){
      queue[i] = button;
      break;
    }
  }
}
