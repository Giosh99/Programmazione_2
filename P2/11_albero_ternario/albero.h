/*
Definire un template di classe albero<T> i cui oggetti rappresentano un albero 3-ario ove i nodi memorizzano dei valori di tipo T ed hanno
3 figli (invece dei 2 figli di un usuale albero binario). Il template albero<T> deve soddisfare i seguenti vincoli:

1. Deve essere disponibile un costruttore di default che costruisce l'albero vuoto
2. Gestione dell memoria senza condivisione.
3. Metodo void insert (constT&): a.insert(t) inserisce nell'albero a una nuova radice che memorizza il valore t ed avente come figli 3 copie di a
4. Metodo bool search(const T&): a.search(t) ritorna true se se t occore nell'albero a, altrimenti ritorna false
5. Overloading dell'operatore di output(<<)
6. Overloading dell'operatore di uguaglianza. 
*/
#ifndef ALBERO_H
#define ALBERO_H
#include <iostream>
//bisogna ridichiarare la classe in quanto se non viene fatto , la dichiarazione dell'operatore di output da' errore e non riconosce trialbero<T>
template <class T> class trialbero;

template <class T> std::ostream& operator<<(std::ostream&, const trialbero<T>&);

template <class T> 
class trialbero{
    friend std::ostream& operator<< <T>(std::ostream&, const trialbero&);
    private:
        //template classe associato ad albero
        class nodo{ 
            public:
                T info;
                nodo *sx, *cx, *dx;
                nodo(const T& t=T(), nodo* s=0, nodo* c=0,nodo* d=0): //viene preso di default un elemento vuoto generato con costruttore di default per T 
                  info(t), sx(s), cx(c), dx(d) {}      
        };
        nodo *root; //trialbero vuoto se root=nullptr
        static nodo* copy(nodo *p)
        {
            if(!p)
                return nullptr;
            //p!=nullptr
            return new nodo(p->info, copy(p->sx), copy(p->cx), copy(p->dx));    
        }
        static void destroy(nodo *p){
           if (p){
               destroy(p->sx);
               destroy(p->cx);
               destroy(p->dx);
               delete p; //richiama il distruttore del nodo contenente tipo T(esas)
           }
        }
        static bool recursive_search(nodo* root, const T& t)
        {
             if(!root)
                return false;
            //se root!=nullptr
            return (t == root->info) || recursive_search(root->sx, t) || recursive_search(root->cx, t) || recursive_search(root->dx, t);
            //se t==root->info altrimenti cerco nel resto dell'albero ricorsivamente
        }

        static bool recursive_equality(nodo* t1, nodo* t2){
            if(!t1  && !t2)
                return true;
            //p1 || p2
            if(!t1  || !t2)
                return false;
            //p1 && p2
            return t1->info==t2->info && recursive_equality(t1->sx, t2->sx)&& recursive_equality( t1->cx, t2->cx)&& recursive_equality( t1->dx, t2->dx);
        }

        static std::ostream& recursive_print(std::ostream& os, nodo *p){
            if(p){
                os<<p->info<<"(";
                recursive_print(os, p->sx);
                os<<",";
                recursive_print(os, p->cx);
                os<<",";
                recursive_print(os, p->dx);
                os<<")";
            }
            else
                os<<"_";;
            return os;
        }
    
    public:
        trialbero():root(nullptr){}
        //rule of Three: c'è un puntatore
        trialbero(const trialbero& t):root(copy(t.root)){}
        trialbero& operator=(const trialbero& t){
            if(this != &t){ //NB se non e' lo stesso albero lo distruggo altrimenti non so che copiare
               destroy(root); //tolgo garbage
               root= copy(t.root);
            }
            return *this;
        }
        ~trialbero(){destroy(root);}

        void insert(const T& t){
            root=new nodo(t, root, copy(root), copy(root));
        }
        bool search(const T& t) const{
            return recursive_search(root, t);
        }
        bool operator==(const trialbero& t) const{
            return recursive_equality(root, t.root);
        }
};

template <class T> 
std::ostream& operator<<(std::ostream& os, const trialbero<T>& t){
    return trialbero<T>::recursive_print(os, t.root);
}

#endif