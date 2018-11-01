#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <list>
#include <vector>

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
LinkedList::LinkedList() {}

template <class T>
LinkedList::LinkedList(const LinkedList<T>& other) {}

template <class T>
LinkedList::~LinkedList() {}

template <class T>
void LinkedList::add(T element)
{
  theList.push_back(element);
}

template <class T>
int LinkedList::size()
{
  return theList.size();
}

template <class T>
T LinkedList::get(int index)
{
  try
  {
    if ( index < 0 || theList.size() < index )
    {
      throw "Out of range";
    }
    list<T>::const_iterator it = theList.begin();

    while (it != theList.begin() + index )
    {
      it++;
    }
    return *it;
  }
  catch(char* str)
  {
    std::cout << "Incorrect index value" << str << std::endl;
  }

}

template <class T>
T LinkedList::remove(int index)
{
  try
  {
    if ( index < 0 || theList.size() < index )
    {
      throw "Out of range";
    }
    list<T>::iterator it = theList.begin();

    while (it != theList.begin() + index )
    {
      it++;
    }
    return theList.erase(it);
  }
  catch(char* str)
  {
    std::cout << "Incorrect index value" << str << std::endl;
  }
}

template <class T>
vector<T> LinkedList::toArray()
{
  vector<T> returnV();
  list<T>::const_iterator it = theList.begin();

  while(it != theList.end())
  {
    returnV.push_back(it);
  }
  return returnV;

}

template <class T>
LinkedList <T>& LinkedList::operator+=(const T& item)
{
  theList.push_back(*item);
  return this.theList;
}

#endif
