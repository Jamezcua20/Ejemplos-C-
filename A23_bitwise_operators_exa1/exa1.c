/* ===================================================================================
ENUNCIADO: INTRODUCCIÓN A OPERACIONES BITWISE (Ejercicios de Calentamiento)

Contexto: Para dominar el control de hardware en microcontroladores, primero debemos 
entender cómo alteran la memoria RAM los operadores lógicos bit por bit. En este 
programa desarrollaremos 4 escenarios rápidos y aislados utilizando una variable 
de 1 byte (uint8_t) para observar el comportamiento de las máscaras binarias.

Tu Misión (Requerimientos Técnicos):

1. Inicialización: Declara una variable llamada 'registro' de tipo uint8_t e 
   inicialízala en 0 (Binario: 00000000).

2. Ejercicio 1 (Encendido selectivo con OR): Aplica una operación para encender 
   únicamente el bit 3 (convertirlo en 1), usando el operador '|' y un desplazamiento.
   Muestra el resultado en formato hexadecimal.

3. Ejercicio 2 (Alternancia con XOR): Aplica una operación tipo "Toggle" para 
   invertir el estado del bit 0. Ejecútala dos veces consecutivas para demostrar 
   cómo se enciende y se apaga un bit de forma cíclica con el operador '^'.

4. Ejercicio 3 (Lectura selectiva con AND): Configura forzadamente el bit 5 en 1. 
   Luego, simula un filtro de "Rayos X" usando el operador '&' dentro de un 'if' 
   para aislar el bit 5 y verificar en pantalla si está encendido o apagado.

5. Ejercicio 4 (Apagado selectivo con AND + NOT): Utilizando el operador '&' 
   junto con el complemento '~', apaga estrictamente el bit 5 que encendiste en el 
   ejercicio anterior, asegurando que los demás bits no sufran ningún cambio.
=================================================================================== */

    /*
    & = AND
    | = OR
    ^ = XOR
    << = left shift
    >> = right shift
    */ 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // esta solo la incluyo pq no me gusta tener la terminal sucia

int main(){
    system("cls"); //Se limpia la terminal, ojo, solo funciona en terminal de windows, no lo hagan con micros

    uint8_t registro = 0x00; // Representacion binaria 00000000

    // Operador OR
    printf("Operador OR (|) \nRegistro actual: 0x%02x\n", registro);
    registro |= (1<<3);
    printf("Registro modificado: 0x%02x",registro);

    //Operador XOR
    printf("\nOperador XOR (^) \nRegistro actual: 0x%02x",registro);
    registro^=(1<<0);
    printf("\nRegistro modificado: 0x%02x",registro);
    registro^=(1<<0);
    printf("\nRegistro modificado: 0x%02x",registro);

    //Operador AND
    //FORZAR BIT 5 EN 1
    registro|=(1<<5);
    printf("\nRegistro modificado: 0x%02x",registro);
    if(registro& (1<<5))
        printf("\nBit 5 activo");
    
    //Operador AND + NOT
    //Forzar bit 5 a 0
    registro &= ~(1<<5);
    printf("\nRegistro modificado: 0x%02x",registro);
    if((registro & (1<<5)) == 0)
        printf("\nBit 5 apagado");
}