/*
Contexto: Estás programando el núcleo del Bat-ordenador en la Batcueva. Los sensores urbanos distribuidos por Gotham envían un reporte en un solo byte (uint8_t) que indica el estado del crimen en un sector específico. Tu trabajo es analizar las banderas de estado (Flags) mediante álgebra de bits pura y activar contramedidas automáticas.

Mapeo del Registro de Diagnóstico (uint8_t RE_AMENAZA):

Bit 7: Gas del Miedo detectado (Scarecrow)

Bit 6: Toxina de la Risa detectada (Joker)

Bit 5: Temperatura bajo cero extrema (Mr. Freeze)

Bit 4: Red de cámaras hackeada

Bit 3: Bat-Señal encendida físicamente en el techo de la Jefatura

Bit 2: Interrupción de comunicaciones (Blackout)

Bit 1: Presencia de rehenes en el sector

Bit 0: Alerta de motín en Arkham Asylum

Tu Misión (Requerimientos Técnicos):

Entrada de Datos Fija:
Declara la variable simulada con un escenario crítico inicial:
uint8_t re_amenaza = 0x8A; // (Equivale a binario 10001010)

Fase 1: Análisis Diagnóstico (Lectura Avanzada):
Desarrolla las siguientes validaciones lógicas usando exclusivamente operadores Bitwise dentro de los condicionales (if). Está prohibido usar operadores lógicos tradicionales como && o ||.

Caso A: Si el Gas del Miedo (Bit 7) O la Toxina de la Risa (Bit 6) están activos, muestra en pantalla un mensaje indicando que se requiere el Bat-traje con filtro NBQ (Nuclear, Biológico, Químico). (Pista: evalúa ambos bits con una sola máscara usando una operación AND).

Caso B: Verifica si el sector tiene Presencia de rehenes (Bit 1) pero las Comunicaciones están caídas (Bit 2). Muestra un mensaje advirtiendo que es una emboscada silenciosa.

Fase 2: Intervención Táctica (Modificación de Bits):
Fuera de los condicionales, ejecuta las siguientes órdenes tácticas sobre la variable original:

a) Enciende de manera inmediata la Bat-Señal (Bit 3) sin alterar a sus vecinos.

b) Desactiva de forma quirúrgica la alerta de Red de cámaras hackeada (Bit 4) asumiendo que Oracle recuperó el control del sistema de seguridad.

c) Invierte (Toggle) el estado de la alerta de Motín en Arkham (Bit 0) para simular un cambio de estado en los servidores del asilo.

Fase 3: Reporte Hexadecimal:
Imprime en la pantalla de la terminal el valor final del registro re_amenaza en formato Hexadecimal de 2 dígitos en mayúsculas (0x%02X) para enviarlo a la bati-computadora del Batmóvil.

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main (){
    
    uint8_t RE_AMENAZA = 0x8A;

    // Fase 1: Análisis Diagnóstico
    if(RE_AMENAZA &((1<<7)|(1<<6)))
        printf("\nRiesgo biologico detectado: Se requiere el Bat-traje con filtro NBQ (Nuclear, Biologico, Quimico).");

    if(RE_AMENAZA &((1<<1)&(1<<2)))
        printf("\nSituación de rehenes, comunicaciones caidas, posible emboscada, tener precaución");
    
    // Fase 2: Modificación de Bits

    RE_AMENAZA |= (1<<3);
    printf("\n 0x%02x", RE_AMENAZA);
    RE_AMENAZA &= ~(1<<4);
    printf("\n 0x%02x", RE_AMENAZA);


}