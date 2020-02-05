#include "orario.h"
#include <iostream>

orario::orario(int h, int m, int s){ //costruttore
    if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59)
        sec=0;
    else
        sec=h*3600+m*60+s;
}
int orario::ore() const{return sec/3600;}
int orario::minuti() const{return (sec/60)%60;}
int orario::secondi() const{return sec%60;}
orario::operator int() const{return sec;} //operatore esplicito di conversione
orario orario::operator+(const orario& op) const{
    orario aux;
    aux.sec=(sec+op.sec)%SEC_GIORNO;
    return aux;
}

orario orario::operator-(const orario& op) const{
    orario aux=*this;
    aux.sec=(aux.sec-op.sec)%SEC_GIORNO;
    return aux;
}

bool orario::operator==(const orario& op) const{return sec==op.sec ? true:false;}
bool orario::operator<(const orario& op) const{return sec<op.sec ? true:false;}
bool orario::operator>(const orario& op) const{return sec>op.sec ? true:false;}
std::ostream& operator<<(std::ostream& os, const orario& x){
    return os<<x.ore()<<":"<<x.minuti()<<":"<<x.secondi();
}