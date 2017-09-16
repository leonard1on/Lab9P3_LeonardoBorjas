#pragma once
#include <string>
#include <vector>
using namespace std;

class Luchador {
  protected:
    string nombre;
    int victorias;
    vector<Luchador*> clases;
    int experiencia;

    int hp;
    int attMag;
    int attFis;
    float defMag;
    float defFis;
    int expNecesaria;
    int expEntregada;

    bool defensa;
    int limite;
    int golpe;
    bool invulnerabilidad;
    int powerup;

  public:
    Luchador (string, int, int, int, float, float, int, int);
    string getNombre();
    int getVictorias();
    vector<Luchador*> getClases();
    int getExperiencia();
    int getHp();
    int getAttMag();
    int getAttFis();
    float getDefMag();
    float getDefFis();
    int getExpEntregada();
    bool getDefensa();
    bool getInvulnerabilidad();

    void setNombre(string);
    void setVictorias(int);
    void setClases(vector<Luchador*>);
    void setExperiencia(int);
    void setHp(int);
    void setDefensa(bool);
    void setGolpe(int);
    void setInvulnerabilidad(bool);
    void toString();
    void setlimite();


    virtual void fisico(Luchador*);
    virtual void magico(Luchador*);
    virtual void defender();
    virtual void especial();
    virtual void pasivo(Luchador*);
    virtual bool confirmar(Luchador*, int);
    virtual void sanar();
};
