#include "Luchador.h"
#include "Aprendiz.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Alquimista.h"
#include "Dragonborn.h"
#include "LinkedList.h"

#include <string>
#include <iostream>
using namespace std;
int menu();
Luchador* crearLuchador();
int main(int argc, char const *argv[]) {
  LinkedList luchadores;
  Luchador* lucha=new Mago("Bob");
  luchadores.addLuchador(lucha);
  luchadores.display();
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
      you==luchadores.get(seleccion);
      cout<<endl;
      do{
        cout<<endl <<"Elija contra quien peleara (No puede escoger el mismo): ";
        cin>>seleccion2;
        cpu==luchadores.get(seleccion2);
        cout<<endl;
      }while(seleccion2<1 || seleccion2>luchadores.getSize() || seleccion2==sleccion);

      ofstream writeFile("Log.txt", ios::app);
      do{
      //Simulacion de Batalla
        string buffer;
        cout<<"Que deseas hacer?" <<endl;


        writeFile<<buffer;






      }while(true);
      writeFile.close();
    }
  }while(opcion!=3);
  return 0;
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
      <<"3. Salir" <<endl
      <<"Escriba la opcion: ";
      cin>>opcion;
      cout<<endl;
  }while(opcion<1 || opcion>3);
  return opcion;
}
