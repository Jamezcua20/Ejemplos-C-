/*
Escribe un programa que lea entrada de dos numeros y muestre la salida de su suma, resta, multiplicacion o division
*/

#include <stdio.h>

int main() {
    int num1; 
    int num2;
    int resultado = 0;

    printf(" Operaciones aritmeticas \n");
    
    printf("\nIntroduzca primer numero: ");
    scanf("%d", &num1);
    
    printf("Introduzca segundo numero: ");
    scanf("%d", &num2);
    
    // 1. Suma
    resultado = num1 + num2;
    printf("\nSuma: %d\n", resultado);
    
    // 2. Resta
    resultado = num1 - num2;
    printf("Resta: %d\n", resultado);
    
    // 3. Multiplicación
    resultado = num1 * num2;
    printf("Multiplicacion: %d\n", resultado);
    
    // 4. División (Convertimos temporalmente a float para no perder los decimales)
    if (num2 != 0) {
        printf("Division: %.2f\n", (float)num1 / num2);
    } else {
        printf("Division: No se puede dividir entre cero.\n");
    }

    return 0;
}