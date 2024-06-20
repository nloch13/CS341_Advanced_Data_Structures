// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// jtwelch & nloch

#include "dictionary.h"

//got help with tutor & Dr. R
Dictionary::Dictionary() 
{
    lookupTable_ = new int[256];
    for (int i = 0; i < 256; i++)
    {
        int count =0;
        for (int j = 0; j < 8; j++)
        {
            if((i >> j) & 1) 
            {
                count++;
            }
        }
        lookupTable_[i] = count;
    }
}

Dictionary::Dictionary(const Dictionary & dict) : data_()
{
    //creates data even if the lookupTable_ doesn't exist

    //if the lookupTable_ exists for the dict object
    //deep copy
    if(dict.lookupTable_)
    {
        lookupTable_ = (new int[DICTIONARY_SIZE]);
        for(int i = 0; i < DICTIONARY_SIZE; i++)
        {
            lookupTable_[i] = dict.lookupTable_[i];
        }
        data_ = dict.data_;
    }
}

Dictionary::~Dictionary()
{
    // delete data_; ?
    delete[] lookupTable_;
}

void Dictionary::initialize(char * word, int size)
{
    //initializes the data_ bitArray with word and size
    data_.initialize(word, size);
}

int Dictionary::rank_range(int start, int end, int bit)
{
    //returns the number of 1's in data_ from 'start' until 'end' is reached
    int count = 0;
    for(int i = start; i < end; i++)
    {
        //if the bit at i is 1
        if(data_.get(i) == bit)
        {
            count++;
        }
    }
    return count;   
}

int Dictionary::select_range(int start, int end, int k, int bit)
{
    //the number of counted bits in the selected range
    int count = 0;

    //the starting position of the selected range
    int position = start;

    //while the counted number of bits is less than k
    //and the current position is less than the selected end of range
    while(count < k && position < end)
    {
        //if the data at the current position is equal to bit
        if(data_.get(position) == bit)
        {
            count++;
        }
        position++;
    }

    //returns the position of the k'th bit within the selected range
    return position;
}

int Dictionary::rank(int end, int bit)
{
    //reads though the word byte wise and looks up the individual byte values in the lookup table
    int count = 0;
    for(int i = 0; i < data_.bytes(); i++)
    {
        //if the data at the current position is equal to bit
        if(data_.get(i))
        {
            //count is the count + lookup of current byte cardinality within char array
            count = count + lookupTable_[data_.get8(i*BIT_IN_BYTE)];
            //                     ^      ^ gets the character in the selected byte
            //                     L  returns a selected byte within data_ to look up in the table
        }
    }
    return count;    
}

int Dictionary::select(int k, int bit)
{
    //the count of bit found within the range so far
    int count = 0;

    //current position within the array
    int position  = 0;

    //gets the end of the data for loop
    int size = data_.getSize();

    //while the counted number of bits is less than k
    //and the current position is less than the end of data_
    while(count < k && position < size)
    {
        //if the data at the current position is equal to bit
        if(data_.get(position) == bit)
        {
            count++;
        }
        position++;
    }

    //returns the position of the k'th bit within the selected range
    return position;
}

//got help from tutor
void Dictionary::printLookupTable(std::ostream & output)
{
    for(int i = 0; i < DICTIONARY_SIZE; i++)
    {
        //use ostream to output to file
        output << i << ": " << lookupTable_[i] << std::endl;
    } 
}