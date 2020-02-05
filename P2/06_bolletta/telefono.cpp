#include "telefono.h"
#include <iostream>
telefonata::telefonata(){}

telefonata::telefonata(const orario& i, const orario& f, const string n):inizio(i), fine(f), num(n){}

orario telefonata::Inizio() const{return inizio;}

orario telefonata::Fine() const{return fine;}

string telefonata::Numero() const{return num;}

bool telefonata::operator==(const telefonata& x) const{
  return inizio==x.inizio && fine==x.fine && num==x.num;
}

std::ostream& operator<<(std::ostream& os, const telefonata& x){
  os<<"Ora inizio: "<<x.Inizio()<<std::endl;
  os<<"Ora fine: "<<x.Fine()<<std::endl;
  os<<"Numero: "<<x.Numero()<<std::endl;
  return os;
}