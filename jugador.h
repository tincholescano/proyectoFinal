class Jugador{
  protected:
    int posX, posY, cantVidas;
  public:
    Jugador();
    Jugador(int,int,int);
    void setPosX(int);
    void setPosY(int);
    void setCantVidas(int);
    int getPosX();
    int getPosY();
    int getCantVidas();
};
