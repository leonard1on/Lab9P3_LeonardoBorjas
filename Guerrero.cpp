#include "Luchador.h"
#include "Guerrero.h"
#include <string>
using namespace std;

Guerrero::Guerrero(string pNombre) : Luchador(pNombre, 120, 0, 15, 0.00, 0.30, 0, 75) {
}

void Guerrero::fisico(Luchador* luchador){
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

void Guerrero::magico(Luchador* luchador){
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

void Guerrero::defender(){
  hp+=hp*0.45;
  if (hp>120) {
    hp=120;
  }
  defensa=true;
}

void Guerrero::especial(){
  if (limite==1) {
    hp+=hp*0.45;
    if (hp>120) {
      hp=120;
    }
    limite--;
  }
}

bool Guerrero::confirmar(Luchador* luchador, int opcion){
  bool confirmar=false;
  if (opcion==1) {
    confirmar=true;
  }

  if (opcion==2) {
    confirmar=false;
  }

  if (opcion==3 && limite==1) {
    confirmar=true;
  }

  return confirmar;
}

void Guerrero::sanar(){
  hp=120;
}
