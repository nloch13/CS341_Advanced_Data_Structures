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

#include <iostream>
#include "Node.h"

Node::Node(int data) : data_(data)
{
    
}

int Node::getData()
{
    return data_;
}

void Node::setData(int data)
{
    data_ = data;
}