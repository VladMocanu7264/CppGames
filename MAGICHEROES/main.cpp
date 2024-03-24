#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include "Enemy.h"
#include "FileManaging.h"
#include "Sprites.h"
#include "Level.h"
#include "Player.h"
#include "Projectile.h"

using namespace std;

const int nrduels=1;
void Gamemode_Duel(Sprites s);

void ScreenAdjustment();
int PassTime(int timer);
void Explode();
void ChooseCharacter(int player, int select, bool locked, Sprites s);

short int Art[5][61][201];
short int HtB[5][61][201];
int NrProjectiles;
int TICKS=0;
int i, j;
char inp;
int ScrLen, ScrHei;

Projectile Bullet[1001];

int main()
{
    ///SetUp
    ios_base::sync_with_stdio(false);
    srand(time(0));
    cout<<"Loading...";
    Sprites S;
    S.ExtractGraphics(3);
    ScrHei=60;
    ScrLen=200;
    //ScreenAdjustment();
    ///Game_mode: DUEL
    Gamemode_Duel(S);

    return 0;
}

void Gamemode_Duel(Sprites s)
{
    int set1=1, set2=1;
    bool lock1=0, lock2=0;
    while(true)
    {
        system("CLS");
        ChooseCharacter(1, set1, lock1, s);
        ChooseCharacter(2, set2, lock2, s);

        if(kbhit())
        {
            inp=getch();
            switch(inp)
            {
            case 'a':
                if(lock1==0)
                {
                    set1--;
                    if(set1<1)
                        set1=6;
                }
                break;
            case 'd':
                if(lock1==0)
                {
                    set1++;
                    if(set1>6)
                        set1=1;
                }
                break;
            case 'w':
                lock1=1;
                break;
            case 'j':
                if(lock2==0)
                {
                    set2--;
                    if(set2<1)
                        set2=6;
                }
                break;
            case 'l':
                if(lock2==0)
                {
                    set2++;
                    if(set2>6)
                        set2=1;
                }
                break;
            case 'i':
                lock2=1;
                break;
            }
        }

        if(lock1==1 && lock2==1)
            break;
    }

    Level Duel;
    Duel.ExtractMap(/*rand()%3+1*/3, s);
    Player P1(3, set1, 6, 6, 3, Duel.spawn1x, Duel.spawn1y, s);
    Player P2(1, set2, 6, 6, 3, Duel.spawn2x, Duel.spawn2y, s);
    Duel.MakeInterface(P1.maxhp, P1.Icon, P2.maxhp, P2.Icon);

    while(true)
    {
        if(TICKS%10==0)///10
        {
            ///Timers
            P1.FTimer=PassTime(P1.FTimer);
            P1.ATimer=PassTime(P1.ATimer);
            if(P1.ATimer==0)P2.HBL=0;
            if(P1.FTimer==1)P2.HBV=0;
            P2.FTimer=PassTime(P2.FTimer);
            P2.ATimer=PassTime(P2.ATimer);
            if(P2.ATimer==0)P1.HBL=0;
            if(P2.FTimer==1)P1.HBV=0;
            ///Screen show
            Duel.InterfaceUpdate(P1.ATimer, P1.cd*10, P1.hp, P1.maxhp, P2.ATimer, P2.cd*10, P2.hp, P2.maxhp);
            Duel.Screen(P1.hp, P2.hp);


            if(P1.action!="Using Ability")
            {
                P1.action="Shooting";
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        P1.Current[i][j]=P1.Firing[0][P1.direction][i][j];
            }
            if(P2.action!="Using Ability")
            {
                P2.action="Shooting";
                for(i=1; i<=15; i++)
                    for(j=1; j<=15; j++)
                        P2.Current[i][j]=P2.Firing[0][P2.direction][i][j];
            }

            ///Extra Hero Specific Ability Update (Vix, Jack)
            if(P1.heronr==2)
            {
                if(P1.ATimer>P1.cd*10-10)
                {
                    P1.Shadowed=1;
                    P1.locked=1;
                    P1.speed=10;
                    switch(P1.direction)
                    {
                    case 1:
                        P1.Move('d');
                        break;
                    case 2:
                        P1.Move('s');
                        break;
                    case 3:
                        P1.Move('a');
                        break;
                    case 4:
                        P1.Move('w');
                        break;
                    }
                    for(i=1; i<=15; i++)
                        for(j=1; j<=15; j++)
                            s.Ghost(P1.Current);
                }
                else
                {
                    P1.locked=0;
                    P1.Shadowed=0;
                }
            }
            else if(P1.heronr==1)
            {
                if(P1.OutOfCombatCont>30)
                    P1.speed=5;
                else
                    P1.speed=3;
            }

            if(P2.heronr==2)
            {
                if(P2.ATimer>P2.cd*10-10)
                {
                    P2.Shadowed=1;
                    P2.locked=1;
                    P2.speed=10;
                    switch(P2.direction)
                    {
                    case 1:
                        P2.Move('d');
                        break;
                    case 2:
                        P2.Move('s');
                        break;
                    case 3:
                        P2.Move('a');
                        break;
                    case 4:
                        P2.Move('w');
                        break;
                    }
                    for(i=1; i<=15; i++)
                        for(j=1; j<=15; j++)
                            s.Ghost(P2.Current);
                }
                else
                {
                    P2.locked=0;
                    P2.Shadowed=0;
                }
            }
            else if(P2.heronr==1)
            {
                if(P2.OutOfCombatCont>30)
                    P2.speed=5;
                else
                    P2.speed=3;
            }

            ///Input
            if(_kbhit())
            {
                inp=getch();

                if((inp=='w' || inp=='s' || inp=='a' || inp=='d') && P1.locked==0)
                    P1.Move(inp);
                else if(inp=='e' && P1.locked==0)
                {
                    if(P1.FTimer==0)
                    {
                        Bullet[++NrProjectiles].SetUp(4, 10+P1.heronr, P1.ad, P1.x, P1.y, P1.direction);
                        P1.Shoot();
                    }
                }
                else if(inp=='q' && P1.locked==0)
                {
                    if(P1.ATimer==0)
                    {
                        P1.ATimer=P1.cd*10;
                        switch(P1.heronr)
                        {
                        case 1:
                            P1.action="Using Ability";
                            Bullet[++NrProjectiles].SetUp(4, 21, P1.ap, P1.x, P1.y, P1.direction);
                            for(i=1; i<=15; i++)
                                for(j=1; j<=15; j++)
                                    P1.Current[i][j]=P1.Ability[P1.direction][i][j];
                        case 2:
                            ///done
                            break;
                        case 3:
                            P1.action="Using Ability";
                            Bullet[++NrProjectiles].SetUp(4, 23, P1.ap, P1.x, P1.y, P1.direction);
                            for(i=1; i<=15; i++)
                                for(j=1; j<=15; j++)
                                    P1.Current[i][j]=P1.Ability[P1.direction][i][j];
                            break;
                        }
                    }
                }
                else if(inp=='z') P1.hp-=5;
                else if(inp=='c') P1.hp+=5;

                if((inp=='i' || inp=='k' || inp=='j' || inp=='l'))
                        P2.Move(inp);
                else if(inp=='u')
                {
                    if(P2.FTimer==0)
                    {
                        Bullet[++NrProjectiles].SetUp(2, 10+P2.heronr, P2.ad, P2.x, P2.y, P2.direction);
                        P2.Shoot();
                    }
                }
                else if(inp=='o')
                {
                    P2.action="Using Ability";
                    if(P2.ATimer==0)
                    {
                        P2.ATimer=P2.cd*10;
                        switch(P2.heronr)
                        {
                        case 1:
                            P2.action="Using Ability";
                            Bullet[++NrProjectiles].SetUp(2, 21, P2.ap, P2.x, P2.y, P2.direction);
                            for(i=1; i<=15; i++)
                                for(j=1; j<=15; j++)
                                    P2.Current[i][j]=P2.Ability[P2.direction][i][j];
                        case 2:
                            ///done
                            break;
                        case 3:
                            Bullet[++NrProjectiles].SetUp(2, 23, P2.ap, P2.x, P2.y, P2.direction);
                            for(i=1; i<=15; i++)
                                for(j=1; j<=15; j++)
                                    P2.Current[i][j]=P2.Ability[P2.direction][i][j];
                            break;
                        }
                    }
                }
                else if(inp=='m') P2.hp-=5;
                else if(inp=='.') P2.hp+=5;
            }
        } ///~10
        ///1

        ///Deconstruction
        for(i=1; i<=60; i++)
            for(j=1; j<=200; j++)
            {
                Art[1][i][j]=0;
                Art[2][i][j]=0;
                Art[3][i][j]=0;
                Art[4][i][j]=0;
                HtB[1][i][j]=0;
                HtB[2][i][j]=0;
                HtB[3][i][j]=0;
                HtB[4][i][j]=0;
            }

        ///Moving algorithm + Vix speed reset
        if(P1.action=="Moving" && TICKS%(10/P1.speed)==0 && P1.LockDirection[P1.direction]==0)
        {
            switch(P1.direction)
            {
            case 1:
                P1.y++;
                break;
            case 2:
                P1.x++;
                break;
            case 3:
                P1.y--;
                break;
            case 4:
                P1.x--;
                break;
            }
            if(P1.x<-4)
                P1.x=-4;
            if(P1.y<1)
                P1.y=1;
            if(P1.x>45)
                P1.x=45;
            if(P1.y>185)
                P1.y=185;
        }
        if(P1.heronr==2 && P1.ATimer<=P1.cd*10-10)
            P1.speed=4;

        if(P2.action=="Moving" && TICKS%(10/P2.speed)==0 && P2.LockDirection[P2.direction]==0)
        {
            switch(P2.direction)
            {
            case 1:
                P2.y++;
                break;
            case 2:
                P2.x++;
                break;
            case 3:
                P2.y--;
                break;
            case 4:
                P2.x--;
                break;
            }
            if(P2.x<-4)
                P2.x=-4;
            if(P2.y<1)
                P2.y=1;
            if(P2.x>45)
                P2.x=45;
            if(P2.y>185)
                P2.y=185;
        }
        if(P2.heronr==2 && P2.ATimer<=P2.cd*10-10)
            P2.speed=4;

        ///Reconstruction and projectile movement
        P1.Reconstruct();
        P2.Reconstruct();

        for(i=1; i<=NrProjectiles; i++)
            if(Bullet[i].existence==1)
            {
                if(Bullet[i].spd<=10 && TICKS%(10/Bullet[i].spd)==0)
                    Bullet[i].ProjectileUpdate();
                else if(Bullet[i].spd>10)
                    Bullet[i].FastProjectileUpdate();

                Bullet[i].Reconstruct(i);
            }

        ///Impact Checking
        for(i=1; i<=60; i++)
            for(j=1; j<=200; j++)
            {
                if(Art[0][i][j]!=0)///wall
                {
                    if(HtB[2][i][j]!=0 && Bullet[HtB[2][i][j]].Type!=23)
                        Bullet[HtB[2][i][j]].DestroyObject();
                    if(HtB[4][i][j]!=0 && Bullet[HtB[4][i][j]].Type!=23)
                        Bullet[HtB[4][i][j]].DestroyObject();
                }
                else if(HtB[3][i][j]!=0 && HtB[2][i][j]!=0)///P1 hit
                {
                    if((Bullet[HtB[2][i][j]].Type!=23 || P1.HBL==0)&&(Bullet[HtB[2][i][j]].Type!=12 || P1.HBV==0)&&P1.Shadowed==0)
                    {
                        P1.hp-=Bullet[HtB[2][i][j]].dmg;
                        Bullet[HtB[2][i][j]].contenemies--;
                        if(Bullet[HtB[2][i][j]].Type==23) P1.HBL=1;
                        if(Bullet[HtB[2][i][j]].Type==12) P1.HBV=1;
                        if(Bullet[HtB[2][i][j]].Type==12) P2.hp+=(P2.ad/2);
                    }
                    if(Bullet[HtB[2][i][j]].contenemies==0)
                        Bullet[HtB[2][i][j]].DestroyObject();
                }
                else if(HtB[1][i][j]!=0 && HtB[4][i][j]!=0)///P2 hit
                {
                    if((Bullet[HtB[4][i][j]].Type!=23 || P2.HBL==0)&&(Bullet[HtB[4][i][j]].Type!=12 || P2.HBV==0)&&P2.Shadowed==0)
                    {
                        P2.hp-=Bullet[HtB[4][i][j]].dmg;
                        Bullet[HtB[4][i][j]].contenemies--;
                        if(Bullet[HtB[4][i][j]].Type==23) P2.HBL=1;
                        if(Bullet[HtB[4][i][j]].Type==12) P2.HBV=1;
                        if(Bullet[HtB[4][i][j]].Type==12) P1.hp+=P1.ad/2;
                    }
                    if(Bullet[HtB[4][i][j]].contenemies==0)
                        Bullet[HtB[4][i][j]].DestroyObject();
                }
            }

        ///Player collision with objects
        for(i=1; i<=4; i++)
            P1.LockDirection[i]=0;
        for(i=1; i<=13; i++)
        {
            if(Art[0][P1.x+i+2][P1.y+13]!=0)
                P1.LockDirection[1]=1;
            if(Art[0][P1.x+i+2][P1.y]!=0)
                P1.LockDirection[3]=1;
        }
        for(i=1; i<=15; i++)
        {
            if(Art[0][P1.x+15][P1.y+i-1]!=0)
                P1.LockDirection[2]=1;
            if(Art[0][P1.x+3][P1.y+i-1]!=0)
                P1.LockDirection[4]=1;
        }

        for(i=1; i<=4; i++)
            P2.LockDirection[i]=0;
        for(i=1; i<=13; i++)
        {
            if(Art[0][P2.x+i+2][P2.y+13]!=0)
                P2.LockDirection[1]=1;
            if(Art[0][P2.x+i+2][P2.y]!=0)
                P2.LockDirection[3]=1;
        }
        for(i=1; i<=15; i++)
        {
            if(Art[0][P2.x+15][P2.y+i-1]!=0)
                P2.LockDirection[2]=1;
            if(Art[0][P2.x+3][P2.y+i-1]!=0)
                P2.LockDirection[4]=1;
        }

        ///Resets and Timers
        if(P1.hp<0) P1.hp=0;
        if(P1.hp>P1.maxhp)P1.hp=P1.maxhp;
        if(P2.hp<0) P2.hp=0;
        if(P2.hp>P2.maxhp)P2.hp=P2.maxhp;

        P1.OutOfCombatCont++;
        P2.OutOfCombatCont++;
        TICKS++;
        if(TICKS==100000)
            TICKS=0;
        //Sleep(1);
        ///~1
    }
}

