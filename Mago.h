#pragma once
#include "Luchador.h"
#include <string>
using namespace std;

class Mago : public Luchador{
  private:

  public:
    Mago (string);

    void fisico(Luchador*);
    void magico(Luchador*);
    void defender();
    void especial();
};
