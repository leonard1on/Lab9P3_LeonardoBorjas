#include "Luchador.h"
#include "Alquimista.h"
#include <string>
using namespace std;

Alquimista::Alquimista(string pNombre) : Luchador(pNombre, 130, 10, 10, 0.20, 0.20, 300, 100){
}

void Alquimista::fisico(Luchador* luchador){
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

void Alquimista::magico(Luchador* luchador){
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

void Alquimista::defender(){
  hp+=40;
  if (hp>130) {
    hp=130;
  }
  defensa=true;
}

void Alquimista::especial(){
  if (limite==1) {
    invulnerabilidad=true;
    limite--;
  }
}

bool Alquimista::confirmar(Luchador* luchador, int opcion){
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

void Alquimista::sanar(){
  hp=130;
}
