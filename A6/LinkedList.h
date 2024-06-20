// The Last Can Of Who Hash
// Assignment #6
// CS341 Spring 2024
// Due 04/29/2024
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
        void insert(HashEntry element);
        void printList();

        LinkedNode * getHead();
        void setHead(LinkedNode * node);
        LinkedNode * getTail();
        void setTail(LinkedNode * node);

    protected:
        LinkedNode * head_;
        LinkedNode * tail_;
        int size_;
};

#endif