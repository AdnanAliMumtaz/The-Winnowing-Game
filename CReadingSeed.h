#pragma once
#include "CFile.h"
#include <vector>

using namespace std;

class CReadingSeed : public CFile {
private:
    int mSeedNumber; // Seed number read from the file

public:
    CReadingSeed(string fileName); // Constructor with fileName parameter

    // Operation
    virtual void ReadSeed(); // Read seed number from the file
    virtual void SplitNumber(string& line); // Split a line from the file
    
    // Getters
    virtual int GetSeedNumber(); // Get the seed number
    
    virtual ~CReadingSeed(); // Virtual destructor for proper cleanup
};
