#include<iostream>
#include <vector>
#include<typeinfo>
using std::cout;
using std::endl;
using std::vector;
class C {public:virtual ~C(){}};
class B: public C {~B(){}};
template<class T1, class T2> bool Fun(T1* t1, T2&t2) {
    C *c3 = &t2;
    cout<<typeid(*t1).name()<<endl;
    cout<<typeid(*c3).name()<<endl;
    if(typeid(t1)==typeid(c3) && typeid(*t1)==typeid(*c3)&& dynamic_cast<C>(t1) ) {
        return true;
    }
    else return false;
}
int main() {
    B *b = new B;
    C *c1 = b;
    C &c2 = *b;
    bool a = Fun(c1,c2);
    cout<<a<<endl;
}