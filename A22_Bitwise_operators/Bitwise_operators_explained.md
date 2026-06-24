Para comprender lo que son las operaciones de bits, necesariamente deben tener conocimiento sobre lógica o sistemas binarios. Con lo que se les ha dejado en ejemplos anteriores sería suficiente para que puedan desarrollar sus prácticas de microcontroladores; pero si quieren ir aprendiendo cómo es que se hacen realmente las cosas, pasemos al siguiente nivel.

Dentro de la memoria RAM de un microcontrolador no existen los números. Lo único que hay sin cajas con interruptores eléctricos.

Una variable de tipo `uint8_t` (un byte) es, literalmente, una caja que contiene 8 interuptores mecánicos alineados de derecha a izquierda.
* Si el interuptor está apagado (0v), el microcontrolador lee un 0.
* Si el interruptor está encendido (5v), el microcontrolador lee un 1.

Los interruptores se numeran estrictamente de derecha a izquierda, empezando por el 0

| Posición del interruptor     | 7     | 6     | 5     | 4     | 3     | 2     | 1     | 0     |
|                         :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Estado físico (Apagados)** | `[0]` | `[0]` | `[0]` | `[0]` | `[0]` | `[0]` | `[0]` | `[0]` |

Cuando tú en C dices `uint8_t registro = 0;`, fisicamente le estás diciendo al chip: "Asegúrate que los 8 interruptores de la cada estén apagados".

Si tú estuvieras programando una computaodra normal y quisieras cambiar el valor de una variable, harías esto: registro = 5;. La computadora borra los 8 interruptores de golpe y acomoda los bits para que sumen 5 (00000101).

Ahora, se deben de estar preguntando, ¿esto por qué no se debe de hacer con microcontroladores?. Bueno, imaginemos por un momento que el interruptor 7 controla el motor que estabiliza un avión por ejemplo, y supongamos que el interruptor 0 controla un Led indicador. Si el motor está encendido (10000000) y le escriben registro ? 5; para encender el Led, van a terminar apagando el motor del avión, y el avión terminaría cayendo.

Las operaciones Bitwise nacieron por una sola razón, modificar o leer un interruptor especifico de la caja, sin alterar o orrar cualquiera de sus números vecinos.

## ¿Cómo usamos las máscaras?

Y no, no me refiero a la máscara del: https://youtu.be/yH2qfNLqfY4.

Para interacturar con el tablero de forma segura, se necesita crear una máscara. Imaginen que toman una hoja de papel sobre de interruptores reales con agujeros en el lugar de los interruptores que van a manipular, de manera que no pueden tocar los demás.

## Operador OR (|) -> Sirve exclusivamente para ENCENDER

Como ya deben de saber, la regla del OR dice que, cualquier cosa comparada contra un 1, se enciende, cualquier cosa comparada contra un 0, se queda igual.

Si ustedes toman una plantilla que tiene un `1` n la posición `3` y ceros en el resto, y le aplicar un `OR`, el regitro resultante quedaría como: 

```text
  1 0 0 0 0 0 0 0 
| 0 0 0 0 1 0 0 0 
------------------
  1 0 0 0 1 0 0 0  (Resultado: La casilla 3 se encendió, ¡y el motor 7 sigue vivo!)
```

Esto suele ser confuso al comienzo, pero más adelante verán cómo se aplica mediante código y entenderán perfectamente todo el contexto.

El `OR` usó los ceros como un scudo protector para los veciones, y usó el uno para forzar el encendido de la casilla deseada.

## Operador AND(&) con NOT(~) -> Sirve exclusivamente para APAGAR

Apagar es más dificil porque necesitas un "filtro destructor". El operaddor `AND` tiene una regla: Cualquier cosa multiplicada por 0 se destruye (se vuelve 0), y cualquier cosa multiplicada por 1 sobrevive.

Si buscamos apagar el interruptor 7, que si retomamos nuestro ejemplo anterior, era un motor, sin apagar nada más, usamos una máscara de bits con el operador `NOT`, que genera una máscara que tiene un 0 en la casilla 7 y puros 1 en el resto (011111111)

Aplicamos el filtro `AND`

```text
  1 0 0 0 1 0 0 0  (Registro: Casilla 7 y 3 encendidas)
& 0 1 1 1 1 1 1 1  (Máscara protectora: Cero en el 7, unos en los demás)
-----------------
  0 0 0 0 1 0 0 0  (Resultado: El motor 7 se apagó, pero la casilla 3 sobrevivió)
```

## Operadores AND (&) solo -> Sirve exlusivamente para LEER

Imaginen que ustedes quieren saber si un interruptor en especifico, en este caso, el 3, está encendido o apagado, y quieren verlo sin que el resto de los números interfiera en tu lectura.

En este caso en especifico, se usa el `AND` con una máscara que tenga un `1` únicamente en la casilla 3 y ceros en todo lo demás (`00001000`). El `AND` multiplicará por cero a todos los números vecinos y dejará pasar solo el valor de la casilla 3.

* Si el interruptor 3 estaba encendido (1): El resultado será `00001000` y el if lo detectará como verdadero.

* Si el interruptor 3 estaba apagado (0): El resultado será `00000000`. El if lo detecta como falso.

## ¿Qué significan las flechas << y >>?

Escribir las máscaras a mano es muy tardado y propenso a errores humanos. Es por esto que se crearon los desplazamientos de bits. 

Cuando tú escribes un 1, por defecto ese 1 nace en la casilla más a la derecha del tablero: la casilla 0 (00000001).

* 1<<3 **(Desplazamiento a la izquierda)**: Considerenlo como un brazo mecánico, si es que eso hace que entenderlo sea más fácil, cuando usamos el desplazamiento a la izquierda, le ordenamos a ese brazo mecánico que tome el 1 que está en la casilla 0 y lo empuje 3 casillas hacía la izquierda, de forma que pase así: 0 -> casilla 1 -> casilla 2 -> casilla 3. El resultado sería 00001000.

* trama >> 4 **(Desplazamiento a la derecha)**: Esto se usa para cuando la información que buscamos aislar se encuentra entre más información, sobre todo cuando hay casilas más altas a la izquierda y quiere arrastrar la casilla hacia 0 para poderla leer mucho más fácil.

## RESUMEN

No les puedo poner videos de subway surfers a los lados o historias con ASMR, pero en resumen:

* Quiero ENCENDER el bit X: registro |= (1 << X);
* Quiero APAGAR el bit X: registro &= ~(1 << X);
* Quiero PREGUNTAR (saber) si el bit X está encendido: if (registro & (1 << X))

Esto suele ser confuso al comienzo, pero más adelante verán cómo se aplica mediante código y entenderán perfectamente todo el contexto.
