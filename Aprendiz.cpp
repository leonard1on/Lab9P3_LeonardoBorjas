#include "Luchador.h"
#include "Aprendiz.h"
#include <string>
using namespace std;

Aprendiz::Aprendiz(string pNombre) : Luchador(pNombre, 60, 0, 10, 0.00, 0.10, 400, 25){
}

void Aprendiz::fisico(Luchador* luchador){
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

void Aprendiz::magico(Luchador* luchador){
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

void Aprendiz::defender(){
  hp+=hp*0.45;
  if (hp>60) {
    hp=60;
  }
  defensa=true;
}

void Aprendiz::pasivo(Luchador* luchador){
  experiencia+=luchador->getExpEntregada();
}

bool Aprendiz::confirmar(Luchador* luchador, int opcion){
  bool confirmar=false;
  if (opcion==1) {
    confirmar=true;
  }

  if (opcion==2) {
    confirmar=false;
  }

  if (opcion==3 && limite==1) {
    confirmar=false;
  }

  return confirmar;
}

void Aprendiz::sanar(){
  hp=60;
}
