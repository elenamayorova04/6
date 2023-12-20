#ifndef __STACK_H__
#define __STACK_H__

template <class T>
class TStack
{
private:
  int  size;
  int count;
  T* data;
  
public:
  TStack(int _size = 1);
  TStack(const TStack<T> &p);
  ~TStack();
  
  void push(T a);
  T pull();
  T top();
  
  int getCount();
  int getSize();
  
  bool isFull();
  bool isEmpty();
};

#endif


template <class T>
TStack<T>::TStack(int _size)
{
  if (_size < 0)
    throw "size error";

  size = _size;
  count = 0;
  data = new T[size];

  for (int i = 0; i < size; i++)
    data[i] = 0;
}

template <class T>
TStack<T>::TStack(const TStack<T>& p)
{
  if (p.size < 0)
    throw "size error";

  size = p.size;
  count = p.count;
  data = new T[size];

  for (int i = 0; i < size; i++)
    data[i] = p.data[i];
}

template <class T>
TStack<T>::~TStack()
{
  delete[] data;
  size = 0;
  count = 0;
}

template <class T>
void TStack<T>::push(T a)
{
  if (count > size)
    throw "size error";

  data[count] = a;
  count++;
}

template <class T>
T TStack<T>::pull()
{
  if (count > size)
    throw "size error";

  T a;
  a = data[count];
  data[count] = 0;
  count--;

  return a;
}

template <class T>
T TStack<T>::top()
{
  if (count > size)
    throw "size error";

  T a;
  a = data[count];

  return a;
}

template <class T>
int TStack<T>::getCount()
{
  return count;
}

template <class T>
int TStack<T>::getSize()
{
  return size;
}

template <class T>
bool TStack<T>::isFull()
{
  if (count > size)
    throw "size error";

  int res = 0;
  if (count == size)
    res = 1;
  return res;
}

template <class T>
bool TStack<T>::isEmpty()
{
  if (count > size)
    throw "size error";

  int res = 0;
  if (count == 0)
    res = 1;
  return res;
}