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
#include "StandardDeck.h"
#include "NonStandardDeck.h"
#include <numeric>

void WarSim(int iterations, bool isStandard, bool testing)
{
    int i(0), p1Total(0), p2Total(0), player1W(0), player2W(0);
	double player1Avg(0), player2Avg(0);
	
	while(i < iterations)
	{
		if(!isStandard) // Phase V
		{
			NonStandardDeck deck(deck.getNumCards());
			
			deck.initializeDeck();
			
			NonStandardDeck Army1(deck.getNumCards());
			NonStandardDeck Army2(deck.getNumCards());
			NonStandardDeck battleground(deck.getNumCards());
			
			if(testing)
			{
				std::cout << "\tDeck: " << deck.getNumCards() << std::endl;
			}
			
			deck.shuffle();
			
			if(i%2 == 0)
			{
				deck.shuffle();

				if(testing)
				{
					std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
					std::cout << "\tPlayer 1 War: " << battleground.getTopCard().getSuit() << ", " << Army1.getTopCard().getSuit() << ", " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
					std::cout << "\tPlayer 2 War: " << battleground.getTopCard().getSuit() << ", " << Army2.getTopCard().getSuit() << ", " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
					std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
				} 
			}
			
			while(!deck.isEmpty())
			{
				Card temp = deck.dealCard();
				Army1.addCard(temp);

				temp = deck.dealCard();
				Army2.addCard(temp);
			}
			
			while(!Army1.isEmpty() && !Army2.isEmpty())
			{
				if(!battleground.isEmpty() && battleground.getTopCard().getSuit() == Army1.getTopCard().getSuit())
				{
					if(testing)
					{
						std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
						std::cout << "\tWar: " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
						std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
					}
					Army1.mergeDecks(battleground, false);
					if(testing)
					{
						std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
						std::cout << "\tWar: " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
						std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
					}
					battleground.addCard(Army1.dealCard());
				}
				else
				{
					battleground.addCard(Army1.dealCard());
				}
				
				if(!battleground.isEmpty() && battleground.getTopCard().getSuit() == Army2.getTopCard().getSuit())
				{
					if(testing)
					{
						std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
						std::cout << "\tWar: " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
						std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
					}
					Army2.mergeDecks(battleground, false);
					if(testing)
					{
						std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
						std::cout << "\tWar: " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
						std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
					}
					battleground.addCard(Army2.dealCard());
				}
				else
				{
					battleground.addCard(Army2.dealCard());
				}
			}
			
			if(Army2.isEmpty())
			{
				p1Total++;
				player1W += Army1.getNumCards();
				
				//if(testing)
				//{
				//	std::cout << "Player 1 has won the war with a score of: " << Army1.getNumCards() << std::endl;
				//	std::cout << "Player 2: " << Army2.getNumCards() << std::endl;
				//	std::cout << "Battleground: " << battleground.getNumCards() << std::endl;
				//}
			} 
			else
			{
				p2Total++;
				player2W += Army2.getNumCards();
				
				//if(testing)
				//{
				//	std::cout << "Player 2 has won the war with a score of: " << Army2.getNumCards() << std::endl;
				//	std::cout << "Player 1: " << Army1.getNumCards() << std::endl;
				//	std::cout << "Battleground: " << battleground.getNumCards() << std::endl;
				//}
			}
	
			i++;
		}
		else 
		{		
			StandardDeck deck;  //  Phase IV
			StandardDeck Army1;
			StandardDeck Army2;
			StandardDeck battleground;
			
			deck.initializeDeck();
			if(testing)
			{
				std::cout << "\tDeck: " << deck.getNumCards() << std::endl;
			}
			
			deck.shuffle();
			
			if(i%2 == 0)
			{
				deck.shuffle();

				if(testing)
				{
					std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
					std::cout << "\tPlayer 1 War: " << battleground.getTopCard().getSuit() << ", " << Army1.getTopCard().getSuit() << ", " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
					std::cout << "\tPlayer 2 War: " << battleground.getTopCard().getSuit() << ", " << Army2.getTopCard().getSuit() << ", " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
					std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
				} 
			}
			
			while(!deck.isEmpty())
			{
				Card temp = deck.dealCard();
				Army1.addCard(temp);

				temp = deck.dealCard();
				Army2.addCard(temp);
			}
			
			while(!Army1.isEmpty() && !Army2.isEmpty())
			{
				if(!battleground.isEmpty() && battleground.getTopCard().getSuit() == Army1.getTopCard().getSuit())
				{
					if(testing)
					{
						std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
						std::cout << "\tWar: " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
						std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
					}
					Army1.mergeDecks(battleground, false);
					if(testing)
					{
						std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
						std::cout << "\tWar: " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
						std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
					}
					battleground.addCard(Army1.dealCard());
				}
				else
				{
					battleground.addCard(Army1.dealCard());
				}
				
				if(!battleground.isEmpty() && battleground.getTopCard().getSuit() == Army2.getTopCard().getSuit())
				{
					if(testing)
					{
						std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
						std::cout << "\tWar: " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
						std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
					}
					Army2.mergeDecks(battleground, false);
					if(testing)
					{
						std::cout << "Deck Total: " << deck.getNumCards() << std::endl;
						std::cout << "\tWar: " << battleground.getNumCards() << ", " << Army1.getNumCards() << ", " << Army2.getNumCards() << std::endl;
						std::cout << "Total cards: " << battleground.getNumCards() + Army1.getNumCards() + Army2.getNumCards() << std::endl;
					}
					battleground.addCard(Army2.dealCard());
				}
				else
				{
					battleground.addCard(Army2.dealCard());
				}
			}
			
			if(Army2.isEmpty())
			{
				p1Total++;
				player1W += Army1.getNumCards();
				
				//if(testing)
				//{
				//	std::cout << "Player 1 has won the war with a score of: " << Army1.getNumCards() << std::endl;
				//	std::cout << "Player 2: " << Army2.getNumCards() << std::endl;
				//	std::cout << "Battleground: " << battleground.getNumCards() << std::endl;
				//}
			}
			else
			{
				p2Total++;
				player2W += Army2.getNumCards();
				
				//if(testing)
				//{
				//	std::cout << "Player 2 has won the war with a score of: " << Army2.getNumCards() << std::endl;
				//	std::cout << "Player 1: " << Army1.getNumCards() << std::endl;
				//	std::cout << "Battleground: " << battleground.getNumCards() << std::endl;
				//}
			}
	
			i++;
		}

		if(p1Total > p2Total)
		{
			std::cout << "Player 1 was the champion with " << p1Total << " victories versus Player 2." << std::endl << std::endl;
		}
		else if (p2Total > p1Total)
		{
			std::cout << "Player 2 was the champion with " << p2Total << " victories versus Player 1." << std::endl << std::endl;
		}
		else
		{
			std::cout << "There was no winner! Both players tied!" << std::endl << std::endl;
		}
	
		player1Avg = player1W / iterations;
		player2Avg = player2W / iterations;
	
		std::cout << "Player 1 Average Score: " << player1Avg << std::endl; 
		std::cout << "Player 2 Average Score: " << player2Avg << std::endl; 
	}
}


