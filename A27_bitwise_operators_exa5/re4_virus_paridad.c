/* ===================================================================================
ENUNCIADO: INYECTOR DE ANTÍDOTO BIOLÓGICO — RESIDENT EVIL (MÁSCARAS DINÁMICAS Y PARIDAD)

Contexto: Leon S. Kennedy está atrapado en los laboratorios subterráneos de Umbrella. Su 
cuerpo ha sido infectado con el Virus Las Plagas. Encuentra un dispositivo electrónico 
médico automático para inyectarse el antígeno. El dispositivo analiza la sangre de Leon y 
guarda los datos de infección y control en un registro de 1 Byte (uint8_t). 

Para que el antídoto se libere de forma segura, el microcontrolador del inyector exige 
que el registro pase una prueba rigurosa de integridad basada en la paridad de bits, 
evitando que mutaciones en el código activen una dosis letal.

Mapeo del Registro de Diagnóstico Médico (1 Byte / uint8_t):
===================================================================================
| Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 |       Bit 0       |
|  Mut. |  Mut. | Carb. | Carb. | Sint. | Sint. | Est.  |   Bit de Paridad  |
|  Plaga|  Plaga| Sangre| Sangre| Fiebre| Infec.| Inyec.|   (Bit de Control)|
===================================================================================
* Bits 7-6: Nivel de mutación celular (00 = Normal, 01 = Alerta, 10 = Mutación Activa, 11 = Crítico)
* Bits 5-4: Carbono en sangre (00 a 11)
* Bit 3: Sintomatología de Fiebre (1 = Activo, 0 = Inactivo)
* Bit 2: Sintomatología de Infección Avanzada (1 = Activo, 0 = Inactivo)
* Bit 1: Estado del Inyector Neumático (1 = Bloqueado/Seguro, 0 = Desbloqueado/Listo)
* Bit 0: Bit de Paridad Impar (Control de integridad)

Tu Misión (Requerimientos Técnicos):

1. Entrada de Datos Fija:
   Declara el registro corrupto inicial que el dispositivo lee de la sangre de Leon:
   `uint8_t reg_medico = 0xCE;` // Binario: 11001110

2. Fase 1: Verificación de Integridad (Filtro Anti-Ruido de Hardware):
   El sistema de Umbrella utiliza "Paridad Impar" en el Bit 0. Esto significa que si sumas 
   la cantidad de '1s' que hay del Bit 7 al Bit 1, el total de unos DEBE ser un número IMPAR.
   a) Desarrolla un algoritmo que use un bucle 'for' y un desplazamiento a la derecha '>>' 
      para contar cuántos bits están encendidos (en 1) desde el Bit 1 hasta el Bit 7 de la variable.
   b) Con un condicional 'if' usando el operador módulo '%', verifica si la cuenta de unos es 
      un número par. Si es par, significa que los datos se corrompieron en el bus o la Plaga los alteró. 
      Imprime en pantalla: "[ERROR]: Datos corruptos o interferencia parasitaria. Inyector Bloqueado." 
      y finaliza el programa inmediatamente con un `return 0;`.
   *Tip de validación:* Para el valor 0xCE, los bits del 1 al 7 tienen exactamente cinco '1s' (1100111). 
   Como 5 es impar, tu validación debe pasar con éxito y continuar el programa.

3. Fase 2: Diagnóstico Clínico (Aislamiento de Bits):
   Si la integridad es correcta, el programa continúa. Extrae los siguientes datos utilizando 
   desplazamientos y máscaras:
   a) Extrae el "Nivel de mutación celular" (Bits 7 y 6) en una variable independiente `uint8_t mutacion;`. 
      Si el valor es igual a 3 (Crítico), imprime: "[ALERTA]: Mutacion celular en estado CRITICO."
   b) Evalúa si la Fiebre (Bit 3) Y la Infección Avanzada (Bit 2) están encendidas AL MISMO TIEMPO. 
      Usa la técnica de la Súper-Máscara combinada con OR para el 'if'. Si es verdadero, imprime: 
      "[DIAGNOSTICO]: Sintomatologia severa detectada."

4. Fase 3: Liberación del Antídoto (Modificación Quirúrgica):
   Para salvar la vida de Leon, debes realizar tres operaciones bitwise estrictas sobre `reg_medico`:
   a) Forzar de forma segura el "Nivel de mutación celular" (Bits 7 y 6) a 00 (Normal) usando el 
      operador `&= ~` con una máscara combinada para limpiar las casillas de golpe.
   b) Desbloquear el Inyector Neumático poniendo el Bit 1 en 0 (Listo para disparar).
   c) Imprimir el estado final del registro médico en formato Hexadecimal (`0x%02X`).
=================================================================================== */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int main (){
    system("cls");

    printf("--- DISPOSITIVO MEDICO AUTOMATICO - UMBRELLA CORP. ---");

    // Declaracion de variables
    uint8_t reg_medico = 0xCE;
    uint8_t contador = 0;
    uint8_t mutacion = 0;

    // Fase 1: Verificación de Integridad 
    printf("\nVerificando integridad de la muestra de sangre...");
    printf("\nContador de bits en 1 (Bits 1 al 7)");
    for(uint8_t i = 1; i<8;i++){
        if(reg_medico &(1<<i))
            contador++;
    }
    
    printf("\nBits detectados: %hhu", contador);

    if(contador%2 == 0){
       printf("\nDatos corruptos o interferencia parasitaria. Inyector Bloqueado."); 
       reg_medico &= ~(1<<0); // Ajustamos bit de paridad
       return 0;
    }

    else{
        printf("\nParidad impar correcta. Datos validos.\nInyector desbloqueado."); 
        reg_medico |= (1<<0); // Ajustamos bit de paridad
    }

    // Fase 2: Diagnóstico Clínico
    mutacion = (reg_medico>>6);
    printf("\nVerificando nivel de mutacion celular...");
    if(mutacion == 3)
        printf("\nMutacion celular en estado CRITICO.");
    
    uint8_t mascara_sintomas = (1 << 3) | (1 << 2);
    if((reg_medico & mascara_sintomas) == mascara_sintomas)
        printf("\nSintomatologia severa detectada.");

    // Fase 3: Liberación del Antídoto
    printf("\nLiberando Antigeno...");
    reg_medico &= ~((1 << 7) | (1 << 6)); 
    if(reg_medico & ((1<<6)&(1<<7)))
            printf("\nNivel de mutacion revertido a normal."); 

    reg_medico &= ~(1<<1);
    printf("\nInyector manual desbloqueado.");
    printf("\nRegistro medico final: 0x%02X", reg_medico);
}
