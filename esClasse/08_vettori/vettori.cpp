#include "vettori.h"
#include <iostream>
using std::ostream;
//COSTRUTTORE DI DEFAULT
//vettore::vettore():a(nullptr), dim(0){}

//DISTRUTTORE
vettore::~vettore(){delete[] a;}

//COSTRUTTORE DI COPIA
vettore::vettore(const vettore& v):a(v.dim==0 ? nullptr:new int[v.dim]), dim(v.dim){
    for(int i=0; i<v.dim; i++)
        a[i]=v.a[i];
}

/*vettore vettore::operator+(const vettore& v){
    vettore aux(dim+v.dim);
    int i=0;
    for(; i<dim; i++)
        aux[i]=a[i];
    for(; i<dim+v.dim; i++)
        aux[i]=v.a[i-dim];
    return aux;
}*/

vettore operator+(const vettore& v1, const vettore& v2){
    vettore aux(v1.dim + v2.dim);
    int i=0;
    for( ;i<v1.dim; ++i) aux[i] = v1[i];
    for( ;i<aux.dim; ++i) aux[i] = v2[i-v1.dim];
    return aux;
}

vettore::vettore(unsigned int s, int x):a(s==0 ? nullptr :  new int[s]), dim(s)
{
    for(int i=0; i<dim; ++i)
        a[i]=x;
}

vettore& vettore::operator=(const vettore& v)
{
    //pulisco il vettore di destinazione
    if(this!=&v)
    {
        delete[] a;
        a= v.dim==0 ? nullptr : new int[v.dim];
        dim=v.dim;
        for(int i=0; i<dim; i++)
            a[i]=v.a[i];
    }
    return *this;
}

int& vettore::operator[](const unsigned int i) const{
    return a[i]; //non servono controlli perché è giusto che chi li usa bestemmi per bene
}

bool vettore::operator==(const vettore& v) const
{
    if(dim!=v.dim)
        return false;
    for(int i=0;i<dim;i++)
        if(a[i]!=v[i])
            return false;
    return true;
}

bool vettore::operator!=(const vettore& v) const{
    if(dim!=v.dim)
        return true;
    for(int i=0;i<dim;i++)
        if(a[i]!=v[i])
            return true;
    return false;
}

void vettore::append(const vettore& v)
{
    /*int* aux=(*this+v).a; //viene fatta solo una copia del vettore
    delete[] a;
    a=aux;
    dim+=v.dim;*/
    *this=*this+v;
}

ostream& operator<<(ostream& os, const vettore& v){
    for(int i=0; i<v.dim; i++)
        os<<v[i]<<" ";
    return os;
}