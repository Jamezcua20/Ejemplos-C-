/* =========================================================================
   DESAFÍO 1: AVENGERS — PROTOCOLO OMNIBUS DE STARK INDUSTRIES (EXPERTO)
   =========================================================================
   Contexto: Las tropas de Thanos atacan la red de satélites. Tony Stark 
   necesita empaquetar de forma compacta un registro de 16 bits para 
   reconfigurar los escudos de nanobots antes de que colapsen.

   Mapa de Bits del Registro (uint16_t nanotech_core):
   =========================================================================
   | Bits 15-12 (4b) |  Bits 11-6 (6b)   |  Bits 5-2 (4b)  | Bits 1-0 (2b) |
   |   ID Vengador   | Energía Repulsor  | Coor. Nanobots  | Cód. Seguridad|
   =========================================================================
   * Bits 15-12: ID del Vengador en zona (0 al 15 decimal).
   * Bits 11-6:  Nivel de Energía de Repulsores (0 al 63 decimal).
   * Bits 5-2:   Coordenadas de Despliegue de Nanobots (0 al 15 decimal).
   * Bits 1-0:   Código de Autorización de Seguridad (0 a 3 decimal).

   Tu Misión (Requerimientos Técnicos):

   1. Entrada de Datos Fija:
      uint16_t nanotech_core = 0xC9B2; // Binario: 1100 1001 1011 0010

   2. Fase 1: Filtro Puro Sin Operadores Lógicos:
      Verifica si el Código de Autorización (Bits 1-0) NO es cero (00) Y si 
      the ID del Vengador (Bits 15-12) es mayor o igual a 10 decimal. 
      [PROHIBIDO]: usar operadores && o ||. Si falla, aborta con return 0;.

   3. Fase 2: Rotación y Modificación Algorítmica:
      Extrae Energía de Repulsores y Coordenadas en contenedores uint8_t.
      LÓGICA: Si las Coordenadas son múltiplo de 4 (bits 0 y 1 de la variable 
      aislada son 00), rota cíclicamente los bits de Energía 2 posiciones a 
      la izquierda dentro de su propio límite de 6 bits (los bits que salen 
      por la izquierda reingresan por la derecha). Luego, aplica un Toggle 
      (XOR completo) al Código de Seguridad.

   4. Fase 3: Paridad Cruzada Avanzada:
      Reconstruye la trama desde cero en un uint16_t core_enviado.
      * Bit 0 debe ser la Paridad Par de todos los bits de posiciones 
        impares de la trama (1, 3, 5, 7, 9, 11, 13, 15).
      * Bit 1 debe ser la Paridad Impar de todos los bits de posiciones 
        pares de la trama (2, 4, 6, 8, 10, 12, 14).
   ========================================================================= */

   #include <stdint.h>
   #include <stdio.h>
   #include <stdlib.h>

   int main(){
      
      system("cls");
      
      printf(" DESAFIO: PROTOCOLO OMNIBUS DE STARK INDUSTRIES\n\n");

      uint16_t nanotech_core = 0xC9B2; // 1100 1001 1011 0010
      uint16_t core_enviado = 0x00;

      //variables para desempaquetado de trama
      uint8_t avenger_id = 0x00, rep_ener = 0x00, nano_coor = 0x00, cod_seg = 0x00;

      avenger_id = (nanotech_core>>12);
      rep_ener = (nanotech_core>>6) &  0x3F;
      nano_coor = (nanotech_core >>2) & 0x0F;
      cod_seg = (nanotech_core>>0) & 0x03;

      //Fase 1
      uint8_t ver_avenger = (avenger_id >= 10);
      uint8_t ver_cod = (cod_seg != 0);
      uint8_t mask = ((1<<1)|(1<<0)), rotacion = 0x00;

      if (avenger_id < 10) return 0; 
      if (cod_seg == 0)    return 0;

      printf(" ID y codigo de autorizacion correctos: Continuando con la fase 2");
         if((nano_coor & mask)==0){
            rotacion = (rep_ener<<2);
            mask = (rotacion>>6);
            rep_ener = ((rotacion| mask) & 0x3F);
            cod_seg ^= (1<<0)|(1<<1);
         }

      //Fase 3
      core_enviado |= (avenger_id<<12);
      core_enviado |= (rep_ener<<6);
      core_enviado |=  (nano_coor<<2);
      core_enviado |= (cod_seg << 0);

      uint8_t contador = 0x00;
         
         // paridad par de impares
         for(int i=1;i<16;i+=2){
            if(core_enviado &(1<<i)){
               contador++;
            }
         }

         if((contador%2 ==0)){
            core_enviado &= ~(1<<0);
         }

         else{
            core_enviado |= (1<<0);
         }

         contador = 0x00;

         //paridad impar de pares
         for(int i=2;i<16;i+=2){
            if(core_enviado &(1<<i)){
               contador++;
            }
         }

         if((contador%2 ==0)){
            core_enviado |= (1<<1);
         }

         else{
            core_enviado &= ~(1<<1);
         }
         printf("\n Empaquetado inicial de trama: 0x%04X\n Reempaquetado final: 0x%04X\n\n",nanotech_core, core_enviado);

   }