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

#include "HashEntry.h"

#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node(int data);
        ~Node() {}
        void setData(HashEntry entry);
        virtual HashEntry getData();
    private:
        Node() {}
        int data_;
        HashEntry entry_;
};

#endif