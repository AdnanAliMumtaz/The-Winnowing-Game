#pragma once
#include <iostream>
#include "CCard.h"

using namespace std;

class CPassLeader : public CCard {
protected:
    int mResilience;
    int mPowerIncrement;

public:
    CPassLeader(istream& file); // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables
    friend istream& operator>>(istream& file, CPassLeader& passLeader); // Friend function for extracting card data from an input stream

    // Operations
    virtual void Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Play() function specific to CPassLeader class, it plays the card to its table.
    virtual void Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Attack() function specific to CPassLeader class.

    // Setters
    virtual void SetResilience(int resilience); // Sets the resilience of the card
    virtual void SetPower(int power); // Sets the power of the card
    void SetPowerIncrement(unique_ptr<CTable>& table); // Sets the mPowerIncrement of the card
    void SetPowerIncrement(int power); // Sets 

    // Getters
    virtual string GetName(); // Gets the name of the card
    virtual int GetPower(); // Gets the power of the card
    virtual int GetResilience() const; // Gets the resilience of the card
    int GetPowerIncrement(); // Gets the powerIncrement of the card

    virtual ~CPassLeader(); // Virtual destructor for proper cleanup
};
