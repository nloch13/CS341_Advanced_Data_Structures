// Color Me Dawgs
// Assignment #5
// CS341 Spring 2024
// Due 04/17/2024
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
#include <sstream>
#include "RedBlackTree.h"

int main() 
{
    RedBlackTree myTree;
    std::ifstream inFile("data.txt");
    std::string line;

    if (inFile.is_open()) 
    {
        while (std::getline(inFile, line)) 
        {
            std::istringstream iss(line);
            int number;
            while (iss >> number) 
            {
                myTree.insert(number);
            }
        }
        inFile.close();

       std::cout << "Red Nodes: ";
       myTree.printRedNodes(myTree.getRoot());
       std::cout << std::endl;

        std::cout << "Black Nodes: ";
       myTree.printBlackNodes(myTree.getRoot());
       std::cout << std::endl;

       std::cout << "Root: " << myTree.getRoot()->getData() << std::endl;
    } 
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    return 0; 
}