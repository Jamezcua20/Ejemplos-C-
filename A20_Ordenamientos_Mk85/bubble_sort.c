/*
Enunciado: RECALIBRACIÓN DE PROPULSORES — MARK 85 (Filtro Antirruido)

Contexto: Durante un vuelo supersónico, la Inteligencia Artificial de la armadura Mark 85 detecta que los datos de 
presión del estabilizador de vuelo izquierdo están llegando distorsionados debido al calor extremo de la fricción 
atmosférica. El sensor analógico toma una ráfaga rápida de 5 lecturas consecutivas de presión y las almacena en memoria.
Para evitar que la armadura compense el vuelo de forma errática por culpa de un pico de lectura falso (ruido), es 
necesario limpiar la señal físicamente mediante software.

Tu Misión (Requerimientos Técnicos):

Captura de Señal: Permite la entrada de un arreglo de 5 elementos de tipo decimal (float) que representen las presiones 
del estabilizador.

Algoritmo de Ordenamiento: Desarrolla el Método de la Burbuja para organizar estas presiones estrictamente de MENOR a 
MAYOR.

Filtro de Mediana (Sistemas Embebidos): El programa debe ignorar de forma automática el valor más bajo (índice 0) y el 
valor más alto (último índice) por considerarse picos de ruido electromagnético.

Diagnóstico del Sistema: Calcula el promedio matemático utilizando únicamente las 3 lecturas centrales remanentes y 
muestra el resultado en pantalla
*/

#include <stdio.h>
#include <stdint.h>

int main(){

float comodin=0, prom=0;
float v_presion[5] ={0};

printf("\nPRECAUCION, SE DETECTA MAL FUNCIONAMIENTO EN LA BOTA IZQUIERDA");
printf("\nRealizando analisis de emergencia\n");

//Ingreso de valores
for(uint8_t i=0;i<5;i++){
    printf("Ingresar valor de presion %d (MPa): ",i+1);
    scanf("%f",&v_presion[i]);
}

//Ordenamiento
for(uint8_t y=0;y<4;y++){
    for (uint8_t i=0;i<4-y;i++){
        if(v_presion[i+1]<v_presion[i] && i<4){
            comodin = v_presion[i];
            v_presion[i] = v_presion[i+1];
            v_presion[i+1] = comodin;
        }
    }
}

for(uint8_t i=0;i<5;i++){
    printf("%0.2f", v_presion[i]);
    
    if(i>0 && i<4)
        prom +=v_presion[i];
    
        if(i<4)
        printf(", ");
    
    else
        printf(".");
}

printf("\nLa media de presion es de %0.2f MPa", prom/3);

}