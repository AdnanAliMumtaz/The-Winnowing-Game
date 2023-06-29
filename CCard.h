#pragma once
#include  <iostream>
#include "CPlayer.h"
using namespace std;

class CPlayer;

class CCard : public enable_shared_from_this<CCard> {
protected:
    string mName;
    string mSecondName;
    int mPower;

public:
    CCard(istream& file); // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables
    friend istream& operator>> (istream& file, CCard& card); // Overloaded sstream operator for breaking the line read from the file

    // Operations
    virtual void Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented by derived classes differently to play the card
    virtual void Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent);  // Implemented by derived classes differently to attack the card

    // Setters
    virtual void SetResilience(int resilience); // Sets the resilience of the card
    virtual void SetPower(int power); // Sets the power of the card

    // Returns
    virtual string GetName(); // Gets the name of the card
    virtual int GetPower(); // Gets the power of the card
    virtual int GetResilience() const;// Gets the resilience of the card

    virtual ~CCard();   // Virtual destructor for proper cleanup
};
