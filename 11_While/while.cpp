/*
=== DESAFÍO 2: EL CAJERO AUTOMÁTICO ===

Vas a simular un retiro de cuenta bancaria. El usuario empieza con un 
saldo inicial de $2000 dólares.

Tu programa debe:
1. Usar un ciclo 'while' que se ejecute MIENTRAS el saldo sea mayor a $0.
2. Dentro del ciclo, pedirle al usuario la cantidad de dinero que desea retirar.
3. Si el monto a retirar es menor o igual al saldo actual, se resta del saldo 
   y se muestra: "Retiro exitoso. Saldo restante: X".
4. Si el monto es mayor al saldo actual, mostrar: "Fondos insuficientes" (sin restar nada).
5. El ciclo debe terminar inmediatamente si el saldo llega a 0, mostrando: 
   "Tu cuenta está vacía. Adiós".

REQUISITO: El usuario puede hacer tantos retiros como quiera hasta que se acabe el dinero.
*/

/* OJO, el propósito de esto es demostrar el funcionamiento del while, al realizar operaciones
 binarias nos podemos encontrar con que la terminal muestre que tenemos .05 restantes
 pero en realidad puede ser un .0499999 y los condicionales no nos dejen realizar operaciones,
se le llama floating - point precison error, bastante común al querer realizar operaciones
aritmeticas base 10 en base 2
 */
#include <iostream>

using namespace std;

int main (){
    float retiro = 0, restante = 2000;
    cout<<" Banco bienestar \n Saldo inicial $2000";


        while(1){

            if(restante <= 0.009){
                cout<<"\n Saldo agotado";
                break;
            }

            cout<<"\n Ingrese cantidad a retirar: ";
            cin>>retiro;
            if(retiro>restante){
                cout<<"\n Saldo insuficiente, intente de nuevo";
            }

            else if(retiro == 0){
                cout<<"\n Opcion no valida";
            }

            else{
                restante-=retiro;
                printf("\n Retiro exitoso, saldo restante: %0.2f ", restante);
            }
        }

    return 0;
}