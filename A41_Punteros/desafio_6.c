/* =====================================================================
   DESAFÍO 6: PROYECTO HAIL MARY — SINCRONIZACIÓN DE ASTROFAGOS
   =====================================================================
   Contexto: El reactor de la nave Hail Mary es inestable. Los datos 
   de los astrofagos (bits de control) están dispersos en un banco de 
   registros de 16 bits. Rocky necesita que manipules la memoria RAM 
   física usando punteros para reajustar los parámetros de ignición.

   Requerimientos Técnicos y Restricciones:
   1. Mapa de Registros (uint16_t[4]): Declara un arreglo global:
      {0x1000, 0x2000, 0x3000, 0x4000}.
   
   2. Rutina 'sync_reactor': Diseña una función que reciba un puntero 
      doble (uint16_t**). Debe mapear el puntero para inspeccionar el 
      segundo registro del banco.
      [PROHIBIDO]: Usar operadores lógicos tradicionales (==, !=, <, >). 
      Valida la integridad de la dirección aplicando solo XOR (^).

   3. Operaciones de Bajo Nivel (Dentro de la rutina):
      a) Accede al valor del segundo registro mediante doble desreferencia.
      b) Utilizando un casteo a puntero de 8 bits, modifica el byte 
         superior del registro para que sea igual al byte inferior.
      c) Utilizando una máscara XOR y un operador de asignación, 
         invierte los bits 0, 4 y 8 del valor resultante.

   4. Auditoría de Memoria: Imprime el estado final de los 4 registros 
      en formato '0x%04X' desde el main, tras invocar la rutina.
   ===================================================================== */

   #include <stdint.h>
   #include <stdlib.h>
   #include <stdio.h>

   uint16_t control_register[4] = {0x1000, 0x2000, 0x3000, 0x4000};
   
   void sync_reactor(uint16_t **ptr_ptr){
      uint16_t *ptr_trhs = *ptr_ptr; // Usamos un puntero temporal para modificar
      ptr_trhs++; // Avanzamos dentro de la dirección de memoria
      uintptr_t direction = (uintptr_t)ptr_trhs; // Se crea una varaible con la dirección de ptr_tsh, se podría hacer directamente tmb
      uintptr_t valid = ( direction ^ (uintptr_t)&control_register[1]); // Se realiza una comparación por medio de una XOR   
      //printf("\n0X%04X",valid); // Si los valores son iguales el resultado arroja 0

      if(valid){

      }
      else{
         (*ptr_ptr)++;
         uint8_t cast = (uint8_t)**ptr_ptr;
         **ptr_ptr = (**ptr_ptr<<8);
         **ptr_ptr |= cast;
         **ptr_ptr ^= (1<<0)|(1<<4)|(1<<8); 
         
      }
   }

   int main(){
      system("cls");
      //printf("0X%04X", control_register);
      uint16_t *ptr_ctl = control_register;
      sync_reactor(&ptr_ctl);
      for(int i=0;i<4;i++){
         printf("\nRegistro de control en la posicion [%d]: 0X%04X",i,control_register[i]);
      }
   }