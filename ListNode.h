#ifndef ListNode_h
#define ListNode_h

#include <stdio.h>

template<typename T>
class ListNode{

public:
    ListNode *next;
    ListNode *prev;
    T data;
    ListNode();
    ListNode(T d);
    ~ListNode();
};


template<typename T>
ListNode<T>::ListNode(){

}

template<typename T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
    prev = NULL;
}

template<typename T>
ListNode<T>::~ListNode(){
    next = NULL; 
    prev = NULL;
}


#endif
