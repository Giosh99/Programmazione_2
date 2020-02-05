/* ESERCIZIO:
Definire una classe vettore i cui oggetti rappresentano array di template. 
vettore deve includere un costruttore di default, una operazione di 
concatenazione che restituisce un nuovo vettore v1+v2, una operazione di 
append v1.append(v2), l'overloading dell'uguaglianza, dell'operatore di 
output e dell'operatore di indicizzazione.  Deve inoltre includere il 
costruttore di copia profonda, l'assegnazione profonda e la distruzione profonda.*/
#ifndef VETTORI_H
#define VETTORI_H
#include <ostream>
template <class T> class vettore;
template <class T>
std::ostream& operator<<(std::ostream&,const vettore<T>&);

template <class T> 
vettore<T> operator+(const vettore<T>&, const vettore<T>&);

template<class T> class vettore{
    friend vettore<T> operator+ <T> (const vettore<T>&, const vettore<T>&);
    friend std::ostream& operator<< <T>(std::ostream&, const vettore<T>&);
    public:
        vettore(T, unsigned int=0);
        vettore();
        ~vettore();
        vettore(const vettore&);
        vettore operator=(const vettore&);
        void append(const vettore&);
        bool operator==(const vettore&) const;
        T& operator[](unsigned int) const;
    private:
        T* v;
        unsigned int dim;
};

template<class T> vettore<T>::vettore(T x, unsigned int d):v(d ? new T[d] : nullptr), dim(d){
    for(int i=0; i<d; i++)
        v[i]=x;
}

template<class T> vettore<T>::vettore():v(nullptr), dim(0){}

template<class T> vettore<T>::~vettore(){
    delete[] v;
}

template<class T>
vettore<T>::vettore(const vettore& x):v(x.dim ? new T[x.dim]:nullptr), dim(x.dim){
    for(int i=0; i<x.dim; i++)
        *(v+i)=*(x.v+i);
}

template<class T>
vettore<T> vettore<T>::operator=(const vettore& x){
    if(this!=&x){
        delete[] v;
        dim=x.dim;
        v= dim ? new T[dim] : nullptr;
        for(int i=0; i<dim; i++)
            v[i]=x.v[i];
    }
    return *this;
}

template<class T>
void vettore<T>::append(const vettore& x){
    T* aux=(*this+x).v;
    delete[] v;
    v=aux;
    dim+=x.dim;
}

template<class T>
T& vettore<T>::operator[](unsigned int i) const{
    return v[i];
}

template<class T>
bool vettore<T>::operator==(const vettore& x) const{
    if(dim!=x.dim) return false;
    for(int i=0; i<dim; i++)
        if((*this)[i]!=x[i])
            return false;
    return true;
}

template<class T>
vettore<T> operator+(const vettore<T>& v1, const vettore<T>& v2){
    vettore<T> aux;
    aux.dim=v1.dim+v2.dim;
    aux.v=aux.dim ? new T[aux.dim]:nullptr; //SE VIENE ALLOCATO UN ARRAY SULLO HEAP DI DIMENSIONE NULLA(0) SE SI PROVA A DEREFERENZIARE TALE ARRAY, NON VIENE SEGNALATO
    //UN ERRORE DI SEG-FAULT, MA E' POSSIBILE ALLOCARE LA MEMORIA A PIACIMENTO (BOH). 'Ccodio
    int i;
    for(i=0; i<v1.dim; i++)
        aux[i]=v1[i];
    for(i=v1.dim; i<aux.dim; i++)
        aux[i]=v2[i-v1.dim];
    return aux;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const vettore<T>& x){
    for(int i=0; i<x.dim; i++)
        os<<x[i]<<" ";
    return os;
}
#endif