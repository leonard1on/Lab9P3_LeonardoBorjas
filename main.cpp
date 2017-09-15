#include "Luchador.h"
#include "Aprendiz.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Alquimista.h"
#include "Dragonborn.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  Luchador* guerrero=new Guerrero("Rafael");
  Luchador* aprendiz=new Aprendiz("Thomas");
  Luchador* mago=new Mago("Merlin");
  Luchador* alquimista=new Alquimista("Santiago");
  Luchador* dragonborn=new Dragonborn("Leolas");
  while(aprendiz->getHp()>0){
  cout<<"Hp1: " <<aprendiz->getHp() <<endl;
  dragonborn->fisico(aprendiz);

  cout<<"Hp2: " <<aprendiz->getHp()<<endl;
  cout<<"Attmag: " <<aprendiz->getAttMag() <<endl;
  cout<<"attfis: " <<aprendiz->getAttFis() <<endl;
  cout<<"deffis: " <<aprendiz->getDefFis() <<endl;
  cout<<"defmag: " <<aprendiz->getDefMag() <<endl;

  aprendiz->defender();
  dragonborn->fisico(aprendiz);
  cout<<"Hp3: " <<aprendiz->getHp()<<endl <<endl;
  }
  cout<< dragonborn->getExperiencia() <<endl;
  dragonborn->pasivo(aprendiz);
  dragonborn->setExperiencia(dragonborn->getExperiencia() + aprendiz->getExpEntregada());
  cout<< dragonborn->getExperiencia()<<endl;

  return 0;
}
