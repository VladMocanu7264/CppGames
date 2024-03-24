#include <iostream>
#include <windows.h>
#include "Paleta.h"
#include "Art.h"
#include "Ball.h"

using namespace std;

int score1, score2;
int Screen[17][42];
void Reset();

Paleta P1(1);
Paleta P2(2);
Ball B;
Art S;
int inp;
int px, py;

int main()
{
    int n=0, nr=50;

    while(true)
    {
        if(score1<5 && score2<5)
        {
            S.Draw();

            if(B.y()==2)
            {
                score2++;
                Reset();
                S.Draw();
                Sleep(200);
                nr=0;
            }
            else if(B.y()==39)
            {
                score1++;
                Reset();
                S.Draw();
                Sleep(200);
                nr=0;
            }

            n++;

            inp=S.Imput();
            if(inp==2 || inp==3)
            {
                P1.Move(inp%2);
                S.PChanges(P1.x(),P1.y());
            }
            else if(inp==4 || inp==5)
            {
                P2.Move(inp%2);
                S.PChanges(P2.x(),P2.y());
            }

            px=B.x();
            py=B.y();
            B.Move();
            S.BChanges(px, py, B.x(), B.y());

            if(n%10==0)
                nr--;

            if(nr<10)
                nr=10;

            Sleep(nr);
        }
        else
        {
            S.Draw();

            if(score1==5)
                cout<<"Player 1 won!"<<endl;
            else
                cout<<"Player 2 won!"<<endl;

            break;
        }
    }

    return 0;
}

void Reset()
{
    S.BChanges(B.x(), B.y(), 8, 21);
    S.PChanges(6, 4);
    S.PChanges(6, 38);
    P1.R(1);
    P2.R(2);
    B.r();
}
