#include "LinkedList.h"

#include <string>
#include <iostream>


int main ()
{
    std::cout << "These are the tests: " << std::endl;

    LinkedList<int> intList();
    intList.add(10);
    intList.add(20);

    stdt::cout << "Size: " <<intList.size(); << std::endl;

    std::cout << << intList.get(0) << std::endl;
    std::cout << "Expected: [10]" << std::endl;

}
