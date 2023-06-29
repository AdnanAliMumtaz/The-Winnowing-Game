#include "CPlayer.h"

CPlayer::CPlayer(string name, int prestige, CardVector deck)
{
    mName = name;
    mPrestige = prestige;
    mDeck = deck;
    Table = make_unique<CTable>(); // Initialise table with a new instance of CTable
}

void CPlayer::DrawCard()
{
    if (!mDeck.empty()) // Checks if the deck isn't empty.
    {
        // Gets the front of the mDeck to draw it in order as per the requirments.
        shared_ptr<CCard> card = mDeck.front();
        
        // Hand can only have 2 cards at max, Otherwise, card isn't drawn
        if (mHand.size() < 2)
        {
            mHand.push_back(card);
            if (mHand.size() == 1) { cout << mName << " starts with " << card->GetName() << endl; }
            else { cout << mName << " draws " << mHand.back()->GetName() << endl; }
        }
        
        // Deletes the card from deck, after drawing it
        mDeck.erase(mDeck.begin()); 
    }
}

int CPlayer::Random(int max) 
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));
}

void CPlayer::PlayCard(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Generates a random number within the size of hand
    int random = Random(mHand.size());

    if (opponent->GetPrestige() > 0) // As long as the opponent's prestige is more 0, player continues to play.
    {
        mHand[random]->Play(player, opponent);
    }

    // Displays the cards on the table.
    Table->DisplayTable();

    // Activates the cards of table after every player turn as final operation.
    Table->ActivateCard(player, opponent);
    
    cout << endl;
}

shared_ptr<CPlayer> CPlayer::GetSacked()
{
    // Checks if player's prestige is less than or equal to 0 to sack the player
    if (mPrestige <= 0)
    {
        return shared_from_this();
    }
    else {
        return nullptr;
    }
}

void CPlayer::DeleteCardFromHand(shared_ptr<CCard> card)
{
    // Finds the card passed from the parameter to find out its position in the hand
    auto it = find(mHand.begin(), mHand.end(), card);
    if (it != mHand.end())
    {
        mHand.erase(it);
    }
}

void CPlayer::SetPrestige(int prestige)
{
    mPrestige = prestige;
}

string CPlayer::GetName()
{
    return mName;
}

int CPlayer::GetPrestige()
{
    return mPrestige;
}

CPlayer::CardVector CPlayer::GetDeck()
{
    return mDeck;
}

CPlayer::CardVector CPlayer::GetHand()
{
    return mHand;
}

unique_ptr<CTable>& CPlayer::GetTable()
{
    return Table;
}

int Random(int max)
{
    return 0;
}
