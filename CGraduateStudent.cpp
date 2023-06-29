#include "CGraduateStudent.h"

CGraduateStudent::CGraduateStudent(istream& file) : CCard(file)
{
    file >> mResilience >> mBoost; // Reads additional resilience and boost value to initialise the variable members 
}

istream& operator>>(istream& file, CGraduateStudent& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience >> card.mBoost;
    card.mName += (" " + card.mSecondName);
    return file;
}

void CGraduateStudent::Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Plays the card from the hand
    cout << player->GetName() << " plays " << this->GetName() << endl;

    // Plays the card to the table
    unique_ptr<CTable>& table = player->GetTable();
    table->AddCard(shared_from_this());

    // Deletes the card from the table
    player->DeleteCardFromHand(shared_from_this());
}

void CGraduateStudent::Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    unique_ptr<CTable>& opponentTable = opponent->GetTable();

    if (opponentTable->IsEmpty()) // Enemy student card don't exist
    {
        // Attacks the card enemy directly
        int damage = opponent->GetPrestige() - this->GetPower();
        opponent->SetPrestige(damage);

        // Final Output
        cout << this->GetName() << " attacks " << opponent->GetName() << ". " << opponent->GetName() << "'s prestige is now " << opponent->GetPrestige() << endl;
    }
    else
    { // enemy student card exist

        // Choose a random enemy to attack
        int randomIndex = player->Random(opponentTable->Size());
        shared_ptr<CCard> randomEnemyCard = opponentTable->GetCard(randomIndex);

        // Attacks the enemy card
        int damage = randomEnemyCard->GetResilience() - this->GetPower();
        randomEnemyCard->SetResilience(damage);

        // Final Output
        if (damage <= 0)
        {
            cout << this->GetName() << " attacks " << randomEnemyCard->GetName() << ". " << randomEnemyCard->GetName() << " is defeated." << endl;
            opponentTable->RemoveCard(randomEnemyCard);
        }
        else
        {
            cout << this->GetName() << " attacks " << randomEnemyCard->GetName() << ". " << randomEnemyCard->GetName() << "'s resilience is now " << damage << endl;
        }
    }

    // Bosting the player
    BoostPrestige(player);
}

void CGraduateStudent::BoostPrestige(shared_ptr<CPlayer> player)
{
    // Boosting the prestige of the player
    int boost = player->GetPrestige() + this->mBoost;
    player->SetPrestige(boost);

    // Displa the boosting prestige message
    cout << this->mName << " boosts prestige of " << player->GetName() << ". " << player->GetName() << "'s prestige is now " << player->GetPrestige() << ". " << endl;
}

CGraduateStudent::~CGraduateStudent()
{
}