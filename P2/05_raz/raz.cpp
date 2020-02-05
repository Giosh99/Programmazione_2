#include "raz.h"
#include <iostream>

//scelta implementativa: se viene passato denominatore nullo prendo valore di default 1
Raz::Raz(int n, int d):num(n), den(d ? d:1){}

//scelta implementativa: reciproco di 0 è 0
Raz Raz::inverso() const{return num==0 ? Raz():Raz(den, num);}

Raz::operator double() const{
    return static_cast<double>(num)/static_cast<double>(den);
}

Raz Raz::operator+(const Raz& x) const{
    double mcm=den*x.den;
    return Raz((mcm/den*num)+(mcm/x.den*x.num),mcm);
}

Raz Raz::operator*(const Raz& x) const{
    return Raz(num*x.num, den*x.den);
}

Raz& Raz::operator++(){
    num+=den;
    return *this;
}

Raz Raz::operator++(int){
    Raz aux(*this);
    *this=this->operator+(1);
    return aux;
}

bool Raz::operator==(const Raz& x) const{
    Raz aux=(*this)*(x.inverso());
    return aux.num==aux.den;
}

std::ostream& operator<<(std::ostream& os, const Raz& x){
    return os<<x.operator double();
}

Raz Raz::unTerzo() {return Raz(1,3);}