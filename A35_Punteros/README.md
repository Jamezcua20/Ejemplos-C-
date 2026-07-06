# Programación en C: Punteros

## ¿Qué es un puntero?

En la programación, una variable como las que usan siempre (tipo int, char, o demás, por decir un ejemplo) se podría decir que son como una caja en la que se guarda un valor en específico, mientras que un puntero, es una variable, que tiene como propósito almacenar direcciones de memoria. De forma que en lugar de guardar un "5" o un "10", estaría guardando el lugar de la memoria RAM donde existe ese valor.

Para que lo vean de una forma más sencilla, imaginense que la memoria RAM es como un hotel, dónde, la variable es el huésped que se queda en la habitación x, y el puntero es donde se guarda el número de la hábitación del huésped. 

## Operadores ( " & " y " * "  )

Para trabajar con punteros en C sin que la computadora les de un pantallazo azul o el micro se les congele, necesitan entender y aprender a utilizar 2 simbolos.

1. Operador de dirección (&):

El operador & se coloca antes del nombre de una variables para averiguar cual es su dirección física en la memoria. Si tienen una variable x, al escribir &x le estarían preguntando al sistema:"En qué dirección hexadecimal de la RAM está guardada esta variable?".

2. Operador de indirección o desreferencia (*):

El asterisco "*" es el operador que tiene 2 usos:

* Para declarar: Cuando crean la variable, el * le avisa al compilador que ese será un puntero (eje. uint8_t *x;).

* Para desreferenciar: Cuando ya tienen un puntero guardado, usar el * antes de su nombre les permite acceder indirectamente al valor de la variable original y modificarlo, sin tener que tocar la variable original.

## Sintaxis en C

Aquí tienen un ejemplo de cómo se declara, asigna y desreferencia un puntero:

 ```c
int main (){

    int x = 10; // Se crea una variable normal

    //1. Se crea el puntero indicando el tipo e dato y se le da la dirección de x usando "&"
    int *puntero =  &x;

    //2. Desreferencia (modificación). Usamos el "*" para entrar en la dirección y cambiar el valor.
    *puntero = 20;

    // Ahora si se imprime la variable original número valdrá 20
    printf("El valor del numero es: %d\n", numero);

    return 0;
}

 ```

## Usos

En C, cuando una función usa una variable, el compilador hace una copia y gasta el doble de RAM, esto no es un problema al realizar programas dentro de una computadora porque tenemos Gigas de memoria, pero, cuando pasamos a microcontroladores, hablamos de que apenas tenemos algunos Kilobytes, es por esto que usando punteros que le pasen a la función solo la dirección de la variable original, ahorramos mucha memoria.

## Cosas a tomar en cuenta

1. La aritmética de punteros

A los punteros se les puede sumar o restar valores ( usando +,-, ++, -- ) para navegar por la memoria, pero la matemática binario no suma bytes normales, sino bloques completos.

Piensen en la memoria como si fuera una calle y en los datos como si fueran casas de diferentes tamaños. Si le sumas 1 a un puntero, este no da un paso de un solo byte, sino que salta un bloque completo del temaño del tipo de dato al que apunta. Solo estarían cambiando la referencia que tienen, no estarían modificando el valor de la referencia.

2. Error de puntero (Wild Pointer)

Como les comenté, podemos tomar a los punteros como un papel donde anotamos una dirección. Cuando creamos el puntero, pero olvidamos escribir a que dirección apunta, se convierte en un Wild Pointer (puntero salvaje en español, pero suena bien xd, así que usaremos wild pointer), este puntero estaría apuntando a un lugar random de la memoria RAM. Si usamos ese puntero para modificar algo, estaríamos modificando valores ciegamente, y podríamos causar lo que es un fallo de segmentación.

Es por eso cuando creamos un puntero, pero, aún no sabemos que valor va a tener, por lo que le asignamos el valor de NULL. De manera que decimos al código que el puntero existe pero no apunta a ninguna dirección (de momento).


## En resumen... 

1. Declaración e Inicialización (Vincular a una variable)

Para crear un puntero necesitas usar el asterisco *. Para extraer la dirección de una variable existente, usas el operador de dirección &.

 ```c
int variable = 42;

// ASIGNACIÓN: Creamos el puntero 'ptr' y le guardamos la dirección de 'variable'
int *ptr = &variable;

 ```

2. Modificar y Leer el Valor (*ptr)

Para entrar a la memoria y cambiar o leer el dato real, usas el asterisco * (desreferenciación).

 ```c
// MODIFICACIÓN: Entra a la dirección guardada y cambia el 42 por un 100
*ptr = 100; // 'variable' ahora vale 100

// LECTURA: Lee el dato guardado en esa memoria
int copia = *ptr; // 'copia' guarda un 100

 ```

 3. Operaciones con arreglos (Moverse en bloques)

 Cuando asingas un arrreglo a un puntero, no usamos el &. Un arreglo ya es una dirección de memoria por si mismo.

 ```c
uint8_t vector[4] = {10, 20, 30, 40};
uint8_t *p = vector; // 'p' apunta al primer elemento (vector[0] -> 10)

 ```

 4. Operaciones de Valor vs. Operaciones de Memoria

Fíjense muy bien en los paréntesis y el asterisco:

 ```c
// Caso A: Modificar el número dentro de la casilla
(*p)++; // Toma el valor actual (ej. 10) y le suma 1. El dato se vuelve 11. El puntero NO SE MOVIÓ.

// Caso B: Mover la dirección del puntero
p++;    // Mueve el puntero a la siguiente casilla del arreglo. El dato original NO CAMBIÓ.

 ```

 5. Comparaciones de Memoria (==, !=, <, >)

 Se usan para validar posiciones en Arreglos o Memoria RAM:

 ```c
if (p == &vector[3]) {
    // Código si el puntero llegó exactamente al final del arreglo
}

if (p1 < p2) {
    // Da verdadero si la dirección de p1 está numéricamente antes que p2 en la RAM
}
 ```

 6. Pasar por Referencia en Funciones

 Cuando trabajamos con funciones, en C, se hacen "copias" y no alteran las variables por si solas. En cambio, si pasamos un puntero, podemos modificar la variable real desde dentro de la función.

 ```c
// La función recibe la dirección de la variable
void duplicar(int *ptr_num) {
    *ptr_num = (*ptr_num) * 2; // Modifica directamente la variable de afuera
}

int main() {
    int energia = 50;
    duplicar(&energia); // Le pasamos la dirección usando '&'
    // 'energia' ahora vale 100 de forma real
}
 ```


