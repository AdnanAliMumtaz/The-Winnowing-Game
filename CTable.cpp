#include "CTable.h"

CTable::CTable()
{

}

void CTable::AddCard(shared_ptr<CCard> card)
{
    // Resets the table everytime to avoid inconsistencies
    VectorToStack(mTable);

    // Push backs the new card to the table
    mTable.push_back(card);

    // Converts the table to a stack as a final operation
    VectorToStack(mTable); 
}

void CTable::RemoveCard(shared_ptr<CCard> card)
{
    auto it = find(mTable.begin(), mTable.end(), card); // Finds the card in table
    if (it != mTable.end())
    {
        mTable.erase(it); // Remove it from table
    }
}

void CTable::VectorToStack(CardVector table)
{
    mTable.clear(); // Resets the table

    // Iterates over the elements of the table in the reverse order to implement LIFO structure
    for (auto it = table.rbegin(); it != table.rend(); ++it)
    {
        mTable.push_back(*it);
    }
}

void CTable::ActivateCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    //Activating all of the cards in the players table
    for (int i = 0; i < mTable.size(); ++i)
    {
        if (opponent->GetPrestige() > 0) // As long as the opponent's prestige is greate than 0, the cards keep activating to attack the opponent cards / opponent
        {
            mTable[i]->Attack(player, opponent); // Call the Attack(), uses polymorphism to understand which attack to activate depending upon the object types.
        }
    }
}

void CTable::DisplayTable()
{
    // Display all the cards on the table
    cout << "Cards on Table: ";
    for (auto card : mTable)
    {
        cout << card->GetName() << " (" << card->GetResilience() << "), ";
    }
    cout << endl;
}

CTable::CardVector CTable::GetTable()
{
    return mTable;
}

bool CTable::IsEmpty()
{
    bool isEmpty;
    if (mTable.size() == 0) // If the size of the table is 0, then it sets the isEmpty to true.
    {
        isEmpty = true;
    }
    else
    {
        isEmpty = false;
    }
    return isEmpty; // returns the bool value based on the code above.
}

int CTable::Size()
{
    return mTable.size();
}

shared_ptr <CCard> CTable::GetCard(int index)
{
    if (index < mTable.size()) // Check if the index can exists in the table size
    {
        return mTable[index]; // returns the card that is stored at the value of this specifc index
    }
    else {
        return nullptr;
    }
}

CTable::~CTable()
{
}
