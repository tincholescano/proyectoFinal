#include "juego.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;
//Bergami-Moriconi

juego::juego(){
	tamanio=10;
	tablero= new int* [tamanio];
	for (int i=0;i<tamanio;i++)
    	tablero[i]=new int [tamanio];
	vida=3;
	bombas=5;
	x=0;
	z=0;
}

juego::juego(int v, int t, int b){
	tamanio=t;
	tablero= new int* [tamanio];
	for (int i=0;i<tamanio;i++)
    	tablero[i]=new int [tamanio];
	vida=v;
	bombas=b;
	x=0;
	z=0;
}

int juego::getvida(){
	return vida;
}
void juego::bombamax(){
	int max;
	max=(tamanio*tamanio)*0.4;
	if(bombas>max){
		bombas=max;
		cout<<"Ingresaste demasiadas bombas, cantidad de bombas actual :"<<bombas<<endl;
	}
	if(vida>bombas){
		cout<<"Ingresaste mas vidas que bombas para no perder, modifique eso, ahora tienes solo una vida"<<endl;
		vida=1;
	}
}

void juego::ingresar(){
	rtablero();
	bombamax();
	srand(time(NULL));
	for(int i=0;i<bombas;i++){  //ingreso la catidad de bombas
		random(f,c);
		tablero[f][c]=1;
	}
	random(f,c); //ingreso un tesoro
	tablero[f][c]=3;
}

void juego::random(int a, int b){
	a=rand()%(tamanio-1);
	b=rand()%(tamanio-1);
	f=a;
	c=b;
	if(tablero[f][c]!=0)
		random(f,c);
}

void juego::rtablero(){
	for (int i=0;i<tamanio;i++){
		for(int j=0;j<tamanio;j++)
				tablero[i][j]=0;
	}
	tablero[x][z]=2;
}

void juego::mostrar(){
	for(int i=0;i<tamanio;i++){
		for(int j=0;j<tamanio;j++){
			if(tablero[i][j]==2)
				cout<<" o";
			else
				cout<<" x";
		}
		cout<<endl;
	}
}

void juego::mostrarfinal(){
	for(int i=0;i<tamanio;i++){
		for(int j=0;j<tamanio;j++)
			cout<<" "<<tablero[i][j];
		cout<<" "<<endl;
	}
}

int juego::mover(char m){
	int i=x;
	int j=z;
	//cout<<"El personaje esta en la posicion ["<<x<<"]["<<z<<"]"<<endl;
	if(m=='n')
		x--;
	if(m=='s')
		x++;
	if(m=='o')
		z--;
	if(m=='e')
		z++;
	if(verificacion(x,z)==true){
		if(tablero[x][z]==3){
			tablero[i][j]=0;
			tablero[x][z]=2;
			return 3;
		}
		if(tablero[x][z]==1){
			tablero[i][j]=2;
			tablero[x][z]=0;
			vida--;
			x=i;
			z=j;
			if(vida==0)
				return 2;
			else
				return 1;
		}
		else{
			tablero[i][j]=0;
			tablero[x][z]=2;
			return 0;
		}
	}
	else{
		x=i;
		z=j;
		return -1;

	}
}


bool juego::verificacion(int a, int b){
	if(a<=-1 || b<=-1)
		return false;
	if(a>=tamanio || b>=tamanio)
		return false;
	return true;
}

int juego::explorar(int r){
	int s=0;
	if(r>tamanio) // hago esto para que el for no sea muy grande, ya que si r es mas grande que el tamaño daria vuelvas demas que son innecesaria
		r=tamanio-1;
	for(int c=r;c!=0;c--){
		if(verificacion(x+c,z)==true){
			if(tablero[x+c][z]==1)
				s++;
		}
		if(verificacion(x-c,z)==true){
			if(tablero[x-c][z]==1)
				s++;
		}
		if(verificacion(x,z+c)==true){
			if(tablero[x][z+c]==1)
				s++;
		}
		if(verificacion(x,z-c)==true){
			if(tablero[x][z-c]==1)
				s++;
		}
	}
	return s;
}




