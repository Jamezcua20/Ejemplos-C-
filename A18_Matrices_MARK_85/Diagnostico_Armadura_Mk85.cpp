/*
El ejercicio fue propuesto por gemini y resuelto por mi.

=== DESAFÍO MATRICES: DIAGNÓSTICO MARK-LXXXV ===

La armadura Mark 85 tiene un panel térmico en el pecho de 4 filas y 4 columnas.
Si un nodo supera los 200°C, está en riesgo de fundirse. Si toda una fila se funde, 
el Reactor Arc se apagará por seguridad.

Tu programa debe:
1. Declarar una matriz 'float armadura[4][4]' y permitir al usuario ingresar 
   las temperaturas de los 16 nodos.
2. Escaneo de Puntos Críticos: Recorrer la matriz para contar cuántos nodos 
   individuales están sobrecalentados (> 200°C).
3. Protocolo de Pérdida de Línea: Verificar si existe alguna FILA COMPLETA donde 
   TODOS sus nodos superen los 200°C. De ser así, activa la bandera 'shutdown = 1'.
4. Reporte F.R.I.D.A.Y.: Mostrar la matriz en formato de cuadrícula en consola.
   Si 'shutdown == 1', imprimir: "¡EMERGENCIA! Fila [X] fundida. Apagando Reactor Arc".
   Si no, imprimir: "Estabilidad del sistema: [X] nodos dañados. Armadura operativa".

*/

//OJO, SE PUEDE OPTIMIZAR EL CODIGO, PERO EL PUNTO DEL EJEMPLO ES EL USO DE MATRICES

#include <iostream>
using namespace std;

int main (){

   float armadura[4][4] ={0}; // Declaración de matriz 
   int vec_overheating [4][4] ={0}, vec_damage[4]={0};
   int i=0, overheating = 0, row = 0;

   printf("\nNANO ARMADURA MK 85, INICIO DE SECUENCIA\n");  
   printf("Inicializando sistemas....\nSe detecta una anomalia en el reactor del pecho!\nIniciando protocolos de supervision\n");

      for(int f=0;f<4;f++){
         for(int c=0;c<4;c++){
            printf("\nEscaneo de puntos criticos...\n");
            printf("Ingresar temperatura de nodo %d: ",i+1);
            cin>>armadura[f][c]; // filas - columnas
            i++; //Contador de celdas
            if(armadura[f][c]>200){
               overheating++; //Contador individual de celdas sobrecalentadas
               vec_overheating[f][c] = 1;
            }
            else 
               vec_overheating[f][c] = 0;
         }
   }

   printf("\nSectores independientes defectuosos: %d",overheating);

   for(int f=0;f<4;f++){
      i=0;
      for(int c=0;c<4;c++){
         if(vec_overheating[f][c] == 1)
            i++;
      }
         if(i==4)
               vec_damage[f] = 1;
         else
               vec_damage[f]= 0;
   }

   for(int i=0;i<4;i++){
      if(vec_damage[i]==1){
         row++;
         printf("\nSe detecta que la fila %d fallo en su totalidad",i+1);
      }
   }

   if(row==0){
      printf("\nEstabilidad del sistema: %d nodos defectuosos. Armadura operativa",overheating);
   }
   else
      printf("\nSistemas fallando!, apagado de emergencia activo");

}