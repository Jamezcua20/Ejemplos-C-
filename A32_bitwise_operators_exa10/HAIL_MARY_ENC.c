/* =========================================================================
   DESAFÍO 3: PROJECT HAIL MARY — ENCRIPCION DE FRECUENCIA ERIDIANA (MASTER)
   =========================================================================
   Contexto: Ryland Grace y Rocky sincronizan los motores de salto de la 
   Hail Mary mediante un vector comprimido. Si un solo bit se desalinea, 
   se eyectarán por accidente los tanques de amoniaco de Rocky.

   Mapa de Bits del Registro (uint16_t space_vector):
   =========================================================================
   | Bits 15-12 (4b) | Bits 11-7 (5b) | Bits 6-2 (5b)  |  Bits 1-0 (2b)    |
   | Coef. Radiación | Frec. Rocky    | Combustible    | Modo Propulsión   |
   =========================================================================
   * Bits 15-12: Coeficiente de Radiación Cósmica.
   * Bits 11-7:  Frecuencia Armónica de Rocky.
   * Bits 6-2:   Combustible de Astrofagos Restante.
   * Bits 1-0:   Modo de Propulsión (0 a 3 decimal).

   Tu Misión (Requerimientos Técnicos):

   1. Entrada de Datos Fija:
      uint16_t space_vector = 0x99BA;

   2. Fase 1: Filtro por Umbral Umbilical:
      Diseña una máscara hexadecimal para evaluar si el Coeficiente de 
      Radiación (Bits 15-12) es estrictamente mayor a 12 decimal O si el 
      Combustible (Bits 6-2) es menor a 8 decimal. De ser así, imprime un 
      mensaje de peligro en consola y aborta la ejecución con return 0;.

   3. Fase 2: Intercambio de Bloques (Bit-Swapping):
      Extrae la Frecuencia Armónica (11-7) y el Combustible (6-2).
      EL RETO: Intercambia por completo sus posiciones en memoria (la frec. 
      pasa a ocupar los bits de combustible y viceversa). Antes de unirlos, 
      aplica una máscara de inversión selectiva: invierte únicamente los 
      bits en posiciones impares dentro de cada contenedor independiente. 
      Calcula las máscaras en hexadecimal con la regla 8-4-2-1.

   4. Fase 3: Validación de Red de Doble Anillo:
      Ensambla la trama. Desarrolla un algoritmo que configure el Bit 0 de 
      modo que fuerce paridad par en los bits de posiciones 1 a 7, y el 
      Bit 1 para forzar paridad impar en los bits de posiciones 8 a 15.
   ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main (){    

   system("cls");
    
   // Entrada de datos fija
   uint16_t space_vector = 0x99BA;//1001 1001 1011 1010

   //Salida de datos
   uint16_t space_vector_output = 0x00;

   // Fase 1
   uint8_t fuel_mask = 0x00;
   uint8_t radiation_mask = 0x00;
   uint8_t frec = 0x00;
   uint8_t prop = 0x00;
   uint8_t inverted_fuel_mask = 0x00;
   uint8_t inverted_frequency_mask = 0x00;
   uint8_t contador = 0x00;

   fuel_mask = (space_vector>>2)& 0x1F;
   radiation_mask =  (space_vector>>12) & 0x0F;
   frec = (space_vector>>7) & 0x1F;
   prop = (space_vector>>0) & 0x03;

   printf("\nPROJECT HAIL MARY - SECTOR DE ENCRIPCION ERIDIANA");
   printf("\nCoeficiente de Radiacion: %d", radiation_mask);
   printf("\nCombustible de Astrofagos: %d", fuel_mask);
   if(radiation_mask>12 || fuel_mask< 8){
      printf("\nPeligro: Niveles Criticos \nAbortando...");
      return 0;
   } 
   
   // Fase 2
   inverted_fuel_mask = fuel_mask ^ 0x0A;
   inverted_frequency_mask = frec ^ 0x0A;

   space_vector_output |= (radiation_mask<<12);
   space_vector_output |= (inverted_fuel_mask<<7);
   space_vector_output |= (inverted_frequency_mask<<2);
   space_vector_output |= (prop<<0);
   
   // Primero calculamos la paridad impar, pues modifica el bit 1, y el bit uno es requerido para calcular paridad par
   for(int i=8;i<16;i++){
   if(space_vector_output &(1<<i)){
         contador++;
      }
   }
   if(contador%2==0){
      space_vector_output |= (1<<1);
   }
   else{
      space_vector_output &= ~(1<<1);
   } 

   contador = 0;

   for(int i=1;i<8;i++){
      if(space_vector_output &(1<<i)){
         contador++;
      }
   }
   if(contador%2==0){
      space_vector_output &= ~(1<<0);
   }

   else{
      space_vector_output |= (1<<0);
   }


   printf("\n----------------------------------------------------------");
   printf("\nTanques de Rocky asegurados\nTrama Vectorial Final transmitida: 0X%04x",space_vector_output);
   printf("\n----------------------------------------------------------");
   
}