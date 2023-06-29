#pragma once
#include <iostream>
#include "CCard.h"

using namespace std;

class CGraduateStudent : public CCard {
protected:
    int mResilience;
    int mBoost;

public:
    CGraduateStudent(istream& file);  // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables
    friend istream& operator>>(istream& file, CGraduateStudent& card); // Overloaded sstream operator for breaking the line read from the file

    //Operations
    virtual void Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Play() function specific to CGraduateStudent class, it plays the card to its table.
    virtual void Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent);// Implemented the Attack() function specific to CGraduateStudent class.

    //Returns
    void BoostPrestige(shared_ptr<CPlayer> player); // Boosts the prestige of a player

    virtual ~CGraduateStudent(); // Virtual destructor for proper cleanup
};