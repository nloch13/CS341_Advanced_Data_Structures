// Hop Dawg
// Assignment #4
// CS341 Spring 2024
// Due 03/29/2024
// By: Nathaniel Loch
//
// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// nloch

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedNode.h"

class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();
        bool isEmpty();
        int getLength();
        void insert(int element);
        void printList();
        void removeNode();
        LinkedNode * getTail();
        LinkedNode * getHead();
        void setTail(LinkedNode * tail);
        void setHead(LinkedNode * head);
    protected:
        LinkedNode * head_;
        LinkedNode * tail_;
};

#endif