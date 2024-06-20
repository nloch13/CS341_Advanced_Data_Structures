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

#include "LinkedNode.h"

LinkedNode::LinkedNode(HashEntry data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode) : data_(data), nextLinkedNode_(nextLinkedNode), prevLinkedNode_(prevLinkedNode){}

HashEntry LinkedNode::getData()
{
    return data_;
}

void LinkedNode::setData(HashEntry data)
{
    data_ = data;
}

LinkedNode * LinkedNode::getNextLinkedNode()
{
    return nextLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode * nextLinkedNode)
{
    nextLinkedNode_ = nextLinkedNode;
}

LinkedNode * LinkedNode::getPrevLinkedNode()
{
    return prevLinkedNode_;
}

void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
    prevLinkedNode_ = prevLinkedNode;
}