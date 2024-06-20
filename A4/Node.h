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

#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node 
{
    public:
        Node(int data);
        ~Node() {}
        void setData(int data);
        int getData();
    private:
        Node() {}
        int data_;
};

#endif