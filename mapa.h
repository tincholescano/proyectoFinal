class Mapa{
  private:
    int X, Y, nroBombas;
  public:
    Mapa();
    Mapa(int,int,int);
    void setX(int);
    void setY(int);
    void setNumeroBombas(int);
    int getX();
    int getY();
    int getNumeroBombas();
};
