#include "Luchador.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Luchador::Luchador(string pNombre, int pHp, int pAttMag, int pAttFis, float pDefMag, float pDefFis, int pExpNecesaria, int pExpEntregada){
  nombre=pNombre;
  victorias=0;
  experiencia=0;
  hp=pHp;
  attMag=pAttMag;
  attFis=pAttFis;
  defMag=pDefMag;
  defFis=pDefFis;
  expNecesaria=pExpNecesaria;
  expEntregada=pExpEntregada;
  defensa=false;
  limite=1;
  golpe=0;
  invulnerabilidad=false;
  powerup=0;
}

string Luchador::getNombre(){
  return nombre;
}

int Luchador::getVictorias(){
  return victorias;
}

vector<Luchador*> Luchador::getClases(){
  return clases;
}

int Luchador::getExperiencia(){
  return experiencia;
}

int Luchador::getHp(){
  return hp;
}

int Luchador::getAttMag(){
  return attMag;
}

int Luchador::getAttFis(){
  return attFis;
}

float Luchador::getDefMag(){
  return defMag;
}

float Luchador::getDefFis(){
  return defFis;
}

int Luchador::getExpEntregada(){
  return expEntregada;
}

bool Luchador::getDefensa(){
  return defensa;
}

bool Luchador::getInvulnerabilidad(){
  return invulnerabilidad;
}

void Luchador::setNombre(string pNombre){
  nombre=pNombre;
}

void Luchador::setVictorias(int pVictorias){
  victorias=pVictorias;
}

void Luchador::setClases(vector<Luchador*> pClases){
  clases=pClases;
}

void Luchador::setExperiencia(int pExperiencia){
  experiencia=pExperiencia;
}

void Luchador::setHp(int pHp){
  hp=pHp;
}

void Luchador::setDefensa(bool pDefensa){
  defensa=pDefensa;
}

void Luchador::setGolpe(int pGolpe){
  golpe=pGolpe;
}

void Luchador::setInvulnerabilidad(bool pInvul){
  invulnerabilidad=pInvul;
}

void Luchador::toString(){
  cout<<"Nombre: " <<nombre <<endl
    <<"Batallas ganadas: " <<victorias <<endl
    <<"# de Clases adquiridas: " <<clases.size() <<endl
    <<"Experiencia: " <<experiencia <<endl
    <<"Hp: " <<hp <<"   Ataque Magico: " <<attMag <<endl
    <<"Attaque Fisico: " <<attFis <<"   Defensa Magica: " <<defMag <<endl
    <<"Defensa Fisica: " <<defFis <<"   Experiencia Entregada: " <<expEntregada <<endl;
}

void Luchador::fisico(Luchador* luchador){

}

void Luchador::magico(Luchador* luchador){

}

void Luchador::defender(){

}

void Luchador::especial(){

}

void Luchador::pasivo(Luchador* luchador){

}

void Luchador(Luchador* luchador){
  if () {
    /* code */
  }
}
