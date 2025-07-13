#include <L298NMotor.h>

// Definir pines para el motor
const uint8_t PIN_IN1 = 2;
const uint8_t PIN_IN2 = 3;
const uint8_t PIN_ENA = 5;

// Crear instancia del motor
L298NMotor motor(PIN_IN1, PIN_IN2, PIN_ENA);

void setup() {
  Serial.begin(9600);
  Serial.println("Test de Motor DC con L298N");
  
  // Prueba de rampa de aceleración
  Serial.println("Acelerando...");
  motor.rampUp(FORWARD, 100, 50, 10);
  delay(2000);
  
  // Prueba de rampa de desaceleración
  Serial.println("Desacelerando...");
  motor.rampDown(FORWARD, 100, 50, 10);
  delay(1000);
  
  // Prueba de velocidad constante
  Serial.println("Velocidad constante...");
  motor.run(FORWARD, 75);
  delay(2000);
  
  // Detener motor
  Serial.println("Deteniendo...");
  motor.stop();
}

void loop() {
  // El ejemplo termina en setup()
}
