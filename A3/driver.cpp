// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// jtwelch & nloch

#include "bitarray.h"
#include <iostream>
#include "dictionary.h"
#include "set.h"
#include <fstream>

int main()
{
    Dictionary dict;
    char word1[] = {'j', 'o', 'h', 'n'};
    dict.initialize(word1,4);

    std::cout << "Rank: " << dict.rank(31) << std::endl;
    std::cout << "Select(5,1): " << dict.select(5) << std::endl;
    std::cout << "Printing Lookup Table..." << std::endl;

    std::ofstream output;
    output.open("lookupTable.txt");
    dict.printLookupTable(output);
    output.close();

    return 0;
}