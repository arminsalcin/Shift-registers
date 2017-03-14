#include <shift.h>

Shift Shift (16,5,4,1);// Shift(SER_Pin,RCLK_Pin,SRCLK_Pin,NUM_Shift);
void setup() {
 
}

void loop() {

Shift.setRegister(5,1); //turn HIGH pin 5 on shift register

}
