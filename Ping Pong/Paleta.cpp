#include <iostream>
#include "Paleta.h"
#include "Art.h"

using namespace std;

extern int score1, score2;

Paleta::Paleta(int a)
{
    if(a==1)
        yp=4;
    else
        yp=38;

    xp=6;
    score1=0;
    score2=0;
}

void Paleta::Move(int b)
{
    if(b==0 && xp>2)
        xp--;
    else if(b==1 && xp<10)
        xp++;
}

void Paleta::R(int a)
{
    xp=6;

    if(a==1)
        yp=4;
    else
        yp=38;
}

int Paleta::x()
{return xp;}

int Paleta::y()
{return yp;}


