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

#include "Node.h"

Node::Node(int data) : data_(data){}

HashEntry Node::getData()
{
    return entry_;
}

void Node::setData(HashEntry entry)
{
    entry_ = entry;
}