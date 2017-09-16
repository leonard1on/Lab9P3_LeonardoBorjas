#include "Luchador.h"
#include "Mago.h"
#include <string>
using namespace std;

Mago::Mago(string pNombre) : Luchador(pNombre, 100, 15, 0, 0.30, 0.00, 200, 75){
}

void Mago::fisico(Luchador* luchador){
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

void Mago::magico(Luchador* luchador){
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

void Mago::defender(){
  hp+=hp*0.45;
  if (hp>100) {
    hp=100;
  }
  defensa=true;
}

void Mago::especial(){
  if (limite==1) {
    hp+=golpe;
    limite--;
  }
}

bool Mago::confirmar(Luchador* luchador, int opcion){
  bool confirmar=false;
  if (opcion==1) {
    confirmar=false;
  }

  if (opcion==2) {
    confirmar=true;
  }

  if (opcion==3 && limite==1) {
    confirmar=true;
  }

  return confirmar;
}

void Mago::sanar(){
  hp=100;
}
