#ifndef GenStack_h
#define GenStack_h

#include <stdio.h>
#include <iostream>
#include "ListNode.h"
using namespace std;


template <typename T>
class GenStack{
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;
public:
    GenStack();
    ~GenStack();
    bool isEmpty();
    int getSize();
    T pop();
    void push(T data);
    T peek();

};

#endif

template <typename T>
GenStack<T>::GenStack(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
GenStack<T>::~GenStack(){

    ListNode<T> *node = head;
    ListNode<T> *nodeToDelete = head;
    while (node != NULL){
        nodeToDelete = node->next;
        delete node;
        node = nodeToDelete;
    }
}

template <typename T>
bool GenStack<T>::isEmpty(){
    return size == 0;
}


template <typename T>
int GenStack<T>::getSize(){
    return size;
}

template <typename T>
T GenStack<T>::pop(){
    try{
    if(isEmpty()){
        throw "Stack is empty.";
    }

    T ret = tail->data;

    if(head == tail){
        head = NULL;
        tail = NULL;
        delete tail;
    }
    else{
      ListNode<T>* temp = tail;
      tail = tail->prev;
      tail->next = NULL;
      temp->prev = NULL;
      delete temp;
    }
    size--;
    return ret;
    }
  catch(char const* error) {
  cout << "Exception " << error << endl;
  }
}


template <typename T>
void GenStack<T>::push(T data){
    size++;
    ListNode<T>* node = new ListNode<T>();
    node->data = data;
    //list entirely empty
    if(head == nullptr && tail == nullptr){
        head = node;
        tail = node;
        return;
    }

    node->prev = tail;
    tail->next = node;
    tail = node;
    ++size;
}

template <typename T>
T GenStack<T>::peek(){
  try{
    if(isEmpty()) {
      throw "Stack is empty. ";
    }
   return tail->data;
  }
   catch(char const* error) {
     cout << "Exception " << error << endl;
   }
}
