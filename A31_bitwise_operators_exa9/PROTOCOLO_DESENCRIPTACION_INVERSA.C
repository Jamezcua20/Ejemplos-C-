/* =========================================================================
   DESAFÍO 2: RESIDENT EVIL — SECUENCIADOR NÉMESIS (EXPERTO)
   =========================================================================
   Contexto: Jill Valentine está herida. Leon S. Kennedy encuentra una 
   consola de Umbrella para sintetizar un antígeno. El sistema se protege 
   de la radiación electromagnética usando un empaquetado de 16 bits.

   Mapa de Bits del Registro (uint16_t nemesis_payload):
   =========================================================================
   | Bits 15-11 (5b) |    Bits 10-4 (7b)    | Bits 3-1 (3b) |     Bit 0     |
   |  Carga Inmune   | Estabilización Huésped| Cepa Viral    | Flag Necrosis |
   =========================================================================
   * Bits 15-11: Carga Inmune Sintética (0 a 31 decimal).
   * Bits 10-4:  Nivel de Estabilización del Huésped (0 a 127 decimal).
   * Bits 3-1:   Tipo de Cepa Viral (000 a 111 binario).
   * Bit 0:      Flag de Inhibición de Necrosis (1=Estable, 0=Crítica).

   Tu Misión (Requerimientos Técnicos):

   1. Entrada de Datos Fija:
      uint16_t nemesis_payload = 0x3E7B;

   2. Fase 1: Filtro Multivariable:
      Usando álgebra de bits pura, verifica si el Flag de Inhibición (Bit 0) 
      está apagado. Si está en 0, aborta con return 0;, A MENOS que el Tipo 
      de Cepa Viral (Bits 3-1) sea exactamente igual a 7 (111 binario), en 
      cuyo caso se permite continuar.

   3. Fase 2: Prevención de Desborde (Bit Bleeding):
      Extrae la Carga Inmune Sintética (Bits 15-11). El protocolo exige 
      multiplicar este valor por 4 usando desplazamientos a la izquierda.
      [PELIGRO]: Al multiplicar, el valor puede superar los 5 bits máximos 
      (31 dec). Diseña una máscara hexadecimal con la regla 8-4-2-1 para 
      truncar de forma estricta los bits excedentes, asegurando que al 
      reempaquetar, el valor jamás corrompa al campo contiguo.

   4. Fase 3: Reconstrucción Dinámica:
      Declara una variable vacía y vuelve a integrar los elementos nuevos. 
      Calcula un bit de paridad par global en el Bit 0 recorriendo los bits 
      del 1 al 15 mediante un bucle for.
   ========================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (){

    system("cls");

    // Entrada de datos fija
    uint16_t nemesis_payload = 0x3E7B; // 0011 1110 0111 1011
    uint16_t nemesis_payload_repacked = 0x00;

    // Desempaquetado
    uint8_t cepa = 0x00;
    uint8_t necrosis = 0x00;
    uint8_t carga_inmun = 0x00;
    uint8_t estabilizacion_huesp = 0x00;
    cepa = (nemesis_payload>>1) & 0X07;
    necrosis = nemesis_payload & 0X01;
    carga_inmun = (nemesis_payload>>11) & 0X1F;
    estabilizacion_huesp = (nemesis_payload>>4) & 0x7F;

    // Conteo 
    int8_t contador = 0x00;

    printf("\nCONSOLA DE UMBRELLA CORP. - SECUENCIADOR NEMESIS v2.4");

     // Fase 1
    if(necrosis == 0x00){
        
        if(cepa == 0x07){
            printf("\nTipo de cepa admisible");
        }
        else{
            printf("\nEstado critico: No se puede continuar");
            return 0;
        }
    }

    else{
        printf("\nFlag de Inhibicion de Necrosis en estado estable\nIniciando Fase 2...");
    }

    //  Fase 2
    carga_inmun = (carga_inmun << 2) & 0x1F;

    // Fase 3
    nemesis_payload_repacked |= (carga_inmun<<11);
    nemesis_payload_repacked |= (estabilizacion_huesp<<4);
    nemesis_payload_repacked |= (cepa<<1);
    nemesis_payload_repacked |= (necrosis<<0);

    for(int i=1;i<16;i++){
        if(nemesis_payload_repacked &(1<<i)){
            contador++;
        }
    }

    if(contador%2==0){
        nemesis_payload_repacked &= ~(1<<0);
    }

    else
        nemesis_payload_repacked |= (1<<0);

    // Datos final 
    printf("\n----------------------------------------------------------");
    printf("\nSINTESIS EXITOSA: Configuracion de antigeno estabilizada.");
    printf("\nTrama Original:     0x%04X\n", nemesis_payload);
    printf("Recconstruccion Final:  0x%04X", nemesis_payload_repacked);
    printf("\n----------------------------------------------------------");

}