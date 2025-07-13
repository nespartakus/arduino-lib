#ifndef L298NMotor_h
#define L298NMotor_h

#include "Arduino.h"

// Enum para el sentido de giro
enum MotorDirection {
  FORWARD,
  BACKWARD
};

// Clase para motor DC
class L298NMotor {
  public:
    L298NMotor(uint8_t pinIn1, uint8_t pinIn2, uint8_t pinEn);
    void run(MotorDirection direction, uint8_t speedPercent = 100); // velocidad en porcentaje
    void stop();
    void runForDuration(MotorDirection direction, uint8_t speedPercent, unsigned long ms);
    bool isRunning();
    void rampUp(MotorDirection direction, uint8_t finalPercent, unsigned int stepDelay = 20, uint8_t stepPercent = 5);
    void rampDown(MotorDirection direction, uint8_t initialPercent, unsigned int stepDelay = 20, uint8_t stepPercent = 5);

  private:
    uint8_t _pinIn1, _pinIn2, _pinEn;
    bool _running;
    uint8_t percentToPWM(uint8_t percent);
};

#endif