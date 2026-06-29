/* Programa para calcular función matematica f(x,y) = (sqrt(x))/ y^2-1
Para usar raiz(sqrt) y potencia (pow) usar math.h
*/
#include <stdio.h>
#include <math.h>

int main(){
    float resultado = 0, x=0; 
    int y=0;
    printf("Ingresar valor de X: ");
    scanf("%f", &x);
    printf("\nIngresar valor de y: ");
    scanf("%d", &y);

    resultado = sqrt(x)/(pow(y,2)-1);
    printf("\nEl resultado es: %f\n", resultado);

    return 0;
}