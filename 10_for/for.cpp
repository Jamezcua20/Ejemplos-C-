/*
=== DESAFÍO 1: EL INVENTARIO DEL ESPACIO (Ciclo FOR) ===

Estás programando el sistema de carga de una nave espacial. El cargamento
tiene espacio exactamente para 6 contenedores de minerales.

Tu programa debe:
1. Usar un ciclo 'for' que se repita exactamente 6 veces.
2. En cada vuelta, pedir el peso (float) del contenedor actual (Contenedor 1, 2, etc.).
3. Ir sumando los pesos en una variable 'pesoTotal'.
4. Al final del ciclo, si el 'pesoTotal' supera las 50.5 toneladas, mostrar un 
   mensaje de alerta: "¡Peligro! Sobrecarga en la nave". Si no, mostrar: "Despegue seguro".

REQUISITO: Mostrar el peso total final con mínimo 2 decimales.
*/


//This is FOR ----> preguntenle a Sofi por la referencia 

#include <iostream>
using namespace std;

int main (){
    
    float contenedor = 0, peso_total = 0;
    float factor_ton = 0.001;

    cout<<"Contexto de la mision: \nPeter Quill dejo cargando a Rocket y a Groot la nave con baterias anulax, \nverifiquen que el peso no exceda los limites del Milano (50.5 TONELADAS)";
    cout<<"\nInventario: 6 contenedores, inicio de llenado ...";

    for(int i = 0;i<6;i++){
        cout<<"\nIngresar el peso del contenedor "<<i+1;
        cout<<" en kg: ";
        cin>>contenedor;
        contenedor*=factor_ton; // Ojo, en C tenemos abreviaturas para no poner x=x+y
        peso_total+=contenedor; // Para usar las abreviaturas es x*=y,x/=y,x-=y, x+=y
        cout<<"\nPeso actual: "<<peso_total;
        cout<<" toneladas ";
    }

    if(peso_total<=50.50)
        cout<<"\nLimites seguros, puede despegar";
    else
        cout<<"\n Peligro, sobrecarga en la nave";

    return 0;
}