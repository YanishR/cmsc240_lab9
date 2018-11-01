#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <list>
#include <vector>
#include <iostream>

template <class T>
class LinkedList
{
   private:
     std::list<T> theList;

   public:
     LinkedList();
     LinkedList(const LinkedList<T>& other);
     ~LinkedList();

     int  size() const;  // note: a const method
     void add(T element);

     T get(int index) const;  // note: a const method
     T remove(int index);

     std::vector<T> toArray() const;  // note: a const method

     LinkedList<T>& operator+=( const T& item );
};

template <class T>
LinkedList<T>::LinkedList() {}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {}

template <class T>
LinkedList<T>::~LinkedList() {}

template <class T>
void LinkedList<T>::add(T element)
{
  theList.push_back(element);
  return;
}

template <class T>
int LinkedList<T>::size() const
{
  return theList.size();
}

template <class T>
T LinkedList<T>::get(int index) const
{
  /*try
  {
    if ( index < 0 || theList.size() < index )
    {
      throw "Out of range";
    }
    auto it = theList.begin();

    while (it != theList.begin() + index )
    {
      it++;
    }
    return *it;
  }
  catch(char* str)
  {
    std::cout << "Incorrect index value" << str << std::endl;
  }*/
  T t;
  return t;

}

template <class T>
T LinkedList<T>::remove(int index)
{
  /*try
  {
    if ( index < 0 || theList.size() < index )
    {
      throw "Out of range";
    }
    std::list<T>::iterator it = theList.begin();

    while (it != theList.begin() + index )
    {
      it++;
    }
    return theList.erase(it);
  }
  catch(char* str)
  {
    std::cout << "Incorrect index value" << str << std::endl;
  }*/
  T t;
  return t;

}

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

template <class T>
LinkedList <T>& LinkedList<T>::operator+=(const T& item)
{
  theList.push_back(item);
  return &(this->theList);
}

#endif
