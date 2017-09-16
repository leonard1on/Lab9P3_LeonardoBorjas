#include "LinkedList.h"
#include <iostream>
#include "Luchador.h"
#include "Guerrero.h"
#include "Aprendiz.h"
#include "Mago.h"
#include "Alquimista.h"
#include "Dragonborn.h"

using namespace std;

LinkedList::LinkedList(){
  head=NULL;
  tail=NULL;
  size=0;
}

void LinkedList::addLuchador(Luchador* luchador){
  Node* nuevo = new Node;
  nuevo->luchador = luchador;
  nuevo->next = NULL;
  if (head==NULL) {
    head=nuevo;
    tail=nuevo;
    nuevo=NULL;
  }else{
    tail->next = nuevo;
    tail = tail->next;
  }
  size++;
}

void LinkedList::display(){
  int cuenta=1;
  Node* nuevo=new Node;
  nuevo=head;
  while (nuevo!=NULL) {
    cout<<cuenta <<". " <<nuevo->luchador->getNombre()<<endl;
    nuevo=nuevo->next;
    cuenta++;
  }
}

void LinkedList::insert(int pos, Luchador* pLuchador){
  Node* antes=new Node;
  Node* ahora=new Node;
  Node* nuevo=new Node;
  ahora=head;
  if (pos==1) {
    nuevo->luchador=pLuchador;
    nuevo->next=head;
    head=nuevo;
  }else{
    for (int i = 1; i < pos; i++) {
      antes=ahora;
      ahora=ahora->next;
    }
    nuevo->luchador=pLuchador;
    antes->next=nuevo;
    nuevo->next=ahora;
  }
  size++;
}

void LinkedList::remove(int pos){
  Node* ahora=new Node;
  Node* antes=new Node;
  ahora=head;
  if (pos==1) {
    head=head->next;
    delete ahora;
  }else{
    for (int i = 1; i < pos; i++) {
      antes=ahora;
      ahora=ahora->next;
    }
    antes->next=ahora->next;
  }
  size--;
}

int LinkedList::getSize(){
  return size;
}

Luchador* LinkedList::get(int pos){
  Node* nuevo=new Node;
  nuevo=head;
  if (pos!=1) {
    for(int i=1; i<pos; i++) {
      nuevo=nuevo->next;
    }
  }
  return nuevo->luchador;
}
