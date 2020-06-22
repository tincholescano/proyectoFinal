#include <iostream>
#include <stdlib.h>
#include "juego.h"
using namespace std;

void Mapa::crearJuego(){
    int t = getTam();
    bool tesoro = False;
    int nb = getNumeroBombas();

    for (int a=0;a<t;a++){
        for (int b=0;b<t;b++){
            if (tesoro==False){
                num=1+rand()%(3-0);
                if (num==1 && nb!=0){
                    nb--;
                    mapa[a][b] = num;
                } else if (num==2) {
                    mapa[a][b] = num;
                    tesoro = True;
                } else {
                    mapa[a][b] = 0;
                }
            } else {
                num=1+rand()%(2-0);
                if (num==1 && nb!=0){
                    nb--;
                    mapa[a][b] = num;
                } else {
                    mapa[a][b] = 0;
                }
            }
        }
    }
}

int Mover(char d[1]){
    if (d == "N"){
    } else if (d == "O"){
    } else if (d == "S"){
    } else if (d == "E"){
    } else {cout<<"La letra es incorrecta";};
};

int Explorar(int r){
    int cant = 0;
    for (int i=0;i<=r;i++){
        if (mapa[x+i][y+i]==1) cant++;
        if (mapa[x-i][y-i]==1) cant++;
    }
};
