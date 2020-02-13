#include "raz.h"
#include <iostream>
using namespace std;

int main(){
    Raz n1(4,2), n2(10,5), n3, n4(Raz::unTerzo()); //se dichiari un tipo senza specificare parametri ricorda di NON mettere parentesi
    cout<<"n1: "<<n1<<endl;
    cout<<"n2: "<<n2<<endl;
    cout<<"n3: "<<n3<<endl;
    cout<<"n4: "<<n4<<endl;
    cout<<"n1 inverso: "<<n1.inverso()<<endl;
    double n3d(n3);
    cout<<"n3 double: "<<n3d<<endl;
    cout<<"n1+n4="<<n1+n4<<endl;
    cout<<"n2*n4="<<n2*n4<<endl;
    if(n1==n2)
        cout<<"OK n1 ed n2 uguali"<<endl;
    else
        cout<<"ERR"<<endl;
    if(n1==n4)
        cout<<"ERR"<<endl;
    else
        cout<<"OK n1 ed n4 diversi"<<endl;
    cout<<"Incremento postfisso n3: "<<n3++<<endl;
    cout<<"Incremento prefisso n3: "<<++n3<<endl;
    return 0;
}