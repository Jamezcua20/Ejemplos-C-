#include <stdio.h>

int main() {
    int entero = 15;
    float flotante = 15.24;
    double doble = 16.37455;
    char caracter = 'a';
    
    // En C usamos printf con %c para imprimir un solo carácter
    // El '\n' hace la función del 'endl' (salto de línea)
    printf("%d | %.2f | %.5lf | %c\n", entero, flotante, doble, caracter);
    
    return 0;
}

/*Para trabajar con microcontroladores, usualmente acostumbramos a priorizar el uso de memoria y usar tipo de datos
uint8_t, int8_t, uint16_t, int16_t, etc, todo esto es por el uso de memoria, pero ahora que van comenzando, no deberían
de tener problemas con los tipos de datos tradicionales.
*/