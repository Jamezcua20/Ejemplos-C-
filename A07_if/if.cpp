/*Sentencias condicionales

El cine cobra la entrada normal a $7.00 dólares. Sin embargo, 
si el cliente es un niño menor de 12 años o un adulto mayor de 60 años,
 recibe un descuento del 50%. Si el cliente tiene entre 12 y 17 años, 
 recibe un descuento del 20%. El sistema debe pedir la edad del usuario
 y mostrar el precio final a pagar

*/

#include <stdio.h>

    int main(){
        int cliente = 0, entrada = 7, edad_nino = 12, edad_adulto = 60, descuento1= 50, descuento2=20;
        float pagar = 0;
        printf("Entradas de cine \n");
        printf("Ingrese la edad del cliente: ");
        scanf("%d", &cliente);

        if(cliente<edad_nino || cliente>edad_adulto){
            printf("\nFelicidades, Aplica para el descuento del 50%%");
            pagar = entrada-((descuento1*entrada)/100.0);
        }
        else if(cliente>edad_nino && cliente <18){
            printf("\nFelicidades, Aplica para el descuento del 20%%");
            pagar = entrada-((descuento2*entrada)/100.0);
        }

        else
        pagar = entrada;
        

        printf("\nEl precio a pagar es: %.2f", pagar);
        printf(" dolares\n");
        
        return 0;
    }