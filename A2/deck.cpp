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

#include "deck.h"
#include <iostream>
#include <bits/stdc++.h>
#include <random> 

Deck::Deck():numCards_(0)
{
    srand(time(NULL));
}

Deck::Deck(int size):numCards_(0)
{
    size_ = size;
    deck_ = new Card[size_]; 
}

Deck::~Deck()  // Destructor 
{
    delete[] deck_; 
}

int Deck::getNumCards() // gets the number of cards in the deck 
{
    return numCards_;
}

void Deck::shuffle() // Shuffles the deck 
{
    int randomNum = 3 + rand() % 10;

    for (int i = 0; i < randomNum; i++)
    {
        std::shuffle(deck_, deck_ + numCards_, std::default_random_engine(0));
    }
}

void Deck::printDeck() //prints decks 
{
    for (int i = 0; i < numCards_; i++)
    {
        std::cout << deck_[i].print() << std::endl;
    }
}

void Deck::displayCard(int i)  //displays card
{
    if (i < 0 || i >= numCards_)
    {
        std::cout << "Display card error"; // Testing 
        return;
    }
    std::cout<< deck_[i].print() <<std::endl;
}

Card Deck::dealCard() 
{
    Card topCard = deck_[numCards_ - 1];
    numCards_--;
    return topCard;   //deals a card and returns the new top card
}

//Card Deck::getDeckSize() // Find size of the deck 
//{
 //   return cards.size();
//}

bool Deck::isEmpty() //sees if the deck is empty 
{
    return numCards_ == 0;
}

Card Deck::getTopCard()
{
    return deck_[numCards_ - 1];
}

bool Deck::addCard(Card c) // adds cards if the total is less then deck size 
{
    if (numCards_ < size_)
    {
        deck_[numCards_] = c;
        numCards_++;
        return true;
    }
    return false;
}
