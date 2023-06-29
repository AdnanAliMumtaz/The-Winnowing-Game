#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "CCard.h"
#include "CPlayer.h"
#include "CTable.h"

using namespace std;

class CFeedbackForum : public CCard {
protected:
    int mResilience;
    int mBoost;

public:
    CFeedbackForum(istream& file); // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables
    friend istream& operator>> (istream& file, CFeedbackForum& card); // Overloaded sstream operator for breaking the line read from the file

    // Operations
    virtual void Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Play() function specific to CFeedbackForum class, it plays the card and calls the Attack() function.
    virtual void Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Attack() function specific to CFeedbackForum class.

    // Setters
    virtual void SetResilience(int resilience); // Sets the resilience of the card

    // Getters
    int GetBoost() const; // Gets the boost of the card
    int GetResilience() const; // Gets the resilience of the card

    virtual ~CFeedbackForum(); // Virtual destructor for proper cleanup
};