int main()
{
    // Phase IV / V
    int iterations = 5;
    bool testing = false; 
	bool isStandard = true;

    WarSim(iterations, testing, isStandard);

    // Phase III

   /* StandardDeck deck;
    
    deck.initializeDeck(); //initializes and prints original deck 
    std::cout << "Unshuffled Deck: " << std::endl;
    deck.printDeck();
    
    deck.shuffle(); //shuffles and prints deck
    std::cout << "Shuffled Deck: " << std::endl;
    deck.printDeck();

    StandardDeck secondDeck;
    secondDeck.initializeDeck();
    if (deck.mergeDecks(secondDeck, true))
    {
        std::cout << "Merged and shuffled decks: " << std::endl;
        deck.printDeck();
    } else 
    {
        std::cout << "Failed to merge" << std::endl;
    }
    */

    // Phase II
    
   //deck.printDeck();  // Print deck

   //StandardDeck deck;

   // std::cout << "Is the deck empty? " << deck.isEmpty() <<std::endl; // Check if the deck is empty 

   // std::cout << "# of Cards: " << deck.getNumCards() << std::endl; //Get the number of cards

   // std::cout << "The 15th card is: "; 
   // deck.displayCard(14); //Display the 15th card (array starts at 0)
    
    
    //Phase I

    /*Card Deck[52]; 
    int suit = 1;
    int face = 1;

    //Initialize the deck for a loop of 52 to fill the deck 
    for(int i =0; i < 52; ++i)
    {
        Deck[i].initialize(suit, face);
        face++;

        if (face > 13) //Only 13 cards per suit 
        {
            face =1;
            suit++;
        }
    }

    for (int i =0; i < 52; ++i)
    {
        std::cout << Deck[i].print() << std::endl;
    }
    */

    return 0;
}
