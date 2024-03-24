#ifndef SPRITES_H
#define SPRITES_H
#include <string>
using namespace std;

class Sprites
{
    public:
        void ExtractGraphics(int someinteger);
        void Ghost(int Sprite[16][16]);
        short int DuelMaps[3][61][201];
        int Spawns[3][4];
        int Icons[6][8][8];
        short int Heroes[6][4][2][5][16][16];
        char Symbol(short int nr);
    protected:
        void Extract(string file_name, int Sprite[16][16]);
        void Extract(string file_name, int k1, int k2, int Sprite[2][5][16][16]);
        void Extract(string file_name, int hero, bool Icon[8][8]);
        void MakeHitbox(int x, int Sprite[16][16], int Hitbox[16][16]);
        void MakeBig(int Sprite[16][16], int Big[31][31]);
    private:
        int i, j, k, l, m;
};

#endif // SPRITES_H
