#pragma once
#include <iostream>
#include <istream>
#include "CCard.h"
#include "CPlayer.h"
#include "CTable.h"

using namespace std;

class CCourseAccreditation : public CCard {
public:
    CCourseAccreditation(istream& file); // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables

    // Operations
    virtual void Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy); // Implemented the Play() function specific to CCourseAccreditation class, and calls Attack() to activate to attack. 
    virtual void Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy); // Implemented the Attack() function specific to CCourseAccreditation class
    
    virtual ~CCourseAccreditation(); // Virtual destructor for proper cleanup
};
