#include "mapa.cpp"

class Juego: public Mapa{
  protected:
    int mapa[][];
  public:
    Juego(int x,int y,int nb):Mapa(x,y,nb){mapa[x][y]};
    void crearJuego();
    int Explorar(int);
};
