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

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"


class LinkedNode : public Node
{
    public:
        ~LinkedNode();
        LinkedNode(int data, LinkedNode * nextLinkedNode = nullptr, LinkedNode * prevLinkedNode = nullptr);
        LinkedNode * getNextLinkedNode();
        void setNextLinkedNode(LinkedNode * nextLinkedNode);
        bool hasNextLinkedNode();
        LinkedNode * getPrevLinkedNode();
        void setPrevLinkedNode(LinkedNode * prevLinkedNode);
        bool hasPrevLinkedNode();
    private:
        LinkedNode * nextLinkedNode_;
        LinkedNode * prevLinkedNode_;
};

#endif