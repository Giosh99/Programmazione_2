#include<iostream>
using std::cout;
using std::endl;
template <class T, int size> class C;
template <class T, int size> std::ostream& operator << (std::ostream& os, C<T,size>& c);

template <class T, int size> class C {
    friend std::ostream& operator << <T>(std::ostream& os, C<T,size>& c);
    private:
    class Multinfo {
        public:
        T t;
        int molt;
        Multinfo(): molt(0) {}
        Multinfo(T obj, int m=0): t(obj), molt(m) {}
    };
        Multinfo *a;
    public:
    C() : a(nullptr){}
    C(const T& t, int s) {
        int i = 0;
        a = new Multinfo[size]; // costruisce un oggetto per ogni posziione tamite costruttore fdidefault, non oposso chiamare esplicitamente altri costruttori
        while(size>i) {
            a[i].t = t;
            if(s>=1)
                a[i].molt = s;
            i++;
        }
    }
    C(const C& c) {
        delete[] a;
        a = new Multinfo(*(c.a));
    }
    C& operator = (const C& c) {
        if(this!=&c) {
            delete [] a;
            a = new Multinfo(*(c.a));
        }
    }
    ~C() {delete [] a;}
    T* operator[](int i) {
        if(size&&i>=0) {
            T* p = &(a[i]);
            return p;
        }
        else return nullptr;
    }
};
template <class T, int size>
std::ostream& operator << (std::ostream& os, C<T,size>& c) {
    int i = 0;
    while(i<size) {
        os<< c.a[i].t;
        i++;
    }
    return os;
}
int main() {
    int i = 1;
    C<int, 4> c(i,4);
    cout<<c<<endl;
}