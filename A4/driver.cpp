// Hop Dawg
// Assignment #4
// CS341 Spring 2024
// Due 03/29/2024
// By: Nathaniel Loch
//
// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// nloch

#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main() 
{
    std::string filenames[] = {"data.txt", "sorted.txt"};
    std::string outputFilenames[] = {"output.txt", "sortedOutput.txt"};
    std::ofstream readme("README.txt");

    for (int i = 0; i < 2; i++) 
    {
        DoublyLinkedList DLL;
        std::ifstream inputFile(filenames[i]);
        std::ofstream outputFile(outputFilenames[i]);
        std::ifstream insertFile("inserts.txt");
        int totalHops = 0;
		
        readme << "---- " << (i == 0 ? "Data (output)" : "Sorted (sortedoutput)") << " ----" << std::endl;

        int num;
        while (inputFile >> num) 
        {
            DLL.append(num); 
        }

        while (insertFile >> num) 
        {
            std::cout << "Inserting " << num << "..." << std::endl;
            DLL.optimalInsert(num, totalHops, readme);
        }

        insertFile.close();

        DLL.printList(outputFile);
        outputFile.close();
        std::cout << "Total Number of Big Dawg Hops: " << totalHops << std::endl;
        readme << "Total Number of Big Dawg Hops for " << filenames[i] << ": " << totalHops << std::endl;
    }

    readme.close();

    return 0;
}