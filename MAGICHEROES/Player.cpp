#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(int layer, int HERO, int A1Lvl, int A2Lvl, int A3Lvl, int xi, int yi, Sprites s)
{
    Layer=layer;
    heronr=HERO;
    action="Standing";
    switch(HERO)
    {
    case 1:
        hero="Jack";
        maxhp=200+(A1Lvl-1)*10;
        hp=maxhp;
        ad=10+(A2Lvl-1)*3;
        fr=5;
        ap=50+(A3Lvl-1)*50;
        cd=3;
        speed=3;
        break;
    case 2:
        hero="Vix";
        maxhp=150+(A1Lvl-1)*10;
        hp=maxhp;
        ad=25+(A2Lvl-1)*10;
        fr=2;
        ap=0;
        cd=5-(A3Lvl-1)*1;
        speed=4;
        break;
    case 3:
        hero="Lara";
        maxhp=125+(A1Lvl-1)*10;
        hp=maxhp;
        ad=50+(A2Lvl-1)*20;
        fr=1;
        ap=50+(A3Lvl-1)*50;
        cd=10;
        speed=3;
        break;
    case 4:
        hero="Ella";
        maxhp=200+(A1Lvl-1)*10;
        hp=maxhp;
        ad=10+(A2Lvl-1)*3;
        fr=3;
        ap=25+(A3Lvl-1)*25;
        cd=20;
        speed=3;
        break;
    case 5:
        hero="Rodrigo";
        maxhp=300+(A1Lvl-1)*40;
        hp=maxhp;
        fr=2;
        ap=0;
        cd=12-(A3Lvl-1)*2;
        speed=2;
        break;
    case 6:
        hero="Dia";
        maxhp=200+(A1Lvl-1)*20;
        hp=maxhp;
        ad=5+(A2Lvl-1)*1;
        fr=10;
        ap=0;
        cd=12-(A3Lvl-1)*2;
        speed=3;
        break;
    case 7:
        hero="Pyke";
        break;
    }
    if(layer==3)
        direction=1;
    else
        direction=3;
    BMC=1;
    FTimer=0;
    ATimer=0;
    //Extract("Icons.txt", heronr, Icon);
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
            Icon[i][j]=s.Icons[heronr-1][i][j];
    /*for(i=0; i<=1; i++)
        for(j=1; j<=4; j++)
        {
            Extract(hero+"M"+(char)(i+48)+(char)(j+48)+".txt", i, j, Movement);
            Extract(hero+"F"+(char)(i+48)+(char)(j+48)+".txt", i, j, Firing);
            if(i==0)
                Extract(hero+"A"+(char)(j+48)+".txt", 0, j, Ability);
        }*/
    for(i=0; i<=1; i++)
        for(j=1; j<=4; j++)
            for(k=1; k<=15; k++)
                for(l=1; l<=15; l++)
                    Movement[i][j][k][l]=s.Heroes[heronr-1][0][i][j][k][l];
    for(i=0; i<=1; i++)
        for(j=1; j<=4; j++)
            for(k=1; k<=15; k++)
                for(l=1; l<=15; l++)
                    Firing[i][j][k][l]=s.Heroes[heronr-1][1][i][j][k][l];
    for(i=1; i<=4; i++)
        for(j=1; j<=15; j++)
            for(k=1; k<=15; k++)
                Ability[i][j][k]=s.Heroes[heronr-1][2][0][i][j][k];

    if(Firing[0][1][7][7]==0)
        Firing[0][1][7][7]=4;
    //MakeBig(Hero, Huge);
    x=xi;
    y=yi;
    for(i=1; i<=15; i++)
        for(j=1; j<=15; j++)
            Current[i][j]=Firing[0][1][i][j];
    MakeHitbox(1, Current, Hitbox);

    for(i=1; i<=15; i++)
        for(j=1; j<=15; j++)
        {
            Art[layer][x+i-1][y+j-1]=Current[i][j];
            HtB[layer][x+i-1][y+j-1]=Hitbox[i][j];
        }
}

void Player::Move(char ch)
{
    if(ch=='d' || ch=='l')
    {
        if(direction==1)
        {
            action="Moving";
            if(BMC==1)
                BMC=0;
            else
                BMC=1;
            for(i=1; i<=15; i++)
                for(j=1; j<=15; j++)
                    Current[i][j]=Movement[BMC][direction][i][j];
        }
        else
        {
            direction=1;
            BMC=0;

            if(action=="Moving")
            {
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        Current[i][j]=Movement[BMC][direction][i][j];
            }
            else if(action=="Shooting")
            {
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        Current[i][j]=Firing[0][direction][i][j];
            }
        }
    }
    else if(ch=='s' || ch=='k')
    {
        if(direction==2)
        {
            action="Moving";
            if(BMC==1)
                BMC=0;
            else
                BMC=1;
            for(i=1; i<=15; i++)
                for(j=1; j<=15; j++)
                    Current[i][j]=Movement[BMC][direction][i][j];
        }
        else
        {
            direction=2;
            BMC=0;

            if(action=="Moving")
            {
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        Current[i][j]=Movement[BMC][direction][i][j];
            }
            else if(action=="Shooting")
            {
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        Current[i][j]=Firing[0][direction][i][j];
            }
        }
    }
    else if(ch=='a' || ch=='j')
    {
        if(direction==3)
        {
            action="Moving";
            if(BMC==1)
                BMC=0;
            else
                BMC=1;
            for(i=1; i<=15; i++)
                for(j=1; j<=15; j++)
                    Current[i][j]=Movement[BMC][direction][i][j];
        }
        else
        {
            direction=3;
            BMC=0;

            if(action=="Moving")
            {
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        Current[i][j]=Movement[BMC][direction][i][j];
            }
            else if(action=="Shooting")
            {
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        Current[i][j]=Firing[0][direction][i][j];
            }
        }
    }
    else if(ch=='w' || ch=='i')
    {
        if(direction==4)
        {
            action="Moving";
            if(BMC==1)
                BMC=0;
            else
                BMC=1;
            for(i=1; i<=15; i++)
                for(j=1; j<=15; j++)
                    Current[i][j]=Movement[BMC][direction][i][j];
        }
        else
        {
            direction=4;
            BMC=0;

            if(action=="Moving")
            {
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        Current[i][j]=Movement[BMC][direction][i][j];
            }
            else if(action=="Shooting")
            {
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        Current[i][j]=Firing[0][direction][i][j];
            }
        }
    }
}

void Player::Shoot()
{
    action="Shooting";
    OutOfCombatCont=0;
    FTimer=10/fr;
    for(i=1; i<=15; i++)
        for(j=1; j<=15; j++)
            Current[i][j]=Firing[1][direction][i][j];
}

void Player::Reconstruct()
{
    MakeHitbox(1, Current, Hitbox);
    for(i=1; i<=15; i++)
        for(j=1; j<=15; j++)
        {
            Art[Layer][x+i-1][y+j-1]=Current[i][j];
            HtB[Layer][x+i-1][y+j-1]=Hitbox[i][j];
        }
    /*switch(heronr)
    {
    case 1:
        speed=3;
        break;
    case 2:
        speed=4;
        break;
    case 3:
        speed=3;
        break;
    case 4:
        speed=3;
        break;
    case 5:
        speed=2;
        break;
    case 6:
        speed=4;
        break;
    }*/
}
