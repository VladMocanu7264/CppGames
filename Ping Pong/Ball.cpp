#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Ball.h"

using namespace std;

extern int Screen[17][42];

Ball::Ball()
{
    xb=8;
    yb=21;
    dir=4;
}

void Ball::Ricochet()
{
    if(Screen[xb+1][yb]==1)
    {
        if(dir==2)
            dir+=2;
        else
            dir-=2;
    }
    else if(Screen[xb-1][yb]==1)
    {
        if(dir==8)
            dir+=2;
        else
            dir-=2;
    }
    else if(Screen[xb][yb-1]>0)
    {
        if(Screen[xb][yb-1]==1)
            dir=8;
        else
            dir=2;
    }
    else if(Screen[xb][yb+1]>0)
    {
        if(Screen[xb][yb+1]==1)
            dir=6;
        else
            dir=4;
    }
}

void Ball::Move()
{
    Ricochet();

    if(dir>8)
        dir-=8;

    if(Screen[Movex(dir)][Movey(dir)]>0)
    {
        dir+=4;
    }

    if(dir>8)
        dir-=8;

    xb=Movex(dir);
    yb=Movey(dir);
}

int Ball::Movex(int direction)
{
    switch(direction)
    {
    case 1:
        return xb;
        break;
    case 2:
        return xb+1;
        break;
    case 3:
        return xb+1;
        break;
    case 4:
        return xb+1;
        break;
    case 5:
        return xb;
        break;
    case 6:
        return xb-1;
        break;
    case 7:
        return xb-1;
        break;
    case 8:
        return xb-1;
        break;
    default:
        return xb;
    }
}

int Ball::Movey(int direction)
{
    switch(direction)
    {
    case 1:
        return yb+1;
        break;
    case 2:
        return yb+1;
        break;
    case 3:
        return yb;
        break;
    case 4:
        return yb-1;
        break;
    case 5:
        return yb-1;
        break;
    case 6:
        return yb-1;
        break;
    case 7:
        return yb;
        break;
    case 8:
        return yb+1;
        break;
    default:
        return yb;
    }
}

void Ball::r()
{
    xb=8;
    yb=21;

    srand(time(0));

    dir=2*rand()%4;
}

int Ball::x()
{return xb;}

int Ball::y()
{return yb;}
