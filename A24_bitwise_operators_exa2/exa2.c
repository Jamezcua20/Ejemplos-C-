/* ===================================================================================
ENUNCIADO: Propulsion Wingsuit — EXO-7 FALCON (Manipulación de Registros)

Contexto: Estás programando el microcontrolador que gestiona los sistemas de hardware 
del traje de vuelo EXO-7 Falcon. Para evitar cortocircuitos o activar sistemas por 
error, está estrictamente prohibido alterar registros completos usando números decimales 
o asignaciones directas. Debes configurar y simular el comportamiento de los actuadores 
y sensores usando máscaras y desplazamientos de bits de forma estricta.

Mapeo del Puerto B (1 Byte / uint8_t):
* Pin 7 (Bit 7): Propulsor Izquierdo (Salida)
* Pin 6 (Bit 6): Propulsor Derecho (Salida)
* Pin 5 (Bit 5): Alerón de Estabilización (Salida)
* Pin 4 (Bit 4): Paracaídas de Emergencia (Salida)
* Pin 3 (Bit 3): Sensor de Altura Máxima (Entrada)
* Pin 2 (Bit 2): Botón de Eyección (Entrada)
* Pin 1 (Bit 1): LED de Alerta en el Casco (Salida)
* Pin 0 (Bit 0): LED de Sistema Listo (Salida)

Tu Misión (Requerimientos Técnicos):

1. Inicialización de Hardware: Declara una variable 'REG_SALIDA' en 0x00.
   Enciende de forma inmediata el 'LED de Sistema Listo' (Bit 0).

2. Simulación de Entrada (Lectura): Declara una variable 'REG_ENTRADA'. Simula que 
   el hardware externo activa el 'Sensor de Altura Máxima' (fuerza el Bit 3 a 1). 
   Desarrolla un condicional 'if' con el operador '&' para detectar si dicho sensor 
   está activo sin modificar la variable.

3. Protocolo de Emergencia (Si el sensor del punto anterior está activo):
   a) Enciende en una sola línea de código el 'Propulsor Izquierdo' (Bit 7) y el 
      'Propulsor Derecho' (Bit 6) combinando máscaras con el operador OR.
   b) Haz un "Toggle" (XOR) del 'LED de Alerta en el Casco' (Bit 1) simulando un parpadeo.

4. Estabilización: Fuera del condicional, apaga de forma segura el 'Propulsor Derecho' 
   (Bit 6) utilizando el operador '&=' junto con '~', asegurando que el Propulsor 
   Izquierdo (Bit 7) y el LED de Listo (Bit 0) permanezcan encendidos. Imprime el 
   estado final del registro en formato Hexadecimal.
=================================================================================== */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // esta solo la incluyo pq no me gusta tener la terminal sucia

int main (){

    system("cls"); //Se limpia la terminal, ojo, solo funciona en terminal de windows, no lo hagan con micros

    //Declaración de variables inicializada a 0
    uint8_t reg_salida = 0x00;
    uint8_t reg_entrada = 0x00;

    //Se enciende el led de sistemas listos (Bit 0)
    reg_salida |= (1<<0);

    //Impresion de regisotrs de salida
    printf("Sistemas listos\nEstado del puerto B: 0x%02x", reg_salida);

    //Forzamos bit 3 del registro de entradas a 1
    reg_entrada |= (1<<3);

    if(reg_entrada & (1<<3)){
        printf("\nAltitud maxima alcanzada\nSistema en riesgo!");
        reg_salida |=(1<<6) | (1<<7);
        printf("\nPropulsor Izquierdo y Derecho encendidos, iniciando maniobras de estabilizacion\nEstado del puerto B: 0x%02x", reg_salida);
        reg_salida ^=(1<<1);
        printf("\nLed de alerta en casco! \nEstado del puerto B: 0x%02x", reg_salida);
        reg_salida ^=(1<<1);
        printf("\nLed de alerta en casco! \nEstado del puerto B: 0x%02x", reg_salida);
    }

    reg_entrada &= ~(1<<3); //Simulacion de apagado de sensor de altura
    printf("\nTraje EXO - 7 Falcon estabilizado \nEstado del puerto B: 0x%02x", reg_salida);
    reg_salida &= ~(1<<6);
    printf("\nPropulsor derecho apagado \nEstado del puerto B: 0x%02x", reg_salida);

}