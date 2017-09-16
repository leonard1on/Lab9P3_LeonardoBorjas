#pragma once
#include <iostream>
#include "Luchador.h"
#include "Guerrero.h"
#include "Aprendiz.h"
#include "Mago.h"
#include "Alquimista.h"
#include "Dragonborn.h"

using namespace std;

struct Node {
  Luchador* luchador;
  Node* next;
};

class LinkedList{
  private:
    Node* head;
    Node* tail;
    int size;
  public:
    LinkedList();
    void addLuchador(Luchador*);
    void display();
    void insert(int, Luchador*);
    void remove(int);
    int getSize();
    Luchador* get(int);
};
