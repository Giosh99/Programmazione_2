#ifndef STACK
#define STACK 
#include <iostream>
template <class T=char, int num=100>
class stack {
    private:
    class nodo;
    nodo *s;
    class nodo {
        public: 
        T info;
        nodo* next;
        nodo(): next(nullptr){}
        nodo(const T& i, nodo * n): info(i), next(n){}
        ~nodo() {
            if(next!=0) delete next;
        }
    };
    nodo* copy(nodo* p) const {
        if(!p) return nullptr;
        else return new nodo(p->info, copy(p->next));
    }
    public: 
    stack() :s(0){ }
    stack(T t, int k):s(0){
        int n;
        if(k>num)
            n = num;
        else if(k<0) n = 0; else n = k;
        while(n) {
            if(!s) 
                s = new nodo(t,nullptr);
            else 
                s = new nodo(t,s);
            n--;
        }
    }
    ~stack() {
        if(s) delete s;
    }
    bool isEmpty() const {
        if(s==0) return true;
        else return false;
    }
    bool isFull() const  {
        int n=0;
        nodo*ptr = s;
        while(ptr) {
            std::cout<<ptr->info<<std::endl;
            ptr = ptr->next;
            n++;
        }
        if(n == num)
            return true;
        else return false;
    }
    unsigned int size() const {
        nodo*p = s;
        int i = 0;
        while(p) {
            i++;
            p = p->next;
        }
        return i;
    }
    // ridefinizioni varie per copia profonda (distruzione profonda gia' fatta)
    const stack&  operator = (const stack& c) {
        if(this != &c) {
            delete s;
            s = copy(c.s);
            return *this;
        }
    }
    stack(const stack& c): s(copy(c.s)) {}
    // conversione esplicita a int
    operator int() const {return size();}
    // funzione inserimento, se lo stack e' gia' pieno lascia invariato, ritorna true se 
    // l'inserimento e' avvenuto correttamente, altrimenti false
    bool push(const T& t) {
        int size = *this;
        if(size<num) {
            s = new nodo(t,s);
            return true;
        }
        else return false;
    }
    void pop() {
        if(s) {
            nodo* old = s;
            s = s->next;
            old->next = nullptr;
            delete old;
        }
    }
    T top(){
        if(s) {
            nodo* old = s;
            s = s->next;
            old->next = nullptr;
            nodo* new =  copy(old);
            this->push(old);
            return new;
        }
        else return NULL;
    }
    T bottom() {
        nodo *ptr = s;
        if(ptr) {
            while(ptr->next)
            ptr->next;
            return copy(ptr);
        }
        else return NULL;
    }
    bool search(T t) {
        nodo *ptr = s;
        while(ptr) {
            if(ptr->info == t)
                return true;
        }
        return false;
    }
};
#endif