void ScreenAdjustment()
{
    int ok=0;
    while(ok==0)
    {
        system("CLS");
        cout<<(char)218;
        for(j=1; j<=ScrLen; j++)
            cout<<(char)196;
        cout<<(char)191<<endl;
        for(i=1; i<=ScrHei; i++)
        {
            cout<<(char)179;
            for(j=1; j<=ScrLen; j++)
            {
                if(i==1 && j==1)
                {
                    cout<<"Adjust the outer rectangle until it fits the screen using the A and D keys. When the rectangle fits your screen press W to lock.";
                    j=128;
                }
                else
                    cout<<" ";
            }
            cout<<(char)179<<endl;
        }
        cout<<(char)192;
        for(j=1; j<=ScrLen; j++)
            cout<<(char)196;
        cout<<(char)217<<endl;

        if(kbhit())
        {
            inp=getch();
            switch(inp)
            {
            case 'a':
                ScrLen-=10;
                ScrHei-=3;
                break;
            case 'd':
                ScrLen+=10;
                ScrHei+=3;
                break;
            case 'w':
                ok=1;
                break;
            }
        }

        if(ScrHei>60)
            ScrHei=60;
        if(ScrLen>200)
            ScrLen=200;
        if(ScrHei<30)
            ScrHei=30;
        if(ScrLen<100)
            ScrLen=100;
    }
}

