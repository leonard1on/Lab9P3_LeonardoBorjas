#include "Luchador.h"
#include "Dragonborn.h"
#include <string>
using namespace std;

Dragonborn::Dragonborn(string pNombre) : Luchador(pNombre, 200, 25, 23, 0.20, 0.20, 400, 150){
}

void Dragonborn::fisico(Luchador* luchador){
  int ataque=attFis;

  if (powerup>0) {
    ataque*=2;
    powerup--;
  }

  if (luchador->getDefensa()) {
    ataque-=(attFis*luchador->getDefFis());
  }

  if(!luchador->getInvulnerabilidad()){
    luchador->setHp(luchador->getHp()-ataque);
    luchador->setGolpe(ataque);
  }

  luchador->setInvulnerabilidad(false);
  luchador->setDefensa(false);
}

void Dragonborn::magico(Luchador* luchador){
  int magia=attMag;

  if (powerup>0) {
    magia*=2;
    powerup--;
  }

  if (luchador->getDefensa()) {
    magia-=(attMag*luchador->getDefMag());
  }

  if(!luchador->getInvulnerabilidad()){
    luchador->setHp(luchador->getHp()-magia);
    luchador->setGolpe(magia);
  }

  luchador->setInvulnerabilidad(false);
  luchador->setDefensa(false);
}

void Dragonborn::defender(){
  hp+=40;
  defensa=true;
}

void Dragonborn::especial(){
  if (limite==1) {
    powerup=2;
    limite--;
  }
}
