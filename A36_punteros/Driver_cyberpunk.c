/* =====================================================================
   DESAFÍO 1: SIMULADOR DE DRIVER CYBERPUNK (PUNTEROS Y SFR)
   =====================================================================
   Contexto: Estás hackeando el brazo robótico de un implante. El 
   sistema operativo bloqueó las variables principales, pero tú conoces 
   la dirección física de la memoria RAM donde viven los registros.
   
   Tu Misión (Requerimientos Técnicos):
   1. La RAM Virtual: Declara un arreglo global de 3 elementos de tipo 
      uint8_t llamado 'virtual_ram' e inicialízalo en ceros. Esto 
      simulará nuestro banco de memoria física.
   
   2. Hackeo por Punteros: Declara un puntero de tipo uint8_t llamado 
      'ptr_puerto'. [PROHIBIDO]: Modificar 'virtual_ram' directamente 
      usando sus índices (ej. virtual_ram = 5).
      
   3. Control de Hardware:
      a) Asigna a 'ptr_puerto' la dirección de memoria del primer 
         elemento del arreglo usando el operador '&'.
      b) Usando el operador de desreferencia '*', escribe el valor 
         0xFF (Pines como Salida) en esa dirección.
      c) Avanza el puntero a la siguiente dirección de memoria (suma 1)
         y escribe el valor 0x0A (Encender motores).
         
   4. Reporte de Memoria: Imprime los valores finales de 'virtual_ram' 
      para demostrar que lograste alterar los datos a distancia sin 
      haber tocado el arreglo original.
   ===================================================================== */

   #include<stdio.h>
   #include<stdint.h>
   #include<stdlib.h>

   int main(){
    system("cls");
    
    uint8_t virtual_ram[3] = {0x00};
    uint8_t *ptr_driver = virtual_ram;

    *ptr_driver = 0xFF;
    printf("Valor RAM [0]: 0X%02X\n", virtual_ram[0]);
    ptr_driver++;
    *ptr_driver = 0X0A;
    printf("Valor RAM [1]: 0X%02X\n", virtual_ram[1]);
    ptr_driver++;
    printf("Valor RAM [2]: 0X%02X\n", virtual_ram[2]);
   }