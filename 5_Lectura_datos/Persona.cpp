/*
Realizar un programa que lea la entrada de datos de una persona:
Edad: entero
Sexo: Caracter
Altura: flotante

Tras leerlos el programa debe mostrarlos en consola
*/

#include <iostream>
using namespace std;

int main(){
    int edad; char sexo; float altura;

    cout<<"Ingresar edad: ";
    while(edad<5||edad>80){
        cin>> edad;
        if(edad<5||edad>80)
            cout<<"No valido\n";
        }

    cout<<"\nIngresar sexo: ";
    while(sexo!='H'&&sexo!='M'&&sexo!='m'&&sexo!='h'){
        cin>>sexo;
        if(sexo!='H'&&sexo!='M'&&sexo!='m'&&sexo!='h')
            cout<<"No valido\n";
    }

    cout<<"\nIngresar altura: ";
    cin>>altura;


    cout<<"\nEdad registrada: "<<edad;
    cout<<"\nSexo registrado: "<<sexo;
    cout<<"\nAltura registrada: "<<altura;
    cout<<" m";

    return 0;

}