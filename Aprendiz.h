#pragma once
#include "Luchador.h"
#include <string>
using namespace std;

class Aprendiz : public Luchador{
  private:

  public:
    Aprendiz (string);

    void fisico(Luchador*);
    void magico(Luchador*);
    void defender();
    void pasivo(Luchador*);
};
