#include <iostream>
#include <string.h>
#include "juego.cpp"
using namespace std;

int main(){
    int tam, cantVidas, nroBombas;
    bool b = false;
    cout<<"BIENVENIDO"<<endl;
    cout<<"Ingrese el tamaño del tablero: ";
    cin>>tam;
    cout<<"Ingrese la cantidad de vidas: ";
    cin>>cantVidas;
    cout<<"Ingrese el numero de bombas: ";
    do {
        cin>>nroBombas;
        if (nroBombas>tam*tam-2) {
            cout<<"El numero de bombas es muy grande ingrese un numero menor";
            b = false;
            } else  b = true;
        } while (b==false);
    Juego j(tam,nroBombas);
    j.crearJuego();
    Jugador j1(0,0,cantVidas);
    int mov=0;
    do {
        int act;
        cout<<"Desea moverse o explorar?(1/2): ";
        cin>>act;
        if (act == 1) {
            char *d;
            cout<<"Hacia donde desea avanzar?(N-O-S-E): ";
            cin>>d;
            int mov = j.Mover(d);
            cout<<mov<<endl;
        } else if (act == 2) {
            int r;
            cout<<"Que rango desea explorar: ";
            cin>>r;
            int cant = j.Explorar(r);
            cout<<"La cantidad de bombas es de: "<<cant<<endl;
            } else mov=2;
    } while (mov!=2 or mov!=3);
}
