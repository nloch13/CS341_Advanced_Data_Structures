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

#include "LinkedNode.h"

LinkedNode::~LinkedNode()
{
    if(nextLinkedNode_ != nullptr)
    {
        delete nextLinkedNode_;
    }
}

LinkedNode::LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode) : Node(data), nextLinkedNode_(nextLinkedNode), prevLinkedNode_(prevLinkedNode)
{

}

LinkedNode * LinkedNode::getNextLinkedNode()
{
    return nextLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode * nextLinkedNode)
{
    nextLinkedNode_ = nextLinkedNode;
}

bool LinkedNode::hasNextLinkedNode()
{
    if(nextLinkedNode_ != nullptr)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

LinkedNode * LinkedNode::getPrevLinkedNode()
{
    return prevLinkedNode_;
}

void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
    prevLinkedNode_ = prevLinkedNode;
}

bool LinkedNode::hasPrevLinkedNode()
{
    if(prevLinkedNode_ != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}