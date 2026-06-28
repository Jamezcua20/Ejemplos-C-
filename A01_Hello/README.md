# Programación en C: primeros pasos

## ¿Para qué sirve <stdio.h>?

Si recuerdan sus clases de programación básica en C++, recordarán que antes usabamos la biblioteca `<iostream>` junto con funciones como `cin`, `cout`, etc. En microcontroladores no tenemos el lujo de desperdiciar memoria con flujos de objetos grandes. Es por eso que aquí jugamos mucho con la optimización.

Para comunicarnos con el exterior, ya sea una pantalla LCD, un puerto serie (UART) o la terminal de la compu, usamos la librería estándar <stdio.h> (Standard Input/Output). Considérenla como el puente que toma las variables raras de la memoria RAM del chip y las traduce a un formato que un humano pueda leer.

---
## Nuestra herramienta principal: `printf(""); ` 

La función que van a usar dentro de esta materia y en adelante para depurar registros, revisar estados de variables o mandar alertas es printf. Su trabajo es agarrar texto, combinarlo con los valores de tus variables y enviarlo formateado hacia la consola.

EL problema, es que aquí es donde muchos reprueban o se les bugea el microcontrolador. Como estamos programando sistemas embebidos, el compilador exige que seamos estrictamente específicos con el tipo de dato que vamos a imprimir. Si usan el especificador de dato incorrecto, el micro va a leer basura de la memoria RAM o, peor aún, les va a tirar un Hard Fault (o en otras palabras, tendrán un pisa papeles bonito hasta que carguen un código sin bugs).

Para que no se rompan la cabeza adivinando, aquí les dejo la tabla de los que usaremos en las prácticas: (En el siguiente segmento les explicaré los tipos de datos, pero aquí se los pongo para que puedan imprimirlos).

| Tipo de Dato | Especificador | Uso típico en el Microcontrolador |
| :--- | :--- | :--- |
| `int` (Entero estándar) | `%d` o `%i` | Contadores generales en ciclos `for`. |
| `float` (Punto flotante) | `%f` | Lecturas analógicas (Voltajes, sensores). |
| `uint8_t` (Un byte / 8 bits) | `%hhu` | Banderas (*flags*), pines o estados lógicos. |
| `uint16_t` (Dos bytes / 16 bits) | `%hu` | Registros de temporizadores (*Timers*) o tramas cortas. |
| `uint32_t` (Cuatro bytes / 32 bits) | `%u` | Contadores de tiempo de alta precisión (como los `millis`). |

---

## Recomendaciones

Para que sus entregas no parezcan hechas con las patas y luego digan que uno no es buen profe, les dejo algunos consejos:
(La neta nomas les tiro el paro pq son mis amigos, fueran otros les diría que no me acuerdo de C)

_1. El filtro de decimales_

Por defecto, cuando imprimes un `float` con `%f`, el micro les va a llenar la pantalla con seis decimales llenos de ceros (y la neta se ve bien feo). Si solo quieren ver dos decimales limpios, metan un .2 entre el porcentaje y la efe, este número puede ser modificado según la precisión que requieran:

Ejemplo: 

```c
float voltaje = 3.2745;
printf("Voltaje del sensor: %.2f V\n", voltaje); 
// Resultado en consola: Voltaje del sensor: 3.27 V
```

_2. ¿Cómo imprimo el símbolo de porcentaje (%)?_

Como ya se habrán dado cuenta, el símbolo % es el comando que usa printf para saber que viene un formato. Si ustedes quieren poner textualmente en la consola un "80%", no pueden ponerlo así nada más porque el compilador se va a quedar esperando una variable.

El truco es duplicarlo (%%).

Ejemplo: 

```c
uint8_t bateria = 85;
printf("Carga del sistema: %hhu%%", bateria);
// Resultado en consola: Carga del sistema: 85%
```

_3. El formato Hexadecimal Técnico (%02X o %04X)_

Esto a mi no me lo enseñaron en clases, y dentro de prácticas no lo llegué a necesitar, pero necesitan saber de buenas prácticas como programadores.

Cuando estén trabajando con registros puros o haciendo operaciones Bitwise (tema que les explico más adelante), ver los números en decimal da flojera y no ayuda a entender qué bit se encendió. Lo ideal es verlo en Hexadecimal (0x).

Usamos %X (con X mayúscula para que las letras A-F salgan en mayúsculas). Si le agregamos un 02 o 04, le estamos diciendo al sistema: "Si el número es muy pequeño, rellena con ceros a la izquierda para mantener el formato de byte limpio".

Ejemplo: 

```c
uint16_t registro_falla = 0x0A3F;
printf("Registro de telemetría: 0x%04X", registro_falla);
// Resultado en consola: Registro de telemetría: 0x0A3F
```
---

## Secuencias de Escape (\)

Cuando mandas datos por el puerto serie (UART) a la compu, el microcontrolador no sabe si quieres separar las lecturas o ponerlas juntas; él solo imprime todo. Para que su terminal no parezca un texto ilegible, usamos las secuencias de escape.

En pocas palabras, la diagonal invertida \ le dice al printf: "Ojo cuate, lo que viene no es texto normal, es una orden de formato físico para la pantalla" y ya la terminal ejecuta la instrucción correspondiente.

Aquí tienen las que van a usar el 99% de las veces:

* `\n` _(Salto de línea)_: Mueve el cursor a la línea de abajo. Si no lo ponen, cada nuevo printf se pegará al final del anterior en una sola línea infinita de la terminal. Es el equivalente al endl de C++.

* `\t` _(Tabulador horizontal)_: Da un espacio largo (como cuatro espacios normales). Sirve un buen para alinear columnas o crear tablitas visuales en la consola sin tener que estar presionando la barra espaciadora como locos.

_Ejemplos:_

Sin `\n`:

```c
printf("Voltaje: 3.3V");
printf("Corriente: 1.2A");
// En la consola saldrá: Voltaje: 3.3VCorriente: 1.2A
```

Con `\n`:

```c
printf("=== TELEMETRÍA ===\n");
printf("Voltaje:\t%.1f V\n", 3.33);
printf("Corriente:\t%.1f A\n", 1.25);
/* En la consola se verá así de limpio:
=== TELEMETRÍA ===
Voltaje:    3.3 V
Corriente:  1.2 A
*/
```


---

## RESUMEN DE IMPRESIÓN

Los conozco, y sé que verán mucho texto y seguramente su autismo no les deje continuar, tampoco les puedo poner un video de ASMR de fondo, pero aquí tienen el acordeón:

```
===================================================================
        GUÍA RÁPIDA DE ESPECIFICADORES EN <stdio.h>
===================================================================
* Quiero imprimir un texto normal sin variables:
  printf("Sistemas embebidos activados.\n");

* Quiero imprimir un contador entero común (int):
  printf("Iteración actual: %d", contador);

* Quiero imprimir un pin o bandera de 8 bits (uint8_t):
  printf("Estado del Pin: %hhu", pin_estado);

* Quiero imprimir un registro de 16 bits en Hexadecimal (uint16_t):
  printf("Trama: 0x%04X", mi_trama);

* Quiero imprimir un voltaje con solo 1 decimal (float):
  printf("Sensor: %0.1f V", lectura);
===================================================================

```

 **Pd:** Si tienen dudas me avisan muchachos. 

> Redactado por: **Amezcua**
