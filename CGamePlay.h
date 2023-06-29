#pragma once
#include "CPlayer.h"
#include <iostream>

class CGameplay
{
private:
    using PlayerVector = vector<shared_ptr<CPlayer>>; // Type alias for a vector of shared pointers to CPlayer objects
    int mRounds;
    PlayerVector mPlayers; // Vector to store players in the game
    PlayerVector mSackedPlayers; // Vector to store sacked players

public:
    CGameplay(int rounds); // Constructor takes an input sstream as a parameter, reads the data to initialise the member variables

    // Operations
    void AddPlayer(shared_ptr<CPlayer> player); // Adds a player to the game
    void RemovePlayer(shared_ptr<CPlayer> player); // Removes a player from the game
    void Play(); // Plays the game: Drawing Cards, Playing turn, Attacking and showing final output
    shared_ptr<CPlayer> GetOpponent(shared_ptr<CPlayer> currentPlayer, const PlayerVector& players); // Returns the next player to attack
    void SackPlayer(shared_ptr<CPlayer> player); // Sacks a player from the game
    void GameResult(); // Shows the final game result

    ~CGameplay(); // Destructor for proper cleanup
};
