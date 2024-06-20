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

#include <iostream>
#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};
std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card(){
    suitVal_ = 0; //Set Suit Value 
    faceVal_ = 0; // Set Face Value 
}

Card::Card(int suit, int face)
{
   initialize(suit, face); //Initialization
}

void Card::initialize(int suit, int face) 
{ 
    suitVal_ = suit;
    faceVal_ = face;
}

Card::~Card()
{
    //Destructor
}

std::string Card::getSuit() //Gets suit value 
{
    return SUIT[suitVal_];
}

std::string Card::getFace() //Gets face value 
{
    return FACE[faceVal_];
}

std::string Card::print() 
{
    return getFace() + " of " + getSuit(); //Prints work
}