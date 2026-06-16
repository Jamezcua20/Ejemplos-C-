/*
=== DESAFÍO 2: FILTRO DIGITAL DE SEÑAL ULTRASÓNICA ===

Un sensor de proximidad ultrasónico en una banda transportadora industrial
presenta ruido eléctrico, generando lecturas atípicas fuera de su rango operativo (0 a 100 cm).

Tu programa debe:
1. Declarar un arreglo entero de 8 elementos.
2. Permitir al usuario simular el llenado de las 8 lecturas.
3. Evaluar cada elemento: si el valor es < 0 o > 100, se considera un error
   de lectura y debe ser sustituido por un '0' de forma inmediata dentro del arreglo.
4. Imprimir el arreglo final ya sanitizado en una sola línea.
*/
 
//"I can do this all day" - Steve Rogers
// Nomas que no pasen micro, que neta les voy a dar una ptiza a los 4

#include <iostream>
using namespace std;

int main (){

    float signal[8]; // declaramos vector de 8 elementos

    printf(" DESAFIO 2: FILTRO DIGITAL DE SEÑAL ULTRASÓNICA");

    //Entrada de valores del usuario
    for(int i=0; i<8;i++){
        printf("\n Ingresar valor de lectura %d: ",i+1);
        cin>>signal[i];
    }

    //Evaluacion y corrección
    for(int i=0; i<8;i++){
        if(signal[i]<0  || signal[i]>100)
            signal[i]=0;
    }

     //Impresion
    printf("\n Vector final: ");
    for(int i=0; i<8;i++){
        printf("%0.2f",signal[i]);
        if(i<7)
            printf(", ");
        else
            printf(".");
    }

}