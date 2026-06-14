/* Programa para calcular función matematica f(x,y) = (sqrt(x))/ y^2-1
Para usar raiz(sqrt) y potencia (pow) usar math.h
*/
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float resultado = 0, x=0; 
    int y=0;
    cout<<"Ingresar valor de X: ";
    cin>>x;
    cout<<"\nIngresar valor de y: ";
    cin>>y;

    resultado = sqrt(x)/(pow(y,2)-1);
    cout<<"\nEl resultado es: "<<resultado;

    return 0;
}