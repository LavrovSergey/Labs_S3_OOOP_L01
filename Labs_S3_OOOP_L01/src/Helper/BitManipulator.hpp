#pragma once

class BitManipulator 
{
public:
    //Sets 'numbits' of bits from 'source' at position 'at' to 'destination' and returns it
	static int setbits(int destination, int source, int at, int numbits)
    {
        int ones = ((1 << (numbits)) - 1) << at;
        return (ones | destination) ^ ((~source << at) & ones);
    }
};