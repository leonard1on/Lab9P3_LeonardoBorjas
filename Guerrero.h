#pragma once
#include "Luchador.h"
#include <string>
using namespace std;

class Guerrero : public Luchador{
  private:

  public:
    Guerrero (string);

    void fisico(Luchador*);
    void magico(Luchador*);
    void defender();
    void especial();
    bool confirmar(Luchador*, int);
    void sanar();
};
