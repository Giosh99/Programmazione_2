#include <iostream>
using std::cout;
using std::endl;
template <class T>
class SmartP
{
private:
    T *ptr;

public:
    SmartP(const T *t = nullptr) : ptr(t == nullptr ? nullptr : new T(*t)) {}
    // costruttore di copia ridefinito, considerando che lo SmartP punta ad un solo elemento.
    SmartP(const SmartP &s) : ptr(new T(*(s.ptr))) {}
    T& operator*() const {
        return *ptr;
    }
   /* operator T() const {
        return *ptr;
    }*/
    ~SmartP() {
        delete ptr;
    }
    // operatore di assegnazione
    SmartP& operator=(const SmartP&s) {
        if(this!=&s) {
            delete ptr;
            ptr = new T(*(s.ptr));
        }
        return *this;
    }
    bool operator == (const SmartP& s) const {
        return *ptr==*(s.ptr);
    }
    bool operator != (const SmartP& s) const {
        return *ptr!=*(s.ptr);
    }
    T* operator->() const {
        return ptr;
    }
};
class C
{
public:
    int *p;
    C() : p(new int(5)) {}
};
int main()
{
    const int a = 1;
    const int *p = &a;
    SmartP<int> r;
    SmartP<int> s(&a);
    SmartP<int> t(s);
    cout << *s << " " << *t << " " << *p << endl; // 1 1 1
    *s = 2;
    *t = 3;
    cout << *s << " " << *t << " " << *p << endl; // 2 3 1
    r = t;
    *r = 4;
    cout << *r << " " << *s << " " << *t << " " << *p << endl; // 4 2 3 1 cout
    cout<< (s == t) << " " << (s != p) << endl;                    // 0 1
    C c;
    SmartP<C> x(&c);
    cout << *(c.p) << " " << *(x->p) << endl; // 5 5
    *(c.p) = 6;
    cout << *(c.p) << " " << *(x->p) << endl; // 6 6
    SmartP<C> *q = new SmartP<C>(&c);
    delete q;
    cout << *(x->p) << endl; // 6*/
}