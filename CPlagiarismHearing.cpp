#include "CPlagiarismHearing.h"

void CPlagiaristHearing::Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    unique_ptr<CTable>& enemyTable = opponent->GetTable();
    int enemySize = enemyTable->Size();
    int random = player->Random(enemySize + 1);

    if (random < enemySize) {
        // Attacks the enemy student
        shared_ptr <CCard> enemyCard = enemyTable->GetCard(random);
        int damage = enemyCard->GetResilience() - this->GetPower();

        if (damage <= 0) {
            enemyTable->RemoveCard(enemyCard);
            cout << this->GetName() << " attacks " << enemyCard->GetName() << ". ";
            cout << enemyCard->GetName() << " is defeated." << endl;
        }
        else {
            enemyCard->SetResilience(damage);
            cout << this->GetName() << " attacks " << enemyCard->GetName() << ". ";
            cout << enemyCard->GetName() << "'s resilience is now " << enemyCard->GetResilience() << endl;
        }
    }
    else {
        // Attacks the professor
        int damage = opponent->GetPrestige() - this->GetPower();
        opponent->SetPrestige(damage);
        cout << this->GetName() << " attacks " << opponent->GetName() << ". ";
        cout << opponent->GetName() << "'s prestige is now " << opponent->GetPrestige() << endl;
    }
}

CPlagiaristHearing::CPlagiaristHearing(istream& file) : CCard(file)
{
}

void CPlagiaristHearing::Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Plays the card
    cout << player->GetName() << " plays " << this->GetName() << endl;

    //Attacks
    Attack(player, opponent);

    // Removes the card from the hand
    player->DeleteCardFromHand(shared_from_this());
}

CPlagiaristHearing::~CPlagiaristHearing()
{
}
