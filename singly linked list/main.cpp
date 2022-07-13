#include <iostream>
#include "sll.h"

int main(){
    INTSLList sl;
    sl.addToHead(5);
    std::cout << sl.isInList(5) << '\n';
}