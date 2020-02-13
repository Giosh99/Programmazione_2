#include <iostream>
#include "stack.h"
int main() {
    stack<int,9> stack1(8,6);
   // std::cout<<s.isEmpty()<<std::endl;
   // std::cout<<s.isFull()<<std::endl;
  // std::cout<<s.size()<<std::endl;
  std::cout<<stack1.size()<<std::endl;
   stack1.push(7);

}