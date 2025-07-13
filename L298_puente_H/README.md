# L298NMotor

**Librería para controlar dos motores DC con el puente H L298N. Incluye ramp-up y ramp-down, con velocidad configurable en porcentaje (0-100).**

## Instalación

1. Descarga la carpeta `L298NMotor` y colócala dentro de tu directorio `libraries` de Arduino.
2. Reinicia el IDE de Arduino.
3. Incluye la librería en tu sketch con:

```cpp
#include <L298NMotor.h>
```

## Cómo usar

### Motores DC

```cpp
L298NMotor motorA(IN1, IN2, ENA); // Pines del puente H
L298NMotor motorB(IN3, IN4, ENB); // Pines para el segundo motor
```

#### Encender y apagar el motor

```cpp
motorA.run(FORWARD, 80); // Motor adelante, velocidad 80% (0-100)
motorA.run(BACKWARD, 60); // Motor atrás, velocidad 60%
motorA.stop(); // Apaga el motor
```

#### Encender por tiempo definido

```cpp
motorB.runForDuration(FORWARD, 100, 1500); // Adelante al 100% por 1.5 segundos
```

#### Ramp-up y ramp-down

Permiten acelerar o frenar el motor suavemente, con velocidad en porcentaje y pasos configurables:

```cpp
// Ramp-up: acelera progresivamente hasta velocidad final
motorA.rampUp(FORWARD, 80, 30, 10); // Sentido, velocidad final, delay entre pasos (ms), incremento (%)
motorA.rampDown(FORWARD, 80, 30, 10); // Sentido, velocidad inicial, delay entre pasos (ms), decremento (%)
```

## Ejemplo completo

```cpp
#include <L298NMotor.h>

L298NMotor motorA(2, 3, 5);
L298NMotor motorB(4, 7, 6);

void setup() {
  motorA.rampUp(FORWARD, 80, 30, 10);
  delay(1000);
  motorA.rampDown(FORWARD, 80, 30, 10);

  motorB.run(FORWARD, 60);
  delay(1500);
  motorB.stop();
}

void loop() {
  // Tu lógica aquí
}
```

## Parámetros importantes

- **direction**: `FORWARD` o `BACKWARD` (enum para sentido de giro)
- **speedPercent**: Velocidad en porcentaje (0-100)
- **stepDelay**: Tiempo entre cada aumento/disminución de velocidad (ms)
- **stepPercent**: Incremento/decremento en cada paso de ramp-up/ramp-down (%)

## Notas

- Verifica la conexión de los pines IN1, IN2, ENA, IN3, IN4, ENB según tu puente H.
- Puedes controlar dos motores DC simultáneamente.

## Créditos

Desarrollado por [Tu Nombre].

---

¿Necesitas ayuda o quieres sugerir mejoras? ¡Envía un issue o pull request!