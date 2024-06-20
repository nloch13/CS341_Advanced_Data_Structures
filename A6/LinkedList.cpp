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

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr){}

LinkedList::~LinkedList()
{
    if(head_ != nullptr)
    {
        delete head_;
    }
}

bool LinkedList::isEmpty()
{
    if(head_ == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int LinkedList::getLength()
{
    int count = 0;

    if(isEmpty())
    {
        return count;
    }
    else 
    {
        LinkedNode * countNode = getHead();
        while(countNode != nullptr)
        {
            count++;
            countNode = countNode->getNextLinkedNode();
        }
        return count;
    }
}


void LinkedList::insert(HashEntry element)
{
    LinkedNode * insert = new LinkedNode(element, head_, tail_);
    insert->setNextLinkedNode(nullptr);

    if(head_ == nullptr)
    {
        size_++;
        head_ = insert;
        tail_ = insert;
    }
    else
    {
        size_++;
        tail_->setNextLinkedNode(insert);
        tail_ = insert;
    }
}

void LinkedList::printList()
{
    LinkedNode * current = getHead();

    while(current != nullptr)
    {
        HashEntry entry = current->getData();
        std::cout << entry.getKey() << ":" << entry.getValue();
        current = current->getNextLinkedNode();
        if(current != nullptr)
        {
            std::cout << " --> ";
           
        }
    }
    std::cout <<std::endl;
}

LinkedNode * LinkedList::getHead()
{
    return head_;
}    
    
void LinkedList::setHead(LinkedNode * node)
{
    head_ = node;
}

LinkedNode * LinkedList::getTail()
{
    return tail_;
}

void LinkedList::setTail(LinkedNode * node)
{
    tail_ = node;
}