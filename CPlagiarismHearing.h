#pragma once
#include <iostream>
#include <vector>
#include "CCard.h"
#include "CPlayer.h"
#include "CTable.h"

using namespace std;

class CPlagiaristHearing : public CCard {
public:
    CPlagiaristHearing(istream& file); // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables

    // Operations
    virtual void Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Play() function specific to CPlagiarismHearing class, and it calls Attack() function.
    virtual void Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Implemented the Attack() function specific to CPlagiarismHearing class.

    virtual ~CPlagiaristHearing(); // Virtual destructor for proper cleanup
};
