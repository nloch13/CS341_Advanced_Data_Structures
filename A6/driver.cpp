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

#include <iostream>
#include <fstream>
#include <string>
#include "HashTableArray.h"
#include "HashTableChaining.h"
#include "HashTableCuckoo.h"

void fromFile(HashTable * hashTable, const std::string & filename)
{
    std::ifstream file(filename);
    int key, value ;

    while (file >> key >> value)
    {
        hashTable->insert(key, value);
    }
}

void userInput(HashTable * hashTable)
{
    int choice;
    hashTable->print();

    do
    {
        std::cout << "1) Search For Entry\n";
        std::cout << "2) Remove Entry\n";
        std::cout << "3) Print Hash Table\n";
        std::cout << "4) Return to Main Menu\n";
        std::cout << "Please enter your choice: ";
        std::cin >> choice;

        int key, value;
        switch (choice)
        {
            case 1:
                std::cout << "Search (Please enter a Key): ";
                std::cin >> key;
                value = hashTable->search(key);
                break;
            case 2:
                std::cout << "Remove (Please enter a Key): ";
                std::cin >> key;
                hashTable->remove(key);
                break;   
            case 3:
                hashTable->print();
                break;
        }
    } while (choice != 4);
}

int main()
{
    int choice, size;
    std::string filename = "data.txt";

    do
    {
        std::cout << "Welcome tp Blue IV's Can of Who Hash!\n";
        std::cout << "1) Linear Probing\n";
        std::cout << "2) Quadratic Probing\n";
        std::cout << "3) Separate Chaining\n";
        std::cout << "4) Cuckoo Hashing\n";
        std::cout << "5) Quit Program\n";
        std::cout << "Please enter your choice: ";
        std::cin >> choice; 

        if (choice >= 1 && choice <= 4)
        {
            std::cout << "Please enter the sie of the Hash Table you wish to create: ";
            std::cin >> size;

            HashTable * hashTable = nullptr;

            switch (choice)
            {
                case 1:
                    hashTable = new HashTableArray(size, LINEAR);
                    break;
                case 2:
                    hashTable = new HashTableArray(size, QUADRATIC);
                    break;
                case 3:
                    hashTable = new HashTableChaining(size);
                    break;
                case 4:
                    hashTable = new HashTableCuckoo(size);
                    break;
            }

            fromFile(hashTable, filename);

            bool skipUserInput = false;

            if (choice == 4)
            {
                HashTableCuckoo * cuckooTable = dynamic_cast<HashTableCuckoo*>(hashTable);
                if (cuckooTable && cuckooTable->rehashingNeeded)
                {
                    skipUserInput = true;
                }
            }

            if (!skipUserInput)
            {
                userInput(hashTable);
            }

            delete hashTable;
        }
    } while (choice != 5);

    std::cout << "Thank you for using Blue IV's program - Goodbye!\n";
    return 0;
}