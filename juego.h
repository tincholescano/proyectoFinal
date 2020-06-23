#include "mapa.cpp"
#include "jugador.cpp"

class Juego: public Mapa, Jugador{
  protected:
    int **mapa;
  public:
    Juego(int t,int nb):Mapa(t,nb){mapa = new int* [t]; for (int i=0;i<t;i++) mapa[i] = new int [t];};
    void crearJuego();
    bool validar(int,int);
    int Explorar(int);
    int Mover(char*);
};
