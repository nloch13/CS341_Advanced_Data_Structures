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

#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>  


void DoublyLinkedList::printList() 
{
    LinkedNode* currentNode = head_;
    while (currentNode != nullptr) 
    {
        std::cout << currentNode->getData().getKey();
        currentNode = currentNode->getNextLinkedNode();
        if (currentNode != nullptr) {
            std::cout << "<-->";
        }
    }
    std::cout << std::endl;
}

void DoublyLinkedList::append(HashEntry data) 
{
    LinkedNode* newNode = new LinkedNode(data);

    if (tail_ == nullptr) 
    {
        head_ = tail_ = newNode;
    } 
    else 
    {
        tail_->setNextLinkedNode(newNode);
        newNode->setPrevLinkedNode(tail_);
        tail_ = newNode;
    }
}


void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, HashEntry data) 
{
    if (node == nullptr || node == head_) 
    {
        insertLinkedNode(nullptr, data);
    } 
    else 
    {
        insertLinkedNode(node->getPrevLinkedNode(), data);
    }
}

void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, HashEntry data) 
{
    insertLinkedNode(node, data);
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, HashEntry data) 
{
    LinkedNode* newNode = new LinkedNode(data);
    if (node == nullptr) 
    {
        if (head_ == nullptr) 
        {
            head_ = tail_ = newNode;
        } 
        else 
        {
            newNode->setNextLinkedNode(head_);
            head_->setPrevLinkedNode(newNode);
            head_ = newNode;
        }
    } 
    else 
    {
        newNode->setNextLinkedNode(node->getNextLinkedNode());
        newNode->setPrevLinkedNode(node);
        node->setNextLinkedNode(newNode);

        if (newNode->getNextLinkedNode() != nullptr) 
        {
            newNode->getNextLinkedNode()->setPrevLinkedNode(newNode);
        }
        if (node == tail_) 
        {
            tail_ = newNode;
        }
    }
}

int DoublyLinkedList::find(int key) 
{
    LinkedNode* currentNode = getHead();

    while (currentNode != nullptr)
    {
        if (currentNode->getData().getKey() == key) 
        {
            return currentNode->getData().getValue();
        }
        currentNode = currentNode->getNextLinkedNode();
    }
    return -1;
    delete currentNode;
}

void DoublyLinkedList::removeLinkedNode(int key)
{
    LinkedNode* currentNode = head_;

    while (currentNode != nullptr)
    {
        if (currentNode->getData().getKey() == key) 
        {
            if (currentNode == head_) 
            {
                head_ = currentNode->getNextLinkedNode();
                if (head_) 
                {
                    head_->setPrevLinkedNode(nullptr);
                }
            } 
            else if (currentNode == tail_) 
            {
                tail_ = currentNode->getPrevLinkedNode();
                tail_->setNextLinkedNode(nullptr);
            } 
            else 
            {
                currentNode->getPrevLinkedNode()->setNextLinkedNode(currentNode->getNextLinkedNode());
                currentNode->getNextLinkedNode()->setPrevLinkedNode(currentNode->getPrevLinkedNode());
            }
            delete currentNode;
        }
        currentNode = currentNode->getNextLinkedNode();
    }
}