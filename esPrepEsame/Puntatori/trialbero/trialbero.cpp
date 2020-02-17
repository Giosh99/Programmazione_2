#include<iostream>
using std::cout;
using std::endl;

template <class T>
class trialbero;
template <class T>
std::ostream& operator<<(std::ostream& os, const trialbero<T>& t);
template <class T>
class trialbero{
    friend std::ostream& operator<< <T>(std::ostream&, const trialbero&);
};
int main(){

}