#include "CReadDeck.h"

CReadDeck::CReadDeck(string fileName) : CFile(fileName)
{
    ReadCards(); // Calls the ReadCards() function to read the cards during object construction.
}

void CReadDeck::ReadCards()
{
    ifstream file(mFileName);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            SplitLine(line); // Calls a SplitLine() to break the string.
        }
        file.close();
    }
    else {
        cout << "Unable to open file " << mFileName << endl;
    }
}

void CReadDeck::SplitLine(string& line)
{
    int type = 0;
    
    // stringstream 'breakWord' to break 'line' into type.
    stringstream breakWord(line); 
    breakWord >> type;

    // Creates a deck of right object types by calling NewCard function that returns it.
    mDeck.push_back(NewCard(ECardType(type), breakWord));
}

CReadDeck::CardVector CReadDeck::GetCards() const
{
    return mDeck;
}

CReadDeck::~CReadDeck()
{
}
