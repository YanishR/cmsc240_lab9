#include "LinkedList.h"

#include <string>
#include <iostream>
#include <vector>


int main ()
{
    std::cout << "These tests will help the development of the LinkedList class: " << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    std::cout << "LinkedList<int> intList" << std::endl;
    LinkedList<int> intList;


    std::cout << "intList.add(10)" << std::endl;
    intList.add(10);
    std::cout << "intList.add(20)" << std::endl;
    intList.add(20);
    std::cout << "intList.get(0):    " << intList.get(0) << "[\tExpected: 10]" << std::endl;
    intList.get(0);
    std::cout << "intList.get(1):    " << intList.get(0) << "[\tExpected: 10]" << std::endl;
    intList.get(1);
    intList += 30;
    // std::cout << "intList += 30:    " << intList += 30 << "[\tExpected: 30]" << std::endl;
    intList.get(2);


    int size = intList.size();
    std::cout << "Size: " << size << std::endl;
    std::cout << "\tExpected : [2]" << std::endl;


    //intList.remove(0);

    //std::cout << "Size:" << intList.size() << std::endl;
    //std::cout << "\tExpected: [1]" << std::endl;*/


    std::vector<int> v = intList.toArray();

    for (int i = 0; i < v.size(); i++)
    {
      std::cout << v[i] << std::endl;
    }




}
