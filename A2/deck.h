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

#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck
{
    public:
        Deck();
        Deck(int size);
        ~Deck();
        virtual void initializeDeck() = 0;
        int getNumCards();
        void shuffle();
        void printDeck();
        void displayCard(int i);
        bool addCard(Card c);
        Card dealCard(); 
       // Card getDeckSize();
        bool isEmpty();
        Card getTopCard(); 
    protected:
        int numCards_;
        Card * deck_;
		int size_;
};


#endif

