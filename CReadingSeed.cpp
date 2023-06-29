#include "CReadingSeed.h"

CReadingSeed::CReadingSeed(string fileName) : CFile(fileName) 
{
    ReadSeed(); // Calls the ReadSeed() function to read the seedNumber during object construction.
}

void CReadingSeed::ReadSeed()
{
    ifstream file(mFileName);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            SplitNumber(line); // Calls SplitNumber to split the line into 1 word for seed.
        }
        file.close();
    }
    else {
        cout << mFileName << " file isn't opening!" << endl;
    }
}

void CReadingSeed::SplitNumber(string& line)
{
    mSeedNumber = atoi(line.c_str()); // Converts the string 'line' string to an integer 

}

int CReadingSeed::GetSeedNumber()
{
    return mSeedNumber;
}

CReadingSeed::~CReadingSeed()
{
}