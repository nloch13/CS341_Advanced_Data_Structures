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

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkedList.h"
#include <fstream>

class DoublyLinkedList : public LinkedList 
{
    public:
        DoublyLinkedList() {}
        virtual ~DoublyLinkedList() {}
        virtual void printList();
        void insertLinkedNode(LinkedNode * node, int data);
        void insertAfterLinkedNode(LinkedNode * node, int data);
        void insertBeforeLinkedNode(LinkedNode * node, int data);
        int getLength();
        virtual void printList(std::ofstream & outputFile);  
        void optimalInsert(int data, int & totalHops, std::ofstream & readme);
        void append(int data);  
    private:
        int size_ = 0;
};

#endif

