//  Lectura o entrada de datos C

#include <stdio.h>

int main(){
    int numero;
    
    printf("Digite un numero: ");
    // Usamos %d porque es un entero, y el & para guardar el dato en la variable
    scanf("%d", &numero);

    printf("\nEl numero que digito es %d\n", numero);
    
    return 0;
}