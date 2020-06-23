#include "jugador.h"

Jugador::Jugador(){
    posX = 0;
    posY = 0;
    cantVidas = 1;
}
Jugador::Jugador(int x, int y, int cv){
    posX = 0;
    posY = 0;
    cantVidas = cv;
}
void Jugador::setPosX(int){
}
void Jugador::setPosY(int){
}
void Jugador::setCantVidas(int){
}
int Jugador::getPosX(){
    return posX;
}
int Jugador::getPosY(){
    return posY;
}
int Jugador::getCantVidas(){
    return cantVidas;
}
