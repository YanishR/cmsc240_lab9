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
#include <exception>
#include <iterator>

template <class T>
class LinkedList
{
   private:
     std::list<T> theList;  // instance variable for a list

   public:
     LinkedList(); // default constructor
     LinkedList(const LinkedList<T>& other); // copy constructor
     ~LinkedList(); // destructor

     int  size() const; // gets the size of the LinkedList
     void add(T element); // adds an element T to the LinkedList

     T get(int index) const; // gets an element from the index of the LinkedList
     T remove(int index); // removes an element T from the index of the LinkedList

     std::vector<T> toArray() const; // puts the contents of the LinkedList into a vector

     LinkedList<T>& operator+=( const T& item ); // adds an item to the LinkedList
};

// default constructor for LinkedList
template <class T>
LinkedList<T>::LinkedList() {}

// constructor where LinkedList takes another LinkedList as input
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
  for (int i = 0; i < other.size(); i ++)
    this->add(other.get(i));
}

// destructor for LinkedList
template <class T>
LinkedList<T>::~LinkedList() {}

// adds an element T into the LinkedList
template <class T>
void LinkedList<T>::add(T element)
{
  theList.push_back(element);
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
  if (!(0 <= index && index < theList.size()))
  {
    std::string msg = "Invalid argument. Index "
    "provided has to be between 0 and size of the list";
    throw std::out_of_range(msg);
  }
  typename std::list<T>::const_iterator it = theList.begin();
  int count = 0;
  while (count < index)
  {
    count++;
    it++;
  }
  return *it;
}

// removes an element T from the index of the LinkedList
template <class T>
T LinkedList<T>::remove(int index)
{
    if (!(0 <= index && index < theList.size()))
    {
      std::string msg = "Invalid parameter";
      throw std::out_of_range(msg);
    }
    T returnValue = this->get(index);
    typename std::list<T>::const_iterator it = theList.begin();
    int count = 0;

    while (count < index)
    {
      count++;
      it++;
    }
    theList.erase(it);
    return returnValue;

}

// puts the contents of the LinkedList into a vector
template <class T>
std::vector<T> LinkedList<T>::toArray() const
{
  std::vector<T> returnV;
  typename std::list<T>::const_iterator it = theList.begin();

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
