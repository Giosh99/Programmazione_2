#include "telefono.h"
#include <iostream>
telefonata::telefonata(){num=0;}

telefonata::telefonata(const orario& i, const orario& f, char* n){
  inizio=i;
  fine=f;
  num=n;
}

orario telefonata::Inizio() const{return inizio;}

orario telefonata::Fine() const{return fine;}

const char* telefonata::Numero() const{return num;}

bool telefonata::operator==(const telefonata& x) const{
  return inizio==x.inizio && fine==x.fine && this->confrontaNumeri(x.num); //this per chiarezza, possibile omissione
}

bool telefonata::confrontaNumeri(const char* const x) const{ //NB non si può fare overloading confronto
                                                            //tra due char* poichè già definito da standard
  bool check=true;
  for(int i=0; check && (x+i)!=0 && (num+i)!=0 && *(x+i)!=0 && *(num+i)!=0; i++)
    if(*(x+i)!=*(num+i))
      check=false;
  return check;
}

std::ostream& operator<<(std::ostream& os, const telefonata& x){
  os<<"Ora inizio: "<<x.Inizio()<<std::endl;
  os<<"Ora fine: "<<x.Fine()<<std::endl;
  os<<"Numero: ";
  int i=0;
  while((x.Numero()+i)!=0 && *(x.Numero()+i)!=0){
    os<<*(x.Numero()+i);
    i++;
  }
  os<<std::endl;
  return os;
}