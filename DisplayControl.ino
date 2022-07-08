const int AMOUNTTEKENS = 8;

int const SH_CP_PIN = 5;
int const ST_CP_PIN = 4;
int const DS_PIN = 3;

const byte BITTEKEN[AMOUNTTEKENS] = {B11011010, B00001100, B10110110, B10011110, B11001100, B11011010, B11111010, B01110000};

void displaySetup(){
  pinMode(SH_CP_PIN, OUTPUT);
  pinMode(ST_CP_PIN, OUTPUT);
  pinMode(DS_PIN, OUTPUT);
}

void lightBitPattern(int index){
  byte bitPattern = BITTEKEN[index];
  boolean bitCheck = false;
  for(int i = 0; i < 8; i++){
    bitCheck = isBitOn(bitPattern, i);
    
    if(bitCheck){
      pinOn(DS_PIN);
    }
    
    pinOn(SH_CP_PIN);
    
    if(bitCheck){
      pinOff(DS_PIN);
    }
    
    pinOff(SH_CP_PIN);
  }
  pinOn(ST_CP_PIN);
  
  pinOff(ST_CP_PIN);
}

boolean isBitOn(byte bitVolgorde, int index){
  return (bitVolgorde >> index) & 001 == B1;
}
