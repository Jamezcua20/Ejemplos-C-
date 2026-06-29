/*
Realizar un programa que lea la entrada de datos de una persona:
Edad: entero
Sexo: Caracter
Altura: flotante

Tras leerlos el programa debe mostrarlos en consola
*/

#include <stdio.h>

int main(){
    int edad; char sexo; float altura;

    // Inicializamos las variables
    edad = 0;
    sexo = 'X'; 

    printf("Ingresar edad: ");
    while(edad<5||edad>80){
        scanf("%d", &edad);
        if(edad<5||edad>80)
            printf("No valido\n");
    }

    printf("\nIngresar sexo: ");
    while(sexo!='H'&&sexo!='M'&&sexo!='m'&&sexo!='h'){
        // El espacio antes de %c limpia el buffer del Enter anterior
        scanf(" %c", &sexo);
        if(sexo!='H'&&sexo!='M'&&sexo!='m'&&sexo!='h')
            printf("No valido\n");
    }

    printf("\nIngresar altura: ");
    scanf("%f", &altura);


    printf("\nEdad registrada: %d", edad);
    printf("\nSexo registrado: %c", sexo);
    printf("\nAltura registrada: %.2f", altura); 
    printf(" m\n");

    return 0;
}