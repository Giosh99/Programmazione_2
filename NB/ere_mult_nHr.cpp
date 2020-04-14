// ereditarieta' multipla name hiding rule (le funzioni o hanno nomi completamente diversi oopure devo usare l'operatore id scoping)
#include<iostream>
using namespace std;

class A {
    public:
    void f() {cout<<"A"<<endl;}
};
class B {
    public:
    void f(int i=0) {cout<<"B"<<endl;}
};
class C: public B, public A {

};

int main() {
    C c;
    //c.f() ambiguita' 
    c.A::f(); // disambiguando con lo scoping va bene
    return 0;
}