#include <shift.h>
int number_of_shiftergisters = 1;
Shift Shift (16,5,4,number_of_shiftergisters);// Shift(SER_Pin,RCLK_Pin,SRCLK_Pin,NUM_Shift);
void setup() {
 
}

void loop() {

Shift.setRegister(5,1); //turn HIGH pin 5 on shift register
delay(1000);
Shift.setRegister(5,0);
}
