#include "Arduino.h"
#include "shift.h"

Shift::Shift(int _SER_pin, int _RCLK_pin, int _SRCLK_pin, int _numberOfShifts) {
    clearRegisters();

    SER_pin = _SER_pin;
    RCLK_pin = _RCLK_pin;
    SRCLK_pin = _SRCLK_pin;

    pinMode(SER_pin, OUTPUT);
    pinMode(RCLK_pin, OUTPUT);
    pinMode(SRCLK_pin, OUTPUT);

    numberOfPins = numberOfShifts * 8;
    registers = new bool[numberOfPins];
}

Shift::~Shift() {
    delete[] registers;
}

void Shift::clearRegisters() {
    setAll(HIGH);
}

void Shift::writeRegisters() {
    int i;

    digitalWrite(RCLK_pin, LOW);

    for (int i = numberOfPins - 1; i >= 0; i--) {
        digitalWrite(SRCLK_pin, LOW);

        int val = registers[i];

        digitalWrite(SER_pin, val);
        digitalWrite(SRCLK_pin, HIGH);
    }

    digitalWrite(RCLK_pin, HIGH);
}

void Shift::setRegister(int index, int value) {
    registers[index] = value;
    writeRegisters();
}

void Shift::setAll(int value) {
    for (int i = numberOfPins - 1; i >= 0; i--) {
        registers[i] = value;
    }

    writeRegisters();
}

void Shift::shiftOneByOne(int time, int position) {
    setAll(HIGH);

    if (position == 1) {
        for (int i = 0; i <= numberOfPins; i++) {
            setRegister(i, LOW);
            delay(time);
            setRegister(i, HIGH);
        }
    }
    else if (position == 0) {
        for (int i = numberOfPins - 1; i >= 0; i--) {
            setRegister(i, LOW);
            delay(time);
            setRegister(i, HIGH);
        }
        setAll(HIGH);
    }
    else {
        setAll(HIGH);
    }
}