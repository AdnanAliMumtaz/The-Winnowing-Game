#pragma once
#include <iostream>
#include <vector>
#include <memory> 
#include "CCard.h"
#include "CTable.h"

using namespace std;

class CCard; // Forward declaration of CCard class
class CTable; // Forward declaration of CTable class

class CPlayer : public enable_shared_from_this<CPlayer> {
protected:
    using CardVector = vector<shared_ptr<CCard>>; // Type alias for a vector of shared pointers to CCard objects

    string mName;
    int mPrestige;
    CardVector mDeck; // Player's deck of cards
    CardVector mHand; // Player's hand of cards
    unique_ptr <CTable> Table; // Pointer to the CTable 

public:
    CPlayer(string name, int prestige, CardVector deck); // Constructor with name, prestige, and deck parameters
    
    // Operations
    void DrawCard(); // Draws a card from the deck to the hand
    void PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Plays a randomly choosen card from the hand
    void DeleteCardFromHand(shared_ptr<CCard> card); // Delete a card from the hand
    int Random(int max); // Generates a random number
    
    // Setters
    void SetPrestige(int prestige); // Sets player's prestige

    // Getters
    string GetName(); // Get player's name
    int GetPrestige(); // Get player's prestige
    CardVector GetDeck(); // Get player's deck of cards
    CardVector GetHand(); // Get player's hand of cards
    unique_ptr<CTable>& GetTable(); // Get pointer to the game table
    shared_ptr<CPlayer> GetSacked(); // Get shared_ptr to a sacked player
};
