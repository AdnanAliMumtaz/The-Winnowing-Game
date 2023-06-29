#include "CFeedbackForum.h"

CFeedbackForum::CFeedbackForum(istream& file) : CCard(file)
{
    file >> mBoost; // Reads additional boost value from input file stream to initialise the member variable
}

istream& operator>>(istream& file, CFeedbackForum& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience >> card.mBoost;
    card.mName += (" " + card.mSecondName);
    return file;
}

void CFeedbackForum::Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Plays the card from the hand 
    cout << player->GetName() << " plays " << this->mName << endl;

    // Attack the enemy
    Attack(player, opponent);

    // Deletes the card from the table after playing
    player->DeleteCardFromHand(shared_from_this());
}

void CFeedbackForum::Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    unique_ptr <CTable>& playerTable = player->GetTable(); // Get the player's table by reference
    unique_ptr <CTable>& opponentTable = opponent->GetTable(); // Get the opponent's table by reference

    int playerCount = playerTable->Size() + 1; //+1 for the player
    int opponentCount = opponentTable->Size() + 1; //+1 for the enemy 

    // Lines up the player card + player and the opponent card + enemy
    int sum = playerCount + opponentCount;

    // Generates a random number
    int random = player->Random(sum);

    if (random <= (playerCount - 1)) // Performs Boost Action for (Player cards & Player prestige)
    {
        if (random < (playerCount - 1)) // Boost action for the player's cards
        {
            // Getting the random card from the player's table
            shared_ptr<CCard> card = playerTable->GetCard(random);

            // Boosting the resilience of the player's card
            int boost = card->GetResilience() + this->GetBoost();
            card->SetResilience(boost);
            cout << this->mName << " boosts " << card->GetName() << ". " << card->GetName() << "'s resilience is now " << card->GetResilience() << endl;
        }
        else // Boost action for the player (player's prestige) 
        {
            //Booting the prestige of the player
            int boost = player->GetPrestige() + this->GetBoost();
            player->SetPrestige(boost);
            cout << this->GetName() << " boosts " << player->GetName() << ". " << player->GetName() << "'prestige is now " << player->GetPrestige() << endl;
        }
    }
    else // Performs Attacking Action for (Opponent's cards & Opponent prestige) 
    {
        random -= playerCount; // Produces random number for opponent
        if (random < (opponentCount - 1)) // Attacking the opponent's cards
        {
            // Gettinng the random carf from the opponent's table
            shared_ptr <CCard> card = opponentTable->GetCard(random);

            //Attacking the resilience card of the opponent's cards
            int damage = card->GetResilience() - this->GetBoost();
            card->SetResilience(damage);

            // Displaying the output 
            cout << this->GetName() << " attacks " << card->GetName() << ". ";
            if (card->GetResilience() <= 0)
            {
                cout << card->GetName() << " is defeated " << endl;
                opponentTable->RemoveCard(card); //Removes the card defeated card.
            }
            else
            {
                cout << card->GetName() << "'s resilience is now " << card->GetResilience() << endl;
            }
        }
        else // Attacking the opponent directly by targeting his prestige. 
        {
            //Attacking the opponent's player's prestige
            int damage = opponent->GetPrestige() - this->GetBoost();
            opponent->SetPrestige(damage);

            //Output
            cout << this->GetName() << " attacks " << opponent->GetName() << ". " << opponent->GetName() << "'s prestige is now " << opponent->GetPrestige() << endl;
        }
    }
}

void CFeedbackForum::SetResilience(int resilience)
{
    mResilience = resilience;
}

int CFeedbackForum::GetBoost() const
{
    return mBoost;
}

int CFeedbackForum::GetResilience() const
{
    return mResilience;
}

CFeedbackForum::~CFeedbackForum()
{
}