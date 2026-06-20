Para comprender lo que son las operaciones de bits, necesariamente deben tener conocimiento sobre lógica o sistemas binarios. Con lo que se les ha dejado en ejemplos anteriores sería suficiente para que puedan desarrollar sus prácticas de microcontroladores; pero si quieren ir aprendiendo cómo es que se hacen realmente las cosas, pasemos al siguiente nivel.

### ¿Qué es un registro?

Cuando trabajamos en una computadora o un microcontrolador, no estamos interactuando con números decimales; en realidad, estamos trabajando con señales eléctricas de voltaje:

* **5V o 3.3V** equivalen a un estado lógico alto (**1**).
* **0V (GND)** equivale a un estado lógico bajo (**0**).

Cuando declaramos variables optimizadas de 8 bits (`uint8_t`), en el microcontrolador se le asigna un **registro de hardware**. Imaginen que el registro es como una caja que contiene exactamente 8 interruptores electrónicos llamados *Flip-Flops* (esto lo vieron o verán en la materia de Digitales). Cada interruptor controla o lee un pin físico del chip.

Las aplicaciones de las operaciones de bits en microcontroladores las encontraremos cuando dejamos de pensar en variables de software y comenzamos a interactuar directamente con el mapa de memoria física. En el hardware, los fabricantes organizan las patitas del microcontrolador en grupos de 8 bits llamados **Puertos**. Cada puerto tiene asignado su propio registro de control en la memoria RAM.

Ya sea que hablemos de microcontroladores PIC o de los chips de Arduino (como el ATmega328P), muchas veces se manejan arquitecturas de 8 bits. Para controlar un puerto físico se usan principalmente 3 registros dedicados:

* **Registro de Dirección (`TRIS` o `DDR`):** Configura cada pin del puerto según cómo va a actuar; como una **Entrada** (`1`, de *Input*) para leer sensores, o como una **Salida** (`0`, de *Output*) para enviar corriente a motores o luces.
* **Registro de Salida (`PORT` o `LAT`):** Controla el voltaje físico que sale de la patita del chip. Poner un bit en `1` saca 5V o 3.3V, mientras que ponerlo en `0` conecta el pin a GND (0V).
* **Registro de Entrada (`PIN` o `PORT`):** Mapea el voltaje que entra desde el exterior al microcontrolador para saber, por ejemplo, si un botón físico está presionado.

Esto suele ser confuso al comienzo, pero más adelante verán cómo se aplica mediante código y entenderán perfectamente todo el contexto.