/*
Se requiere desarrollar un videojuego matemático interactivo por consola en C++.
El programa debe almacenar un número entero secreto en memoria y permitir que el usuario intente
adivinarlo mediante retroalimentación en tiempo real (pistas de "mayor" o "menor"), contabilizando 
el número total de intentos hasta que el usuario acierte.
*/

#include <iostream>
#include <cstdlib> // Aqui tiene las funciones rand
#include <ctime>  // Rand()genera una lista fija de numeros, srand() junto con time(0), da más variedad al algoritmo aleatorio
using namespace std;

int main(){

    srand(time(0));

    unsigned int num_sec = 1 + rand () % 100; // definimos un margen entre 1 y 100 
    unsigned int num=0, intento = 0;

    printf("Numero aleatorio generado, comenzando partida \n");
    printf("Intente adivinar el numero, jochis si te toma mas de 10 intentos");

    do{
        printf("\nNumero: ");
        cin>>num;
        intento++;

            if(num<num_sec)
                printf("\nNumero equivocado, intento: %u \nMas arriba we", intento);
            else if (num > num_sec)
                printf("\nNumero equivocado, intento: %u \nMas abajo we", intento);
    }while(num!=num_sec);

    //Ganador
    printf("\nGanaste, el numero era: %u", num_sec);
    if(intento<=10)
        printf("\nNo eres jochis ;), o quizas si");
    else
        printf("\nJochis????");

    return 0;

}