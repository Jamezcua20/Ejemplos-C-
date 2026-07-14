/* =====================================================================
   DESAFÍO 8: DEAD SPACE — RECALIBRACIÓN DEL ISHIMURA
   =====================================================================
   Contexto: El motor hiperespacial de la USG Ishimura sufre una
   desincronización cuántica. Isaac Clarke necesita remapear un
   bloque de datos críticos almacenados en palabras ultra anchas de
   64 bits. Manipula la memoria física a través de indirección
   múltiple para corregir el vector de navegación.

   Requerimientos Técnicos y Restricciones:
   1. Mapa de Telemetría (uint64_t[4]): Declara un arreglo global:
      { 0x1111222233334444ULL, 0x5555666677778888ULL,
        0x9999AAAABBBBCCCCULL, 0xDDDDEEEEFFFF0000ULL }.
   
   2. Rutina 'override_system': Diseña una función que reciba un
      puntero doble (uint64_t**). Debe mapear el puntero para
      pararse exactamente en el cuarto registro del banco.
      [PROHIBIDO]: Usar operadores relacionales tradicionales.
      Valida la integridad de la dirección aplicando solo XOR (^).

   3. Operaciones de Bajo Nivel (Dentro de la rutina):
      a) Accede al valor del cuarto registro con doble indirección.
      b) Utilizando un casteo a puntero de 16 bits (uint16_t*),
         intercambia físicamente en la memoria el valor del sub-bloque
         más significativo (MSW) con el menos significativo (LSW)
         de ese registro de 64 bits.
      c) Utilizando una máscara XOR y un operador de asignación,
         invierte los bits de paridad interna en las posiciones
         2, 10, 18 y 26 del valor resultante de 64 bits.

   4. Auditoría de Memoria: Imprime el estado final de los 4
      registros en formato '0x%016llX' desde el main.
   ===================================================================== */

   #include <stdio.h>
   #include <stdint.h>
   #include <stdlib.h>

   uint64_t mapa_tel[4] =  { 0x1111222233334444ULL, 0x5555666677778888ULL, 0x9999AAAABBBBCCCCULL, 0xDDDDEEEEFFFF0000ULL};
   //ULL se usa para que se usen directamente 64 bits y el compilador no trate de usar 32 bits

   void override_system(uint64_t **ptr_ptr){
      (*ptr_ptr)+=3;
      uintptr_t direction = (uintptr_t)*ptr_ptr;
      uintptr_t valid = (direction ^ (uintptr_t)&mapa_tel[3]);
      
      if(valid){
         exit(1);
      }       

      uint16_t *cast = (uint16_t*)*ptr_ptr;
      uint16_t temp = cast[3];
      cast[3] = cast[0];
      cast[0] = temp;
      **ptr_ptr ^= ((1ULL<<2) | (1ULL<<10) | (1ULL<<18) | (1ULL<<26));//ULL Unsigned Long Long es para cuando son operaciones de 64 bits.
   }

   int main (){
      system("cls");
      uint64_t *ptr = mapa_tel;
      override_system(&ptr);

      for(int i=0;i<4;i++){
         printf("Registro [%d]: 0X%016llX\n",i, mapa_tel[i]);
      }

   }