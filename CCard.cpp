#include "CCard.h"

CCard::CCard(istream& file) // Reads the data from file (istream) and initialise the member variables
{
    file >> mName >> mSecondName >> mPower; // Reads the input stream.
    mName += (" " + mSecondName); // Attachs the second name to first name to make it one word
}

istream& operator>> (istream& file, CCard& card)
{
    file >> card.mName >> card.mSecondName >> card.mPower;// Reads the input stream.
    card.mName += (" " + card.mSecondName); // Attachs the second name to first name to make it one word
    return file;
}

void CCard::Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Play a random card from the hand
    cout << player->GetName() << " plays " << this->mName << endl;

    // Deletes the card from the player's hand after playing
    player->DeleteCardFromHand(shared_from_this());
}

void CCard::Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
    // Functionality to be developed in the derived classes.
}

void CCard::SetResilience(int resilience)
{

}

void CCard::SetPower(int power)
{
    mPower = power;
}

string CCard::GetName()
{
    return mName;
}

int CCard::GetPower()
{
    return mPower;
}

int CCard::GetResilience() const
{
    return 0;
}

CCard::~CCard()
{

}
