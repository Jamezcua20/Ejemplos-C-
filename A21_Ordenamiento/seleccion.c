/* ===================================================================================
ENUNCIADO: DISTRIBUCIÓN DE ENERGÍA CARDINAL — WAKANDA DEFENSE (Ahorro de RAM)

Contexto: Shuri está actualizando las torretas de defensa automatizadas situadas 
en la frontera de Wakanda. El sistema cuenta con 6 baterías de vibranio de 
respaldo, cada una asignada a un cuadrante defensivo diferente. Tras un ataque, 
las baterías quedan con diferentes porcentajes de carga (0 a 100%). Shuri necesita 
que las torretas consuman primero la energía de las baterías más descargadas. 
Debido a que el microcontrolador de las torretas tiene una memoria RAM sumamente 
limitada y escribir en la memoria del sistema consume demasiados ciclos de reloj, 
debes usar un algoritmo que minimice los intercambios de variables.

Tu Misión (Requerimientos Técnicos):

1. Optimización de Memoria: Crea el arreglo para almacenar los 6 niveles de carga 
   utilizando tipos de datos de ancho fijo de la librería <stdint.h> (específicamente 
   enteros de 8 bits sin signo, uint8_t), asegurando que cada celda ocupe exactamente 
   1 byte de memoria en el microcontrolador.
   
2. Algoritmo de Ordenamiento: Desarrolla el método de Ordenamiento por Selección 
   (Selection Sort) para organizar la carga de las baterías de MENOR a MAYOR.
   (Aprovecha que este método solo realiza un único intercambio por cada iteración 
   externa, protegiendo los recursos de hardware).
   
3. Reporte del Panel Táctil: Imprime en la consola la lista final ordenada indicando 
   el orden en que las torretas deben conmutar las baterías (desde la que requiere 
   recarga inmediata hasta la más llena).
=================================================================================== */
#include<stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(){

    uint8_t carga_b[6]={0}, min_idx = 0, min_pos = 0;
    bool flag = false; 
    // Ingreso de valores
    for (uint8_t i=0; i<6;i++){
        printf("Ingrese el porcentaje de carga de la bateria %hhu: ",i+1);
        scanf("%hhu",&carga_b[i]);

        //validacion
        if(carga_b[i]>100 || carga_b[i]<0){
            printf("\nValor no valido, intente de nuevo\n");
            i--;
        }
    }

    for(uint8_t y=0;y<6;y++){
        min_idx = carga_b[y];
        for(uint8_t i=y;i<6;i++){
            if(carga_b[i]<min_idx){
                min_pos = i;
                min_idx = carga_b[i];
                flag = true;
            }
        }

        if(flag == true){
        min_idx = carga_b[y]; //Se reutiliza min_idx como comodin para no crear una  variable nueva
        carga_b[y] = carga_b[min_pos];
        carga_b[min_pos] = min_idx;
        flag = false;
        }
    }
    printf("\nNivel de carga de las torretas: ");
    for(uint8_t i=0;i<6;i++){
        printf("%hhu%%", carga_b[i]);
        if(i<5)
            printf(", ");
        else   
            printf(". ");
    }

}
