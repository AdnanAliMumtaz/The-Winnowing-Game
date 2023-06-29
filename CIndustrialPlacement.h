#pragma once
#include <iostream>
#include "CCard.h"

using namespace std;

class CIndustrialistPlacement : public CCard {
protected:
    int mResilience;
    int mBoost;
    void BoostResilience(int boost); // Boosts resilience of itself

public:
    CIndustrialistPlacement(istream& file); // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables
    friend istream& operator>>(istream& file, CIndustrialistPlacement& card); // Overloaded sstream operator for breaking the line read from the file

    // Operations
    virtual void Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Play() function specific to CIndustrialPlacement class, it plays the card to its table.
    virtual void Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Attack() function specific to CIndustrialPlacement class.
    
    // Setters
    virtual void SetResilience(int resilience); // Sets the resilience of the card
    
    // Getters
    int GetResilience() const; // Gets the resilience of the card

    virtual ~CIndustrialistPlacement(); // Virtual destructor for proper cleanup
};
