#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Sprites.h"

using namespace std;

extern short int Art[5][61][201];
extern short int HtB[5][61][201];

class Level: Sprites
{
    public:
        //void GetDuelNrAndMap(int number);
        //void GetCustom(string custom);
        void ExtractMap(int duelnr, Sprites s);
        void Screen(int HP1, int HP2);
        void MakeInterface(int maxpoint1, bool ICON1[8][8], int maxhitpoint2, bool ICON2[8][8]);
        void InterfaceUpdate(int timer1, int cooldown1, int hitpoints1, int maxhitpoints1, int timer2, int cooldown2, int hitpoints2, int maxhitpoints2);
        char Sym(short int nr);
        string Map;
        int Interface[61][201];
        bool completed;
        int spawn1x, spawn1y, spawn2x, spawn2y;
    protected:
    private:
        int i, j, k;
};

#endif // LEVEL_H
