/* =====================================================================
   DESAFÍO 2: TIKTOK / INSTAGRAM — REORDENAMIENTO DE HISTORIAL DE FEED
   =====================================================================
   Contexto: Estás desarrollando el backend de una red social. Un 
   usuario abrió su feed y la app cargó un vector secuencial de 16 bits 
   en la memoria RAM que guarda los IDs de los videos o publicaciones.
   
   Tu Misión (Requerimientos Técnicos):
   1. El Buffer del Feed: Declara un arreglo local de 4 elementos de 
      tipo uint16_t llamado 'feed_posts' e inicialízalo con los 
      siguientes códigos fijos de posts: {0x100, 0x200, 0x300, 0x400}.
   
   2. El Cursor del Historial: Declara un puntero de tipo uint16_t 
      llamado 'ptr_feed'.
      [PROHIBIDO]: Usar corchetes u operar directamente con el nombre 
      del arreglo 'feed_posts' después de su inicialización.
      
   3. Manipulación del Feed:
      a) Inicializa 'ptr_feed' apuntando al inicio del arreglo.
      b) Usando operaciones matemáticas sobre el puntero, haz que el 
         cursor salte directamente hasta la tercera publicación 
         (índice 2) sumando un valor entero al puntero.
      c) Duplica el ID de esa tercera publicación (multiplica su VALOR 
         por 2) usando el operador de desreferencia '*'.
      d) Mueve el puntero exactamente una posición hacia adelante 
         utilizando el operador de incremento '++'.
      e) Réstale el valor 0x50 al VALOR de esta última publicación.
         
   4. Reporte de Base de Datos: Imprime los 4 valores finales de 
      'feed_posts' usando sus índices normales para demostrar que tu 
      cursor alteró los IDs de forma indirecta en la memoria RAM.
   ===================================================================== */

#include <stdio.h>
#include<stdint.h>
#include<stdlib.h>

int main(){

    system("cls");

    uint16_t feed_posts[4] = {0x100, 0x200, 0x300, 0x400};
    uint16_t *ptr_feed = feed_posts;

    ptr_feed += 2; // Avanzamos de la casilla 0 a la 2
    *ptr_feed*=2; // Duplicamos el valor de la casilla 2
    ptr_feed++; // Avanzamos a la casilla 3
    *ptr_feed -= 0x50; // Restamos 0x50 al valor actual de feed post en la posición 3

    printf("--- CONTENIDO DEL FEED ACTUALIZADO ---\n");
    for(int i=0;i<4;i++){
        printf("Valor %d del feed: 0X%04X\n", i+1, feed_posts[i]);
    }
}