/* 

Antes que nada quiero aclarar, que fue la IA la que planteó el problema, yo solo hago el código
si esta muy esquizofrenico el asunto, ya no fue cosa mía.

=====================================================================
DESAFÍO 5: CROSSOVER — ANOMALÍA INTERDIMENSIONAL OMEGA
========================================================================
Contexto: Un colapso temporal fusionó los servidores de Umbrella Corp
con la computadora de la Hail Mary. Leon S. Kennedy y Ryland Grace
deben procesar una transmisión crítica que regula la contención de 
un reactor.

Mapa de Bits de la Anomalía (uint16_t omega_anomaly):
========================================================================
| Bits 15-11 (5b) | Bits 10-6 (5b) | Bits 5-2 (4b)     | Bits 1-0 (2b) |
| Carga Patógeno  | Estabilización | ID del Operador   | Flags Emerg.  |
========================================================================
* Bits 15-11: Carga de Patógeno de Astrofagos Combinados.
* Bits 10-6:  Nivel de Estabilización Magnética del Núcleo.
* Bits 5-2:   ID de Firma del Operador:
              (Leon=0x5, Grace=0xA, Umbrella=0xF).
* Bits 1-0:   Flags de Estado de Emergencia Interdimensional.

Tu Misión (Requerimientos Técnicos):

1. Entrada de Datos Fija:
   uint16_t omega_anomaly = 0xE27D; // Calibración segura: 0xE257    ** 0xE26B

2. Fase 1: Filtro Biométrico Ciego
   El programa solo continúa si el ID del Operador (Bits 5-2)
   corresponde exactamente a Leon (0x5) o a Grace (0xA).
   [PROHIBIDO]: usar operadores relacionales tradicionales
   (==, !=, <, >) o lógicos (||, &&). Valida la igualdad aplicando
   exclusivamente operaciones XOR (^) y operadores de negación (~).
   Si falla, imprime un error y aborta la ejecución con return 0;.

3. Fase 2: Enmascaramiento Dinámico con Clave Cruzada
   Extrae la Carga de Patógeno (15-11) y la Estabilización (10-6).
   LÓGICA: Si los Flags de Emergencia (Bits 1-0) son iguales a 3
   (11 binario), la Carga de Patógeno se modifica con una operación 
   XOR usando como clave los 5 bits de la Estabilización Magnética.
   Calcula tus máscaras en hexadecimal con la regla 8-4-2-1.

4. Fase 3: Checksum de Nibbles Exclusivo
   Vuelve a empaquetar todos los componentes en sus posiciones.
   Para validar, calcula un código de verificación de 2 bits en los
   Bits 1-0 haciendo una operación XOR sucesiva entre los tres
   nibbles superiores de la trama reconstruida (Bits 15-12, 
   Bits 11-8 y Bits 7-4).
   Imprime la trama en formato hexadecimal de 4 dígitos en
   mayúsculas (0x%04X).
======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){

   system("cls");

   // Declaración inicial de variables
   uint16_t omega_anomaly = 0xE26B; 
   uint16_t omega_anomaly_solved = 0x00;

   // Trama desempaquetada 
   uint8_t patogenos_c = 0x00, estabilizacion = 0x00, id = 0x00, flags = 0x00;
   
   // Extras
   uint8_t leon_op = 0x00, grace_op = 0x00, op = 0x00, nibble_xor = 0x00;

   patogenos_c = (omega_anomaly>>11) & 0x1F;
   estabilizacion = (omega_anomaly>>6) & 0x1F;
   id = (omega_anomaly>>2) & 0x0F;
   flags = omega_anomaly & 0x03;

   // FASE 1 -----------------------------------------------------------------------------------------------------------------
   
   leon_op = (id ^ 0x5); // Si Leon es operador el XOR nos dará 0

   if(leon_op){ // El if responde, si es 0 no entra, si es cualquier otro numero, entra
      grace_op = (id ^ 0xA); // Entrará en caso de que Leon no es operador y verifica el ID de Grace
      
      if(grace_op){  // Mismo caso de con Leon, si es operador XOR da 0, si no es, entra al condicional, si es entra al else
         printf("\nNo se reconocen operadores validos");
         leon_op =0x01; grace_op = 0x01;
      }
      else{
            printf("\nOperador detectado.\nBienvenido, Dr. Grace"); //En caso de que el XOR de 0, no entra al condicional, por lo tanto, Grace es el operador
            grace_op = 0x00; leon_op = 0x00;
         }
   }

   else{
      leon_op = 0x00;  grace_op = 0x00;
      printf("\nOperador detectado.\nBienvenido, Sr. Kennedy"); //En caso de que el XOR de 0, no entra al condicional, por lo tanto, Leon es el operador
   }

   op = (leon_op | grace_op); // Hace un Or, si hay un operador valido el resultado es 0, haciendo que el condicional sig. no se active
   //printf("\n0X%02X", op);

   if(op){ //Si ninguno es operador salta condicional
      printf("\nNo es posible continuar con la operacion\nOperador no valido\nCerrando terminal...");
      return 0;
   }

      // FASE 2 -----------------------------------------------------------------------------------------------------------------

      if(flags == 0x03){
         patogenos_c = (patogenos_c ^ estabilizacion) & 0x1F;
      }

      // FASE 3 -----------------------------------------------------------------------------------------------------------------      

      omega_anomaly_solved |= (patogenos_c<<11);
      omega_anomaly_solved |= (estabilizacion<<6);
      omega_anomaly_solved |= (id<<2);
      omega_anomaly_solved |= (flags);

      //printf("\nomega_anomaly Solved: 0x%04X", omega_anomaly_solved);

      nibble_xor = ((omega_anomaly_solved>>12)^(omega_anomaly_solved>>8)) ;
      nibble_xor = ((omega_anomaly_solved>>4)^ nibble_xor) & 0x03;
      //printf("\nNibble xor Solved: 0x%02X", nibble_xor);

      omega_anomaly_solved &= ~((1<<0) | (1<<1));
      //printf("\nomega_anomaly Solved: 0x%04X", omega_anomaly_solved);
      omega_anomaly_solved |= nibble_xor & 0x03;
      //printf("\nomega_anomaly Solved: 0x%04X", omega_anomaly_solved);

      printf("\n\n--------------------------------------------------");
      printf("\n   SISTEMA DE CONTENCION CORREGIDO");
      printf("\n--------------------------------------------------");
      printf("\n Carga Patogeno (Mutada):\t0x%02X", patogenos_c);
      printf("\n Estabilizacion Nucleo:   \t0x%02X", estabilizacion);
      printf("\n Codigo Verificacion (CRC):\t0x%02X", nibble_xor);
      printf("\n--------------------------------------------------");
      printf("\n TRAMA TRANSMITIDA:\t\t0x%04X", omega_anomaly_solved);
      printf("\n--------------------------------------------------");

}