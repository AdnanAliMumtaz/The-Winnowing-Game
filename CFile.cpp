#include "CFile.h"

CFile::CFile(string fileName)
{
    mFileName = fileName;
}

void CFile::ReadCards()
{
    // Functionality to be implemented in the derived classes
}

void CFile::ReadSeed()
{
    // Functionality to be implemented in the derived classes
}

void CFile::SplitLine(string& line)
{
    // Functionality to be implemented in the derived classes
}

void CFile::SplitNumber(string& line)
{
    // Functionality to be implemented in the derived classes
}

CFile::CardVector CFile::GetCards() const
{
    return CardVector();
}

int CFile::GetSeedNumber()
{
    return 0;
}

CFile::~CFile()
{
}