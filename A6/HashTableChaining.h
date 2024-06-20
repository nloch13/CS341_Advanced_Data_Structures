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

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include "HashTable.h"
#include "DoublyLinkedList.h"


class HashTableChaining : public HashTable 
{
    public:
        HashTableChaining(int size);
        virtual ~HashTableChaining();
        void insert(int key, int value);
        int search(int key);
        void remove(int key);
        void print();

    private:
        DoublyLinkedList * entry_;
        int size_;

};

#endif