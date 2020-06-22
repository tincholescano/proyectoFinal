#include "mapa.cpp"

class Juego: public Mapa{
  protected:
    int mapa[][];
  public:
    Juego(int t,int nb):Mapa(t,nb){mapa[t][t]};
    void crearJuego();
    int Explorar(int);
};
