/*
Se requiere desarrollar un programa en C++ que automatice la toma de pedidos de una cafetería mediante un menú interactivo en la terminal. El sistema debe permitir al usuario seleccionar múltiples productos de forma consecutiva, acumulando el costo en una cuenta final, y detenerse únicamente cuando el usuario decida finalizar la orden.

Requisitos del Sistema:

Flujo Obligatorio: El sistema debe desplegar el menú interactivo en la consola al menos una vez antes de evaluar si el usuario desea continuar o salir, utilizando obligatoriamente una estructura de control cíclica post-prueba (do-while).

Menú de Opciones y Tarifas: El menú debe presentar exactamente las siguientes opciones con sus respectivos valores monetarios:

Opción 1: Comprar Café — Precio: $2.50 USD

Opción 2: Comprar Dona — Precio: $1.50 USD

Opción 3: Ver Total y Salir del sistema.

Lógica de Acumulación: Cada vez que el usuario seleccione la opción 1 o 2, el programa debe sumar el valor correspondiente a una variable acumuladora global (cuenta_total) y regresar de inmediato al menú principal para permitir una nueva selección.

Condición de Parada: El ciclo de compras debe romperse única y exclusivamente cuando el usuario ingrese el dígito 3.

Formato de Salida: Tras finalizar el ciclo, el programa debe imprimir en pantalla el monto total a pagar formateado estrictamente a dos cifras decimales.

*/

// Aprenden a programar pq son mecatronicos? o  son mecatrónicos pq aprenden a programar?


//OJO: La lógica podria simplificarse, pero es un ejemplo de uso de Do-While.

#include <iostream>
using namespace std;

int main (){
    float total = 0, cafe = 2.50, dona = 1.50;
    int selector=0, contador_cafe=0, contador_dona=0;

    //mensaje inicial
    printf("Bienvenido a la caferia, nuestros servicios son los siguientes: ");

    while(1){
        do{ //usamos do-while para validar la seleccion, nunca falta el chistoso
            printf("\n1. Comprar cafe. Precio: $2.50 USD\n2. Comprar dona. Precio: $1.50 USD.\n3. Ver total y salir");
            printf("\nQue desea realizar?: ");
            cin>>selector;
            if(selector!=1 && selector !=2 && selector !=3)
                printf("\nOpcion no disponible, intente de nuevo\n");
        
        }while(selector!=1 && selector !=2 && selector !=3);

        //Una vez verificada la selección, procedemos a la compra
            switch(selector){
                case 1:
                    total +=cafe;
                    printf("\n+1 Cafe\n");
                    contador_cafe++;
                    break;

                case 2:
                    total +=dona;
                    printf("\n+1 Dona\n");
                    contador_dona++; // Para no hacer el x=x+1, se usa x++;
                    break;  
                
                default:
                    printf("\nEl total sera de %.02f, %u cafes, %u donas", total, contador_cafe, contador_dona);
                    break;
            }
            if(selector == 3)
                break;
    }

}
