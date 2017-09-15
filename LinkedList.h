#pragma once
#include <iostream>
#include "Luchador.h"
#include "Guerrero.h"
#include "Aprendiz.h"
#include "Mago.h"
#include "Alquimista.h"
#include "Dragonborn.h"

using namespace std;

struct node {
  Luchador* data;
  node* next;
};

class LinkedList{
  private:
    node* head, tail;
  public:
    LinkedList();
};
