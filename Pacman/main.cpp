#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>

using namespace std;

bool gameover, win;
int score, n;
int i, j;
int X, Y;
char direction;
int DIR;
int dirB, dirS, dirI, dirP;
int XB, YB, XS, YS, XI, YI, XP, YP;
bool ok;
int anakinihavethehighground;

int MAP[21][16]={
        {},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1},
        {0, 1, 3, 1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 1, 3, 1},
        {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {0, 1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1},
        {0, 1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1},
        {0, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 1, 1, 1},
        {0, 0, 0, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 0, 0},
        {0, 1, 1, 1, 2, 1, 2, 1, 4, 1, 2, 1, 2, 1, 1, 1},
        {0, 0, 0, 0, 2, 2, 2, 1, 0, 1, 2, 2, 2, 0, 0, 0},
        {0, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1},
        {0, 0, 0, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 0, 0},
        {0, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1},
        {0, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1},
        {0, 1, 2, 1, 1, 2, 1, 2, 0, 2, 1, 2, 1, 1, 2, 1},
        {0, 1, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 3, 1},
        {0, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 1},
        {0, 1, 2, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 2, 1},
        {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

bool PACMAN[21][16];
bool Blinky[21][16];
bool Speedy[21][16];
bool Inky[21][16];
bool Pokey[21][16];

void Blink()
{
    if(dirB==1 && MAP[XB-1][YB]==1)
    {
        if(XB==X && YB<Y)
            dirB=3;
        else if(XB==X && YB>Y)
            dirB=4;
        else if(YB==Y && XB<X)
            dirB=2;
        else if(YB==Y && XB>X)
            dirB=1;
        else
            while(dirB==1)
                dirB=rand()%4+1;
    }
    else if(dirB==2 && MAP[XB+1][YB]==1)
    {
        if(XB==X && YB<Y)
            dirB=3;
        else if(XB==X && YB>Y)
            dirB=4;
        else if(YB==Y && XB<X)
            dirB=2;
        else if(YB==Y && XB>X)
            dirB=1;
        else
            while(dirB==2)
                dirB=rand()%4+1;
    }
    else if(dirB==3 && MAP[XB][YB-1]==1)
    {
        if(XB==X && YB<Y)
            dirB=3;
        else if(XB==X && YB>Y)
            dirB=4;
        else if(YB==Y && XB<X)
            dirB=2;
        else if(YB==Y && XB>X)
            dirB=1;
        else
            while(dirB==3)
                dirB=rand()%4+1;
    }
    else if(dirB==4 && MAP[XB][YB+1]==1)
    {
        if(XB==X && YB<Y)
            dirB=3;
        else if(XB==X && YB>Y)
            dirB=4;
        else if(YB==Y && XB<X)
            dirB=2;
        else if(YB==Y && XB>X)
            dirB=1;
        else
            while(dirB==4)
                dirB=rand()%4+1;
    }

    if(dirB==1 && MAP[XB-1][YB]!=1)
    {
        Blinky[XB][YB]=0;
        XB--;
        Blinky[XB][YB]=1;
    }
    else if(dirB==2 && MAP[XB+1][YB]!=1)
    {
        Blinky[XB][YB]=0;
        XB++;
        Blinky[XB][YB]=1;
    }
    else if(dirB==3 && MAP[XB][YB-1]!=1)
    {
        Blinky[XB][YB]=0;
        YB--;
        Blinky[XB][YB]=1;
    }
    else if(dirB==4 && MAP[XB][YB+1]!=1)
    {
        Blinky[XB][YB]=0;
        YB++;
        Blinky[XB][YB]=1;
    }
}

void Speed()
{
    if(dirS==1 && MAP[XS-1][YS]==1)
    {
        if(XS==X && YS<Y)
            dirS=3;
        else if(XS==X && YS>Y)
            dirS=4;
        else if(YS==Y && XS<X)
            dirS=2;
        else if(YS==Y && XS>X)
            dirS=1;
        else
            while(dirS==1)
                dirS=rand()%4+1;
    }
    else if(dirS==2 && MAP[XS+1][YS]==1)
    {
        if(XS==X && YS<Y)
            dirS=3;
        else if(XS==X && YS>Y)
            dirS=4;
        else if(YS==Y && XS<X)
            dirS=2;
        else if(YS==Y && XS>X)
            dirS=1;
        else
            while(dirS==2)
                dirS=rand()%4+1;
    }
    else if(dirS==3 && MAP[XS][YS-1]==1)
    {
        if(XS==X && YS<Y)
            dirS=3;
        else if(XS==X && YS>Y)
            dirS=4;
        else if(YS==Y && XS<X)
            dirS=2;
        else if(YS==Y && XS>X)
            dirS=1;
        else
            while(dirS==3)
                dirS=rand()%4+1;
    }
    else if(dirS==4 && MAP[XS][YS+1]==1)
    {
        if(XS==X && YS<Y)
            dirS=3;
        else if(XS==X && YS>Y)
            dirS=4;
        else if(YS==Y && XS<X)
            dirS=2;
        else if(YS==Y && XS>X)
            dirS=1;
        else
            while(dirS==4)
                dirS=rand()%4+1;
    }

    if(dirS==1 && MAP[XS-1][YS]!=1)
    {
        Speedy[XS][YS]=0;
        XS--;
        Speedy[XS][YS]=1;
    }
    else if(dirS==2 && MAP[XS+1][YS]!=1)
    {
        Speedy[XS][YS]=0;
        XS++;
        Speedy[XS][YS]=1;
    }
    else if(dirS==3 && MAP[XS][YS-1]!=1)
    {
        Speedy[XS][YS]=0;
        YS--;
        Speedy[XS][YS]=1;
    }
    else if(dirS==4 && MAP[XS][YS+1]!=1)
    {
        Speedy[XS][YS]=0;
        YS++;
        Speedy[XS][YS]=1;
    }
}

void Ink()
{
    if(dirI==1 && MAP[XI-1][YI]==1)
    {
        if(XI==X && YI<Y)
            dirI=3;
        else if(XI==X && YI>Y)
            dirI=4;
        else if(YI==Y && XI<X)
            dirI=2;
        else if(YI==Y && XI>X)
            dirI=1;
        else
            while(dirI==1)
                dirI=rand()%4+1;
    }
    else if(dirI==2 && MAP[XI+1][YI]==1)
    {
        if(XI==X && YI<Y)
            dirI=3;
        else if(XI==X && YI>Y)
            dirI=4;
        else if(YI==Y && XI<X)
            dirI=2;
        else if(YI==Y && XI>X)
            dirI=1;
        else
            while(dirI==2)
                dirI=rand()%4+1;
    }
    else if(dirI==3 && MAP[XI][YI-1]==1)
    {
        if(XI==X && YI<Y)
            dirI=3;
        else if(XI==X && YI>Y)
            dirI=4;
        else if(YI==Y && XI<X)
            dirI=2;
        else if(YI==Y && XI>X)
            dirI=1;
        else
            while(dirI==3)
                dirI=rand()%4+1;
    }
    else if(dirI==4 && MAP[XI][YI+1]==1)
    {
        if(XI==X && YI<Y)
            dirI=3;
        else if(XI==X && YI>Y)
            dirI=4;
        else if(YI==Y && XI<X)
            dirI=2;
        else if(YI==Y && XI>X)
            dirI=1;
        else
            while(dirI==4)
                dirI=rand()%4+1;
    }

    if(dirI==1 && MAP[XI-1][YI]!=1)
    {
        Inky[XI][YI]=0;
        XI--;
        Inky[XI][YI]=1;
    }
    else if(dirI==2 && MAP[XI+1][YI]!=1)
    {
        Inky[XI][YI]=0;
        XI++;
        Inky[XI][YI]=1;
    }
    else if(dirI==3 && MAP[XI][YI-1]!=1)
    {
        Inky[XI][YI]=0;
        YI--;
        Inky[XI][YI]=1;
    }
    else if(dirI==4 && MAP[XI][YI+1]!=1)
    {
        Inky[XI][YI]=0;
        YI++;
        Inky[XI][YI]=1;
    }
}

void Poke()
{
    if(dirP==1 && MAP[XP-1][YP]==1)
    {
        if(XP==X && YP<Y)
            dirP=3;
        else if(XP==X && YP>Y)
            dirP=4;
        else if(YP==Y && XP<X)
            dirP=2;
        else if(YP==Y && XP>X)
            dirP=1;
        else
            while(dirP==1)
                dirP=rand()%4+1;
    }
    else if(dirP==2 && MAP[XP+1][YP]==1)
    {
        if(XP==X && YP<Y)
            dirP=3;
        else if(XP==X && YP>Y)
            dirP=4;
        else if(YP==Y && XP<X)
            dirP=2;
        else if(YP==Y && XP>X)
            dirP=1;
        else
            while(dirP==2)
                dirP=rand()%4+1;
    }
    else if(dirP==3 && MAP[XP][YP-1]==1)
    {
        if(XP==X && YP<Y)
            dirP=3;
        else if(XP==X && YP>Y)
            dirP=4;
        else if(YP==Y && XP<X)
            dirP=2;
        else if(YP==Y && XP>X)
            dirP=1;
        else
            while(dirP==3)
                dirP=rand()%4+1;
    }
    else if(dirP==4 && MAP[XP][YP+1]==1)
    {
        if(XP==X && YP<Y)
            dirP=3;
        else if(XP==X && YP>Y)
            dirP=4;
        else if(YP==Y && XP<X)
            dirP=2;
        else if(YP==Y && XP>X)
            dirP=1;
        else
            while(dirP==4)
                dirP=rand()%4+1;
    }

    if(dirP==1 && MAP[XP-1][YP]!=1)
    {
        Pokey[XP][YP]=0;
        XP--;
        Pokey[XP][YP]=1;
    }
    else if(dirP==2 && MAP[XP+1][YP]!=1)
    {
        Pokey[XP][YP]=0;
        XP++;
        Pokey[XP][YP]=1;
    }
    else if(dirP==3 && MAP[XP][YP-1]!=1)
    {
        Pokey[XP][YP]=0;
        YP--;
        Pokey[XP][YP]=1;
    }
    else if(dirP==4 && MAP[XP][YP+1]!=1)
    {
        Pokey[XP][YP]=0;
        YP++;
        Pokey[XP][YP]=1;
    }
}

void SetUp()
{
    score=0;
    gameover=0;
    X=15;
    Y=8;
    XB=10;
    YB=8;
    dirB=1;
    XS=10;
    YS=8;
    dirS=1;
    XI=10;
    YI=8;
    dirI=1;
    XP=10;
    YP=8;
    dirP=1;
    n=0;
    PACMAN[X][Y]=1;
    Blinky[XB][YB]=1;
    Speedy[XS][YS]=1;
    Inky[XI][YI]=1;

}

void Art()
{
    system("CLS");

    cout<<endl;
    cout<<"Score: "<<score<<endl;
    cout<<endl;

    for(i=1; i<=20; i++)
    {
        for(j=1; j<=15; j++)
        {
            if(PACMAN[i][j]==1)
            {
                if(n%2==0)
                    cout<<'C';
                else
                    cout<<'O';
            }
            else if(anakinihavethehighground>0 && (Blinky[i][j]==1 || Speedy[i][j]==1 || Inky[i][j]==1 || Pokey[i][j]==1))
                cout<<'A';
            else if(Blinky[i][j]==1)
                cout<<'B';
            else if(Speedy[i][j]==1)
                cout<<'S';
            else if(Inky[i][j]==1)
                cout<<'I';
            else if(Pokey[i][j]==1)
                cout<<'P';
            else if(MAP[i][j]==1)
                cout<<(char)177;
            else if(MAP[i][j]==2)
                cout<<'.';
            else if(MAP[i][j]==3)
                cout<<'o';
            else if(MAP[i][j]==4)
                cout<<'-';
            else
                cout<<' ';
        }

        cout<<endl;
    }
    cout<<endl;
    if(anakinihavethehighground>0)
        cout<<anakinihavethehighground<<endl;
}

void Input()
{
    if(kbhit())
    {
        direction=getch();

        if(direction=='w')
            DIR=1;
        else if(direction=='s')
            DIR=2;
        else if(direction=='a')
            DIR=3;
        else if(direction=='d')
            DIR=4;
    }
}

void BigBrain()
{
    n++;
    if(anakinihavethehighground>0)
        anakinihavethehighground--;

    if(n%5==0)
    {
        if(DIR==1)
        {
            if(MAP[X-1][Y]!=1 && MAP[X-1][Y]!=4)
            {
                PACMAN[X][Y]=0;
                X--;
                PACMAN[X][Y]=1;
                if(MAP[X][Y]==3)
                    anakinihavethehighground=100;
                if(MAP[X][Y]!=0)
                    score++;
                MAP[X][Y]=0;
            }
        }
        else if(DIR==2)
        {
            if(MAP[X+1][Y]!=1 && MAP[X+1][Y]!=4)
            {
                PACMAN[X][Y]=0;
                X++;
                PACMAN[X][Y]=1;
                if(MAP[X][Y]==3)
                    anakinihavethehighground=100;
                if(MAP[X][Y]!=0)
                    score++;
                MAP[X][Y]=0;
            }
        }
        else if(DIR==3)
        {
            if(MAP[X][Y-1]!=1 && MAP[X][Y-1]!=4)
            {
                if(X==10 && Y==1)
                {
                    PACMAN[X][Y]=0;
                    Y=15;
                    PACMAN[X][Y]=1;
                }
                else
                {
                    PACMAN[X][Y]=0;
                    Y--;
                    PACMAN[X][Y]=1;
                    if(MAP[X][Y]==3)
                        anakinihavethehighground=100;
                    if(MAP[X][Y]!=0)
                        score++;
                    MAP[X][Y]=0;
                }
            }
        }
        else if(DIR==4)
        {
            if(MAP[X][Y+1]!=1 && MAP[X][Y+1]!=4)
            {
                if(X==10 && Y==15)
                {
                    PACMAN[X][Y]=0;
                    Y=1;
                    PACMAN[X][Y]=1;
                }
                else
                {
                    PACMAN[X][Y]=0;
                    Y++;
                    PACMAN[X][Y]=1;
                    if(MAP[X][Y]==3)
                        anakinihavethehighground=100;
                    if(MAP[X][Y]!=0)
                        score++;
                    MAP[X][Y]=0;
                }
            }
        }
    }

    if(n%7==0)
        Blink();
    else if(n%7==2)
        Speed();
    else if(n%7==4)
        Ink();
    else if(n%7==6)
        Poke();
}

void Check()
{
    if(anakinihavethehighground==0)
    {
        if(X==XB && Y==YB)
            gameover=1;
        if(X==XS && Y==YS)
            gameover=1;
        if(X==XI && Y==YI)
            gameover=1;
        if(X==XP && Y==YP)
            gameover=1;
    }else
    {
        if(X==XB && Y==YB)
        {
            Blinky[XB][YB]=0;
            XB=10;
            YB=8;
            Blinky[XB][YB]=1;
            score+=10;
        }
        if(X==XS && Y==YS)
        {
            Speedy[XS][YS]=0;
            XS=10;
            YS=8;
            Speedy[XS][YS]=1;
            score+=10;
        }
        if(X==XI && Y==YI)
        {
            Inky[XI][YI]=0;
            XI=10;
            YI=8;
            Inky[XI][YI]=1;
            score+=10;
        }
        if(X==XP && Y==YP)
        {
            Pokey[XP][YP]=0;
            XP=10;
            YP=8;
            Pokey[XP][YP]=1;
            score+=10;
        }
    }

    win=1;

    for(i=1; i<=20; i++)
        for(j=1; j<=15; j++)
            if(MAP[i][j]==2 || MAP[i][j]==3)
                win=0;
}

void WIN()
{
    system("CLS");

    cout<<endl;
    cout<<"YOU WON!"<<endl;
    cout<<endl;
}

void LOSE()
{
    system("CLS");

    cout<<endl;
    cout<<"GAME OVER"<<endl;
    cout<<endl;
}

int main()
{
    srand(time(0));
    SetUp();
    while(gameover==0)
    {
        Art();
        Input();
        BigBrain();
        Check();
        if(win==1)
        {
            WIN();
            return 0;
        }else if(gameover==1)
        {
            LOSE();
            return 0;
        }
        Sleep(10);
    }

    return 0;
}
