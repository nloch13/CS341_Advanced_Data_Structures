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

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkedList.h"
#include "HashEntry.h"
#include <fstream>

class DoublyLinkedList : public LinkedList 
{
    public:
        virtual void printList();
        void insertLinkedNode(LinkedNode * node, HashEntry data);
        void insertAfterLinkedNode(LinkedNode * node, HashEntry data);
        void insertBeforeLinkedNode(LinkedNode * node, HashEntry data); 
        void optimalInsert(HashEntry data, int & totalHops, std::ofstream & readme);
        void append(HashEntry data);  

        int find(int key);
        void removeLinkedNode(int key);
};

#endif