#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Sprites.h"

using namespace std;

extern short int Art[5][61][201];
extern short int HtB[5][61][201];

class Player: Sprites
{
    public:
        Player(int layer, int HERO, int A1Lvl, int A2Lvl, int A3Lvl, int xi, int yi, Sprites s);
        int heronr;
        string action;
        int x, y;
        int maxhp, hp;
        int ad, fr, ap, cd;
        int speed, direction;
        bool LockDirection[5];
        int Current[16][16];
        int Hitbox[16][16];
        int Hero[16][16];
        bool Icon[8][8];
        int Movement[2][5][16][16];
        int Firing[2][5][16][16];
        int Ability[5][16][16];
        int FTimer, ATimer;
        int OutOfCombatCont;
        void Move(char ch);
        void Shoot();
        void Reconstruct();
        bool BMC, HBL, HBV, locked, Immune, Shadowed;
    protected:
    private:
        string hero;
        int Layer;
        int i, j, k, l;
};

#endif // PLAYER_H
