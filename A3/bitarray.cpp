// P'Bit'ty
// Assignment #3
// CS341 Spring 2024
// Due 03/08/2024
// By: Nathaniel Loch
//
// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// jtwelch & nloch

#include <iostream>
#include <bitset>
#include "bitarray.h"
          
BitArray::BitArray(int size)
{
	LENGTH = size * BIT_IN_BYTE;
	BYTES = size; 
	data_ = new char[BYTES];

	for (int i = 0; i < BYTES; i++)  // initialize bits to 0
	{
		data_[i] =0;
	}

}

BitArray::BitArray(const BitArray & array)
{
	LENGTH = array.LENGTH;
	BYTES = array.BYTES;
	data_ = new char[BYTES];

	for (int i = 0; i < BYTES; i++)  // copy data
	{
		data_[i] = array.data_[i];
	}
}

BitArray::~BitArray() //Destructor 
{
	delete[] data_; // Free memory 
}

void BitArray::initialize(const char * word, int size)
{
	for (int i=0; i < size; i++)
	{
		data_[i] = word[i];
	}
}

bool BitArray::flip(int position)
{
	int byteIndex = position / 8;
	int bitIndex = position % 8;
	data_[byteIndex] ^= (1 << bitIndex);
	return true;
}

bool BitArray::get(int position) const 
{
	int byteIndex = position / 8;
	int bitIndex = position % 8;
	return (data_[byteIndex] >> bitIndex) & 1;
}

bool BitArray::set(int position, int bit)
{
	int byteIndex = position / 8;
	int bitIndex = 7 - (position % 8); //Reverse the bits

	if (bit)
	{
		data_[byteIndex] |= (1 << bitIndex);
	}	else 
		{	
			data_[byteIndex] &= ~(1 << bitIndex);
		}

	return true;
}

char BitArray::get8(int position) const
{
	int byteIndex = position / 8;
	return data_[byteIndex];
}

void BitArray::complement()
{
	for (int i = 0; i < BYTES; i++)
	{
		data_[i] = ~data_[i];
	}
}

void BitArray::clear()
{
	for (int i = 0; i < BYTES; i++)
	{
		data_[i] = 0;
	}
}

void BitArray::print() 
{	
	std::cout << "|";
	
	for (int i=0; i < BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}

void BitArray::set8(char c, int index)
{
	data_[index] = c;
}

int BitArray::getSize() const
{
	return LENGTH;
}
