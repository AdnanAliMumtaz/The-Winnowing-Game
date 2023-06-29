#pragma once
#include <iostream>
#include <sstream>
#include "CCard.h"

using namespace std;

class CSerialOffender : public CCard
{
protected:
    int mResilience;

public:
    CSerialOffender(istream& file); // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables
    friend istream& operator>>(istream& file, CSerialOffender& card); // Overloaded sstream operator for breaking the line read from the file

    //Operations
    virtual void Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Play() function specific to CSerialOffender class, it plays the card to its table.
    virtual void Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Attack() function specific to CSerialOffender class.

    virtual ~CSerialOffender(); // Virtual destructor for proper cleanup
};