#include "Luchador.h"
#include "Aprendiz.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Alquimista.h"
#include "Dragonborn.h"
#include "LinkedList.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include <string>
#include <iostream>
using namespace std;
int menu();
Luchador* crearLuchador();
Luchador* convertir(int, Luchador*);
int main(int argc, char const *argv[]) {
  LinkedList luchadores;
  Luchador* lucha=new Mago("Bob");
  lucha->setExperiencia(1000);
  Luchador* lucha2=new Guerrero("Gene");
  luchadores.addLuchador(lucha);
  luchadores.addLuchador(lucha2);
  Luchador* you;
  Luchador* cpu;
  int opcion;
  cout<<"Bienvenido A Elders Scrolls VI: Argonia" <<endl;
  do{
    opcion = menu();
    if (opcion == 1) {
      Luchador* peleador=crearLuchador();
      luchadores.addLuchador(peleador);
    }

    if (opcion==2) {
      int seleccion, seleccion2;
      do{
        luchadores.display();
        cout<<"Elija el luchador que usara para pelear: ";
        cin>>seleccion;
      }while(seleccion<1 || seleccion>luchadores.getSize());
      you=luchadores.get(seleccion);
      cout<<endl;
      do{
        cout<<endl <<"Elija contra quien peleara (No puede escoger el mismo): ";
        cin>>seleccion2;
        cpu=luchadores.get(seleccion2);
        cout<<endl;
      }while(seleccion2<1 || seleccion2>luchadores.getSize() || seleccion2==seleccion);

      ofstream writeFile("Log.txt", ios::app);
      string buffer;
      buffer="Ha comenzado una batalla entre "+you->getNombre()+" contra "+cpu->getNombre()+"\n";
      cout<<buffer;
      writeFile<<buffer;
      int decision;
      int victoria;
      do{
      //Simulacion de Batalla
      do{
          cout<<"Que deseas hacer?" <<endl
            <<"1. Ataque Fisico" <<endl
            <<"2. Ataque Magico" <<endl
            <<"3. Ataque Especial" <<endl
            <<"4. Defender" <<endl
            <<"//: ";
          cin>>decision;
          cout<<endl;
      }while(!you->confirmar(you, decision));

        if (decision==1) {
          buffer=""+you->getNombre()+" ha decidido hacer un ataque fisico\n";
          writeFile<<buffer;
          you->fisico(cpu);
        }

        if(decision==2){
          buffer=""+you->getNombre()+" ha decidido hacer un ataque magico\n";
          writeFile<<buffer;
          you->magico(cpu);
        }

        if (decision==3) {
          buffer=""+you->getNombre()+" ha decidido hacer un ataque especial\n";
          writeFile<<buffer;
          you->especial();
        }

        if (decision==4) {
          buffer=""+you->getNombre()+" ha decidido defenderse\n";
          you->defender();
        }
        cout<<buffer;
        //Oponente
        srand (time(NULL));
        int random=rand() %4 + 1;

        if (random==1) {
          buffer=""+cpu->getNombre()+" ha decidido hacer un ataque fisico\n";
          writeFile<<buffer;
          cpu->fisico(you);
        }

        if(random==2){
          buffer=""+cpu->getNombre()+" ha decidido hacer un ataque magico\n";
          writeFile<<buffer;
          cpu->magico(you);
        }

        if (random==3) {
          buffer=""+cpu->getNombre()+" ha decidido hacer un ataque especial\n";
          writeFile<<buffer;
          cpu->especial();
        }

        if (random==4) {
          buffer=""+cpu->getNombre()+" ha decidido defenderse\n";
          cpu->defender();
        }
        cout<<buffer;

        buffer=""+you->getNombre()+" tiene "+to_string(you->getHp())+" de vida\n";
        cout<<buffer;

        writeFile<<buffer;
        buffer=""+cpu->getNombre()+" tiene "+to_string(cpu->getHp())+ " de vida\n\n";
        cout<<buffer;
        writeFile<<buffer;

        if (you->getHp()<=0) {
          cout<<"Haz perdido la batalla\n";
          victoria=2;
        }else if (cpu->getHp()<=0) {
          cout<<"Haz ganado la batalla\n";
          victoria=2;
        }
      }while(victoria!=2);
      writeFile.close();
      you->setlimite();
      cpu->setlimite();

      you->pasivo(cpu);
      cpu->pasivo(you);

      if (cpu->getHp()<=0) {
        you->setExperiencia(cpu->getExpEntregada() + you->getExperiencia());
        you->sanar();
      }else{
        cpu->setExperiencia(you->getExpEntregada() + cpu->getExperiencia());
        cpu->sanar();
      }

    }

    if (opcion==3) {
      int rango, resp2;
      Luchador* aumento;
      luchadores.display();
      cout<<"Cual luchador quiere que suba de rango?" <<endl;
      cin>>rango;
      aumento=luchadores.get(rango);
      cout<<endl;
      aumento->toString();

      cout<<"1. Aprendiz" <<endl <<"2. Guerrero" <<endl <<"3. Mago" <<endl
        <<"4. Alquimista" <<endl <<"5. Dragonborn" <<endl
        <<"A que quiere convertirse?" <<endl;
      cin>>resp2;
      Luchador* nuevo=convertir(resp2, aumento);
      luchadores.remove(rango);
      luchadores.insert(rango, nuevo);
      cout<<endl;
    }
  }while(opcion!=4);
  return 0;
}

