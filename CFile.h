#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "CCard.h"

using namespace std;

class CFile {
protected:
    string mFileName;
    using CardVector = vector<shared_ptr<CCard>>; // Type alias for a vector of shared pointers to CCard objects

public:
    CFile(string fileName); // Constructor that takes a file name as a parameter

    // Operations
    virtual void ReadCards(); // Reads cards from the file and stores them in the CardVector
    virtual void ReadSeed(); // Reads seed number from the file
    virtual void SplitLine(string& line); // Splits a line read from the file
    virtual void SplitNumber(string& line); // Splits a number from a line read from the file

    // Returns
    virtual CardVector GetCards() const; // Gets the vector of shared pointers to CCard objects
    virtual int GetSeedNumber(); // Gets the seed number

    virtual ~CFile(); // Virtual destructor for proper cleanup
};
