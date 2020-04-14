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

#endif