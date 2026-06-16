/*

Se requiere desarrollar un programa en C++ para registrar y analizar el comportamiento térmico de un motor eléctrico durante un turno de trabajo. El sistema debe almacenar las lecturas de temperatura tomadas secuencialmente, calcular métricas estadísticas básicas e identificar el punto crítico de operación.

Especificaciones Técnicas:

Estructura de Datos: Declarar un arreglo unidimensional de tipo flotante (float) con una capacidad fija de 6 elementos para representar las lecturas por hora.
Entrada de Datos: Solicitar al usuario el ingreso secuencial de las 6 temperaturas a través de la consola mediante un ciclo.
Cálculo de Métricas: El programa debe recorrer el arreglo para determinar:
El promedio aritmético de las temperaturas registradas.
La temperatura máxima absoluta (pico térmico).
Salida de Datos: Desplegar en pantalla el promedio y el valor máximo con un formato de dos cifras decimales.
*/

#include <iostream>
using namespace std;

int main (){
    float temps = 0, tmax= 0, promt = 0;
    float v_temp[6];

    //Entrada de datos:
    for(int i=0;i<6;i++){
        printf("\nDigite valor de temperatura %d: ", i+1);
        cin>>v_temp[i];
    }

    //calculo de metricas
    for(int i=0;i<6;i++){
        temps=v_temp[i]+temps;
        if(v_temp[i]>tmax)
            tmax = v_temp[i];
    }
    promt = temps/6;

    //salida de datos
    printf("\nEl promedio es: %0.2f\nLa temperatura maxima es: %0.2f",promt, tmax);
}