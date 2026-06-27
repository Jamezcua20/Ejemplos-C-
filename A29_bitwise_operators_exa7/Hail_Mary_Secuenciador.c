/* =========================================================================
ENUNCIADO: SECUENCIADOR GENERAL DE LA HAIL MARY — EDICIÓN IMPLACABLE
============================================================================
Contexto: Los Astrofagos mutaron debido a la radiación. El espectrómetro 
capturó una trama de 16 bits (uint16_t). El software está desalineado 
y exige que para transmitir la nueva configuración, el paquete de datos 
sea reempaquetado desde cero cumpliendo con una Firma de Paridad Par 
calculada por software, o los motores eyectarán el combustible.

Mapa de Bits de la Telemetría de Emergencia (2 Bytes / uint16_t):
============================================================================
| Bits 15-12 (4b) | Bits 11-4 (8b)  | Bits 3-1 (3b)   |    Bit 0       |
| Nivel de Toxina | Absorcion Solar | Genoma Especie  |  Flag Ready    |
============================================================================
* Bits 15-12: Nivel de Toxina detectada (0 al 15 decimal).
* Bits 11-4:  Porcentaje de Absorción Solar (0 al 255 decimal).
* Bits 3-1:   Identificador de la Especie de Genoma (000 al 111 binario).
* Bit 0:      Flag Ready (1 = Lectura válida, 0 = Lectura inválida).

Tu Misión (Requerimientos Técnicos):

1. Entrada de Datos Fija:
   Declara la variable de telemetría corrupta extraída del sensor:
   uint16_t reg_hail = 0xFA35; // Binario: 1111 1010 0011 0101

2. Fase 1: El Filtro Anti-Falso Positivo:
   Verifica mediante álgebra de bits si el Bit 0 (Flag Ready) está en 1 
   Y si el Nivel de Toxina (Bits 15-12) es mayor o igual a 10 decimal. 
   - Si se cumple: Muestra "[SISTEMA]: Lectura de emergencia validada."
   - De lo contrario: Aborta el programa con return 0;.

3. Fase 2: Extracción y Modificación Algorítmica (Lógica Avanzada):
   Extrae las variables en contenedores independientes uint8_t usando 
   máscaras estáticas optimizadas (corrimiento y colador).
   - a) Extrae la Absorción Solar (Bits 11-4) y el Genoma (Bits 3-1).
   - b) Modificación Táctica: Si el Genoma es un número IMPAR (evalúa 
        el bit 0 del genoma extraído), debes:
        1. Reducir la Absorción Solar exactamente a la mitad de su valor
           actual usando un desplazamiento aritmético a la derecha.
        2. Invertir (Toggle) por completo los bits del Genoma de la 
           Especie (aplica XOR solo a sus 3 bits correspondientes).

4. Fase 3: Reconstrucción Total con Firma de Paridad Dinámica:
   Declara una variable vacía: uint16_t trama_enviada = 0x0000;
   - a) Empaqueta el Nivel de Toxina original, la nueva Absorción Solar 
        y el nuevo Genoma en sus casillas originales usando << y |.
   - b) Cálculo de Paridad de Red: El Bit 0 debe ser bit de Paridad Par.
        Desarrolla un bucle 'for' que recorra los bits del 1 al 15 de la 
        nueva trama_enviada para contar cuántos unos tiene en total.
        * Si la cantidad de unos es IMPAR: enciende el Bit 0 (trama |= 1) 
          para forzar que el gran total de unos sea par.
        * Si la cantidad de unos ya era PAR: asegura el Bit 0 en 0.
   - c) Imprime la trama_enviada final en Hexadecimal: (0x%04X).
============================================================================ */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main (){
  
  system("cls"); //Limpieza de terminal, solo valido en windows

  //Declaracion inicial de variables --- 
  uint16_t reg_hail = 0xFA35; // 1111 1010 0011 0101
  uint8_t toxinas = 0x00, abs_solar = 0x00, genoma = 0x00, contador = 0;
  uint16_t trama_enviada = 0x0000;
  printf("----SECUENCIADOR GENERAL DE LA HAIL MARY----");
  
  toxinas = (reg_hail>>12);
  
  //Fase 1
  if((reg_hail & (1<<0)) && (toxinas >= 10))
    printf("\nSISTEMA: Lectura de emergencia validada.");

  else{
    printf("\nSISTEMA: ALERTA: Datos inválidos. Abortando misión...");
    return 0;
  }
  //Fase 2
  abs_solar = ((reg_hail>>4) & 0xFF);
  genoma = ((reg_hail>>1)& 0x07);

  if(genoma%2 == 0){
  }
  else{ 
    abs_solar = (abs_solar>>1);

    printf("\n0x%04x", genoma);
    genoma ^= (genoma<<1) & 0x07;
    printf("\n0x%04x", genoma);
  }

  //Fase 3
  trama_enviada |= ((toxinas & 0x0F)<<12);
  trama_enviada |= ((abs_solar & 0xFF)<<4);
  trama_enviada |= ((genoma & 0x0E)<<1);


  for(int i=0;i<16;i++){
    if(trama_enviada &(1<<i))
      contador++;
  }

  if(contador %2 == 0){
    trama_enviada |= (0<<0);
  }
  else{
    trama_enviada |= (1<<0);
  }
  printf("\nTrama final del secuenciador: 0x%04X ", trama_enviada);

}