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


#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H
#include "card.h"
#include "deck.h"
#include <deque>
#include <bits/stdc++.h>
#define DECK_SIZE 52

/** @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck : public Deck 
{
	public:
		StandardDeck(); /// Default constructor.
		~StandardDeck(); 	/// Default destructor.
		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		//bool isEmpty();	
		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		//int getNumCards();
		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		//void displayCard(int i);
		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		//void printDeck();	
        bool addCard(Card c);
        //void shuffle();
        bool mergeDecks(StandardDeck &, bool shuffle = false);
        //Card dealCard();
        virtual void initializeDeck();
		//Card getTopCard();
	protected:
        int numCards_;
        Card * deck_;
};

#endif



