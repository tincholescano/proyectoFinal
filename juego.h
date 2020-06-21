#include "mapa.cpp"

class Juego: public Mapa{
  public:
    Juego(char* x,int y,char* nb):Mapa(x,y,nb){};
};
