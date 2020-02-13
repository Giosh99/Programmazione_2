#include "albero.h"
#include <iostream>
using namespace std;

int main(){
    trialbero<int> t1, t2, t3;
    t1.insert(1);
    t1.insert(2);
    t2.insert(3);
    t2.insert(4);
    t3.insert(5);
    t3.insert(6);
    cout<<t1<<endl<<t2<<endl<<t3<<endl;
    int x;
    cout<<"Inserisci valore da cercare: ";
    cin>>x;
    bool found=false;
    if(!found && t1.search(x)){
        cout<<"Trovato in t1"<<endl;
        found=true;
    }
    if(!found && t2.search(x)){
        cout<<"Trovato in t2"<<endl;
        found=true;
    }
    if(!found && t3.search(x)){
        cout<<"Trovato in t3"<<endl;
        found=true;
    }
    return 0;
}