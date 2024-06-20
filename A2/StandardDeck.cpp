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

#include "StandardDeck.h"
#include <iostream>
#include <bits/stdc++.h>
#include <random> 


StandardDeck::StandardDeck() : numCards_(DECK_SIZE)
{
    numCards_ = 0;
    deck_ = new Card[DECK_SIZE];  // Initialize deck 
    srand(time(NULL));
}

StandardDeck::~StandardDeck()  // Destructor 
{
    delete[] deck_; 
}


bool StandardDeck::addCard(Card c) // adds cards if the total is less then deck size 
{
    if (numCards_ < DECK_SIZE)
    {
        deck_[numCards_] = c;
        numCards_++;
        return true;
    }
    return false;
}

bool StandardDeck::mergeDecks(StandardDeck & deck, bool shuffler)  //merge decks and shuffle them
{
    if(numCards_ < DECK_SIZE)
    {

        int mergeNum(0);

        mergeNum = DECK_SIZE - numCards_;

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

void StandardDeck::initializeDeck() // void function for initializeDeck
{
    // Phase II, previously StandardDeck::StandardDeck() : numCards_(DECK_SIZE)
   

    for(int suit = 1; suit <= 4; suit++) 
    {
        for(int face = 1; face <=13; face++)
        {
           Card newCard(suit,face);
           addCard(newCard);
        }
    } 
}