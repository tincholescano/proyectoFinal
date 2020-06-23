#include <iostream>
#include <string.h>
#include "juego.cpp"
#include "jugador.cpp"
using namespace std;

int main(){
    int tam, cantVidas, nroBombas;
    cout<<"BIENVENIDO"<<endl;
    cout<<"Ingrese el tamaño del tablero: ";
    cin>>tam;
    cout<<"Ingrese la cantidad de vidas: ";
    cin>>cantVidas;
    cout<<"Ingrese el numero de bombas: ";
    cin>>nroBombas;
    j.Juego(int tam,int nroBombas);
    j.crearJuego();
    j1.Jugador(int,int,int);
    do {
        int r;
        cout<<"Desea moverse o explorar?(1/2)";
        cin>>r;
        if (r == 1) {
            char d[1];
            cout<<"Hacia donde desea avanzar?(N-O-S-E)";
            cin>>d;
            Mover(d);
        } else Explorar(r);
    } while (cantVidas != 0);
}
