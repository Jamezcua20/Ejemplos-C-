/* =====================================================================
   DESAFÍO 4: BATMAN — PROTOCOLO DE CONTINGENCIA "BABEL" (DEIDAD)
   =====================================================================
   Contexto: El Acertijo alteró los amortiguadores de la Batcomputadora.
   Para restaurarlos se debe procesar un bypass vectorial de 16 bits.

   Mapa de Bits del Registro (uint16_t bat_word):
   =====================================================================
   | Bits 15-13 (3b) |     Bits 12-5 (8b)      | Bits 4-1 (4b) | Bit 0 |
   |    ID Sensor    |  Frecuencia de Hackeo   | Sub-sistema   | Override
   =====================================================================
   * Bits 15-13: Código de Identificación del Sensor Perimetral.
   * Bits 12-5:  Frecuencia de la Señal de Hackeo de Enigma.
   * Bits 4-1:   Sub-sistema de Seguridad Bloqueado.
   * Bit 0:      Switch de Override Maestro (1 = Activo).

   Tu Misión (Requerimientos Técnicos):

   1. Entrada de Datos Fija:
      uint16_t bat_word = 0x739F;

   2. Fase 1: Filtro por Máscara Dinámica Clonada:
      El Override (Bit 0) debe estar activo. Aísla la Frecuencia (12-5).
      Esta frecuencia debe coincidir exactamente con una máscara que
      debes generar dinámicamente en el aire: toma el ID Sensor (15-13),
      clónalo en los bits altos y bajos de un contenedor intermedio de
      8 bits, e inviértelo completamente. Todo con álgebra de bits pura.
      Si no coincide el patrón, aborta la ejecución con return 0;.

   3. Fase 2: Espejo y Conversión a Código Gray (Sin Bucles):
      Extrae el Sub-sistema (4-1). Invierte el orden de sus 4 bits en
      espejo (el bit 3 pasa al 0, el 2 al 1, etc.). Al valor resultante
      transfórmalo a su equivalente en Código Gray Binario utilizando
      exclusivamente una operación de corrimiento y una compuerta XOR.

   4. Fase 3: Firma Entrópica Cruzada con Barrel Shift:
      Reempaqueta los elementos en un uint16_t firewall_clear. Antes de
      las firmas, aplica una rotación circular (Barrel Shift) de 3
      posiciones a la izquierda a toda la trama. Finalmente, configura
      el Bit 0 para forzar paridad par evaluando solo las posiciones de
      bits pares (2,4,6,8,10,12,14), y el Bit 8 para forzar paridad
      impar evaluando solo las posiciones de bits impares (1,3,5,7,9,
      11,13,15).
   ===================================================================== */


#include <stdio.h>
#include <stdlib.h>    
#include <stdint.h>

int main(void) {

    system("cls");

    // 1. ENTRADA DE DATOS
    uint16_t bat_word = 0x739F;
    printf("_________________________________________\n\n");
    printf(" BATCOMPUTADORA - PROTOCOLO BABEL\n");
    printf("_________________________________________\n\n");
    printf("Trama recibida:         0x%04X\n\n", bat_word);

    // Variables para empaquetado 
    uint8_t override = 0x00, sub_system = 0x00, hacking_frecquency = 0x00, sensor_ID = 0x00, sub_system_inverted = 0x00;
    uint16_t firewall_clear = 0x00;

    // variables extra
    uint8_t mask = 0x00, gray = 0x00, contador = 0x00;

    //Desempaquetado de la trama
    sensor_ID = (bat_word>>13) & 0x07;
    hacking_frecquency = (bat_word>>5) & 0xFF;
    sub_system = (bat_word>>1) & 0x0F;
    override = (bat_word>>0) & 0x01;

    //printf("\n0X%02X \n0X%02X \n0X%02X \n0X%02X", sensor_ID, hacking_frecquency, sub_system, override);

    if(override == 0){
      printf("\nOverride maestro desactivado.");
      printf("\nAbortando protocolo BABEL.");
      return 0;
    }

    mask = ((sensor_ID<<5)| (sensor_ID<<0));
    mask = ~mask;
    // printf("\n0X%02X \n0X%02X", mask, hacking_frecquency);


    if(hacking_frecquency != mask){
      printf("\nLa frecuencia no coincide con la mascara generada.");
      printf("\nAbortando protocolo BABEL.");
      return 0;  
    }
    
    printf("FASE 1: Verificacion de seguridad\n");
    printf("Override:\t 0x%02X\n", override);
    printf("ID del sensor:\t 0x%02X\n", sensor_ID);
    printf("Frecuencia:\t 0x%02X\n", hacking_frecquency);
    printf("Mascara:\t 0x%02X", mask);

    sub_system_inverted = ((sub_system & 0x01) << 3) |  // Bit 0 pasa a Bit 3
                          ((sub_system & 0x02) << 1) |  // Bit 1 pasa a Bit 2
                          ((sub_system & 0x04) >> 1) |  // Bit 2 pasa a Bit 1
                          ((sub_system & 0x08) >> 3);   // Bit 3 pasa a Bit 0

    gray = sub_system_inverted ^ (sub_system_inverted>>1);
    //printf("\n0X%02X ", gray);

    printf("\n\nFASE 2: Conversion del sub-sistema");
    printf("\nSub-sistema:\t 0x%X", sub_system);
    printf("\nEspejo:   \t 0x%X", sub_system_inverted);
    printf("\nCodigo Gray:\t 0x%X\n", gray);

    firewall_clear |= (override<<0); 
    firewall_clear |= (gray<<1);
    firewall_clear |= (hacking_frecquency<<5); 
    firewall_clear |= (sensor_ID<<13); 
    //printf("\nReempaquetado: 0X%02X ", firewall_clear);

    firewall_clear = (firewall_clear << 3) | (firewall_clear >> 13);
    // printf("\nRotado: 0X%02X ", firewall_clear);
    
    
    //Paridad impar bits impares
    for(uint8_t i=1;i<16;i+=2){
      if(firewall_clear &(1<<i))
        contador ++;
    }

    if(contador % 2 == 0x00){
      firewall_clear |= (1<<8);
    }
    
    else
      firewall_clear &= ~(1<<8);

    //Paridad par bits pares
    contador = 0x00;

    for(uint8_t i=2;i<16;i+=2){
      if(firewall_clear &(1<<i))
        contador ++;
    }

    if(contador % 2 == 0x00){
      firewall_clear &= ~(1<<0);
    }
    
    else
      firewall_clear |= (1<<0);
    
    printf("_________________________________________\n\n");
    printf(" FIREWALL RESTAURADO\n");
    printf("_________________________________________\n\n");
    printf("Resultado final:       0x%04X\n", firewall_clear);
}