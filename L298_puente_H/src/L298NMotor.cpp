#include "Arduino.h"
#include "L298NMotor.h"

// Conversión de porcentaje (0-100) a PWM (0-255)
uint8_t L298NMotor::percentToPWM(uint8_t percent) {
  if (percent > 100) percent = 100;
  return map(percent, 0, 100, 0, 255);
}

// ------- DC Motor -------
L298NMotor::L298NMotor(uint8_t pinIn1, uint8_t pinIn2, uint8_t pinEn) {
  _pinIn1 = pinIn1;
  _pinIn2 = pinIn2;
  _pinEn = pinEn;
  _running = false;
  pinMode(_pinIn1, OUTPUT);
  pinMode(_pinIn2, OUTPUT);
  pinMode(_pinEn, OUTPUT);
  stop();
}

void L298NMotor::run(MotorDirection direction, uint8_t speedPercent) {
  if (direction == FORWARD) {
    digitalWrite(_pinIn1, HIGH);
    digitalWrite(_pinIn2, LOW);
  } else {
    digitalWrite(_pinIn1, LOW);
    digitalWrite(_pinIn2, HIGH);
  }
  analogWrite(_pinEn, percentToPWM(speedPercent));
  _running = true;
}

void L298NMotor::stop() {
  digitalWrite(_pinIn1, LOW);
  digitalWrite(_pinIn2, LOW);
  analogWrite(_pinEn, 0);
  _running = false;
}

void L298NMotor::runForDuration(MotorDirection direction, uint8_t speedPercent, unsigned long ms) {
  run(direction, speedPercent);
  delay(ms);
  stop();
}

bool L298NMotor::isRunning() {
  return _running;
}

void L298NMotor::rampUp(MotorDirection direction, uint8_t finalPercent, unsigned int stepDelay, uint8_t stepPercent) {
  for (uint8_t percent = 0; percent <= finalPercent; percent += stepPercent) {
    run(direction, percent);
    delay(stepDelay);
  }
  run(direction, finalPercent);
}

void L298NMotor::rampDown(MotorDirection direction, uint8_t initialPercent, unsigned int stepDelay, uint8_t stepPercent) {
  for (int percent = initialPercent; percent >= 0; percent -= stepPercent) {
    run(direction, percent);
    delay(stepDelay);
  }
  stop();
}

