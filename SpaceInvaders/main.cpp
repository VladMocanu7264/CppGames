#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>

using namespace std;

bool GAMEOVER;
bool MAP[4][7][6];
char imp;
int h, i, j;
int score;
int X, Y;
int n;
int nrenemies, pozenemy;

void setup()
{
    X=6; Y=3;
    for(h=1; h<=3; h++)
        for(i=1; i<=6; i++)
            for(j=1; j<=5; j++)
                MAP[h][i][j]=0;
    MAP[3][X][Y]=1;
    n=0;
    score=0;
}

void art()
{
    system("CLS");

    cout<<"#######"<<endl;
    for(i=1; i<=6; i++)
        {
            cout<<"#";
            for(j=1; j<=5; j++)
            {
                if(MAP[3][i][j]==1)
                    cout<<'A';
                else if(MAP[2][i][j]==1)
                    cout<<'^';
                else if(MAP[1][i][j]==1)
                    cout<<'O';
                else if(i==6)
                    cout<<'-';
                else
                    cout<<' ';
            }
            cout<<"#"<<endl;
        }
    cout<<"#######"<<endl;
    if(GAMEOVER==1)
    {
        cout<<endl;
        cout<<"GAME OVER"<<endl;
    }
    cout<<endl;
    cout<<"Score: "<<score;
}

void check()
{
    for(i=1; i<=5; i++)
        for(j=1; j<=5; j++)
            if(MAP[2][i][j]==1 && MAP[1][i][j]==1)
            {
                MAP[2][i][j]=0;
                MAP[1][i][j]=0;
                score+=10;
            }
}

void input()
{
    if(_kbhit())
    {
        imp=getch();

        if(imp=='a' && Y>1)
        {
            MAP[3][X][Y]=0;
            MAP[3][X][--Y]=1;
        }else if(imp=='d' && Y<5)
        {
            MAP[3][X][Y]=0;
            MAP[3][X][++Y]=1;
        }else if(imp=='w')
        {
            MAP[2][X-1][Y]=1;

            check();
        }
    }
}

void bigbrain()
{
    n++;

    for(i=1; i<=4; i++)
        for(j=1; j<=5; j++)
            MAP[2][i][j]=MAP[2][i+1][j];

    for(j=1; j<=5; j++)
        MAP[2][5][j]=0;

    check();

    if(n%10==0)
    {
        for(i=6; i>=2; i--)
            for(j=1; j<=5; j++)
                MAP[1][i][j]=MAP[1][i-1][j];

        for(j=1; j<=5; j++)
            MAP[1][1][j]=0;

        nrenemies=rand()%3;
        nrenemies++;

        while(nrenemies>0)
        {
            pozenemy=1+(rand()%5);
            if(MAP[1][1][pozenemy]==0)
            {
                MAP[1][1][pozenemy]=1;
                nrenemies--;
            }
        }

        check();

        for(j=1; j<=5; j++)
            if(MAP[1][6][j]==1)
            {
                GAMEOVER=1;
                art();
                imp=getch();
            }
    }
}

int main()
{
    srand(time(0));
    setup();
    while(GAMEOVER==0)
    {
        art();
        input();
        bigbrain();
        Sleep(50);
    }

    return 0;
}
