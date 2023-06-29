#include "CStudent.h"

CStudent::CStudent(istream& file) : CCard(file)
{
    file >> mResilience; // Reads the addtional resilience value to initialise the variable member
}

istream& operator>>(istream& file, CStudent& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience;
    card.mName += (" " + card.mSecondName);
    return file;
}

void CStudent::Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Obtains a reference to the opponent's table using the GetTable() function
    unique_ptr<CTable>& opponentTable = opponent->GetTable();

    if (opponentTable->IsEmpty()) // Checks if the opponent's table is empty.
    {
        // Attack the opponent's prestige directly
        int damage = opponent->GetPrestige() - this->GetPower();
        opponent->SetPrestige(damage);

        // Display the attacking message
        cout << this->GetName() << " attacks " << opponent->GetName() << ". " << opponent->GetName() << "'s prestige is now " << opponent->GetPrestige() << endl;
    }
    else // If the opponenet has cards in its table
    {
        int random = player->Random(opponentTable->Size()); // Generates a random number for the card to choose from the opponent's table
        shared_ptr <CCard> opponentCard = opponentTable->GetCard(random);

        // Attacking the enemy student card
        int damage = opponentCard->GetResilience() - this->GetPower();
        opponentCard->SetResilience(damage);

        // Displays the message for the attacking opponent card
        if (damage <= 0)
        {
            cout << this->GetName() << " attacks " << opponentCard->GetName() << ". " << opponentCard->GetName() << " is defeated." << endl;
            opponentTable->RemoveCard(opponentCard); // Removes the defeated card
        }
        else
        {
            cout << this->GetName() << " attacks " << opponentCard->GetName() << ". " << opponentCard->GetName() << "'s resilience is now " << damage << endl;
        }
    }
}

void CStudent::SetResilience(int resilience)
{
    mResilience = resilience;
}

void CStudent::Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> enemy)
{
    // Plays the card from the hand 
    cout << player->GetName() << " plays " << this->GetName() << endl;

    // Plays the card to the table
    unique_ptr<CTable>& table = player->GetTable();
    table->AddCard(shared_from_this());

    // Deletes the card from the table
    player->DeleteCardFromHand(shared_from_this());
}

int CStudent::GetResilience() const
{
    return mResilience;
}

string CStudent::GetName()
{
    return mName;
}

CStudent::~CStudent()
{

}
