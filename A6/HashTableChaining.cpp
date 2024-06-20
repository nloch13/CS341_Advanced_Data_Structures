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

#include "HashTableChaining.h"
#include <iostream>

HashTableChaining::HashTableChaining(int size) : size_(size)
{
    entry_ = new DoublyLinkedList[size_];
}

HashTableChaining::~HashTableChaining()
{
    delete[] entry_;
}

void HashTableChaining::insert(int key, int value)
{
    int index = key % size_;
    entry_[index].append(HashEntry(key, value));
}

int HashTableChaining::search(int key)
{
    int index = key % size_;
    int value = entry_[index].find(key);

    if (value != -1)
    {
        std::cout << "Key: " << key << " Value: " << value << std::endl;
        return value;
    }
    else
    {
        std::cout << "Invalid key. Key: " << key << " not found in table." << std::endl;
        return -1;
    }
}


void HashTableChaining::remove(int key)
{
    int index = key % size_;
    DoublyLinkedList & list = entry_[index];

    if (list.find(key) != -1)
    {
        list.removeLinkedNode(key);
        std::cout << "Key: " << key << " removed." << std::endl;
    }
    else
    {
        std::cout << "Invalid key. Key: " << key << " not found in table." << std::endl;
    }

}

void HashTableChaining::print()
{
    for (int i = 0; i < size_; i++)
    {
        std::cout << "[" << i << "]";
        entry_[i].printList();
    }
}