#include<iostream>
#include<typeinfo>
using namespace std;
class C {
    public:
    int m;
    int n;
    virtual void f() {cout<<"C.f()"<<endl;}
    void g() {}
    void g(int i, int z){}
    int s() {return 0;}
};
class D: public C{
    public:
    int a;
    void f() {cout<<"D.f"<<endl; a =0;}
    void f(int i) {}
    virtual void g(int i){}
};
void g(C& c) {
    c.f();
   // c.a = 10;
}
int main() {
    D d;
    C *pc = &d;
    if(typeid(*pc)==typeid(D)){
        D *pd = dynamic_cast<D*> (pc);
        cout<<pd->a<<endl;
    }
    int a,b;
    d.C::g(a,b);
}