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

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr)
{

}

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
        LinkedNode * countNode = head_;
        while(countNode != nullptr)
        {
            count++;
            countNode = countNode->getNextLinkedNode();
        }
        return count;
    }
}

LinkedNode * LinkedList::getTail()
{
    return tail_;
}

LinkedNode * LinkedList::getHead()
{
    return head_;
}

void LinkedList::setTail(LinkedNode * tail)
{
    tail_ = tail;
}

void LinkedList::setHead(LinkedNode * head)
{
    head_ = head;
}


void LinkedList::insert(int element)
{
   LinkedNode * newNode = new LinkedNode(element);

   if (isEmpty())
   {
    head_ = newNode;
    tail_ = newNode;
   }
   else
   {
    tail_->setNextLinkedNode(newNode);
    tail_ = newNode;
   }
}

void LinkedList::printList()
{
    LinkedNode * current = head_;

    while(current != nullptr)
    {
        std::cout << current->getData();
        current = current->getNextLinkedNode();
        if(current != nullptr)
        {
            std::cout << " --> ";
           
        }
    }
    std::cout <<std::endl;
}