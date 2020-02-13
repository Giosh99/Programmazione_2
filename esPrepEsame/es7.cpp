#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;
class A{
    public:
    virtual ~A()=0;
};

class B:A{};
class C:public B{
~C(){}
};
class D {
    public:
    int c;
    protected: 
    D():c(100){}
};
class E:public D{
    public:
    const E& operator=(const E& e) {D::operator=(e); return *this;}
};
int main(){
    E e;
    E copy(e);
    cout<<copy.c<<endl;
}