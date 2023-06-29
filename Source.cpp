// Name : Adnan Ali Mumtaz
// Reg  : 20862007

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream> 
#include "CFile.h"
#include "CReadDeck.h"
#include "CReadingSeed.h"
#include "CPlayer.h"
#include "CGamePlay.h"
#include <memory>
#define _CRTDBG_MAP_ALLOC

using namespace std;

int main()
{
    {
        // Reading files 
        unique_ptr<CFile> plagiaristFile = make_unique<CReadDeck>("plagiarist.txt");
        unique_ptr<CFile> pifflePaperFile = make_unique<CReadDeck>("piffle-paper.txt");
        unique_ptr<CFile> pointLessFile = make_unique<CReadDeck>("pointless.txt");
        unique_ptr<CFile> perditionFile = make_unique<CReadDeck>("perdition.txt");
        unique_ptr<CFile> seedFile = make_unique<CReadingSeed>("seed.txt");

        // Professors
        shared_ptr<CPlayer> plagiarist = make_shared<CPlayer>("Prof Plagiarist", 30, plagiaristFile->GetCards());
        shared_ptr<CPlayer> pifflePaper = make_shared<CPlayer>("Prof Piffle-paper", 30, pifflePaperFile->GetCards());
        shared_ptr<CPlayer> pointLess = make_shared<CPlayer>("Prof Pointless", 30, pointLessFile->GetCards());
        shared_ptr<CPlayer> perdition = make_shared<CPlayer>("Prof Perdition", 30, perditionFile->GetCards());

        // Setting up srand()
        srand(seedFile->GetSeedNumber());

        // Game Play
        shared_ptr<CGameplay> gameplay = make_shared<CGameplay>(30);
        gameplay->AddPlayer(plagiarist); 
        gameplay->AddPlayer(pifflePaper);
        gameplay->AddPlayer(pointLess);
        gameplay->AddPlayer(perdition);
        gameplay->Play();

    }

    // Memory Detection
    _CrtDumpMemoryLeaks();
}