int PassTime(int timer)
{
    timer--;
    if(timer<0)
        timer=0;
    return timer;
}

void Explode()
{

}

void ChooseCharacter(int player, int select, bool locked, Sprites s)
{
    cout<<endl<<" Player "<<player<<endl;

    for(i=1; i<=10; i++)
    {
        for(j=1; j<=60; j++)
        {
            if(i==1)
            {
                if(j==(select-1)*10+1)
                {
                    if(locked==0)
                        cout<<(char)218;
                    else
                        cout<<(char)201;
                }
                else if(j==select*10)
                {
                    if(locked==0)
                        cout<<(char)191;
                    else
                        cout<<(char)187;
                }
                else if((j>(select-1)*10+1)&&(j<select*10))
                {
                    if(locked==0)
                        cout<<(char)196;
                    else
                        cout<<(char)205;
                }
                else
                    cout<<" ";
            }
            else if(i==10)
            {
                if(j==(select-1)*10+1)
                {
                    if(locked==0)
                        cout<<(char)192;
                    else
                        cout<<(char)200;
                }
                else if(j==select*10)
                {
                    if(locked==0)
                        cout<<(char)217;
                    else
                        cout<<(char)188;
                }
                else if((j>(select-1)*10+1)&&(j<select*10))
                {
                    if(locked==0)
                        cout<<(char)196;
                    else
                        cout<<(char)205;
                }
                else
                    cout<<" ";
            }
            else
            {
                if(j==(select-1)*10+1 || j==select*10)
                {
                    if(locked==0)
                        cout<<(char)179;
                    else
                        cout<<(char)186;
                }
                else
                {
                    if(j%10==0 || j%10==1)
                        cout<<" ";
                    else if(s.Icons[j/10][i-2][j%10-2]==0)
                        cout<<" ";
                    else
                        cout<<(char)219;
                }
            }
        }

        cout<<endl;
    }

    for(i=1; i<=11; i++)
    {
        for(j=1; j<=15; j++)
            cout<<s.Symbol(s.Heroes[select-1][1][0][1][i+4][j]);

        cout<<"   ";
        switch(select)
        {
        case 1:///Jack
            switch(i)
            {
            case 1:
                cout<<"JACK";
                break;
            case 2:
                cout<<"Class: Soldier";
                break;
            case 4:
                cout<<"Passive: Jack will sprint while out of combat";
                break;
            case 5:
                cout<<"Ability: Jack throws a grenade in a straight line";
                break;
            }
            break;

        case 2:///Vix
            switch(i)
            {
            case 1:
                cout<<"VIX";
                break;
            case 2:
                cout<<"Class: Assassin";
                break;
            case 4:
                cout<<"Passive: Vix heals for 50% of damage done";
                break;
            case 5:
                cout<<"Ability: Vix dashes, becoming untargetable";
                break;
            }
            break;

        case 3:///Lara
            switch(i)
            {
            case 1:
                cout<<"LARA";
                break;
            case 2:
                cout<<"Class: Sniper";
                break;
            case 4:
                cout<<"Passive: Lara has a 25% crit chance";
                break;
            case 5:
                cout<<"Ability: Lara shoots a massive projectile";
                break;
            }
            break;

        case 4:///Ella
            switch(i)
            {
            case 1:
                cout<<"Ella";
                break;
            case 2:
                cout<<"Class: Mage";
                break;
            case 4:
                cout<<"Passive: Ella's attacks pierce enemies";
                break;
            case 5:
                cout<<"Ability: WORK IN PROGRESS";
                break;
            }
            break;
        }
        cout<<endl;
    }
}
