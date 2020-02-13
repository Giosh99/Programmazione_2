#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
template <class T=char, int num=100>
class stack {
    template<class T2, int num1>
    friend ostream& operator<<(std::ostream&os, stack<T2,num1>& s);
    private:
    class nodo {
        public:
        T info;
        nodo* next;
        nodo(): next(0) {}
        nodo(T i, nodo* n=0): info(i), next(n) {}
        ~nodo() {delete next;}
    };
    nodo* copy(nodo*s) {
        if(!s)
            return nullptr;
        else return new nodo(s->info, copy(s->next));
    }
    nodo* takeFromBottom() {
        if(ptr) {
            nodo *n = ptr;
            while(n->next) {
                n = n->next;
            }
            return copy(n);
        }
        else return 0;
    }
    nodo* takeFromTop() {
        if(!ptr) return NULL;
        else {
            nodo *p = ptr;
            ptr = ptr->next;
            p->next = 0;
            nodo* n = copy(p);
            this->push();
            return n->info;
        }
    }
    public:
    nodo* ptr;
    stack():ptr(0) {}
    stack(T t, int k) {
        if(k<0) 
            ptr = new nodo();
        else {
            if(k>num) k = num;
            ptr = new nodo(t);
            k--;
            nodo *p = ptr;
            while(k) {
                p->next = new nodo(t);
                p = p->next;
                k--;
            }
        }
    }
    stack(const stack& s) {
        delete this->ptr;
        this->ptr = copy(s.ptr);
    }
    ~stack() {
        delete ptr;
    }
    bool isFull() const{
        nodo* punt = ptr;
        int i = 0;
        while(punt) {
            ++i;
            punt = punt->next;
        }
        return (i==num?true:false);
    } 
    bool isEmpty() const{
        return (!ptr? true: false);
    }
    /*operator int() const{
        return num;
    }*/
    bool push(const T& t) {
        if(this->isFull())
            return false;
        else {
            if(this->isEmpty())
                ptr = new nodo(t);
            else {
                ptr = new nodo(t,ptr);
            }
            return true;
        }
    }
    void pop() {
        if(!this->isEmpty()){
            nodo* n = ptr;
            ptr = ptr->next;
            n->next = 0;
            delete n;
        }
    }
    T top() const {
        if(!ptr) return T();
        else {
            return ptr->info;
        }
    }
    T bottom() const {
        if(ptr) {
            nodo *n = ptr;
            while(n->next) {
                n = n->next;
            }
            return n->info;
        }
        else return 0;
    }
    bool search(const T& t) const{
        nodo*n = ptr;
        while(n) {
            if(n->info == t)
                return true;
        }
        return false;
    }
    bool flush() {
        delete ptr;
    }
    unsigned int size() const{
        int i = 0;
        nodo *n = ptr;
        while(n) {
            n = n->next;
            i++;
        }
        return i;
    }
    // per la somma posso usare bottom e push e size cosi e piu easy
    stack operator+(stack& s) const {
        stack n;
        n.ptr = this->ptr;
        while(num>n.size()) {
            n.push(s.bottom());
        }
        return n;
    }
};
template <class T, int num>
ostream& operator<<(std::ostream&os, stack<T,num>&s) {
    int i =0;
    typename stack<T,num>::nodo *p = s.ptr;
    while(i<s.size()) {
        os<<p->info;
        p++;
        i++;
    }
    return os;
}
int main() {
    stack<int, 6> s1(7,3);
    stack<int,6> s2(1,6);
    stack<int,6> result = s1+s2;
    int i = 0;
    cout<<result<<endl;
}