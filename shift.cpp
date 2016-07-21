#include "Arduino.h"
#include "shift.h"

Shift::Shift(int SER_Pin,int RCLK_Pin,int SRCLK_Pin,int NUM_Shift)
 {
   pinMode(SER_Pin, OUTPUT);
   pinMode(RCLK_Pin, OUTPUT);
   pinMode(SRCLK_Pin, OUTPUT);
   clearAll();
   _SER_Pin = SER_Pin;
   _RCLK_Pin = RCLK_Pin;
   _SRCLK_Pin = SRCLK_Pin;
   _NUM_Pins = NUM_Shift * 8;
   _registers = new bool[_NUM_Pins]; // A onda ovjde kazemo da je to ustvari array sa _NUM_Pins size
}

void Shift::clearAll(){
   setAll(0);
   }
 
 void Shift::wr(){
   int i;
   digitalWrite(_RCLK_Pin, LOW);
   for(int i = _NUM_Pins - 1; i >=  0; i--){
     digitalWrite(_SRCLK_Pin, LOW);
     int val = _registers[i];
    digitalWrite(_SER_Pin, val);
     digitalWrite(_SRCLK_Pin, HIGH);
  }
   digitalWrite(_RCLK_Pin, HIGH);
}

void Shift::setRegister(int index, int value){
  _registers[index] = value;
   wr();
}

void Shift::setAll(int valuee){
  for(int i = _NUM_Pins - 1; i >=  0; i--){
     _registers[i] = valuee;
   wr();
   }}

void Shift::oneByOne(int time, int poz){
   int x = _NUM_Pins; 
  setAll(0);
  if(poz == 1){
   for(int i = 0; i <=x; i++){
      setRegister(i,1);
    delay(time);
  setRegister(i,0);
}
   }
   
   else if(poz == 0){
   for(int i = _NUM_Pins -1; i >=0; i--){
      setRegister(i,1);
    delay(time);
    setRegister(i,0);
   }
   }
 else{
  setAll(0);
}
}