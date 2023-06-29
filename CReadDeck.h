#pragma once
#include "CFile.h"
#include "CCard.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "CardFactory.h"

using namespace std;


class CReadDeck : public CFile {
protected:
    using CardVector = vector<shared_ptr<CCard>>;
    CardVector mDeck;

public:
    CReadDeck(string fileName); // Constructor with fileName parameter
    
    // Operations
    virtual void ReadCards(); // Read cards from the file
    virtual void SplitLine(string& line); // Split a line from the file
    
    // Getters
    virtual CardVector GetCards() const; // Get the deck of cards

    virtual ~CReadDeck(); // Virtual destructor for proper cleanup
};