/* =====================================================================
   DESAFÍO 3: SPOTIFY — CONTROL DEL CURSOR EN COLA DE REPRODUCCIÓN
   =====================================================================
   Contexto: Estás programando el reproductor de una app de música. La 
   lista de reproducción actual carga un arreglo secuencial de 16 bits 
   en la RAM que almacena los códigos de las canciones.
   
   Tu Misión (Requerimientos Técnicos):
   1. La Cola de Canciones: Declara un arreglo local de 4 elementos de 
      tipo uint16_t llamado 'playlist' e inicialízalo con los 
      siguientes IDs fijos: {0x0110, 0x0220, 0x0330, 0x0440}.
   
   2. El Lector de Pistas: Declara un puntero de tipo uint16_t llamado 
      'ptr_track'.
      [PROHIBIDO]: Usar corchetes u operar directamente con el nombre 
      del arreglo 'playlist' después de su inicialización.
      
   3. Navegación de Pistas:
      a) Inicializa 'ptr_track' apuntando al inicio del arreglo.
      b) Salta directamente hasta la última canción (índice 3) sumando 
         un valor entero al puntero.
      c) Incrementa el ID de esa última canción sumándole 0x10 usando 
         el operador de desreferencia '*'.
      d) Regresa el puntero exactamente una posición hacia atrás 
         utilizando el operador de decremento '--'.
      e) Multiplica por 2 el VALOR de esta tercera canción.
         
   4. Reporte de Reproducción: Imprime los 4 valores finales de 
      'playlist' usando sus índices normales para demostrar que tu 
      puntero alteró los códigos de forma indirecta en la RAM.
   ===================================================================== */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    system("cls");
    uint16_t playlist[4] = {0x0110, 0x0220, 0x0330, 0x0440};
    uint16_t * ptr_track = playlist; // Se crea puntero hacia playlist, cuando trabajamos con arreglos, no es necesario el &
    
    ptr_track +=3; // Avanzamos a la última pos
    *ptr_track += 0x10; // Sumamos en esa casilla
    ptr_track --; // Retrocedemos una posición
    *ptr_track *= 2; // Duplicamos 

    for(int i=0;i<4;i++){
        printf("Codigo de cancion %d: 0X%04X\n", i+1, playlist[i]); // Imprime
    }
}