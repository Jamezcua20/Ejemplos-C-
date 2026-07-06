/* =====================================================================
   DESAFÍO 3: DECODIFICADOR DE TRAMAS DE RED — NIVEL EXPERTO
   =====================================================================
   Contexto: Tu microcontrolador recibe un paquete de datos continuo por
   el puerto serie (UART). La trama contiene información mezclada de 
   sensores. Al no tener variables lógicas individuales, debes usar un 
   puntero para extraer y decodificar el reporte crudo de la memoria.
   
   Tu Misión (Requerimientos Técnicos):
   1. El Buffer Crudo: Declara un arreglo global de 4 elementos de tipo
      uint16_t llamado 'raw_packet' e inicialízalo con los siguientes
      datos hexadecimales fijos: {0x1234, 0x5678, 0x9ABC, 0xDEF0}.
   
   2. El Puntero de Inspección: Declara un puntero de tipo uint16_t 
      llamado 'ptr_word'.
      [PROHIBIDO]: Usar corchetes '[]' o usar el nombre del arreglo 
      'raw_packet' después de su inicialización.
      
   3. Extracción Avanzada:
      a) Inicializa 'ptr_word' apuntando al inicio del paquete crudo.
      b) Guarda en una variable local de tipo uint16_t el contenido de
         la primera casilla, y en la misma línea haz que el puntero 
         avance a la siguiente (Usa el operador combinado '*ptr_word++').
      c) Avanza el puntero dos casillas más adelante usando aritmética 
         de suma directa (para pararte en el último elemento, índice 3).
      d) Guarda el valor de esta última casilla en otra variable de 
         tipo uint16_t.
      e) Hackeo de bytes: Declara un puntero de tipo uint8_t (1 byte) 
         llamado 'ptr_byte' y apúntalo a la dirección actual donde está 
         'ptr_word' aplicando un casteo explícito: (uint8_t *)ptr_word.
      f) Como el procesador es Little Endian, 'ptr_byte' apunta al byte 
         bajo (0xF0). Incrementa el puntero 'ptr_byte++' para moverte 
         al byte alto (0xDE) y duplica su VALOR.

   4. Reporte de Consola: Imprime los 4 valores finales de 'raw_packet' 
      en formato hexadecimal usando sus índices normales.
   ===================================================================== */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    system("cls");
    
    uint16_t raw_packet[4] = {0x1234, 0x5678, 0x9ABC, 0xDEF0};
    
    // Declaración del puntero
    uint16_t *ptr_word = raw_packet; 
    uint16_t v1 = 0x00, v2 = 0x00;

    // Extrae el valor actual en v1 y avanza ptr_word
    v1 = *ptr_word++; 
    
    // Avanza dos casillas más.
    ptr_word += 2; 
    
    // Guarda el valor de la última casilla en v2
    v2 = *ptr_word; 
    
    // Casteamos la dirección actual para leerla como bytes (8 bits)
    uint8_t *ptr_byte = (uint8_t *)ptr_word; 
    
    ptr_byte++; 
    
    // Duplicamos el valor del byte alto
    *ptr_byte *= 2; 

    printf("--- REPORTE DE TRAMA DECODE ---\n");
    for(int i = 0; i < 4; i++){
        printf("raw_packet[%d] = 0x%04X\n", i, raw_packet[i]);
    }
    
}