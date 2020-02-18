#include<iostream>
using std::cout;
using std::endl;

template <class T, int size> class C {
    private:
    class Multinfo {
        public:
        T2 t;
        int molt;
        Multinfo(T obj, int m=0): t(obj), molt(m) {}
    };
        Multinfo<T2> a;
    public:
    C(const T2& t, int s) {
        int i = 0;
        a = new Multinfo<T2>[size];
        while(size>i) {
            *(a)[i].t = t;
            if(s>=1)
                *(a)[i].molt = s;
            i++;
        }
    }
    C(const C& c) {
        
    }
};
int main() {

}