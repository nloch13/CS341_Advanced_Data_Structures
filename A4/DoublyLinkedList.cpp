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

#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>  
#include <sstream>

int DoublyLinkedList::getLength()
{
    return size_;
}

void DoublyLinkedList::printList() 
{
    LinkedNode * currentNode = head_;

    while (currentNode != nullptr) 
    {
        std::cout << currentNode->getData();
        currentNode = currentNode->getNextLinkedNode();
        if (currentNode != nullptr) 
        {
            std::cout << "<-->";
        }
    }
    std::cout << std::endl;
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, int data) 
{
    node = LinkedList::getTail();

    LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);

    if(!isEmpty())
    {
        if (node == LinkedList::getTail())
        {
            node->setNextLinkedNode(newNode);
            newNode->setPrevLinkedNode(node);
            LinkedList::setTail(newNode);

            delete newNode;
        }
        else if (node == LinkedList::getHead())
        {
            newNode->setPrevLinkedNode(node);
            node->setNextLinkedNode(newNode);
            LinkedList::setHead(node);

            delete newNode;
        }
        else
        {
            node->getNextLinkedNode()->setPrevLinkedNode(newNode);
            newNode->setNextLinkedNode(node->getNextLinkedNode());
            node->setNextLinkedNode(newNode);
            newNode->setPrevLinkedNode(node);

            delete newNode;
        }
    }
    else
    {
        LinkedList::setHead(newNode);
        LinkedList::setTail(newNode);

        delete newNode;
    }
    size_++;

    delete newNode;
}

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data) 
{
    LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);

    if (getLength() == 0)
    {
        node->setData(data);
        LinkedList::setHead(node);
        LinkedList::setTail(node);

        delete newNode;

    }
    if (node == LinkedList::getHead())
    {
        node->setPrevLinkedNode(newNode);
        newNode->setNextLinkedNode(node);
        LinkedList::setHead(newNode);
        newNode->setPrevLinkedNode(nullptr);

        delete newNode;
    }
    else
    {
        newNode->setPrevLinkedNode(node->getPrevLinkedNode());
        node->getPrevLinkedNode()->setNextLinkedNode(newNode);
        newNode->setNextLinkedNode(node);
        node->setPrevLinkedNode(newNode);

        delete newNode;
    }
    size_++;

    delete newNode;

}

void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, int data) 
{
    LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);

    if (getLength() == 0)
    {
        node->setData(data);
        LinkedList::setHead(node);
        LinkedList::setTail(node);

        delete newNode;
    }
    else
    {
        if(node == LinkedList::getTail())
        {
            node->setNextLinkedNode(newNode);
            newNode->setPrevLinkedNode(node);
            LinkedList::setTail(newNode);
            newNode->setNextLinkedNode(nullptr);

            delete newNode;
        }
        else
        {
            node->getNextLinkedNode()->setPrevLinkedNode(newNode);
            newNode->setNextLinkedNode(node->getNextLinkedNode());
            node->setNextLinkedNode(newNode);
            newNode->setPrevLinkedNode(node);

            delete newNode;
        }
    }
    size_++;

    delete newNode;
}


void DoublyLinkedList::printList(std::ofstream & outputFile) 
{
    LinkedNode * currentNode = head_;
    while (currentNode != nullptr) 
    {
        outputFile << currentNode->getData();
        currentNode = currentNode->getNextLinkedNode();
        if (currentNode != nullptr) 
        {
            outputFile << "<-->";
        }
    }
    outputFile << std::endl;
}

void DoublyLinkedList::append(int data) 
{
    LinkedNode * newNode = new LinkedNode(data);
    if (tail_ == nullptr) 
    { 
        head_ = tail_ = newNode;
    } else 
    {
        tail_->setNextLinkedNode(newNode);
        newNode->setPrevLinkedNode(tail_);
        tail_ = newNode;
    }

        delete newNode;
}

void DoublyLinkedList::optimalInsert(int data, int & totalHops, std::ofstream & readme) 
{
    int hHops = 0, tHops = 0;
    LinkedNode * hCurrent = head_;
    LinkedNode * tCurrent = tail_;

    while (hCurrent && hCurrent->getData() <= data) 
    {
        hCurrent = hCurrent->getNextLinkedNode();
        hHops++;
    }

    while (tCurrent && tCurrent->getData() >= data) 
    {
        tCurrent = tCurrent->getPrevLinkedNode();
        tHops++;
    }

    int bestOption = (hHops < tHops) ? hHops : tHops;

    totalHops += bestOption;

    readme << "Inserting " << data << "... ";
    readme << "Needs " << bestOption << " hops." << std::endl;

    if (hHops < tHops) 
    {
        insertBeforeLinkedNode(hCurrent, data);
    } 
    else 
    {
        insertAfterLinkedNode(tCurrent, data);
    }
}