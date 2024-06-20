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

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"
#include "HashEntry.h"


class LinkedNode
{
    public:
        LinkedNode(HashEntry data, LinkedNode * nextLinkedNode = nullptr, LinkedNode * prevLinkedNode = nullptr);

        HashEntry getData();
        void setData(HashEntry data);


        LinkedNode * getNextLinkedNode();
        void setNextLinkedNode(LinkedNode * nextLinkedNode);

        LinkedNode * getPrevLinkedNode();
        void setPrevLinkedNode(LinkedNode * prevLinkedNode);

    private:
        HashEntry data_;
        LinkedNode * nextLinkedNode_;
        LinkedNode * prevLinkedNode_;
};

#endif