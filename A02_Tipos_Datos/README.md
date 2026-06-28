# Programación en C: Entendiendo la Memoria (Tipos de Datos)

## ¿Por qué en micros sí importa el tamaño?

Si recuerdan sus clases de programación básica en la compu, seguro se acostumbraron a usar `int` para absolutamente todo. ¿Un contador del 1 al 10? `int`. ¿La edad de una persona? `int`. ¿El estado de un LED (0 o 1)? `int`. En una PC esto da igual porque te sobran Gigabytes de RAM, pero en un microcontrolador la memoria RAM se mide en **Kilobytes** (KB). Si desperdicias memoria, su código se va a quedar sin espacio más rápido de lo que les toma compilarlo.

Programar sistemas embebidos es como empacar una mochila para ir al cerro: no vas a cargar una chamarra de nieve estorbosa si vas a la playa. Hay que elegir el tipo de dato exacto para cada variable o el chip se va a quedar sin aire.

---
## El peligro de los tipos estándar (`int`, `short`, `long`)

El problema principal de C es que el tamaño de un `int` **no es fijo**; cambia dependiendo de la arquitectura del microcontrolador que estemos usando:
* En un Arduino Uno (8 bits), un `int` ocupa **2 bytes** (16 bits).
* En un ESP32 o STM32 (32 bits), un `int` ocupa **4 bytes** (32 bits).

Si ustedes programan su código pensando que el `int` les va a aguantar cierta cantidad y luego migran a otra placa, todo se va a bugear bien feo. Para evitar esto, en el desarrollo profesional usamos la librería `<stdint.h>`, la cual define tipos de datos con un **tamaño fijo garantizado**. 

Para que no anden adivinando cuánta memoria están gastando, aquí está la tabla completa (incluyendo texto y booleanos):

| Tipo de Dato | Bytes | Rango de Valores | ¿Cuándo usarlo en el micro? |
| :--- | :---: | :--- | :--- |
| `bool` | 1 | `true` (1) o `false` (0) | Banderas lógicas binarias (Ocupa incluir `<stdbool.h>`). |
| `char` | 1 | `-128` a `127` o código ASCII | Un solo carácter ('A', '7', '\n'). |
| `char[]` (String) | Varía | Cadena de caracteres | Nombres de comandos, texto para pantallas LCD o tramas. |
| `uint8_t` | 1 | `0` a `255` | Pines digitales, estados (ON/OFF), banderas (*flags*). |
| `int8_t` | 1 | `-128` a `127` | Lecturas de temperatura pequeñas que bajen de cero. |
| `uint16_t` | 2 | `0` a `65,535` | Valores de ADC de 10/12 bits o lectura de sensores comunes. |
| `int16_t` | 2 | `-32,768` a `32,767` | Sensores de aceleración/giroscopio que dan valores negativos. |
| `uint32_t` | 4 | `0` a `4,294,967,295` | Contadores de tiempo (`millis()`), direcciones de memoria. |
| `float` | 4 | Decimales estándar | Operaciones matemáticas complejas (fórmulas o filtros). |

---

## Recomendaciones

Para que luego no me digan que su código "mágicamente" dejó de funcionar y no saben por qué:

_1. Desbordamiento_

¿Qué pasa si tienes un vaso de agua lleno y le sigues echando más? Se desborda. En los micros pasa igual. Si a un `uint8_t` que ya vale `255` le sumas un `1`, no va a pasar a 256... **¡se va a reiniciar a 0!** Esto rompe los ciclos y las condiciones porque el micro no te va a mandar un error; simplemente va a actuar como si nada.

Ejemplo de bug:

```c
uint8_t contador = 250;
while(contador < 260) { // BUG: Nunca va a llegar a 260
    contador++;         // Al llegar a 255 se reinicia a 0 y el ciclo se vuelve infinito
}
```

_2. Usar float para todo_

Hacer operaciones con float es lento. El procesador tiene que hacer como 20 pasos para sumar dos decimales, mientras que los enteros los procesa en un solo ciclo de reloj.

Si van a medir un voltaje de 3.27 V, no usen float voltaje = 3.27;. Mejor guárdenlo en milivoltios como un entero: uint16_t voltaje_mv = 3270;. Y ya al final según su aplicación realizan el procesamiento de datos.

_3. Cuidado con olvidar el signo_

Si declaran una variable con la "u" al principio (uint16_t) significa que no tiene signo (solo positivos). Si intentan restarle de más esperando un número negativo, van a romper la lógica del programa. Si a 0 le restas 1 en un uint16_t, el resultado que te va a dar es 65535. Si ocupan valores bajo cero, usen los que empiezan con int a secas.

Ejemplo de bug:

```c
uint16_t nivel_agua = 0;
nivel_agua = nivel_agua - 1; 
// Resultado real en el micro: 65535 (No -1)
```

---

## RESUMEN DE MEMORIA

Los conozco, y sé que verán mucho texto y seguramente su autismo no les deje continuar, tampoco les puedo poner un video de ASMR de fondo, pero aquí tienen el acordeón:

```
===================================================================
         GUÍA RÁPIDA DE SELECCIÓN DE DATOS EN C
===================================================================
* ¿Es un pin digital (0 o 1) o un estado lógico de una bandera?
  -> bool led_encendido = true; // Requiere <stdbool.h>

* ¿Es una sola letra o un comando de un solo carácter?
  -> char comando = 'S'; // Va con comillas simples ''

* ¿Es un texto completo para mandar por puerto serie?
  -> char texto[] = "ERROR_TEMP"; // Va con comillas dobles ""

* ¿Es un valor analógico de un sensor (por ejemplo, de 0 a 1023)?
  -> uint16_t lectura_adc = 512;

* ¿Es para contar el tiempo en milisegundos y ocupo que no se sature?
  -> uint32_t tiempo_previo = 0;

* ¿A fuerza ocupo decimales y no puedo transformarlo a milivoltios?
  -> float factor_calibracion = 1.4142;
===================================================================

```

 **Pd:** Si tienen dudas me avisan muchachos. 

> Redactado por: **Amezcua**
