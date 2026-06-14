/*Sentencias condicionales

El cine cobra la entrada normal a $7.00 dólares. Sin embargo, 
si el cliente es un niño menor de 12 años o un adulto mayor de 60 años,
 recibe un descuento del 50%. Si el cliente tiene entre 12 y 17 años, 
 recibe un descuento del 20%. El sistema debe pedir la edad del usuario
 y mostrar el precio final a pagar

*/

#include <iostream>
using namespace std;

    int main(){
        int cliente = 0, entrada = 7, edad_nino = 12, edad_adulto = 60, descuento1= 50, descuento2=20;
        float pagar = 0;
        cout<<"Entradas de cine \n";
        cout<<"Ingrese la edad del cliente: ";
        cin>>cliente;

        if(cliente<edad_nino || cliente>edad_adulto){
            cout << "\nFelicidades, Aplica para el descuento del 50%";
            pagar = entrada-((descuento1*entrada)/100.0);
        }
        else if(cliente>edad_nino && cliente <18){
            cout << "\nFelicidades, Aplica para el descuento del 20%";
            pagar = entrada-((descuento2*entrada)/100.0);
        }

        else
        pagar = entrada;
        

        cout<<"\nEl precio a pagar es: "<<pagar;
        cout<<" dolares";
    }