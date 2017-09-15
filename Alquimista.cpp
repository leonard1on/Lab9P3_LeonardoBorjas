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
  defensa=true;
}

void Alquimista::especial(){
  if (limite==1) {
    invulnerabilidad=true;
    limite--;
  }
}
