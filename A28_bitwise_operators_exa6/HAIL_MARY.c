/* ===================================================================================
ENUNCIADO: SECUENCIADOR DE ASTROFAGOS — PROJECT HAIL MARY (EL RETO IMPLACABLE)

Contexto: Ryland Grace se encuentra a bordo de la Hail Mary analizando el comportamiento 
de los Astrofagos (los organismos que están consumiendo la energía del Sol). El espectrómetro 
de la nave le entrega un paquete de datos compactado en una variable de 16 bits (uint16_t).

El software automático de la nave está dañado por la radiación cósmica. Debes reprogramar 
manualmente el algoritmo de diagnóstico y control del secuenciador. El problema es que las 
variables están cruzadas y desalineadas, y el hardware exige una serie de validaciones 
estrictas antes de aceptar una modificación en los registros.

Mapa de Bits de la Telemetría Astrofágica (2 Bytes / uint16_t):
===================================================================================
| Bits 15-12 (4 bits) | Bits 11-4 (8 bits) | Bits 3-1 (3 bits) |   Bit 0   |
|   Nivel de Toxina   |   Absorcion Solar  |  Genoma Especie   | Flag Ready|
===================================================================================
* Bits 15-12: Nivel de Toxina detectada (0 al 15 decimal).
* Bits 11-4:  Porcentaje de Absorción Solar del organismo (0 al 255 decimal).
* Bits 3-1:   Identificador de la Especie de Genoma (000 al 111 binario).
* Bit 0:      Flag Ready (1 = Datos listos y estables, 0 = Lectura inválida/ruido).

Tu Misión (Requerimientos Técnicos):

1. Entrada de Datos Fija:
   Declara la variable de telemetría original recibida del sensor espacial:
   `uint16_t reg_hail = 0xF5A1;` // Binario: 1111 0101 1010 0001

2. Fase 1: Validación del Sensor Embebido (El Interruptor Maestro):
   Antes de hacer cualquier cálculo, el sistema exige verificar el estado del sensor.
   - Usando un condicional 'if' y álgebra de bits pura, verifica si el Bit 0 (Flag Ready) 
     está en 0. Si está en 0, significa que el sensor está apagado o corrupto. 
     Debe imprimir un error y matar el programa con un `return 0;`.
   *(Validación de escritorio: En 0xF5A1 el Bit 0 vale 1, por lo que tu programa debe 
     ignorar el error y continuar de forma segura).*

3. Fase 2: Extracción y Análisis Clínico (Análisis sin alterar la entrada):
   Extrae las variables en contenedores independientes optimizados (`uint8_t`) moviéndolas 
   a la casilla cero con '>>' y limpiando con '&'.
   - a) Extrae el Nivel de Toxina (Bits 15-12). Si es exactamente igual a 15 (0x0F), 
        imprime: "[CRITICO]: Toxina al maximo nivel. Sistema en riesgo."
   - b) Extrae la Absorcion Solar (Bits 11-4).
   - c) Extrae el Genoma de la Especie (Bits 3-1).
   - d) Evaluación de Soporte Vital: El protocolo dicta que si la Absorción Solar es menor 
        al 40% (es decir, menor a 40 decimal) O si el Genoma de la Especie es exactamente 
        igual a 0 (Mutación desconocida), se debe activar de inmediato el soporte vital. 
        Muestra en pantalla si se activa o no.

4. Fase 3: Modificación del Registro y Cierre de Ciclo (La parte Difícil):
   Una vez analizados los datos, el hardware de la Hail Mary te exige apagar el Bit 0 
   (Flag Ready = 0) para indicarle al sensor físico que el procesamiento terminó y puede 
   empezar a tomar otra lectura en el espacio.

   - Modifica ÚNICAMENTE el Bit 0 del registro original `reg_hail` para apagarlo de forma 
     quirúrgica sin usar 'if' ni reempaquetar todo desde cero. Aplica una máscara de apagado 
     directa que deje los otros 15 bits intactos.
   - Imprime el valor final modificado de `reg_hail` en formato Hexadecimal de 4 dígitos 
     en mayúsculas (`0x%04X`).
=================================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (){

    system ("cls");
    
    // Declaracion de variables de registro
    uint16_t reg_hail = 0xF5A1;
    uint8_t n_toxina = 0, abs_solar = 0, genoma = 0, flag_r = 0;
    printf("Bienvenido a la Hail Mary Dr Grace \nIncializando dignosticos...");

    //Fae 1: Validacion
    if((reg_hail &(1<<0))==0){
        printf("\nError: sensor apagado o trama de datos corrupta");
        return 0;
    }

    else 
        printf("\nSensor operativo. Continuando con el procedimiento...");

    //Fase 2: Extracción y Análisis Clínico 
    printf("\nExtrayendo valores...");
    n_toxina = (reg_hail>>12);
    abs_solar = (reg_hail>>4) & 0xFF;
    genoma = (reg_hail>>1)  & 0x07;
    flag_r = (reg_hail>>0) & 0x01;

    //0x28 es 40 en decimal
    if(abs_solar<0x28 || genoma == 0x00)
      printf("\nActivando soporte vital...");
    else
      printf("\nDesactivando soporte vital...");

    // Fase 3: Modificación del Registro 
    reg_hail &= ~(1<<0);

    printf("\nValor modificado Hail_REG: 0x%04X",reg_hail);
}