/* =====================================================================
   DESAFÍO 7: CYBERPUNK 2077 — BYPASS DE ENLACE NEURAL
   =====================================================================
   Contexto: El implante neural de V sufre un sobrecalentamiento.
   Los datos de calibración (palabras de 32 bits) están dispersos
   en la RAM. T-Bug necesita que manipules la memoria física
   usando punteros para aislar el núcleo dañado.

   Requerimientos Técnicos y Restricciones:
   1. Mapa de Memoria (uint32_t[4]): Declara un arreglo global:
      {0x11111111, 0x22222222, 0x33333333, 0x44444444}.
   
   2. Rutina 'bypass_neural': Diseña una función que reciba un
      puntero doble (uint32_t**). Debe mapear el puntero para
      inspeccionar el tercer registro del banco.
      [PROHIBIDO]: Usar operadores relacionales tradicionales.
      Valida la integridad de la dirección aplicando solo XOR (^).

   3. Operaciones de Bajo Nivel (Dentro de la rutina):
      a) Accede al valor del tercer registro con doble indirección.
      b) Utilizando un casteo a puntero de 8 bits, modifica el
         byte más significativo (MSB) para que sea idéntico
         al byte menos significativo (LSB) del registro.
      c) Utilizando una máscara XOR y un operador de asignación,
         invierte los bits 1, 5, 9 y 13 del valor resultante.

   4. Auditoría de Memoria: Imprime el estado final de los 4
      registros en formato '0x%08X' desde el main.
   ===================================================================== */

   #include <stdio.h>
   #include <stdint.h>
   #include <stdlib.h>

   uint32_t memory[4] =  {0x11111111, 0x22222222, 0x33333333, 0x44444444};
   
   void bypass_neural(uint32_t **ptr_ptr){
      (*ptr_ptr)+=2;
      uintptr_t dir_mer = (uintptr_t)*ptr_ptr;
      uintptr_t valid = (dir_mer ^ (uintptr_t)&memory[2]);
      //printf("0X%04X", dir_mer);
      //printf("\n0X%04X", &memory[2]);
      //printf("\n0X%04X",valid);

      if(valid){
         printf("\nError");
         exit (1); // Funciona con la bilbioteca stdlib
      }

      uint8_t *cast = (uint8_t*) *ptr_ptr;
      cast[3] = cast[0];
      **ptr_ptr ^= (1<<1) | (1<<5) | (1<<9) | (1<<13);     
      
   }

   int main(){
      system("cls");
      uint32_t *ptr = memory;
      bypass_neural(&ptr);

      for(int i=0;i<4;i++){
         printf("\nRegistro: [%d]: 0X%08X",i, memory[i]);
      }
   }