#include "CSerialOffender.h"

CSerialOffender::CSerialOffender(istream& file) : CCard(file)
{
	file >> mResilience; // Reads additional resilience value to initialise the variable members
}

istream& operator>>(istream& file, CSerialOffender& card)
{
	file >> card.mName >> card.mSecondName >> card.mPower >> card.mResilience;
	card.mName += (" " + card.mSecondName);
	return file;
}

void CSerialOffender::Play(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
	// Plays the card from the hand
	cout << player->GetName() << " plays " << this->GetName() << endl;

	// Plays the card to the table
	unique_ptr<CTable>& table = player->GetTable();
	table->AddCard(shared_from_this());

	// Deletes the card from the hand after playing
	player->DeleteCardFromHand(shared_from_this());
}

void CSerialOffender::Attack(shared_ptr<CPlayer> player, shared_ptr<CPlayer> opponent)
{
	// Reference to opponent's table 
	unique_ptr<CTable>& opponentTable = opponent->GetTable();

	if (!opponentTable->IsEmpty()) // if the enemy student card doesn't exist
	{
		int excessPower = 0; // It is used to calculate the any excessive power that has been left over after attacking opponent
		int random = player->Random(opponentTable->Size()); // Generates a random number from the size of the opponent's table to attack
		shared_ptr<CCard> opponentCard = opponentTable->GetCard(random); // Chooses a random card to attack from the opponent's table

		// Attacks the opponent card randomly chosen from the enemy
		int damage = opponentCard->GetResilience() - this->GetPower();
		opponentCard->SetResilience(damage);

		if (damage <= 0)
		{
			// Defensive programming
			excessPower = abs(damage); // Calculate absolute value of damage to avoid mathmatical errors

			// Display the attacking message for defeated opponent
			cout << this->GetName() << " attacks " << opponentCard->GetName() << ". " << opponentCard->GetName() << " is defeated." << endl;
			opponentTable->RemoveCard(opponentCard); // Removes the card from the opponent table
		}
		else
		{
			// Display the attacking message
			cout << this->GetName() << " attacks " << opponentCard->GetName() << ". " << opponentCard->GetName() << "'s resilience is now " << damage << endl;
		}


		if (excessPower > 0) // Checks if there is any excessive power left over
		{
			this->mPower = excessPower; // Cards power updates to the left over power
			Attack(player, opponent); // Recursion is used to perform an attack in the same turn, if the excessive power is left over
		}
	}
	else // If the opponent has the student card
	{
		// Attacking the opponent directly
		int damage = opponent->GetPrestige() - this->GetPower();
		opponent->SetPrestige(damage);

		// Display the attacking message
		cout << this->GetName() << " attacks " << opponent->GetName() << ". " << opponent->GetName() << "'s prestige is now " << opponent->GetPrestige() << endl;
	}
}

CSerialOffender::~CSerialOffender()
{
}
