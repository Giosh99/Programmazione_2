#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;
class A {
    protected:
    virtual void j() {cout<<"A::j ";}
    public:
    virtual void g() const {cout<<"A::g ";}
    virtual void f() {cout<<"A::F ";g();j();}
    void m() {cout<<"A::m"; g(); j();}
    virtual void k() {cout<<"A::k ";j(); m();}
    virtual A* n() {cout<<"A::n  "; return this;}
};
class B: public A{
    public: 
    virtual void g() const override {cout<<"B::g ";}
    virtual void m() {cout<<"B::m "; g(); j();}
    void k() {cout<<"B::k "; A::n();}
    A* n() override {cout<<"B::n "; return this;}
};
class C: public A {
    private:
    void j() {cout<<"C::j ";}
    public:
    virtual void g() {cout<<"C::g ";}
    void m() {cout<<"C::m "; g(); j();}
    void k() const { cout <<" C::k "; k(); } 
};
class D: public B {
protected:
void j() { cout <<" D::j "; }
public:
B* n() final { cout <<" D::n "; return this; }
void m() { cout <<" D::m "; g(); j(); }
 };
 class E : public A{}; 
 int main() {
     A*p1 = new D(); A*p2 = new B(); A*p3 = new C(); B*p4 = new D(); const A*p5 = new C();
//p1->g(); 
//p1->k(); 
//p2->f(); 
//p2->m(); 
//p3->k(); 
//p3->f(); 
//p4->m(); 
//p4->k(); 
//p5->g(); 
//(p3->n())->m(); 
//(p3->n())->n()->g(); 
//(p4->n())->m(); 
//(p5->n())->g(); 
//(dynamic_cast<B*>(p1))->m();
(static_cast<C*>(p2))->k(); 
//(static_cast<B*>(p3->n()))->g(); 
 }