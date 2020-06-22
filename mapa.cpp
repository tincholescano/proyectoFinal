#include <iostream>
#include "mapa.h"
using namespace std;

Mapa::Mapa(){
    tam = 1;
    nroBombas = 1;
}

Mapa::Mapa(int t,int nb){
    tam = t;
    nroBombas = nb;
}

void Mapa::setTam(int t){
    tam = t;
}

void Mapa::setNumeroBombas(int nb){
    nroBombas = nb;
}

int Mapa::getTam(){
    return tam;
}

int Mapa::getNumeroBombas(){
    return nroBombas;
}
