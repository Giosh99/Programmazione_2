#include<iostream>
using namespace std;
class C {
    public:
    virtual void m() {cout<<"C"<<endl;}
    virtual ~C(){};
};
class D: public C {
    public:
    char m(int i) {cout<<"D"<<endl;}
};
class E:public C{void m() {cout<<"E"; }};
int main() {
    C c;
    D d;
    C *Pd = &d;
    C *Pc = dynamic_cast<C*>(Pd);
    if(!Pc) cout<<"infatti";
    Pc->m();
}
