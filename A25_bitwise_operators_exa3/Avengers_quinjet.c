/* ===================================================================================
ENUNCIADO: PARSER DE TELEMETRÍA E INGENIERÍA DE PROTOCOLOS — AVENGERS QUINJET

Contexto: La base de datos de S.H.I.E.L.D. está recibiendo un paquete de datos crítico de 
16 bits (uint16_t) desde el Quinjet a través de un canal de comunicación UART. Para optimizar 
el ancho de banda, los ingenieros empaquetaron 5 variables distintas dentro de esta 
única trama de 2 bytes.

Tu Misión es actuar como el sistema embebido receptor: debes "desarmar" la trama, 
extraer la información (Payloads), ejecutar diagnósticos, modificar parámetros de seguridad 
y volver a empaquetar todo en una nueva trama de transmisión limpia.

Mapa de Bits de la Trama de 16 bits (uint16_t):
===================================================================================
| Bits 15-12 (4 bits) | Bits 11-4 (8 bits) | Bits 3-2 (2 bits) | Bit 1  | Bit 0   |
|   Nivel de Empuje   |   Temperatura Core |   Modo de Vuelo   | Escudo | Tren de |
|     (0 al 15)       |     (0 al 255)     |    (00 al 11)     | (0 ó 1)| Aterrizaje|
===================================================================================

Modos de Vuelo: 00 = Manual, 01 = Automático, 10 = Sigilo (Stealth), 11 = Emergencia.

Requerimientos Técnicos del Programa:

1. Entrada de Datos Fija:
   Declara la variable de entrada: `uint16_t trama_recibida = 0xB427;`
   (Dato en crudo enviado por el hardware del Quinjet).

2. Fase 1: Desempaquetado Quirúrgico (Unpacking):
   Utilizando únicamente operaciones AND (&) y Desplazamientos a la Derecha (>>), 
   extrae de forma aislada el valor de las 5 variables y guárdalas en variables 
   optimizadas independientes (uint8_t). Imprime los resultados en decimal en la terminal.
   *Tip de validación matemática:* El Empuje debe darte 11, la Temperatura 66, el Modo 1, 
   el Escudo 1 y el Tren 1.

3. Fase 2: Diagnóstico y Modificación por Software:
   Analiza las variables extraídas y realiza las siguientes modificaciones lógicas:
   a) Cambia el Modo de Vuelo de forma segura a "Modo Sigilo" (10 binario) utilizando 
      máscaras y operadores bitwise.
   b) El protocolo dicta que si la Temperatura del Core supera los 60 grados (lo cual 
      es cierto), el Tren de Aterrizaje (Bit 0) debe ser retraído inmediatamente (forzarlo a 0).
   c) Deja intactos el Nivel de Empuje y el Estado del Escudo.

4. Fase 3: Reempaquetado de Transmisión (Packing):
   Declara una variable vacía llamada `uint16_t trama_enviada = 0x0000;`. 
   Utilizando Desplazamientos a la Izquierda (<<) y el operador OR (|), toma tus 5 variables 
   (ya modificadas) y vuelve a unirlas para reconstruir la estructura original de 16 bits.
   
5. Salida de Telemetría:
   Muestra en pantalla el valor final de 'trama_enviada' en formato Hexadecimal en mayúsculas.

   Reglas de Validación de Código (Filtro Anti-Novatos)
Queda estrictamente prohibido usar estructuras condicionales (if/else) para alterar los bits del Modo de Vuelo en la Fase 3. Todo el empaquetado y desempaquetado debe hacerse mediante álgebra de bits pura en una línea por variable.

El if solo lo tienes permitido para evaluar la condición de la Temperatura en la Fase 2b.
=================================================================================== */

// Honestamente, ni yo sé pq me estoy complicando la vida con este repositorio

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // esta solo la incluyo pq no me gusta tener la terminal sucia

int main (){
    system("cls");
    //Entrada simulada
    uint16_t trama_recibida = 0xB427;

    //Fase 1
    //Comenzamos la fase 1 declarando las variables que usaremos para empaquetar individualmente
    uint8_t n_empuje = 0x00, c_temp = 0x00 , m_vuelo = 0x00, escudo = 0x00, t_aterrizaje = 0x00;
    n_empuje      =  (trama_recibida>>12) & 0x0F;
    c_temp        =  (trama_recibida >> 4) & 0xFF;
    m_vuelo       =  (trama_recibida>>2) & 0x03;
    escudo        =  (trama_recibida>>1) & 0x01;
    t_aterrizaje  =  (trama_recibida>>0)  & 0x01;
    printf("\n --- Hexadecimal --- \nNivel de empuje:0x%02x\nTemperatura Core: 0x%02x\nModo de vuelo: 0x%02x\nEscudo: 0x%02x\nTren de aterrizaje: 0x%02x",n_empuje,c_temp,m_vuelo,escudo,t_aterrizaje);
    printf("\n --- Decimal --- \nNivel de empuje: %d\nTemperatura Core: %d\nModo de vuelo: %d\nEscudo: %d\nTren de aterrizaje:%d",n_empuje,c_temp,m_vuelo,escudo,t_aterrizaje);
    
   m_vuelo = (m_vuelo & 0x00) | (1 << 1); // Borra todo y enciende solo el bit 1 -> '10'
   printf("\n --- Hexadecimal --- \nNivel de empuje:0x%02x\nTemperatura Core: 0x%02x\nModo de vuelo: 0x%02x\nEscudo: 0x%02x\nTren de aterrizaje: 0x%02x",n_empuje,c_temp,m_vuelo,escudo,t_aterrizaje);
}