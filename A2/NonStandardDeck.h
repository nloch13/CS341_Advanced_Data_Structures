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

#ifndef NON_STANDARD_DECK_H
#define NON_STANDARD_DECK_H
#include "deck.h"
#include "card.h"
#include <string>
#include <deque>
#include <bits/stdc++.h>

class NonStandardDeck : public Deck 
{
    public:
        NonStandardDeck(int size);
        ~NonStandardDeck();
        void displayCard(int i);
        bool mergeDecks(NonStandardDeck&, bool shuffle = false);
        virtual void initializeDeck();
        void txtDeck(const std::string& fileName);
    protected:
        int numCards_;
        Card * deck_;
};

#endif