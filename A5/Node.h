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

#ifndef NODE_H
#define NODE_H

class Node 
{
    public:
        Node(int data);
        ~Node() {}
        void setData(int data);
        int getData();
    protected:
        Node() {}
    private:
        int data_;
};

#endif