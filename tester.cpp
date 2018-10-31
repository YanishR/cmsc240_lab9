#include "LinkedList.h"

#include <string>
#include <iostream>


int main ()
{
    std::cout << "These tests will help the development of the LinkedList class: " << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    std::cout << "LinkedList<int> intList()" << std::endl;

    LinkedList<int> intList();
    intList.add(10);
    intList.add(20);

    stdt::cout << "Size: " <<intList.size(); << std::endl;
    std::cout << "\tExpected : [2]" << std::endl;

    std::cout << "intList.get(0): " << intList.get(0) << std::endl;
    std::cout << "\tExpected: [10]" << std::endl;

    intList.remove(0);

    std::cout << "Size:" << intList.size() << std::endl;
    std::cout << "\tExpected: [1]" << std::endl;

}
