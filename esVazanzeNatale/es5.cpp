#include<iostream>
using namespace std;
namespace ns {
class C {
    friend int f();
private:
int x;
public:

C(int n=5) : x(n) {}
};
int f() {
    ns::C c;
return c.x;
}
}
/*int f() {
ns::C c;
return c.x;
}*/
int main() {
cout<<ns::f()<<endl;
}