#pragma once
#include "Luchador.h"
#include <string>
using namespace std;

class Dragonborn : public Luchador{
  private:

  public:
    Dragonborn (string);

    void fisico(Luchador*);
    void magico(Luchador*);
    void defender();
    void especial();
    bool confirmar(Luchador*, int);
    void sanar();
};
