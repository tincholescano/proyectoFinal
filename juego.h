class Juego{
private:
    int tamX, tamY, nroBombas;
};

class Jugador{
  private:
    int  cantVidas, posX, posY;
  public:
    int Mover(char);
    int Explorar(char);
};
