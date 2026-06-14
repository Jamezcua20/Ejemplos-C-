/*
=== RETO: EL SISTEMA DE BECAS UNIVERSITARIAS ===

Una universidad privada ofrece becas automáticas a sus estudiantes basados en:
1. Su promedio de calificaciones (un número decimal de 0.0 a 10.0).
2. Los ingresos mensuales de su familia (en dólares).

Tu programa debe pedir estos dos datos y evaluar las siguientes reglas:

- REGLA 1: Si el promedio es de 9.5 o más, la beca es del 50%, SIN IMPORTAR los ingresos.
- REGLA 2: Si el promedio está entre 8.5 y 9.4:
    * Se revisan los ingresos: Si la familia gana MENOS de $1500, se le da una beca del 25%.
    * Si la familia gana $1500 o más, no alcanza beca (se muestra un mensaje explicando por qué).
- REGLA 3: Si el promedio es MENOR a 8.5, no aplica para beca por promedio insuficiente.

REQUISITOS ADICIONALES (Para programadores pro):
1. Usa un bucle 'while' para asegurarte de que el promedio ingresado esté entre 0.0 y 10.0.
2. Asegúrate de que las operaciones con los ingresos y promedios no pierdan sus decimales.
*/

#include <iostream>
using namespace std;

int main (){
    float promedio = 0, ingresos = 0;
    int selector = 0;
    cout<<"SISTEMA DE BECAS \n";
    
    //Validación de calificación
    while(1){
        cout<<"Ingresar promedio del alumno: ";
        cin>>promedio;
        if( promedio<0 || promedio>10.0 ){
            cout<<"\n Promedio invalido \n Intente de nuevo:\n";
        }
        else
            break;
    }

    cout<<"\nIngresar el valor de los ingresos de la familia:";
    cin>>ingresos;
    
    // Simplificamos el case
    if(promedio>=9.5)
        selector = 1;
    else if (promedio<=9.4 && promedio >=8.5)
        selector = 2;
    else
        selector = 3;

    switch(selector){
        case 1:
            cout<<"Felicidades, es acredor a una beca por el 50%";
            break;
        case 2:
            if (ingresos< 1500)
                cout<<"Felicidades, es acredor a una beca por el 25%";
            else
                cout<<"Lo sentimos, no cumple con el rango de ingreso economico para solicitar la beca";
            break;
        case 3:
            cout<<"Promedio insuficiente";
            break;
        default:
            break;
    }

    return 0;
}