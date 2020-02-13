#include "telefono.h"
#include "orario.h"
#include <iostream>

int main(){
  char n[]="3926759172\0";
  telefonata t3(orario(15), orario(15,2), n), t2(orario(15), orario(15,2), n), t1;
  std::cout<<"T1:"<<std::endl<<t1<<"T2:"<<std::endl<<t2<<"T3:"<<std::endl<<t3;
  if(t1==t2)
    std::cout<<"err"<<std::endl;
  else
    std::cout<<"OK (t1 t2 diversi)"<<std::endl;
  if(t2==t3)
    std::cout<<"OK(t2 t3 uguali)"<<std::endl;
  else
     std::cout<<"err"<<std::endl;
  return 0;
}
