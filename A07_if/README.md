# Programación en C: Estructuras Condicionales (`if` / `else`)

## ¿Cómo toma decisiones un microcontrolador?

Hasta ahora, nuestros códigos han sido lineales: el código ejecuta la línea 1, luego la 2, luego la 3 y se acaba. Pero el mundo real no es lineal. ¿Qué pasa si el sensor de temperatura detecta más de 40 °C y necesitas encender un ventilador? ¿O si el botón no está presionado y el motor debe quedarse quieto?

En C++ y en C puro, la herramienta para ramificar el camino de nuestro código es el `if` (si condicional). Su trabajo es evaluar una condición: si la condición es **verdadera** (diferente de cero), el micro ejecuta un bloque de código; si es **falsa** (igual a cero), se lo salta o ejecuta un camino alternativo con `else`.

---
## La anatomía del `if` en Sistemas Embebidos

La sintaxis es exactamente la misma que ya conocen, pero aquí cada línea de lógica cuenta para el rendimiento del procesador.

```c
if (condicion) {
    // Código que se ejecuta si la condición es VERDADERA
} else {
    // Código que se ejecuta si la condición es FALSA
}
```

Para conectar varias condiciones en cascada, usamos el else if:

```c
if (temperatura > 40) {
    encender_ventilador();
} else if (temperatura > 30) {
    encender_alerta_led();
} else {
    sistema_normal();
}
```

## Recomendaciones

El if parece la cosa más fácil del mundo, pero en sistemas embebidos y C puro hay tres errores que los pueden hacer reprobar o congelar el micro si no se cuidan:

* El error del operador de asignación (=) y comparación (==):

El símbolo = sirve para guardar un valor en una variable. El símbolo == sirve para comparar si dos cosas son iguales. Si ustedes ponen un solo = dentro de un if, el compilador no les va a marcar error; va a meter el valor a la variable, esa operación dará verdadero y el if se va a ejecutar siempre.

```c
// Aquí estás guardando un 1 en 'boton'
if (boton = 1) { 
    // Esto se va a ejecutar SIEMPRE, sin importar si el botón está presionado o no
}

// Forma correcta:
if (boton == 1) { 
    // Esto SÓLO se ejecuta si 'boton' realmente vale 1
}
```

* Los operadores lógicos estándar ( && y || )

Para evaluar más de una cosa a la vez dentro de un if, usamos las compuertas lógicas de C:

1.  && (AND / Y): Obliga a que todas las condiciones sean verdaderas.

2.  || (OR / O): Se conforma con que al menos una de las condiciones sea verdadera.

```c
// Se ejecuta sólo si la edad está en el rango correcto Y el sexo es masculino
if (edad >= 18 && sexo == 'H') { ... } 

// Se ejecuta si el sistema falló por temperatura O por falta de voltaje
if (falla_temp == true || falla_voltaje == true) { ... }
```


---

## RESUMEN DE COMPARADORES

Aquí tienen el acordeón de los operadores que pueden meter dentro de los paréntesis de su if:

```
===================================================================
          OPERADORES DE COMPARACIÓN EN C
===================================================================
* a == b   -> ¿'a' es IGUAL a 'b'?
* a != b   -> ¿'a' es DIFERENTE de 'b'?
* a > b    -> ¿'a' es MAYOR que 'b'?
* a < b    -> ¿'a' es MENOR que 'b'?
* a >= b   -> ¿'a' es MAYOR O IGUAL que 'b'?
* a <= b   -> ¿'a' es MENOR O IGUAL que 'b'?
===================================================================

```

> Redactado por: **Amezcua**
