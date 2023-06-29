#pragma once
#include <iostream>
#include <vector>
#include "CCard.h"
#include "CPlayer.h"

using namespace std;

class CCard; // Forward declaration of CCard class
class CPlayer; // Forward declaration of CPlayer class

class CTable {
private:
    using CardVector = vector<shared_ptr<CCard>>; 
    CardVector mTable; // Vector to store shared_ptr to CCard objects representing the table

public:
    CTable(); // Constructor

    // Operations
    void AddCard(shared_ptr<CCard> card); // Add a card to the table
    void RemoveCard(shared_ptr<CCard> card); // Remove a card from the table
    void VectorToStack(CardVector table); // Convert vector to stack (Implement the LIFO structure according to the requriment)
    void ActivateCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent); // Activate cards on the table
    void DisplayTable(); // Display the cards on the table

    // Getters
    CardVector GetTable(); // Get the table of the player
    bool IsEmpty(); // Check if the table is empty
    int Size(); // Get the size of the table
    shared_ptr<CCard> GetCard(int index); // Get a card from the table by index

    ~CTable(); // Virtual destructor for proper cleanup
};
