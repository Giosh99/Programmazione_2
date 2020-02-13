#include<iostream>
using namespace std;
template <class T> class SmartP {
    private:
    T *ptr;
    public:
    SmartP(): ptr(nullptr){}
    SmartP(const T*p){ptr = new T(*p);}
    SmartP(SmartP& p): ptr(new T(*p)) {}
    ~SmartP(){delete(ptr);}
    SmartP& operator=(const SmartP& c) {
        if(this!=&c){
            delete ptr;
            ptr= new T(*(c.ptr));
            return *this;
        }
    }
    T& operator* () {
        return *ptr;
    }
    bool operator==(SmartP& o) const {
        if(*ptr==*o)
            return true;
        else return false;
    }
        bool operator!=(SmartP& o) const {
        if(*ptr==*o)
            return false;
        else return true;
    }
    T* operator->(){
        return ptr;
    }
};
class C{
    public:
    int *p;
    C():p(new int(5)){}
};
int main() {
const int a=1; const int* p=&a;
SmartP<int> r; SmartP<int> s(&a); SmartP<int> t(s);
cout << *s << " " << *t << " " << *p << endl; // 1 1 1
*s=2; *t=3;
cout << *s << " " << *t << " " << *p << endl; // 2 3 1
r=t; *r=4;
cout << *r << " " << *s << " " << *t << " " << *p << endl; // 4 2 3 1
cout << (s == t) << " " << (s != p) << endl; // 0 1
C c; SmartP<C> x(&c);
cout << *(c.p) << " " << *(x->p) << endl; // 5 5
*(c.p)=6;
cout << *(c.p) << " " << *(x->p) << endl; // 6 6
SmartP<C>* q = new SmartP<C>(&c);
delete q;
cout << *(x->p) << endl; // 
}