#include <iostream>
#include "vettori.h"

int main() {
  vettore v1, v2(3,3), v3(5,5);
  v1 = v2+v3;
  v2.append(v2);
  v3.append(v1);
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;
}

/*
problema, erano stati definiti due costruttori
uno a zero parametri "vettore()"
e uno a due parametri, ma con parametri di default impostati a zero: era quindi costruttore a 0, 1 e 2 parametri;
percio' il compilatore era in uno stato di ambiguita' in quanto era come se il 
costruttore di default senz parametri fosse stato definito due volte.
*/