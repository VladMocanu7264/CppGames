#include <string>
#include <fstream>
#include "Sprites.h"
using namespace std;

void Sprites::Extract(string file_name, int Sprite[16][16])
{
    fstream fstr(file_name.c_str());
    string line;
    if(fstr.is_open())
    {
        for(i=1; i<=15; i++)
        {
            getline(fstr, line);
            for(j=0; j<15; j++)
                Sprite[i][j+1]=line[j]-48;
        }
        fstr.close();
    }
    else
        Sprite[1][1]=4;
}

void Sprites::Ghost(int Sprite[16][16])
{
    for(i=1; i<=15; i++)
        for(j=1; j<=15; j++)
            if(Sprite[i][j]!=0)
                Sprite[i][j]=1;
}

void Sprites::MakeHitbox(int x, int Sprite[16][16], int Hitbox[16][16])
{
    for(i=1; i<=15; i++)
        for(j=1; j<=15; j++)
        {
            if(Sprite[i][j]!=0)
                Hitbox[i][j]=x;
            else
                Hitbox[i][j]=0;
        }
}

void Sprites::MakeBig(int Sprite[16][16], int Big[31][31])
{
    for(i=1; i<=30; i++)
        for(j=1; j<=30; j++)
        {
            if(i%2==1 && j%2==1)
            {
                if(Sprite[i/2+1][j/2+1]==5 || Sprite[i/2+1][j/2+1]==6 || Sprite[i/2+1][j/2+1]==7 || Sprite[i/2+1][j/2+1]==8 || Sprite[i/2+1][j/2+1]==9)
                    Big[i][j]=4;
                else
                    Big[i][j]=Sprite[i/2+1][j/2+1];
            }
            else if(i%2==1 && j%2==0)
                Big[i][j]=Big[i][j-1];
            else if(i%2==0 && j%2==1)
                Big[i][j]=Big[i-1][j];
            else
                Big[i][j]=Big[i-1][j-1];
        }
}

void Sprites::Extract(string file_name, int k1, int k2, int Sprite[2][5][16][16])
{
    fstream fstr(file_name.c_str());
    string line;
    if(fstr.is_open())
    {
        for(i=1; i<=15; i++)
        {
            getline(fstr, line);
            for(j=0; j<15; j++)
                Sprite[k1][k2][i][j+1]=line[j]-48;
        }
        fstr.close();
    }
    else
        Sprite[k1][k2][1][1]=4;
}

void Sprites::Extract(string file_name, int hero, bool Icon[8][8])
{
    fstream fstr(file_name.c_str());
    string line;
    int Matrice[6][8][8];
    if(fstr.is_open())
    {
        for(k=0; k<6; k++)
            for(i=0; i<8; i++)
            {
                getline(fstr, line);
                for(j=0; j<8; j++)
                    Matrice[k][i][j]=line[j]-48;
            }
        fstr.close();
    }

    for(i=0; i<=8; i++)
        for(j=0; j<8; j++)
            Icon[i][j]=Matrice[hero-1][i][j];
}

void Sprites::ExtractGraphics(int someinteger)
{
    fstream fstr("Graphics.txt");
    string line;
    int cont;
    if(fstr.is_open())
    {
        ///SavedGame
        /*getline(fstr, line);///Screen Dimensions
        getline(fstr, line);///Completed Levels
        getline(fstr, line);///Ability Levels Jack
        getline(fstr, line);///Ability Levels Vix
        getline(fstr, line);///Ability Levels Lara
        getline(fstr, line);///Ability Levels Ella
        getline(fstr, line);///Ability Levels Rodrigo
        getline(fstr, line);///Ability Levels Dia*/
        ///DuelMaps
        for(i=0; i<someinteger; i++)
        {
            for(j=0; j<4; j++)
                Spawns[i][j]=0;
            getline(fstr, line);
            cont=0;
            for(j=0; (unsigned)j<line.length(); j++)
            {
                if(line[j]==' ')
                    cont++;
                else
                    Spawns[i][cont]=Spawns[i][cont]*10+(line[j]-48);
            }

            for(j=1; j<=60; j++)
            {
                getline(fstr, line);
                for(k=0; k<200; k++)
                {
                    if(('a'<=line[k] && line[k]<='z') || ('A'<=line[k] && line[k]<='Z'))
                        DuelMaps[i][j][k+1]=line[k];
                    else
                        DuelMaps[i][j][k+1]=line[k]-48;
                }
            }
        }
        ///Icons
        for(i=0; i<6; i++)
            for(j=0; j<8; j++)
            {
                getline(fstr, line);
                for(k=0; k<8; k++)
                    Icons[i][j][k]=line[k]-48;
            }
        ///Error
        for(i=1; i<=26; i++)
            getline(fstr, line);
        ///Heroes
        for(i=0; i<6; i++)///hero
        {
            getline(fstr, line);
            ///Movement
            for(j=1; j<=15; j++)
            {
                getline(fstr, line);
                for(k=1; k<=8; k++)
                    for(l=1; l<=15; l++)
                        Heroes[i][0][(k-1)/4][k%4==0?4:k%4][j][l]=line[(k-1)*15+l-1]-48;
            }
            ///Shooting
            for(j=1; j<=15; j++)
            {
                getline(fstr, line);
                for(k=1; k<=8; k++)
                    for(l=1; l<=15; l++)
                        Heroes[i][1][(k-1)/4][k%4==0?4:k%4][j][l]=line[(k-1)*15+l-1]-48;
            }
            ///Ability
            if(i!=1)
            {
                    for(l=1; l<=15; l++)
                    {
                        getline(fstr, line);
                        for(k=1; k<=4; k++)
                            for(m=1; m<=15; m++)
                                Heroes[i][2][0][k][l][m]=line[(k-1)*15+m-1]-48;
                    }
            }
            ///Passive
            if(false)
            {
                /*for(k=1; k<=4; k++)
                    for(l=1; l<=15; l++)
                    {
                        getline(fstr, line);
                        for(m=0; m<15; m++)
                            Heroes[i][3][0][k][l][m+1]=line[m]-48;
                    }*/
            }
        }
        fstr.close();
    }
    else
        DuelMaps[0][1][1]=12;
}

char Sprites::Symbol(short int nr)
{
    switch(nr)
    {
    case 0:
        return ' ';
        break;
    case 1:
        return (char)176;
        break;
    case 2:
        return (char)177;
        break;
    case 3:
        return (char)178;
        break;
    case 4:
        return (char)219;
        break;
    case 5:
        return (char)220;
        break;
    case 6:
        return (char)221;
        break;
    case 7:
        return (char)222;
        break;
    case 8:
        return (char)223;
        break;
    case 9:
        return (char)254;
        break;
    default:
        return 'E';
    }
}
