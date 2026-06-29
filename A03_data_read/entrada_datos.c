// Entrada y Salida de todos los tipos de datos en C

#include <stdio.h>
#include <stdint.h>   // Necesaria para los tipos de tamaño fijo (uint8_t, etc.)
#include <stdbool.h>  // Necesaria para usar el tipo bool (true/false)

int main() {

    // 1. DECLARACIÓN DE VARIABLES
    bool habilitado;
    char letra;
    char palabra[20];
    uint8_t edad;
    uint16_t adc_val;
    uint32_t milisegundos;
    float voltaje;

    printf("---- ENTRADA/SALIDA EN C ----\n\n");

    // 2. LECTURA DE DATOS (INPUT)
    //  OJO, sería buena práctica el realizar una verificación de valores, no lo hacemos por no volvelo más complejo de entender

    // Lectura de un Booleano (en C se lee como entero: 0 o 1)
    printf("Habilitar sistema? (1 = Si, 0 = No): ");
    int temp_bool; 
    scanf("%d", &temp_bool);
    habilitado = (temp_bool == 1);

    // Lectura de un entero común de 8 bits (uint8_t)
    printf("Digite su edad (0-255): ");
    scanf("%hhu", &edad);

    // Lectura de un entero de 16 bits (uint16_t)
    printf("Digite el valor del ADC (0-65535): ");
    scanf("%hu", &adc_val);

    // Lectura de un entero de 32 bits (uint32_t)
    printf("Digite el tiempo en milisegundos: ");
    scanf("%u", &milisegundos);

    // Lectura de un flotante (float)
    printf("Digite el voltaje del sensor (ej. 3.27): ");
    scanf("%f", &voltaje);

    // Lectura de un arreglo de texto (String) -> RECUERDA: NO lleva '&'
    printf("Escribe una sola palabra (ej. ERROR): ");
    scanf("%s", palabra);

    // Lectura de un solo carácter (char) -> RECUERDA: Lleva espacio antes de %c
    printf("Digite una letra para continuar: ");
    scanf(" %c", &letra); 

    printf("   VARIABLES:\n");

    // 3. IMPRESIÓN DE DATOS (OUTPUT)
    
    // El booleano se imprime como texto usando un operador básico
    printf("Estado del sistema:\t%s\n", habilitado ? "ACTIVADO" : "APAGADO");
    printf("Edad ingresada:\t\t%hhu anios\n", edad);
    printf("Valor del ADC:\t\t%hu\n", adc_val);
    printf("Tiempo registrado:\t%u ms\n", milisegundos);
    printf("Voltaje (2 decimales):\t%.2f V\n", voltaje);
    printf("Texto guardado:\t\t%s\n", palabra);
    printf("Letra final:\t\t%c\n", letra);
    printf("Letra en Hexadecimal:\t0x%02X\n", letra); // Truco extra en Hex

    return 0;
}