#pragma once
#include "Luchador.h"
#include <string>
using namespace std;

class Alquimista : public Luchador{
  private:

  public:
    Alquimista (string);

    void fisico(Luchador*);
    void magico(Luchador*);
    void defender();
    void especial();
    bool confirmar(Luchador*, int);
    void sanar();
};
