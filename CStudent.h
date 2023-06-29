#pragma once
#include <iostream>
#include <vector>
#include "CCard.h"

using namespace std;

class CStudent : public CCard {
protected:
    int mResilience;

public:
    CStudent(istream& file); // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables
    friend istream& operator>> (istream& file, CStudent& card); //  function to overload input stream operator for CStudent

    // Operations
    void Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy); // Implemented the Play() function specific to CStudent class, it plays the card to its table.
    void Attack(shared_ptr<CPlayer> Player, shared_ptr<CPlayer> Enemy); // Implemented the Attack() function specific to CStudent class.

    // Setters
    void SetResilience(int resilience); // Sets the resilience of the card
    
    // Getters
    int GetResilience() const; // Gets the resilience of the card
    string GetName(); // Gets the name of the card

    virtual ~CStudent(); // Virtual destructor for proper cleanup
};
