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
  hp+=hp*0.45;
  if (hp>200) {
    hp=200;
  }
  defensa=true;
}

void Dragonborn::especial(){
  if (limite==1) {
    powerup=2;
    limite--;
  }
}

bool Dragonborn::confirmar(Luchador* luchador, int opcion){
  bool confirmar=false;
  if (opcion==1) {
    confirmar=true;
  }

  if (opcion==2) {
    confirmar=true;
  }

  if (opcion==3 && limite==1) {
    confirmar=true;
  }

  return confirmar;
}

void Dragonborn::sanar(){
  hp=200;
}
