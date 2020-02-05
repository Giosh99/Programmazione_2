#include <iostream>
using namespace std;

class Z{
    inline friend ostream& operator<<(ostream& os, const Z& c){os<<c.x; return os;} //forzatura definizione inline
    public:
        Z():x(0){}
        Z(int n):x(n){} //permesso poichè esiste già costruttore di char da int
        Z operator++(){
            Z aux;
            aux.x=x;
            x++;
            return aux;
        }
        Z operator++(int){
            x++; //esiste già incremento postfisso dei char
            return *this;
        }
        bool operator==(const Z& c) const{
            return x==c.x;
        }
        Z operator=(const Z& c){
            x=c.x;
            return *this;
        }
        bool operator==(int n){
            return x==n; //possibile perchè esiste già operatore di confronto tra int e char
        }
        Z operator=(int n){
            x=n; //possibile perchè esiste già operatore di assegnazione da int a char
            return *this;
        }
    private:
        char x;
};

template <class T1, class T2=Z>
class C{
    public:
        T1 x;
        T2 *p;
};

template <class T1, class T2>
void fun(C<T1,T2> *q){
    ++(q->p); //incremento un puntatore, già definito
    if(true==false)
        cout<<++(q->x);
    else
        cout<<q->p<<endl; //stampo un indirizzo di memoria, già definito
    (q->x)++;  
    if(*(q->p)==q->x)
        *(q->p)=q->x;
    T1 *ptr=&(q->x);
    T2 t2=q->x;
}
//SEGMENTATION FAULT PERCHÈ VENGONO SPOSTATI I PUNTATORI A CASO
int main(){
    C<Z> c1; //serve costruttore di default di Z, poichè c1.x è di tipo Z
    fun(&c1); //incremento un tipo Z, da definire (q->x)++ incremento postfisso e prefisso
    //operatore stampa di Z
    //serve operator== poichè si confrontano due elementi di tipo Z
    //serve operatore di assegnazione, poichè assegno Z ad un altro Z
    //costruttore di copia non necessario poichè esegue operazioni di default per copiare due char
//
//
    C<int> c2; //non serve definire nulla, c2.x è di tipo int, c2.p è puntatore a Z, dunque ok
    fun(&c2); //incremento c2.x già definito
    //confronto int con Z, serve operator== tra Z e int
    //assegnazione di un int a Z
    //costruttore ad un parametro di Z per convertire int in Z poichè viene creato t2 a partire da un intero
    return 0;
}