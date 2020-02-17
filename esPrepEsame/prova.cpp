#include<iostream>

class C {
};
class D: public C{
    public:
    virtual C* foo() {
        return new D();
    }
};
int main() {
    D d;
    std::cout<<typeid(d.foo()).name();
}