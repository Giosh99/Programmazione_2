#include<iostream>
using namespace std;
template<class T> class D; // dichiarazione incompleta
template<class T1, class T2>
class C {
friend class D<T1>;
private:
T1 t1;
T2 t2;
};
template<class T>
class D {
public:
void m() {C<T,T> c; cout << c.t1 << c.t2;}
void n() {C<T, int> c; cout << c.t1 << c.t2;}
void o() {C<T,int> c; cout << c.t1 << c.t2;}
void p() {C<int,int> c; cout << c.t1 << c.t2;}
void q() {C<int,double> c; cout << c.t1 << c.t2;}
void r() {C<char,double> c; cout << c.t1 << c.t2;}
};
//int main() { D<char> d; d.m(); } si compila
//int main() { D<char> d; d.n(); } non compila
//int main() { D<char> d; d.o(); } si compila
//int main() { D<char> d; d.p(); } non compila
//int main() { D<char> d; d.q(); } non compila
//int main() { D<char> d; d.r(); } si compila