#include "CGamePlay.h"
#include "CGamePlay.h"

CGameplay::CGameplay(int rounds)
{
    mRounds = rounds; // Sets the rounds for the game 
}

void CGameplay::AddPlayer(shared_ptr<CPlayer> player)
{
    // Adds the player to the game by pushing it back to the vector of players
    mPlayers.push_back(player);
}

void CGameplay::RemovePlayer(shared_ptr<CPlayer> player)
{
    // Removes the player by finding the player in the vector of players
    mPlayers.erase(find(mPlayers.begin(), mPlayers.end(), player));
}

void CGameplay::Play()
{
    cout << "======================================" << endl;
    cout << "Welcome to U-Can't. Let the winnowing begin..." << endl;
    cout << "======================================" << endl;
    cout << endl;

    unsigned int turns = 0;
    while (turns <= mRounds && mPlayers.size() > 1)
    {
        if (turns == 0)
        {
            // Drawing the cards for all players at the start of the game
            for (auto player : mPlayers)
            {
                player->DrawCard();
            }
        }
        else
        {
            cout << endl;
            cout << "=========" << endl;
            cout << "Round " << turns << endl;
            cout << "-------" << endl;

            for (int i = 0; i < mPlayers.size(); i++)
            {
                // Drawing the cards for the current player
                mPlayers[i]->DrawCard();

                // Plays the card for the current player againts the opponent.
                shared_ptr<CPlayer> opponent = GetOpponent(mPlayers[i], mPlayers);
                mPlayers[i]->PlayCard(mPlayers[i], opponent);

                // Check if opponent is sacked and update player vector accordingly
                SackPlayer(opponent->GetSacked());
                cout << "---" << endl;
            }
        }

        turns++; // Goes to the next round
    }

    // Calls for the Final Game Result
    GameResult();
}

shared_ptr<CPlayer> CGameplay::GetOpponent(shared_ptr<CPlayer> currentPlayer, const PlayerVector& players)
{
    //Finds the index of the current player in the players vector
    int currentPlayerIndex = find(players.begin(), players.end(), currentPlayer) - players.begin();

    //Calcualting the index of the next player in the players vector
    int nextPlayerIndex = (currentPlayerIndex + 1) % players.size();

    //Returning the player at the next player index
    return players[nextPlayerIndex];
}

void CGameplay::SackPlayer(shared_ptr<CPlayer> player)
{
    if (player != nullptr)
    {
        // Adds to the sacked players vector
        mSackedPlayers.push_back(player);
        cout << player->GetName() << " has no prestige and is sacked." << endl;

        // Removes the player from the active players vector
        RemovePlayer(player);
    }
}

void CGameplay::GameResult()
{
    cout << endl;
    cout << "======================================" << endl;
    cout << "  =========== GameOver ===========" << endl;
    cout << "======================================" << endl;

    // Displays the Sacked Players
    for (auto player : mSackedPlayers)
    {
        cout << "- " << player->GetName() << "'s prestige is " << player->GetPrestige() << endl;
    }

    // Displays the Active Player that won the game.
    if (mPlayers.size() == 1) //Defensive programming to check the last enemy has been left in the vector of players.
    {
        shared_ptr<CPlayer> player = mPlayers[0];

        // Display the players prestige
        cout << "+ " << player->GetName() << "'s prestige is " << player->GetPrestige() << endl;
        cout << endl;
        cout << "=======================" << endl;
        cout << player->GetName() << " wins. " << endl;
        cout << "=======================" << endl;
    }
}

CGameplay::~CGameplay()
{
}
