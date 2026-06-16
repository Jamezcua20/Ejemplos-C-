/*
=== DESAFÍO 3: INVERSIÓN DE TRAYECTORIA DE UN SERVOMOTOR ===

Un brazo robótico graba una secuencia de 5 ángulos de posición (0 a 180 grados). 
Para regresar a su posición inicial, el sistema de control requiere invertir 
exactamente el orden de la secuencia cinemática.

Tu programa debe:
1. Declarar dos arreglos independientes de 5 elementos cada uno (original e inverso).
2. Solicitar al usuario los 5 ángulos para llenar el primer arreglo.
3. Copiar los elementos del primer arreglo al segundo, pero en orden invertido.
4. Imprimir ambos arreglos en pantalla para contrastar la ida con el retorno.
*/

//  "Sometimes you gotta run before you can walk" - TS.

#include <iostream>
using namespace std;

int main(){
    //Comenzamos con la declaración de 2 arreglos
    float sec_reversion[5];
    float sec_inicial[5];
    int y=0;

    //mensaje inicial
    printf("Sistema de control de servomotores\nIngresar angulos de posicion (0 a 180)");

    //entrada de datos
    for(int i=0;i<5;i++){
        printf("\nPosicion %d a guardar: ",i+1);
        cin>>sec_inicial[i];
        if(sec_inicial[i] < 0 || sec_inicial[i]>180){
            printf("\nValor no valido, intente de nuevo\n");
            i--; //el bucle no avanza hasta meter valor correcto
        }
    }

    //copia de datos
    for(int i=5;i>0;i--){
        sec_reversion[i-1] = sec_inicial[y];
        y++;   
    }

    //Impresion de datos
    printf("\nArreglo inicial: ");
    for(int i=0;i<5;i++){
        printf("%0.2f",sec_inicial[i]);
        if(i!=4){
            printf(", ");
        }
        else
            printf(".");
    }

    printf("\nArreglo invertido: ");
    for(int i=0;i<5;i++){
        printf("%0.2f",sec_reversion[i]);
        if(i!=4){
            printf(", ");
        }
        else
            printf(".");
    }
}