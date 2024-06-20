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

#include "HashEntry.h"

HashEntry::HashEntry() : key_(0), value_(0), status_(EMPTY){}

HashEntry::HashEntry(int key, int value) : key_(key), value_(value), status_(OCCUPIED){}

int HashEntry::getKey()
{
    return key_;
}

void HashEntry::setKey(int key)
{
    key_ = key;
}

int HashEntry::getValue()
{
    return value_;
}

void HashEntry::setValue(int value)
{
    value_ = value;
}

Status HashEntry::getStatus()
{
    return status_;
}

void HashEntry::setStatus(Status status)
{
    status_ = status;
}