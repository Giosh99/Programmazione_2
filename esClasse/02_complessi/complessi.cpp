#include "complessi.h"
#include <iostream>
#include <cmath>
using namespace std;

complesso::complesso(double x, double y){re=x; im=y;}
double complesso::modulo()const{return sqrt(re*re + im*im);}
complesso complesso::operator+(const complesso& x)const{
    complesso aux=*this;
    aux.re+=x.re;
    aux.im+=x.im;
    return aux;
}
complesso complesso::operator-(const complesso& x)const{
    complesso aux=*this;
    aux.re-=x.re;
    aux.im-=x.im;
    return aux;
}
bool complesso::operator==(const complesso& x)const{
    return (re==x.re && im==x.im) ? true:false;
}

void complesso::stampa()const{
    cout<<re;
    if(im>0) cout<<"+";
    if(im!=0)
        if(im==1)
            cout<<"i";
        else
            if(im==-1)
                cout<<"-i";
            else
                cout<<im<<"i";
}

int main(){
    const complesso n1(2,1), n2;
    complesso n3(8,-2),  n4(2,3);
    cout<<"n1: "; n1.stampa(); cout<<endl;
    cout<<"n2: "; n2.stampa(); cout<<endl;
    cout<<"n3: "; n3.stampa(); cout<<endl;
    cout<<"n4: "; n4.stampa(); cout<<endl;
    cout<<"Confronto n1 ed n3: ";
    if(n1==n3)
        cout<<"Uguali"<<endl;
    else
        cout<<"Diversi"<<endl;
    cout<<"Confronto n1 ed n4: ";
    if(n1==n4)
        cout<<"Uguali"<<endl;
    else
        cout<<"Diversi"<<endl;
    cout<<"Moduli"<<endl;
    cout<<"n1: "<<n1.modulo()<<endl;
    cout<<"n2: "<<n2.modulo()<<endl;
    cout<<"n2: "<<n3.modulo()<<endl;
    cout<<"n2: "<<n4.modulo()<<endl;
    complesso somma=n1+n3;
    cout<<"n1+n3 = "; somma.stampa(); cout<<endl;
    complesso diff=n2-n3;
    cout<<"n2-n3 = "; diff.stampa(); cout<<endl;
    return 0;
}