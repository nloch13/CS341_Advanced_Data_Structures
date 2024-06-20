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

#include "HashTableCuckoo.h"
#include <iostream>

HashTableCuckoo::HashTableCuckoo(int size) : size_(size), rehashingNeeded(false) 
{
    entry1_ = new HashEntry[size_];
    entry2_ = new HashEntry[size_];

    for (int i = 0; i < size_; i++) 
    {
        entry1_[i].setStatus(EMPTY);
        entry2_[i].setStatus(EMPTY);
    }
}

HashTableCuckoo::~HashTableCuckoo() 
{
    delete[] entry1_;
    delete[] entry2_;
}

int HashTableCuckoo::hash1(int key) 
{
    return key % size_;
}

int HashTableCuckoo::hash2(int key) 
{
    return (key / size_) % size_;
}

void HashTableCuckoo::insert(int key, int value) 
{
    int index1 = hash1(key);
    int index2 = hash2(key);
    int loops = 0;
    int maxLoops = size_ * 2;
  

    if ((entry1_[index1].getStatus() == OCCUPIED && entry1_[index1].getKey() == key) || (entry2_[index2].getStatus() == OCCUPIED && entry2_[index2].getKey() == key)) 
    {
        if (entry1_[index1].getKey() == key) 
        {
            entry1_[index1].setValue(value);
        } 
        else 
        {
            entry2_[index2].setValue(value);
        }
        return;
    }

    HashEntry tempEntry(key, value);
   
    while (loops < maxLoops) 
    {
        std::swap(tempEntry, entry1_[index1]);
        if (tempEntry.getStatus() == EMPTY) 
        {
            return;
        }

        index2 = hash2(tempEntry.getKey());

        std::swap(tempEntry, entry2_[index2]);
        if (tempEntry.getStatus() == EMPTY) 
        {
            return;
        }

        index1 = hash1(tempEntry.getKey());

        loops++;
    }

    rehashingNeeded = true;
    std::cout << "<<<--- Insufficient Hash Table Size or Cycle Present! Re-hash! --->>>" << std::endl;
}


int HashTableCuckoo::search(int key) 
{
    int index1 = hash1(key);
    int index2 = hash2(key);

    if (entry1_[index1].getStatus() == OCCUPIED && entry1_[index1].getKey() == key) 
    {
		std::cout << "Key: " << key << " Value: " << entry1_[index1].getValue() << std::endl;
        return entry1_[index1].getValue();
    }
    if (entry2_[index2].getStatus() == OCCUPIED && entry2_[index2].getKey() == key) 
    {
		std::cout << "Key: " << key << " Value: " << entry2_[index2].getValue() << std::endl;
        return entry2_[index2].getValue();
    }
	std::cout << "Invalid key. Key " << key << " not found in table." << std::endl;
    return -1; 
}

void HashTableCuckoo::remove(int key) 
{
    int index1 = hash1(key);
    int index2 = hash2(key);

    if (entry1_[index1].getStatus() == OCCUPIED && entry1_[index1].getKey() == key) 
    {
        entry1_[index1].setStatus(REMOVED);
        std::cout << "Key " << key << " removed." << std::endl;
        return;
    }
    if (entry2_[index2].getStatus() == OCCUPIED && entry2_[index2].getKey() == key) 
    {
        entry2_[index2].setStatus(REMOVED);
        std::cout << "Key " << key << " removed." << std::endl;
        return;
    }
    std::cout << "Invalid key. Key " << key << " not found in table." << std::endl;
}

void HashTableCuckoo::print() 
{
    if (!rehashingNeeded) 
    {
        std::cout << "Table 1:" << std::endl;
        for (int i = 0; i < size_; i++) 
        {
            std::cout << "[" << i << "]: ";
            if (entry1_[i].getStatus() == OCCUPIED) 
            {
                std::cout << entry1_[i].getKey();
            }
            std::cout << std::endl;
        }
        std::cout << "Table 2:" << std::endl;
        for (int i = 0; i < size_; i++) 
        {
            std::cout << "[" << i << "]: ";
            if (entry2_[i].getStatus() == OCCUPIED) 
            {
                std::cout << entry2_[i].getKey();
            }
            std::cout << std::endl;
        }
    }
}