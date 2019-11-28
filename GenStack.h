#include "GenDoublyLinkedList.h"
#include <iostream>

using namespace std;

template <class T>
class GenStack {
public:
  GenStack();
  GenStack(int m);
  ~GenStack();

  void push(T d);
  T pop() throw(runtime_error);
  T peek() throw(runtime_error);

  bool isFull();
  bool isEmpty();
  int getSize();
  int getTop();

private:
  int size;
  int maxSize; // optional
  int top;

  GenDoublyLinkedList<T> myList = GenDoublyLinkedList<T>();
};

template <class T>
GenStack<T>::GenStack() {
  size = 0;
  maxSize = -1;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int m) {
  size = 0;
  maxSize = m;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack() {
}

template <class T>
void GenStack<T>::push(T d) {
  myList.insertFront(d);
  ++size;
  ++top;
  if(size > maxSize && maxSize > 0) { // if exceeded max size, delete from bottom of stack
    myList.removeBack();
  }
}

template <class T>
T GenStack<T>::pop() throw(runtime_error) {
  if(isEmpty()) {
    throw runtime_error("Stack empty");
  } else {
    return myList.removeFront();
    --size;
  }
}

template <class T>
T GenStack<T>::peek() throw(runtime_error){
  if(isEmpty()) {
    throw runtime_error("Stack empty");
  } else {
    T temp = myList.removeFront();
    myList.insertFront(temp);
    return temp;
  }
}

template <class T>
bool GenStack<T>::isFull() {
  return(top == size - 1);
}

template <class T>
bool GenStack<T>::isEmpty() {
  return(top == -1);
}

template <class T>
int GenStack<T>::getSize() {
  return size;
}

template <class T>
int GenStack<T>::getTop() {
  return top;
}
