#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;
class B {public: virtual ~B() {} };
class C: public B {};
class D: public B {};
class E: public C {};
int Fun(vector<B*> &v){
    int a = 0;
    for(int i =0; i<v.size();i++){
        if(typeid(C)!=typeid(v[i]) && dynamic_cast<C*>(v[i]) && typeid(*v[0])!=typeid(*v[i]))
            a++;
    }
    return a;
}
main() {
vector<B*> u, v, w;
cout << Fun(u)<<endl; // stampa 0
B b; C c; D d; E e; B *p = &e, *q = &c;
v.push_back(&c); v.push_back(&b); v.push_back(&d); v.push_back(&c);
v.push_back(&e); v.push_back(p);
cout << Fun(v)<<endl; // stampa 2
w.push_back(p); w.push_back(&d); w.push_back(q); w.push_back(&e);
cout << Fun(w)<<endl; // stampa 1
}