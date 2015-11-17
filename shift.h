#ifndef SHIFT_H
#define SHIFT_H

#include "Arduino.h"

class Shift {
public:
    Shift(int _SER_pin, int _RCLK_pin, int _SRCLK_pin, int _numberOfShifts);
    ~Shift();

    void clearRegisters();
    void writeRegisters();


    void setRegister(int index, int value); // setting register,index(number of register) , and value (LOW or HIGH)
    void setAll(int value); // set all registers to value(HIGH or LOW)
    void shiftOneByOne(int delay, int position); // shifting outputs , time(delay) and poz (1= from first to last , 0= from last to first)
private:
    int SER_pin;
    int RCLK_pin;
    int SRCLK_pin;
    int numberOfShifts;
    int numberOfPins;
    bool *registers; // Posto ne znamo velicinu array-a na headeru definisemo ga kao pointer
};

#endif //SHIFT_H
