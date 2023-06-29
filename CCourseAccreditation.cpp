#include "CCourseAccreditation.h"

CCourseAccreditation::CCourseAccreditation(istream& file) : CCard(file)
{
    // No addtional operations to be performed during the construction of the object.
}

void CCourseAccreditation::Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Plays the card from the hand 
    cout << player->GetName() << " plays " << this->GetName() << endl;

    //Activating the Attack function
    Attack(player, opponent);

    // Deletes the card from the hand
    player->DeleteCardFromHand(shared_from_this());
}

void CCourseAccreditation::Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Get the enemy's table by reference
    unique_ptr<CTable>& enemyTable = opponent->GetTable();

    // Attacking the entire enemy cohort
    for (auto enemyCard : enemyTable->GetTable()) // Loop goes through each card in the enemy's table
    {
        // Performs the calculations to attack the opponent card
        int damage = enemyCard->GetResilience() - this->GetPower();
        enemyCard->SetResilience(damage); // Player attacks the opponent

        // Display the output for the opponent
        if (damage <= 0) 
        {
            cout << this->GetName() << " attacks " << enemyCard->GetName() << ". " << enemyCard->GetName() << " is defeated. " << endl;
            enemyTable->RemoveCard(enemyCard); // Removes the enemy card 
        }
        else {
            cout << this->GetName() << " attacks " << enemyCard->GetName() << ". " << enemyCard->GetName() << "'s resilience is " << enemyCard->GetResilience() << endl;
        }
    }

    // Attacks the opponent directly
    int damage = opponent->GetPrestige() - this->GetPower();
    opponent->SetPrestige(damage); // Attacking the professor prestige 
    
    // Display updated prestige of enemy's professor
    cout << this->GetName() << " attacks " << opponent->GetName() << ". " << opponent->GetName() << "'s resilience is " << opponent->GetPrestige() << endl;
}

CCourseAccreditation::~CCourseAccreditation()
{

}