Luchador* convertir(int opcion, Luchador* peleador){
  string nombre=peleador->getNombre();
  Luchador* luchador;
  bool exito=false;
  switch (opcion) {
    case 1:{
      if (peleador->getExperiencia()>=400) {
        luchador=new Aprendiz(nombre);
        exito=true;
      }else{
        cout<<"No puede convertirse en Aprendiz" <<endl;
      }
    }break;

    case 2:{
      luchador=new Guerrero(nombre);
      exito=true;
    }break;

    case 3:{
      if (peleador->getExperiencia()>=200) {
        luchador=new Mago(nombre);
        exito=true;
      }else{
        cout<<"No se puede convertir en Mago" <<endl;
      }
    }break;

    case 4:{
      if (peleador->getExperiencia()>=300) {
        luchador=new Alquimista(nombre);
        exito=true;
      }else{
        cout<<"No se puede convertir en Alquimista";
      }
    }break;

    case 5:{
      if(peleador->getExperiencia()>=400){
        luchador=new Dragonborn(nombre);
        exito=true;
      }else{
        cout<<"No se puede convertir a Dragonborn";
    }
    }break;

    default:{

    }break;
  }
  if (exito) {
    luchador->setExperiencia(peleador->getExperiencia());
    luchador->getClases().push_back(peleador);
    return luchador;
  }else{
    cout<<endl;
    return peleador;
  }

}

Luchador* crearLuchador(){
  string resp="";
  Luchador* luchador;
  do{
    string nombre;
    int opcion;
    cout<<"Cual es el nombre de su luchador: ";
    cin>>nombre;
    cout<<"1. Aprendiz" <<endl <<"2. Guerrero" <<endl <<"3. Mago" <<endl
      <<"4. Alquimista" <<endl <<"5. Dragonborn" <<endl
      <<"Que tipo de luchador creara: ";
    cin>>opcion;
    cout<<endl;
    switch (opcion) {
      case 1:{
        luchador=new Aprendiz(nombre);
      }break;

      case 2:{
        luchador=new Guerrero(nombre);
      }break;

      case 3:{
        luchador=new Mago(nombre);
      }break;

      case 4:{
        luchador=new Alquimista(nombre);
      }break;

      case 5:{
        luchador=new Dragonborn(nombre);
      }break;

      default:{

      }break;
    }
    luchador->toString();
    cout<<"Asi desea su Luchador? Y/n" <<endl;
    cin>>resp;
    if (resp=="n") {
      delete luchador;
    }
  }while(resp=="n");
  return luchador;
}

int menu(){
  int opcion;
  do{
    cout<<" - Acciones - " <<endl
      <<"1. Crear un Luchador" <<endl
      <<"2. Pelear" <<endl
      <<"3. Subir de rango" <<endl
      <<"4. Salir" <<endl
      <<"Escriba la opcion: ";
      cin>>opcion;
      cout<<endl;
  }while(opcion<1 || opcion>3);
  return opcion;
}
