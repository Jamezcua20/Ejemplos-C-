/*
Cabe aclarar, que esto fue propuesto por chagpt y resuelto por mi, por si suena esquizo el contexto

El Escenario: La Tierra está bajo ataque. Un cinturón de 6 asteroides se dirige hacia el planeta. 
El satélite de defensa de Industrias Stark ha escaneado los asteroides y ha registrado dos vectores de datos críticos en memoria RAM:

 * El tamaño de los asteroides (en metros).

 * Su distancia actual al planeta (en miles de kilómetros).

Como el reactor del satélite tiene energía limitada, solo tienes potencia para destruir un número limitado de objetivos,
 por lo que el sistema automático debe priorizar y calcular la estrategia de impacto.

=== DESAFÍO NIVEL VENGADORES: VERONICA ===

Tu programa debe:
1. Declarar DOS arreglos de tipo 'float' de 6 elementos cada uno:
   - 'masa_asteroide' (en toneladas)
   - 'distancia_tierra' (en miles de km)

2. Llenado de Datos: El usuario debe ingresar la masa y distancia de los 6 asteroides.

3. Filtro de Amenaza Crítica (The "Tony Stark" Filter):
   Un asteroide solo se considera "AMENAZA CRÍTICA" si cumple DOS condiciones simultáneas:
   - Su masa es MAYOR a 50 toneladas.
   - Su distancia es MENOR a 200 mil km.
   Crea un tercer arreglo binario llamado 'amenazas' (de 6 elementos), donde guardarás 
   un '1' si el asteroide es crítico, o un '0' si puede ser ignorado por ahora.

4. Cálculo de Impacto Inminente:
   Recorre los arreglos para encontrar cuál de todos los asteroides críticos es el 
   MÁS PELIGROSO (el que tiene la menor distancia a la Tierra). Reporta su índice 
   y su masa para enfocar el cañón láser.

5. Reporte de Estado Mayor:
   Imprime en pantalla:
   - El porcentaje de asteroides que representan una amenaza real.
   - El índice del asteroide más cercano que debe ser destruido de inmediato.
*/

// Si ven referencias a los vengadores, es siguiendo la tematica de la IA

#include <iostream>
using namespace std;

int main(){

    //1. Declaramos las variables
    float distancia_tierra[6]; // En miles de km
    float masa_asteroide[6]; // En toneladas
    int v_amenaza[6];
    float distancia = 200;
    int more_dan, contador = 0;
    float porcentaje = 0;

    // Impresion de mensajes iniciales, le seguimos el cotorreo a la IA
    printf("\nACCESO AUTORIZADO!\n \nBienvenido, servidor seguro Stark"); // Si no me falla la memoria, eso de servidor seguro sale en ironman 3
    printf("\nPosibles amenazas detectadas!\nProtocolos de seguridad no disponibles \nReactor Arc a niveles criticos\n");

    //2. Llenado de datos

    for(int i=0;i<6;i++){
        printf("Ingresar distancia de asteroiode %d en miles de km: ", i+1);
        cin>>distancia_tierra[i];
        printf("Ingresar peso de asteroiode %d en toneladas: ", i+1);
        cin>>masa_asteroide[i];
    }

    //3. Filtro de amenza. Creacion de vector binario segun nivel de amenaza

    for(int i=0;i<6;i++){
        if(masa_asteroide[i]>50 && distancia_tierra[i]<200)
            v_amenaza[i] = 1;
        else
            v_amenaza[i]= 0;
    }

    // 4. Calculo de amenza

    for(int i =0; i<6;i++){
        if(v_amenaza[i]==1 && distancia > distancia_tierra[i]){
            distancia = distancia_tierra[i];
            more_dan = i+1;
        }
    }

    // 5. Reporte de estado

    for(int i=0;i<6;i++){
        if(v_amenaza[i]==1)
            contador++;
    }

    if(contador>0){
        printf("\nAmenaza detectada, asteroirde %d es el mas peligroso\nMasa total: %0.2f Ton", more_dan, masa_asteroide[more_dan-1], distancia_tierra[more_dan-1]);
        porcentaje = (contador*100.0)/6.0;
        printf("\nAmenazas detectadas: %d", contador);
        printf("\nPorcentaje de asteroides que representan riesgo: %0.2f%\nAsteroide mas cercano: %d\nDistancia: %0.2f mil km",porcentaje, more_dan, distancia_tierra[more_dan-1]);
    }   //Puede que por el IDE no compile si no lleva %%  aqui  -------|   

    else
        printf("No se detectan amenzas importantes");

}