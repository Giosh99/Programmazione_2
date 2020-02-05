#include "dList.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "start" << endl;
    dList<int> L(3, 3);
    cout << L << endl;
    dList<int>::const_iterator c = L.begin();
    c.operator++;
    dList<int>::const_iterator d = c++;
    d-5;
    /*L.insertBack(0);
    L.insertFront(1);
    cout << L << endl;
    dList<int>::const_iterator it;
    for (it = L.begin(); it != L.end(); it++)
        cout << *it << " ";
    cout << endl;
    /*it=L.end();
    it--;
    for (; it!=0; it--)
        cout<<*it<<" ";
    cout<<endl;*/
    //*it=6; ERRORE DEL COMPILATORE: EXPRESSION MUST BE A MODIFIABLE L-VALUE (GIUSTO PERCHÈ IL TIPO DI IT È RIFERIMENTO CONST=> L'R-VALORE NON È MODIFICABILE)
   /* dList<char> LC;
    LC.insertBack('a');
    LC.insertBack('b');
    LC.insertBack('c');
    LC.insertFront('x');
    cout << LC << endl;
    dList<char> l2 = LC;
    l2.insertFront('y');
    cout << l2 << endl;
    dList<int> L2;
    L2 = L;
    cout << L2 << endl;
    dList<char>::const_iterator itc = l2.begin();
    for (int i = 0; i < l2.size(); i++)
        cout << *(itc + i) << " ";
    cout << endl;
    dList<int> t;
    if (t.empty())
        cout << "t vuota" << endl;
    else
        cout << "err" << endl;
    if (!l2.empty())
        cout << "l2 non vuota" << endl;
    else
        cout << "err" << endl;
    cout << "end" << endl;*/
    return 0;
}
