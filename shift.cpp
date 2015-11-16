#include "Arduino.h"
#include "shift.h"

shift::shift(int SER_Pin,int RCLK_Pin,int SRCLK_Pin,int NUM_Shift)
{
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  cr();
  _SER_Pin = SER_Pin;
  _RCLK_Pin = RCLK_Pin;
  _SRCLK_Pin = SRCLK_Pin;
  _NUM_Pins = NUM_Shift * 8;
  _registers = new bool[_NUM_Pins]; // A onda ovjde kazemo da je to ustvari array sa _NUM_Pins size
}
void shift::cr(){
  sall(HIGH);
  }

void shift::wr(){
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
void shift::sr(int index, int value){
  _registers[index] = value;
   wr();
}

void shift::sall(int valuee){
  for(int i = _NUM_Pins - 1; i >=  0; i--){
     _registers[i] = valuee;
	 wr();
  }
}
void shift::sh(int time, int poz){
	
	sall(HIGH);
	if(poz == 1){
  for(int i = _NUM_Pins - _NUM_Pins; i <= 15; i++){
     sr(i,LOW);
	 delay(time);
  }
	}
	else if(poz == 0){
		for(int i = _NUM_Pins -1; i >=0; i--){
     sr(i,LOW);
	 delay(time);
  }
		}
else{
	sall(HIGH);
}
}