#include "CPassLeader.h"

CPassLeader::CPassLeader(istream& file) : CCard(file)
{
    file >> mResilience >> mPowerIncrement;  // Reads additional resilience and powerIncrement values from input file stream to initialise the data members
}

istream& operator>>(istream& file, CPassLeader& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience >> card.mPowerIncrement;
    card.mName += (" " + card.mSecondName);
    return file;
}


void CPassLeader::Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    //// Plays the card to the table
    unique_ptr<CTable>& table = player->GetTable();
    table->AddCard(shared_from_this());

    // Plays the card from the hand 
    cout << player->GetName() << " plays " << this->GetName() << endl;
    SetPowerIncrement(table);
    //cout << "There is now " << this->GetCardCount() << " Pass Leader card on the table, with power " << this->GetPower() << endl;

    // Deletes the card from the table
    player->DeleteCardFromHand(shared_from_this());

}

void CPassLeader::Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Get opponent's table using a reference to a unique_ptr
    unique_ptr<CTable>& opponentTable = opponent->GetTable();

    if (opponentTable->IsEmpty()) // If the enemy student card doesn't exist
    {
        // Attacking the card opponent directly
        int damage = this->GetPower();
        opponent->SetPrestige(opponent->GetPrestige() - damage);

        // Displays the card attack the opponent direcly message
        cout << this->GetName() << " attacks " << opponent->GetName() << ". " << opponent->GetName() << "'s prestige is now " << opponent->GetPrestige() << endl;
    }
    else // If the opponent student card exists on the table
    {
        // Get player's table using a reference
        unique_ptr<CTable>& table = player->GetTable();
        
        // Checks for the pass leaders in the table and increments power based on the number of the pass leaders.
        SetPowerIncrement(table);

        // Attacks the opponent student on the table
        int randomIndex = player->Random(opponentTable->Size());
        shared_ptr <CCard> opponentCard = opponentTable->GetCard(randomIndex);

        // Attacks the randomly chosen opponent card
        int damage = opponentCard->GetResilience() - this->GetPower();
        opponentCard->SetResilience(damage);

        // Display attacking message
        if (damage <= 0)
        {
            cout << this->GetName() << " attacks " << opponentCard->GetName() << ". " << opponentCard->GetName() << " is defeated." << endl;
            opponentTable->RemoveCard(opponentCard); // Removes the defeated card from the opponent table
        }
        else
        {
            cout << this->GetName() << " attacks " << opponentCard->GetName() << ". " << opponentCard->GetName() << "'s resilience is now " << damage << endl;
        }
    }
}

void CPassLeader::SetResilience(int resilience)
{
    mResilience = resilience;
}

void CPassLeader::SetPowerIncrement(unique_ptr<CTable>& table)
{
    this->mPowerIncrement = 0; 

    // Goes through the card to find pass leaders to increase mPowerIncrement
    for (int i = 0; i < table->Size(); i++)
    {
        if (table->GetCard(i)->GetName() == this->GetName()) // Checks for the mataching students
        {
            this->mPowerIncrement++;
        } 
    }
    
    int power = this->mPowerIncrement; // Update power to mPowerIncrement

    // Goes through table to set all the mataching cards to the same power
    for (int i = 0; i < table->Size(); i++)
    {
        if (table->GetCard(i)->GetName() == this->GetName())
        {
            table->GetCard(i)->SetPower(power);
        }
    }

    // Display the Power Increment output
    cout << "There is now " << this->mPowerIncrement << " Pass Leader card on the table, with power " << this->GetPower() << endl;
}


void CPassLeader::SetPower(int power)
{
    mPower = power;
}

void CPassLeader::SetPowerIncrement(int power)
{
    mPowerIncrement = power;
}

string CPassLeader::GetName()
{
    return mName;
}

int CPassLeader::GetPower()
{
    return mPower;
}

int CPassLeader::GetResilience() const
{
    return mResilience;
}

int CPassLeader::GetPowerIncrement()
{
    return mPowerIncrement;
}

CPassLeader::~CPassLeader()
{

}
