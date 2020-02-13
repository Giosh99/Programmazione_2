#include "queue.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    queue<int> q1, q2, q3, v;
    int i=1;
    while(i<=10){q1.add(i); ++i;}
    while(i<=20){q2.add(i); ++i;}
    queue<int> q4(q1);
    q3=q1;
    cout<<v<<endl<<q1<<endl<<q2<<endl<<q3<<endl;
}