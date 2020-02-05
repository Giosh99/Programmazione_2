#include "vettori.h"
#include <iostream>
using namespace std;

int main(){
    vettore<int> v1(1,3), v2(2,5), v3;
    v3=v1+v2;
    cout<<"v1: "<<v1<<endl;
    cout<<"v2: "<<v2<<endl;
    cout<<"v3: "<<v3<<endl;
    return 0;
}