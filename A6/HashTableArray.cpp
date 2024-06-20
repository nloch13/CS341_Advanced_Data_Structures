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

#include "HashTableArray.h"
#include <iostream>

HashTableArray::HashTableArray(int size, ProbingMethod method) : size_(size), probingMethod(method)
{
    entry_ = new HashEntry[size_];

    for (int i = 0; i < size_; i++)
    {
        entry_[i].setStatus(EMPTY);
    }
}

HashTableArray::~HashTableArray()
{
    delete[] entry_;
}

void HashTableArray::insert(int key, int value)
{
    for (int i = 0; i < size_; i++)
    {
        int index = probe(key, i);
        if (entry_[index].getStatus() != OCCUPIED)
        {
            entry_[index] = HashEntry(key, value);
            return;
        }
    }
}

int HashTableArray::search(int key)
{
    for (int i = 0; i < size_; i++)
    {
        int index = probe(key, i);
        if (entry_[index].getStatus() == EMPTY)
        {
            std::cout << "Invalid Key. Key: " << key << " not found in the table." << std::endl;
            return -1;
        }
        if (entry_[index].getKey() == key)
        {
            std::cout << "Key: " << key << "Value: " << entry_[index].getValue() <<std::endl;
            return entry_[index].getValue();
        }
    }
    return -1;
}

void HashTableArray::remove(int key)
{
    for (int i = 0; i < size_; i++)
    {
        int index = probe(key, i);
        if (entry_[index].getStatus() == EMPTY)
        {
            std::cout << "Invalid Key. Key: " << key << " not found in the table." << std::endl;
            return;
        }
        if (entry_[index].getKey() == key && entry_[index].getStatus() == OCCUPIED)
        {
            entry_[index].setStatus(REMOVED);
            std::cout << "Key: " << key << "removed." << std::endl;
            return;
        }
    }
}

void HashTableArray::print()
{
    for (int i = 0; i < size_; i++)
    {
        std::cout << "[" << i << "]: ";
        if (entry_[i].getStatus() == OCCUPIED)
        {
            std::cout << entry_[i].getKey();
        }
        std::cout <<std::endl;
    }
}

int HashTableArray::probe(int key, int i)
{
    if (probingMethod == LINEAR)
    {
        return (key + i) % size_;
    }
    else //Quadratic 
    {
        return (key + i * i) % size_;
    }
}