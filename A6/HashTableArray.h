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

#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include "HashTable.h"
#include "HashEntry.h"

enum ProbingMethod { LINEAR, QUADRATIC };

class HashTableArray : public HashTable
{
    public:
        HashTableArray(int size, ProbingMethod method);
        virtual ~HashTableArray();
        void insert(int key, int value);
        int search(int key);
        void remove(int key);
        void print();
        int probe(int key, int i);
    
    private:
        HashEntry * entry_;
        int size_;
        ProbingMethod probingMethod;
};

#endif
