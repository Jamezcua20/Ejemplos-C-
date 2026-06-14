/*
Escribe un programa que lea entrada de dos numeros y muestre la salida de su suma, resta,multiplicacion o division

*/

#include <iostream>
using namespace std;

int main (){
    int num1; int num2;
    int resultado = 0;
    cout<<" Operaciones aritmeticas";
    cout<<"\n Introduzca primer numero: ";
    cin>>num1;
    cout<<"\n Introduzca segundo numero: ";
    cin>>num2;
    resultado = num1+num2;
    cout<<"\n Suma: "<<resultado;
    resultado = num1-num2;
    cout<<"\n Resta: "<<resultado;
    resultado = num1*num2;
    cout<<"\n Multiplicacion: "<<resultado;
    resultado = num1/num2;
    cout<<"\n Division: "<<resultado;
}