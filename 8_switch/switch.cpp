/*
Uso del switch:
    switch(expresion){
        case literal:
            instrucciones;
            break;
        
        default:
            instruciones;
            break;
    }

    === DESAFÍO: EL SELECTOR DE DIFICULTAD ===

El sistema debe pedir al jugador que elija la dificultad de su partida 
ingresando un número del 1 al 4. Dependiendo de la opción, se asigna:

- Caso 1 (Fácil):   100 HP, Multiplicador: 1.5
- Caso 2 (Normal):  100 HP, Multiplicador: 1.0
- Caso 3 (Difícil):  80 HP, Multiplicador: 0.8
- Caso 4 (Experto):   1 HP, Multiplicador: 0.5

REQUISITOS:
1. Usar la estructura 'switch'.
2. No olvidar los 'break;'.
3. Mostrar los resultados finales formateados.
*/

#include <iostream>
using namespace std;

    int main (){
        string modo = "";
        int selector = 0, HP = 0;
        float Mul = 0;
        cout<<"Selector de dificultad \n";
        cout<<"Ingresar nivel de dificultad de partida:";
        cout<<"\n1 (Fácil):   100 HP, Multiplicador: 1.5";
        cout<<"\n2 (Normal):  100 HP, Multiplicador: 1.0";
        cout<<"\n3 (Difícil):  80 HP, Multiplicador: 0.8";
        cout<<"\n4 (Experto):   1 HP, Multiplicador: 0.5";
        
        while(selector<1 || selector>4){
            cout<<"\nNivel de dificultad: ";
            cin>>selector;
            if(selector<1 || selector>4){
                cout<<"\nNo valido ";
            }
        }

        switch (selector)
        {
        case 1:
           HP=100;
           Mul=1.5;
           modo = "Facil";
           break;
        
        case 2:
           HP=100;
           Mul=1.0;
           modo = "Normal";
           break;

        case 3:
           HP=80;
           Mul=0.8;
           modo = "Dificil";
           break;
        
        case 4:
           HP=1;
           Mul=0.5;
           modo = "Experto";
           break;

        default:
            break;
        }

        cout<<"\n Se ha seleccionado el modo: "<<selector;
        cout<<" "<<modo;
        cout<<"\n HP: "<<HP;
        cout<<"\n Multiplicador: "<<Mul;

        return 0;
    }