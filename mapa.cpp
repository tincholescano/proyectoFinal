#include <iostream>
#include "mapa.h"
using namespace std;

Mapa::Mapa(){
    X = 1;
    Y =1;
    nroBombas = 1;
}

Mapa::Mapa(int x,int y,int nb){
    X = x;
    Y = y;
    nroBombas = nb;
}

void Mapa::setX(int x){
    X = x;
}
void Mapa::setY(int y){
    Y = y;
}
void Mapa::setNumeroBombas(int nb){
    nroBombas = nb;
}
int Mapa::getX(){
    return X;
}
int Mapa::getY(){
    return Y;
}
int Mapa::getNumeroBombas(){
    return nroBombas;
}
