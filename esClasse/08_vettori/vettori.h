#ifndef VETTORI_H
#define VETTORI_H
#include <iostream>
using std::ostream;
class vettore{
    private:
        int *a;
        unsigned int dim;
    public:
        //vettore();
        //vettore operator+(const vettore&);
        vettore(const vettore&); //costruttore di copia
        ~vettore();
        vettore& operator=(const vettore&);
        int& operator[](const unsigned int) const;
        void append(const vettore&);
        bool operator==(const vettore&) const;
        bool operator!=(const vettore&) const;
        // Conversione: unsigned int => Vettore
        vettore(unsigned int =0, int =0);
        friend ostream& operator<<(ostream&, const vettore&);
        friend vettore operator+(const vettore&, const vettore&);
};
#endif