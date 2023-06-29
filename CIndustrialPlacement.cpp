#include "CIndustrialPlacement.h"

void CIndustrialistPlacement::BoostResilience(int boost)
{
    this->mResilience += boost;
    cout << this->mName << " boosts its resilience " << ". " << this->mName << "'s resilience is now " << this->mResilience << endl;
}

CIndustrialistPlacement::CIndustrialistPlacement(istream& file) : CCard(file)
{
    file >> mResilience >> mBoost; // Reads additional resilience and boost values to initialise the variable members.
}

istream& operator>>(istream& file, CIndustrialistPlacement& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience >> card.mBoost;
    card.mName += (" " + card.mSecondName);
    return file;
}

void CIndustrialistPlacement::SetResilience(int resilience)
{
    mResilience = resilience;
}

void CIndustrialistPlacement::Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Plays the card from the hand 
    cout << player->GetName() << " plays " << this->GetName() << endl;

    // Plays the card to the table
    unique_ptr<CTable>& table = player->GetTable();
    table->AddCard(shared_from_this());

    // Deletes the card from the hand after playing
    player->DeleteCardFromHand(shared_from_this());
}

void CIndustrialistPlacement::Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    unique_ptr<CTable>& opponentTable = opponent->GetTable();

    if (opponentTable->IsEmpty()) // Checks if the opponent's table is empty.
    {
        // Card attacks opponent's prestige directly
        int damage = opponent->GetPrestige() - this->GetPower();
        opponent->SetPrestige(damage);

        // Displaying the opponent's updated prestige
        cout << this->GetName() << " attacks " << opponent->GetName() << ". " << opponent->GetName() << "'s prestige is now " << opponent->GetPrestige() << endl;
    }
    else // If the opponent does have cards on the table
    {
        int random = player->Random(opponentTable->Size()); // Generates a random function to choose to attack the opponent's cards
        shared_ptr <CCard> OpponentCard = opponentTable->GetCard(random); // Gets a random card from the opponent's table

        // Attacks the opponent's card by deducting its resilience
        int damage = OpponentCard->GetResilience() - this->GetPower();
        OpponentCard->SetResilience(damage);

        // Displaying the output 
        if (damage <= 0)
        {
            cout << this->GetName() << " attacks " << OpponentCard->GetName() << ". " << OpponentCard->GetName() << " is defeated." << endl;
            opponentTable->RemoveCard(OpponentCard); //Removes the card defeated card.
        }
        else
        {
            cout << this->GetName() << " attacks " << OpponentCard->GetName() << ". " << OpponentCard->GetName() << "'s resilience is now " << damage << endl;
        }
    }

    // Always boosting the its own resilience when calling Attack()
    BoostResilience(mBoost);
}

int CIndustrialistPlacement::GetResilience() const
{
    return mResilience;
}


CIndustrialistPlacement::~CIndustrialistPlacement()
{

}