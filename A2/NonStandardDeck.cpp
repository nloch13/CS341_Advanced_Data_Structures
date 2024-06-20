// Master-Card
// Assignment #2
// CS341 Spring 2024
// Due 02/23/2024
// By: Nathaniel Loch
//
// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// nloch

#include "NonStandardDeck.h"
#include "StandardDeck.h"
#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <random> 


NonStandardDeck::NonStandardDeck(int size) : numCards_(DECK_SIZE)
{
    numCards_ = 0;
    initializeDeck();
}

NonStandardDeck::~NonStandardDeck()  // Destructor 
{
    delete[] deck_; 
}

void NonStandardDeck::displayCard(int i)  //displays card
{
    if (i < 0 || i >= numCards_)
    {
        std::cout << "Display card error"; // Testing 
        return;
    }
    std::cout<< deck_[i].print() <<std::endl;
}

bool NonStandardDeck::mergeDecks(NonStandardDeck & deck, bool shuffler)  //merge decks and shuffle them
{
    if(numCards_ < size_)
    {

        int mergeNum(0);

        mergeNum = size_ - numCards_;

        if(mergeNum > deck.getNumCards())
        {
            mergeNum = deck.getNumCards();
        }

        for(int i=0; i < mergeNum; i++)
        {
            deck_[i+numCards_] = deck.deck_[i];
        }

        numCards_ += mergeNum; 

        deck.numCards_ = 0;

        if(shuffler)
        {
            shuffle();
        }
    }

    return true;
}


void NonStandardDeck::initializeDeck() // void function for initializeDeck
{
    std::ifstream inputFile("deck.txt");
    int size(0);

    if (inputFile.is_open())
    {
        inputFile >> size;

        deck_ = new Card[size];
        numCards_ = size;

        int suit(0), face(0);

        for(int i=0; i < size; i++)
        {
            inputFile >> suit >> face;
           Card newCard(suit,face);
           deck_[i] = newCard;
        }
    } 
}

