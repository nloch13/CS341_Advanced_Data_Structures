// P'Bit'ty
// Assignment #3
// CS341 Spring 2024
// Due 03/08/2024
// By: Nathaniel Loch
//
// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// jtwelch & nloch

#include "set.h"
#include <iostream>

Set::Set(int size) : data_(size)
{
    // Initialize the BitArray w 0s 
}

Set::~Set()
{
    
}

void Set::initialize(char * word, int size) //Initialize BitArray 
{
    data_.initialize(word, size);
}

int Set::getCardinality() const //Gets cardinality of the set
{
    int count = 0;
    int size = data_.getSize();
    for (int i =0; i < size; i++)
    {
        if(data_.get(i))
        {
            count++;
        }
    }
    return count;
}

BitArray & Set::getData() //Get bitarray data
{
    return data_;
}

bool Set::setUnion(Set & B) //Finds the union intersection of the 'Set' and 'Set B'
{
   if(data_.length() == B.data_.length())
   {
    //Tutor helped
    unsigned char a = ' ';
    unsigned char b = ' ';

    for(int i = 0; i < data_.bytes(); i++)
    {
        a = data_.get8(i*BIT_IN_BYTE);
        b = B.data_.get8(i*BIT_IN_BYTE);
        a = a | b;
        data_.set8(a,i);
    }
    return true;
   }
   return false;
}

bool Set::setIntersection(Set & B)
{
 if(data_.length() == B.data_.length())
   {
    //Tutor helped
    unsigned char a = ' ';
    unsigned char b = ' ';

    for(int i = 0; i < data_.bytes(); i++)
    {
        a = data_.get8(i*BIT_IN_BYTE);
        b = B.data_.get8(i*BIT_IN_BYTE);
        a = a & b;
        data_.set8(a,i);
    }
    return true;
   }
   return false;
}