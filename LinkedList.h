//**********************************************************************
//* Authors:  Yanish Rambocus Sophie Borchart
//* Date:     1 November 2018
//* Purpose:  This program implements the LinkedList class through a 
//*           template. 
//**********************************************************************

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <list>
#include <vector>
#include <iostream>

template <class T>
class LinkedList
{
   private:
     std::list<T> theList;                          // instance variable for a list

   public:
     LinkedList();                                  // default constructor for LinkedList
     LinkedList(const LinkedList<T>& other);        // constructor where LinkedList takes another LinkedList as input
     ~LinkedList();                                 // destructor

     int  size() const;                             // gets the size of the LinkedList
     void add(T element);                           // adds an element T to the LinkedList     

     T get(int index) const;                        // gets an element from the index of the LinkedList
     T remove(int index);                           // removes an element T from the index of the LinkedList

     std::vector<T> toArray() const;                // puts the contents of the LinkedList into a vector

     LinkedList<T>& operator+=( const T& item );    // adds an item to the LinkedList
};

template <class T>                                        // default constructor for LinkedList
LinkedList<T>::LinkedList() {}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {}  // constructor where LinkedList takes another LinkedList as input

template <class T>                                        // destructor for LinkedList
LinkedList<T>::~LinkedList() {}

// adds an element T into the LinkedList
template <class T>
void LinkedList<T>::add(T element)
{
  theList.push_back(element);
  return;
}

// returns the size of the LinkedList
template <class T>
int LinkedList<T>::size() const
{
  return theList.size();
}

// gets an element T from the index of the LinkedList
template <class T>
T LinkedList<T>::get(int index) const
{
  try
  {
    if ( index < 0 || theList.size() < index )
    {
      throw "Out of range";
    }
    auto it = theList.begin();
    int count = 0;
    while (count < index)
    {
      count++;
      it++;
    }
    return *it;
  }
  catch(char* str)
  {
    std::cout << "Incorrect index value" << str << std::endl;
  }
  T t;
  return t;

}

// removes an element T from the index of the LinkedList
template <class T>
T LinkedList<T>::remove(int index)
{
  try
  {
    if ( index < 0 || theList.size() < index )
    {
      throw "Out of range";
    }
    T returnValue = this->get(index);
    auto it = theList.begin();
    int count = 0;

    while (count < index)
    {
      count++;
      it++;
    }
    theList.erase(it);
    return returnValue;
  }
  catch(char* str)
  {
    std::cout << "Incorrect index value" << str << std::endl;
  }
  T t;
  return t;

}

// puts the contents of the LinkedList into a vector
template <class T>
std::vector<T> LinkedList<T>::toArray() const
{
  std::vector<T> returnV;
  auto it = theList.begin();

  while(it != theList.end())
  {
    returnV.push_back(*it);
    it++;
  }
  return returnV;

}

// adds an item T to the LinkedList
template <class T>
LinkedList <T>& LinkedList<T>::operator+=(const T& item)
{
  theList.push_back(item);
  return *this;
}

#endif
