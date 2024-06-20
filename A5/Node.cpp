// Color Me Dawgs
// Assignment #5
// CS341 Spring 2024
// Due 04/17/2024
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