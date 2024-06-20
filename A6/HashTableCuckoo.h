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

#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include "HashTable.h"
#include "HashEntry.h"


class HashTableCuckoo : public HashTable 
{
    public:
        HashTableCuckoo(int size);
        virtual ~HashTableCuckoo();

        void insert(int key, int value);
        int search(int key);
        void remove(int key);
        void print();
        bool rehashingNeeded;

private:
        HashEntry * entry1_;
        HashEntry * entry2_;
        int size_;

        int hash1(int key);
        int hash2(int key);
};

#endif