#include <iostream>
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
    do {
        int accion;
        cout<<"Desea moverse o explorar?(M/E)";
        cin>>accion;

    } while (cantVidas != 0);
}
