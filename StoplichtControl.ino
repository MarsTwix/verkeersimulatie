const int AANTALKANTEN = 2;
const int AANTALKLEUREN = 3;

const int STOPLICTENPINS[AANTALKANTEN][AANTALKLEUREN] = {
  {13,12,11},
  {10,9,8}
};

void stoplichtSetup(){
  for(int i = 0; i <AANTALKANTEN; i++){
    for(int j = 0; j <AANTALKLEUREN; j++){
      pinMode(STOPLICTENPINS[i][j], OUTPUT);
    }
  }
}

void stoplichtOn(int kant, int kleur){
  pinOn(STOPLICTENPINS[kant][kleur]);
}

void stoplichtOff(int kant, int kleur){
  pinOff(STOPLICTENPINS[kant][kleur]);
}
