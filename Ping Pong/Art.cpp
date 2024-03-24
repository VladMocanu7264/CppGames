#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Art.h"
#include "Paleta.h"

using namespace std;

extern int score1, score2;
extern int Screen[17][42];

Art::Art()
{
    for(i=1; i<=16; i++)
        for(j=1; j<=41; j++)
        {
            if(i==1  || j==1 || i==16 || j==41)
                Screen[i][j]=1;
            else
                Screen[i][j]=0;
        }

    Screen[6][4]=1;
    Screen[7][4]=1;
    Screen[8][4]=1;
    Screen[9][4]=2;
    Screen[10][4]=2;
    Screen[11][4]=2;

    Screen[6][38]=1;
    Screen[7][38]=1;
    Screen[8][38]=1;
    Screen[9][38]=2;
    Screen[10][38]=2;
    Screen[11][38]=2;

    Screen[8][21]=3;
}

void Art::Draw()
{
    system("CLS");
    cout<<endl;
    cout<<"   P1:";
    for(i=1; i<=5; i++)
    {
        if(i<=score1)
            cout<<"#";
        else
            cout<<"-";
    }
    cout<<"                   P2:";
    for(i=1; i<=5; i++)
    {
        if(i<=score2)
            cout<<"#";
        else
            cout<<"-";
    }
    cout<<endl;

    for(i=1; i<=16; i++)
    {
        for(j=1; j<=41; j++)
            {
                if(Screen[i][j]==1 || Screen[i][j]==2)
                    cout<<(char)178;
                else if(Screen[i][j]==3)
                    cout<<"O";
                else if(Screen[i][j]==0)
                    cout<<" ";
            }

        cout<<endl;
    }
}

void Art::PChanges(int X, int Y)
{
    for(i=2; i<=15; i++)
        Screen[i][Y]=0;
    for(i=X; i<=X+2; i++)
        Screen[i][Y]=1;
    for(i=X+3; i<=X+5; i++)
        Screen[i][Y]=2;
}

void Art::BChanges(int x1, int y1, int x2, int y2)
{
    Screen[x1][y1]=0;
    Screen[x2][y2]=3;
}

int Art::Imput()
{
    int imp;
    if(kbhit())
    {
        imp=getch();
        switch(imp)
        {
            case 'w':
                return 2;
                break;
            case 's':
                return 3;
                break;
            case 'i':
                return 4;
                break;
            case 'k':
                return 5;
                break;
            default:
                return 1;
                break;
        }
    }

    return 0;
}




