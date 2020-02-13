#include <iostream>
#include "point.h"
#include <cmath>
using namespace std;

point::point(){x=0; y=0; z=0;}
point::point(double _x, double _y, double _z){x=_x; y=_y; z=_z;}
void point::negate(){
    x=x*(-1.0);
    y=y*(-1.0);
    z=z*(-1.0);
}
double point::norm() const{return sqrt(x*x+y*y+z*z);}
point point::operator+(const point& a) const{
    point aux=*this;
    aux.x+=a.x;
    aux.y+=a.y;
    aux.z+=a.z;
    return aux;
}
double point::getX() const{return x;}
double point::getY() const{return y;}
double point::getZ() const{return z;}
ostream& operator<<(ostream& os, const point& a){
    return os<<"x="<<a.getX()<<" y="<<a.getY()<<" z="<<a.getZ()<<endl;
}

int main(){
    point a(1,1,1), b(2,2,2);
    const point c(3,3,3), d(4,4,4);
    cout<<a<<b<<c<<d;
    point somma=a+c;
    cout<<somma;
    cout<<"norma di c: "<<c.norm()<<endl;
    b.negate();
    cout<<"ho negato b: "<<b;
    return 0;
}