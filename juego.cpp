#include <iostream>
#include <stdlib.h>
#include "juego.h"
using namespace std;

void Juego::crearJuego(){
    int t = getTam();
    bool tesoro = false;
    int nb = getNumeroBombas();
    int num;
    for (int a=0;a<t;a++){
        for (int b=0;b<t;b++){
            if (tesoro==false){
                num=1+rand()%(3-0);
                if (num==1 && nb!=0){
                    nb--;
                    mapa[a][b] = num;
                } else if (num==2) {
                    mapa[a][b] = num;
                    tesoro = true;
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

bool Juego::validar(int x, int y){
	int t = getTam();
	if(x<=-1 or y<=-1) {
	    return false;
	} else if (x>=t or y>=t){
		return false;
	} else {
	    return true;
	    }
}

int Juego::Mover(char d){
	int x = getPosX();
	int y = getPosY();
	int vida = getCantVidas();
	if (d=='N'){
		y++;
	} else if (d=='O'){
		x--;
	} else if (d=='S'){
		y--;
	} else (d=='E'){
		x++;
	};

	if (validar(x,y)==true){
		switch(mapa[tam][tam]){
			case 1: {
				if (mapa[x][y]==0){
					return 0;
					cout<<"La casilla esta vacia";
				}
				break;
			}
			case 2: {
				if (mapa[x][y]==1){
					vida--;
					if (vida==0){
						return 2;
						cout<<"Perdiste! Te quedaste sin vidas";
					} else {
						return 1;
						cout<<"Cuidado una bomba! Perdiste una vida pero sigues en juego";
					}
				}
			}
			case 3:{
				if (mapa[x][y]==3){
					return 3;
					cout<<"Felicidades! Ganaste el juego!";
				}
			}
		}
	} else {
			return -1;
			cout<<"Cuidado, te fuiste del mapa, vuelves a la posicion previa";
		}
}

int Juego::Explorar(int r){
    int cant = 0;
    int x=getPosX(), y=getPosY();
    for (int i=0;i<=r;i++){
        if (validar(x+i,y)==true){
            if (mapa[x+i][y]==1) cant++;
            }
        if (validar(x-i,y)==true){
            if (mapa[x-i][y]==1) cant++;
            }
        if (validar(x,y+i)==true){
            if (mapa[x][y+i]==1) cant++;
            }
        if (validar(x,y-i)==true){
            if (mapa[x][y-i]==1) cant++;
            }
    }
    return cant;
};
