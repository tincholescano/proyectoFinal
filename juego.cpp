#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "juego.h"
using namespace std;

void Juego::crearJuego(){
    int t = getTam();
    bool tesoro = false;
    int nb = getNumeroBombas();
    int num;
    do{
        for (int a=0;a<t;a++){
            for (int b=0;b<t;b++){
                if (a==0 && b==0){
                    mapa[a][b]=0;
                } else {
                    if (tesoro==false){
                        num=rand()%(3-0);
                        if (num==1 && nb>0){
                            nb--;
                            mapa[a][b] = num;
                        } else if (num==2) {
                            mapa[a][b] = num;
                            tesoro = true;
                        } else {
                            mapa[a][b] = 0;
                        }
                    } else {
                        num=rand()%(2-0);
                        if (num==1 && nb>0){
                            nb--;
                            mapa[a][b] = num;
                        } else {
                            mapa[a][b] = 0;

                        }
                    }
                }
            }
        }
    } while (tesoro == false && nb>0);
}

bool Juego::validar(int x, int y){
	int t = getTam();
	if(x<=-1 or y<=-1) {
	    return false;
	} else if (x>t or y>t){
		return false;
	} else {
	    return true;
	    }
}

int Juego::Mover(char* d){
	int x = getPosX();
	int y = getPosY();
	char* N;
	char* O;
	char* S;
	char* E;
	strcpy(N,"N");
	strcpy(O,"O");
	strcpy(S,"S");
	strcpy(E,"E");
	int vida = getCantVidas();
	if (d==N && validar(x,y++)){
		setPosY(y++);
	} else if (d==O && validar(x--,y)){
		setPosX(x--);
	} else if (d==S && validar(x,y--)){
		setPosY(y--);
	} else if (d==E && validar(x++,y)){
		setPosX(x++);
	} else return -1;

	if (mapa[x][y]==0){
	    return 0;
		}
	if (mapa[x][y]==1){
	    setCantVidas(vida--);
	    vida = getCantVidas();
	    if (vida==0){
		    return 2;
	    } else {
		    return 1;
	    }
    }
	if (mapa[x][y]==3){
		return 3;
	}
}

int Juego::Explorar(int r){
    int cant = 0;
    int r2 = r;
    int t = getTam();
    int x=getPosX(), y=getPosY();
    if ((x+r)>t) r=t-x;
    for (int a=0;a<r;a++){
        for (int b=0;b<r;b++){
            if (validar(x+a,y+b)==true){
                if (mapa[x+a][y+b]==1) cant++;
                cout<<mapa[x+a][y+b];
            }
        } cout<<endl;
    }

    for (int a=0;a<r;a++){
        for (int b=0;b<r;b++){
            if (validar(x-a,y-b)==true){
                if (mapa[x-a][y-b]==1) cant++;
            }
        }
    }
    return cant;
};
















        
