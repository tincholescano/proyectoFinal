#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int tamX, tamY, cantVidas, nroBombas;
    cout<<"BIENVENIDO"<<endl;
    cout<<"Ingrese el ancho del tablero: ";
    cin>>tamX;
    cout<<"Ingrese el largo del tablero: ";
    cin>>tamY;
    cout<<"Ingrese la cantidad de vidas: ";
    cin>>cantVidas;
    cout<<"Ingrese el numero de bombas: ";
    cin>>nroBombas;
    void crearMapa();
    do {
        int r;
        cout<<"Desea moverse o explorar?(1/2)";
        cin>>r;
        if (r == 1) {
            char d[1];
            cout<<"Hacia donde desea avanzar?(N-O-S-E)";
            cin>>d;
            int Mover(d);
        } else int Explorar(r);
    } while (cantVidas != 0);
}
