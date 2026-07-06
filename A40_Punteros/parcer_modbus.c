/* =====================================================================
   DESAFÍO 4: PARSER DE PROTOCOLO DE RED MODBUS TRUNCADO
   =====================================================================
   Contexto: Un transceptor de comunicación industrial recibe tramas
   continuas de 16 bits. El búfer físico de entrada guarda un flujo de
   datos estructurado en palabras. Debes desarrollar una rutina que
   inspeccione y modifique de forma indirecta los códigos de control 
   sin duplicar el búfer ni alterar la alineación nativa de la memoria.

   Requerimientos Técnicos y Restricciones:
   1. Entrada del Stream: Declara en el main un arreglo local de tipo
      uint16_t llamado 'packet_stream' e inicialízalo con el siguiente
      patrón binario estático: {0x11AA, 0x22BB, 0x33CC, 0x44DD}.

   2. Filtro Quirúrgico por Referencia: Diseña una rutina modular de
      tipo void llamada 'process_stream' que reciba como parámetro la
      dirección de memoria del paquete crudo mediante un puntero simple
      de 16 bits.
      [PROHIBIDO]: Usar corchetes '[]' u operar directamente con el
      nombre del arreglo original dentro de la rutina.

   3. Algoritmo de Indirección:
      - Utilizando una única sentencia combinada con desreferenciación
        y post-incremento, extrae el valor del índice 0 para su uso y 
        desplaza el puntero a la siguiente palabra.
      - Utilizando aritmética de punteros pura, teletransporta el 
        cursor de memoria hasta la última palabra del stream.
      - Aplica un casteo explícito a la dirección actual para obligar 
        al compilador a interpretar el bloque bajo una lente de 8 bits.
      - Modifica exclusivamente el byte alto de esa palabra sumándole
        de forma indirecta el valor hexadecimal 0x11, asegurando que 
        el byte bajo no sufra ninguna alteración por desbordamiento.

   4. Reporte de Registros: Al retornar al main, imprime el arreglo 
      'packet_stream' completo en formato hexadecimal '0x%04X' 
      utilizando sus índices normales para verificar que la mutación 
      se inyectó de forma correcta en el mapa físico de la RAM.
   ===================================================================== */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void process_stream(uint16_t *ptr_packet){

    uint16_t v1 = *ptr_packet++;
    ptr_packet += 2;
    uint8_t *v2 = (uint8_t*)ptr_packet;
    v2++;
    *v2 += 0x11;
}

int main() {
    system("cls");
    
    uint16_t packet_stream [4] = {0x11AA, 0x22BB, 0x33CC, 0x44DD};
    uint16_t *ptr_packet = packet_stream;
    process_stream(ptr_packet);

    for(int i = 0; i < 4; i++){
    printf("Registros[%d]: 0X%04X\n", i, packet_stream[i]);
    }

}