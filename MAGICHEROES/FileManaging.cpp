#include <fstream>
#include "FileManaging.h"

using namespace std;

void FileManaging::Extract()
{
    ifstream fin("SavedGame.txt");

    fin>>slvls;
    for(i=1; i<=6; i++)
        fin>>sAbLvl1[i]>>sAbLvl2[i]>>sAbLvl3[i];
}

void FileManaging::Save()
{
    ofstream fout("SavedGame.txt");

    fout<<slvls<<endl;
    for(i=1; i<=6; i++)
        fout<<sAbLvl1[i]<<" "<<sAbLvl2[i]<<" "<<sAbLvl3[i]<<endl;
}

void FileManaging::Delete()
{
    ofstream fout("SavedGame.txt");

    fout<<0<<endl;
    for(i=1; i<=6; i++)
        fout<<"1 1 1"<<endl;
}
