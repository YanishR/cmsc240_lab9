//**********************************************************************
//* Authors:  Yanish Rambocus Sophie Borchart
//* Date:     1 November 2018
//* Purpose:  This program is a tester file for the LinkedList class.
//*
//**********************************************************************

#include "LinkedList.h"

#include <string>
#include <iostream>
#include <vector>


int main ()
{
    std::cout << "These tests will help the development of the LinkedList class: " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    std::cout << "Implementing LinkedList with ints" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "LinkedList<int> intList" << std::endl;
    LinkedList<int> intList;
    std::cout << "-------------------------------------------" << std::endl;

    // Test by adding a couple of int, gettting at exisiting indices,
    std::cout << "Testing add(), get(), size() and remove() methods: " << std::endl;
    std::cout << "intList.add(10)" << std::endl;
    intList.add(10);

        std::cout << "intList.add(10), intList.add(0);" << std::endl;
    std::cout << "intList.add(20)" << std::endl;
    intList.add(20);

    std::cout << "intList.get(0): " << intList.get(0) << "\t[Expected: 10]" << std::endl;
    std::cout << "intList.get(1): " << intList.get(1) << "\t[Expected: 20]" << std::endl;

    // test for incorrect values
    std::cout << "intList.get(100): ";
    try
    {
       std::cout << intList.get(100) << std::endl;
    }
    catch (std::out_of_range &e)
    {
       std::cerr << e.what() << std::endl;
    }
    std::cout <<"\t[Expected: \"Out of range\"]" << std::endl;

    std::cout << "intList.get(-10): ";
    try
    {
       std::cout << intList.get(-10) << std::endl;
    }
    catch (std::out_of_range &e)
    {
       std::cerr << e.what() << std::endl;
    }
    std::cout <<"\t[Expected: \"Out of range\"]" << std::endl;

    std::cout << "intList.size(): " << intList.size() << "\t[Expected: 2]" << std::endl;

    std::cout << "intList.remove(0)" << std::endl;
    intList.remove(0);
    std::cout << "intList.get(0): " << intList.get(0) << "\t[Expected: 20]" << std::endl;
    std::cout << "intList.size(): " << intList.size() << "\t[Expected: 1]" << std::endl;

    std::cout << "intList.get(1): ";
    try
    {
       std::cout << intList.get(1) << std::endl;
    }
    catch (std::out_of_range &e)
    {
       std::cerr << e.what() << std::endl;
    }
    std::cout <<"\t[Expected: \"Out of range\"]" << std::endl;


    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Testing +=: " << std::endl;

    std::cout << "intList += 30" << std:: endl;
    intList += 30;
    std::cout << "intList.get(1): " << intList.get(1) << "\t[Expected: 30]" << std::endl;
    std::cout << "intList.size(): " << intList.size() << "\t[Expected: 2]" << std::endl;

    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "intList.add(10), intList.add(0);" << std::endl;

    std::cout << "Testing toArray(): " << std::endl;

    std::cout << "intList.add(10), intList.add(0);" << std::endl;

    intList.add(10), intList.add(0);

    std::vector<int> v = intList.toArray();

    for (int i = 0; i < v.size() - 1; i++)
    {
      std::cout << v[i] << ", ";
    }
    std::cout << v[v.size() - 1] << std::endl;

    std::cout << "\t[Expected: 20, 30, 10, 0]"<< std::endl;

    std::cout << "Testing Copy Constructor: " << std::endl;
    std::cout << "LinkedList<int> intList2(intList)" << std::endl;
    LinkedList<int> intList2(intList);
    std::cout << "intList2.add(44)" << std::endl;
    intList.add(44);
    std::vector<int> v1 = intList.toArray();

    for (int i = 0; i < v1.size(); i++)
    {
      std::cout << v1[i] << std::endl;
    }
    std::cout << "\t[Expected: 20, 44]"<< std::endl;



    std::cout << "************************************************************" << std::endl;



    std::cout << "Implementing LinkedList with strings" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "LinkedList<std::string> stringList" << std::endl;
    LinkedList<std::string> stringList;
    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Testing add() and get(): " << std::endl;
    std::cout << "stringList.add(\"Hello\")" << std::endl;
    stringList.add("Hello");
    std::cout << "stringList.add(\"Goodbye\")" << std::endl;
    stringList.add("Goodbye");
    std::cout << "stringList.get(0):    " << stringList.get(0) << "\t[Expected: \"Hello\"]" << std::endl;
    stringList.get(0);
    std::cout << "stringList.get(1):    " << stringList.get(1) << "\t[Expected: \"Goodbye\"]" << std::endl;
    stringList.get(1);

    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Testing +=: " << std::endl;

    std::cout << "intList += Dog:    " << std:: endl;
    stringList += "Dog";
    std::cout << "stringList.get(2):    " << stringList.get(2) << "\t[Expected: \"Dog\"]" << std::endl;

    std::cout << "Testing toArray(): " << std::endl;
    std::cout << "To Array: " << std::endl;
    std::vector<std::string> v3 = stringList.toArray();

    for (int i = 0; i < v3.size(); i++)
    {
      std::cout << v3[i] << std::endl;
    }
    std::cout << "\t[Expected: \"Hello, Goodbye, Dog\"]"<< std::endl;



    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Testing size(): " << std::endl;

    std::cout << "Size: " << stringList.size() << "\t[Expected: 3]"<< std::endl;

    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Testing remove(): " << std::endl;

    stringList.remove(0);
    std::cout << "stringList.remove(0)" << std::endl;
    std::cout << "stringList.remove(1)" << std::endl;
    stringList.remove(1);
    std::cout << "UdpatedList : " << stringList.get(0) << "\t[Expected: \"Goodbye\"]" << std::endl;
    std::cout << "Updated Size: " << stringList.size() << "\t[Expected: 1]"<< std::endl;

    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Testing toArray(): " << std::endl;
    std::cout << "To Array: " << std::endl;
    std::vector<std::string> v4 = stringList.toArray();

    for (int i = 0; i < v4.size(); i++)
    {
      std::cout << v4[i] << std::endl;
    }
    std::cout << "\t[Expected: \"Goodbye\"]"<< std::endl;


    std::cout << "Testing Copy Constructor: " << std::endl;
    std::cout << "LinkedList<std::string> stringList2(stringList)" << std::endl;
    LinkedList<std::string> stringList2(stringList);
    std::cout << "stringList2.add(\"Computer Science!\")" << std::endl;
    stringList.add("Computer Science!");
    std::vector<std::string> v2 = stringList.toArray();

    for (int i = 0; i < v2.size(); i++)
    {
      std::cout << v2[i] << std::endl;
    }
    std::cout << "\t[Expected: Goodbye, Computer Science!]"<< std::endl;

}
