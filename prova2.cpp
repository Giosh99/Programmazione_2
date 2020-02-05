#include<iostream>
using namespace std;
class C {
    public:
    int x;
    C(): x(100) {cout<<"C()"<<endl;}
    C(int i): x(i){cout<<"C(int)"<<endl;}
    C(const C& i): x(i.x){cout<<"C(const C&)"<<endl;}
    const C& operator=(const C& d) {cout<<"C::operator="<<endl;}
};
class D{
    public:
    int y;
    C c;
    D(): y(0) {cout<<"D()"<<endl;}
    //D(int i): y(i), C(i){cout<<"D(int)"<<endl;}
    D(const D& i): y(i.y) {cout<<"D(const D&)"<<endl;} 
   //const D& operator=(const D& d) {cout<<"D::operator="<<endl;}
};
int main() {
    C c(6);
    cout<<" "<<endl;
    D d;
    cout<<" "<<endl;
    D copia(d);
}