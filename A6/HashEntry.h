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

#ifndef HASHENTRY_H
#define HASHENTRY_H

enum Status { EMPTY, OCCUPIED, REMOVED};

class HashEntry 
{
    public:
        HashEntry();
        HashEntry(int key, int value);
        int getKey();
        void setKey(int key);
        int getValue();
        void setValue(int value);
        Status getStatus();
        void setStatus(Status status);
    
    private:
        int key_;
        int value_;
        Status status_;
};

#endif