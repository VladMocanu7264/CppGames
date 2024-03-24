#include <cstdlib>
#include <time.h>
#include <algorithm>
#include "Projectile.h"

using namespace std;

void Projectile::SetUp(int layer, int type, int attackdamage, int xi, int yi, int direction)
{
    srand(time(0));
    Layer=layer;
    existence=1;
    Type=type;
    dir=direction;
    range=0;
    if(type==14)
        contenemies=3;
    else if(type==23 || type==12 || type==15)
        contenemies=10;
    else
        contenemies=1;
    dmg=attackdamage;
    x=xi;
    y=yi;

    switch(type)
    {
    case 11:
        ///Jack bullet
        Max=1;
        Appearance[1][1]=9;
        spd=10;
        maxrange=200;
        switch(dir)
        {
        case 1:
            x=xi+10;
            y=yi+10;
            break;
        case 2:
            x=xi+5;
            y=yi+7;
            break;
        case 3:
            x=xi+10;
            break;
        case 4:
            x=xi+10;
            y=yi+8;
            break;
        }
        break;
    case 21:
        ///Jack grenade
        Max=2;
        Appearance[1][1]=7;
        Appearance[2][1]=7;
        Appearance[1][2]=8;
        Appearance[2][2]=4;
        spd=5;
        maxrange=100;
        switch(dir)
        {
        case 1:
            x=xi+5;
            y=yi+8;
            break;
        case 2:
            x=xi+7;
            y=yi+2;
            break;
        case 3:
            x=xi+5;
            y=yi+4;
            break;
        case 4:
            x=xi+7;
            y=yi+2;
            break;
        }
        break;
    case 12:
        ///Vix blades
        Max=5;
        for(i=1; i<=Max; i++)
            for(j=1; j<=Max; j++)
            {
                if(i==1)
                    Appearance[i][j]=4;
                else
                    Appearance[i][j]=0;
            }
        spd=3;
        maxrange=4;
        switch(dir)
        {
        case 1:
            x=xi+8;
            y=yi+12;
            break;
        case 2:
            x=xi+10;
            y=yi+3;
            break;
        case 3:
            x=xi+8;
            y=yi-2;
            break;
        case 4:
            x=xi+3;
            y=yi+4;
            break;
        }
        break;
    case 13:
        ///Lara bullet
        if(rand()%4==0)
            dmg*=2;
        Max=2;
        Appearance[1][1]=9;
        Appearance[1][2]=9;
        Appearance[2][1]=0;
        Appearance[2][2]=0;
        spd=20;
        maxrange=200;
        switch(dir)
        {
        case 1:
            x=xi+9;
            y=yi+14;
            break;
        case 2:
            x=xi+14;
            y=yi+6;
            break;
        case 3:
            x=xi+9;
            y=yi;
            break;
        case 4:
            x=xi+2;
            y=yi+9;
            break;
        }
        break;
    case 23:
        ///Lara ult
        Max=10;
        for(i=1; i<=Max/2; i++)
            for(j=1; j<=Max; j++)
            {
                if(j<i || j>i+5)
                    Appearance[i][j]=Appearance[Max-i+1][j]=0;
                else if(j==i)
                    Appearance[i][j]=Appearance[Max-i+1][j]=1;
                else if(j==i+1)
                    Appearance[i][j]=Appearance[Max-i+1][j]=2;
                else
                    Appearance[i][j]=Appearance[Max-i+1][j]=3;
            }
        spd=10;
        maxrange=200;
        switch(dir)
        {
        case 1:
            x=xi+4;
            y=yi+14;
            break;
        case 2:
            x=xi+14;
            y=yi+3;
            break;
        case 3:
            x=xi+4;
            y=yi;
            break;
        case 4:
            x=xi+2;
            y=yi+6;
            break;
        }
        break;
    case 14:
        ///Ella magic
        Max=3;
        for(i=1; i<=3; i++)
        {
            Appearance[i][1]=1;
            Appearance[i][2]=1;
            Appearance[i][3]=0;
            if(i==2)
            {
                Appearance[i][3]=2;
                Appearance[i][1]=0;
            }
        }
        spd=7;
        maxrange=200;
    case 24:
        ///Ella Potion
        break;
    case 15:
        ///Rodrigo sword
        break;
    case 16:
        ///Dia magic
        break;
    }

    if(Type!=21)
        Rotate(dir);
}

void Projectile::ProjectileUpdate()
{
    if(range<=maxrange)
    {
        range++;
        switch(dir)
        {
        case 1:
            y++;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            x--;
            break;
        }
    }
    else
        DestroyObject();

    if(x<1 || y<1 || x>60-Max || y>200-Max)
        DestroyObject();
}

void Projectile::FastProjectileUpdate()
{
    if(range<=maxrange)
    {
        range+=spd/10;
        switch(dir)
        {
        case 1:
            y+=spd/10;
            break;
        case 2:
            x+=spd/10;
            break;
        case 3:
            y-=spd/10;
            break;
        case 4:
            x-=spd/10;
            break;
        }
    }
    else
        DestroyObject();

    if(x<1 || y<1 || x>60-Max || y>200-Max)
        DestroyObject();
}

void Projectile::DestroyObject()
{
    existence=0;
    for(i=1; i<=Max; i++)
        for(j=1; j<=Max; j++)
        {
            Art[Layer][x+i-1][y+j-1]=0;
            HtB[Layer][x+i-1][y+j-1]=0;
        }

    if(Type==21)
        Explode();
}

void Projectile::Rotate(int integer)
{
    int Matrice[11][11];

    switch(integer)
    {
    case 1:
        ///everything's fine
        break;
    case 2:
        for(j=1; j<=Max; j++)
            for(i=Max; i>=1; i--)
                Matrice[i][j]=Appearance[j][i];
        break;
    case 3:
        for(i=1; i<=Max; i++)
            for(j=1; j<=Max; j++)
                Matrice[i][j]=Appearance[i][Max-j+1];
        break;
    case 4:
        for(j=1; j<=Max; j++)
            for(i=Max; i>=1; i--)
                Matrice[i][j]=Appearance[j][Max-i+1];
        break;
    }

    if(integer!=1)
        for(i=1; i<=Max; i++)
            for(j=1; j<=Max; j++)
            {
                if(Matrice[i][j]==9 && integer!=3)
                    Appearance[i][j]=4;
                else
                    Appearance[i][j]=Matrice[i][j];
            }
}

void Projectile::Reconstruct(int id)
{
    for(i=1; i<=Max; i++)
        for(j=1; j<=Max; j++)
        {
            if(Art[Layer][x+i-1][y+j-1]==0)
                Art[Layer][x+i-1][y+j-1]=Appearance[i][j];
            if(HtB[Layer][x+i-1][y+j-1]==0 && Appearance[i][j]!=0)
                HtB[Layer][x+i-1][y+j-1]=id;
        }
}
