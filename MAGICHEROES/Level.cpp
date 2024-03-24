#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Level.h"

using namespace std;

/*void Level::GetDuelNrAndMap(int number)
{
    completed=0;
    string file="Duel.txt";
    string nr;
    nr=number+49;
    file.insert(4, nr);
    ExtractMap(file);
    Map=nr;
}*/

/*void Level::GetCustom(string custom)
{
    ExtractMap(custom+".txt");
    Map=custom;
}*/

void Level::ExtractMap(/*string file_name*/int duelnr, Sprites s)
{
    /*fstream fstr(file_name.c_str());
    string line;
    unsigned int spawn[4], cont=0;
    for(i=0; i<4; i++)
        spawn[i]=0;
    if(fstr.is_open())
    {
        getline(fstr, line);
        for(i=0; (unsigned)i<line.length(); i++)
        {
            if(line[i]==' ')
                cont++;
            else
                spawn[cont]=spawn[cont]*10+(line[i]-48);
        }
        spawn1x=spawn[0];
        spawn1y=spawn[1];
        spawn2x=spawn[2];
        spawn2y=spawn[3];

        for(i=1; i<=60; i++)
        {
            getline(fstr, line);
            for(j=0; j<200; j++)
                Art[0][i][j+1]=line[j]-48;
        }
        fstr.close();
    }
    else
        Art[0][1][1]=4;*/
    for(i=1; i<=60; i++)
        for(j=1; j<=200; j++)
            Art[0][i][j]=s.DuelMaps[duelnr-1][i][j];
    spawn1x=s.Spawns[duelnr-1][0];
    spawn1y=s.Spawns[duelnr-1][1];
    spawn2x=s.Spawns[duelnr-1][2];
    spawn2y=s.Spawns[duelnr-1][3];
}

void Level::Screen(int HP1, int HP2)
{
    system("CLS");
    cout<<(char)218;
    for(j=1; j<=200; j++)
        cout<<(char)196;
    cout<<(char)191<<endl;
    for(i=1; i<=60; i++)
    {
        cout<<(char)179;
        for(j=1; j<=200; j++)
        {
            if(i==60 && ((j>=10 && j<=12) || (j>=189 && j<=191)))
            {
                switch(j)
                {
                case 10:
                    if(HP1/100==0) cout<<" ";
                    else cout<<HP1/100;
                    break;
                case 11:
                    if((HP1/10)%10==0 && HP1/100==0) cout<<" ";
                    else cout<<(HP1/10)%10;
                    break;
                case 12:
                    cout<<HP1%10;
                    break;
                case 189:
                    if(HP2/100==0) cout<<" ";
                    else cout<<HP2/100;
                    break;
                case 190:
                    if((HP2/10)%10==0 && HP2/100==0) cout<<" ";
                    else cout<<(HP2/10)%10;
                    break;
                case 191:
                    cout<<HP2%10;
                    break;
                }
            }
            else if(Interface[i][j]!=0)
            {
                if(Interface[i][j]==21 || Interface[i][j]==20)
                    cout<<" ";
                else
                    cout<<Sym(Interface[i][j]);
            }
            else if(HtB[0][i][j]!=0 && HtB[0][i][j]/100==3)
                cout<<Sym(HtB[0][i][j]%100);
            else if(Art[3][i][j]!=0)
                cout<<Sym(Art[3][i][j]);
            else if(Art[1][i][j]!=0)
                cout<<Sym(Art[1][i][j]);
            else if(Art[4][i][j]!=0)
                cout<<Sym(Art[4][i][j]);
            else if(Art[2][i][j]!=0)
                cout<<Sym(Art[2][i][j]);
            else if(HtB[0][i][j]!=0 && HtB[0][i][j]/100==2)
                cout<<Sym(HtB[0][i][j]%100);
            else if(Art[0][i][j]!=0)
                cout<<Sym(Art[0][i][j]);
            else if(HtB[0][i][j]!=0 && HtB[0][i][j]/100==1)
                cout<<Sym(HtB[0][i][j]%100);
            else
                cout<<Sym(0);

            HtB[0][i][j]=0;
        }
        cout<<(char)179<<endl;
    }
    cout<<(char)192;
    for(j=1; j<=200; j++)
        cout<<(char)196;
    cout<<(char)217<<endl;
}

void Level::MakeInterface(int maxhitpoint1, bool ICON1[8][8], int maxhitpoint2, bool ICON2[8][8])
{
    for(i=1; i<=60; i++)
        for(j=1; j<=200; j++)
            Interface[i][j]=0;
    for(j=1; j<=8; j++)
        Interface[52][j]=10;
    Interface[52][9]=13;
    for(i=1; i<=6; i++)
        Interface[52+i][9]=11;
    Interface[59][9]=16;
    Interface[60][9]=11;

    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++)
            Interface[52+i][j]=20+ICON1[i-1][j-1];

    for(j=1; j<=3+maxhitpoint1/10; j++)
    {
        Interface[59][j+9]=10;
        Interface[60][j+9]=3;
    }
    Interface[59][13+maxhitpoint1/10]=13;
    Interface[60][13+maxhitpoint1/10]=11;

    for(i=1; i<=8; i++)
        Interface[52+i][192]=11;
    Interface[52][192]=12;
    for(j=1; j<=8; j++)
        Interface[52][192+j]=10;
    for(i=1; i<=8; i++)
        for(j=1; j<=8; j++)
            Interface[52+i][200-j+1]=20+ICON2[i-1][j-1];
    Interface[59][192]=18;
    for(j=maxhitpoint2/10+3; j>=1; j--)
    {
        Interface[59][192-j]=10;
        Interface[60][192-j]=3;
    }
    Interface[59][188-maxhitpoint2/10]=12;
    Interface[60][188-maxhitpoint2/10]=11;
}

void Level::InterfaceUpdate(int timer1, int cooldown1, int hitpoints1, int maxhitpoints1, int timer2, int cooldown2, int hitpoints2, int maxhitpoints2)
{
    int nrcoloured1;
    nrcoloured1=((cooldown1-timer1)/(float)cooldown1)*8;
    for(i=53; i<=59-nrcoloured1; i++)
        for(j=1; j<=8; j++)
            if(Interface[i][j]!=21)
                Interface[i][j]=20;
    for(i=60-nrcoloured1; i<=60; i++)
        for(j=1; j<=8; j++)
            if(Interface[i][j]!=21 && i!=52)
            {
                if(timer1==0)
                    Interface[i][j]=3;
                else
                    Interface[i][j]=2;
            }
    for(j=1; j<=maxhitpoints1/10; j++)
    {
        if(j<=hitpoints1/10)
        {
            if(hitpoints1==maxhitpoints1)
                Interface[60][12+j]=3;
            else
                Interface[60][12+j]=2;
        }
        else
            Interface[60][12+j]=20;
    }

    int nrcoloured2;
    nrcoloured2=((cooldown2-timer2)/(float)cooldown2)*8;
    for(i=53; i<=59-nrcoloured2; i++)
        for(j=1; j<=8; j++)
            if(Interface[i][192+j]!=21)
                Interface[i][192+j]=20;
    for(i=60-nrcoloured2; i<=60; i++)
        for(j=1; j<=8; j++)
            if(Interface[i][192+j]!=21 && i!=52)
            {
                if(timer2==0)
                    Interface[i][192+j]=3;
                else
                    Interface[i][192+j]=2;
            }
    for(j=1; j<=maxhitpoints2/10; j++)
    {
        if(j<=hitpoints2/10)
        {
            if(hitpoints2==maxhitpoints2)
                Interface[60][189-j]=3;
            else
                Interface[60][189-j]=2;
        }
        else
            Interface[60][189-j]=20;
    }
}

char Level::Sym(short int nr)
{
    if(('a'<=nr && nr<='z') || ('A'<=nr && nr<='Z'))
    {
        return (char)nr;
    }
    else
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
        case 10:
            return (char)196;///─
            break;
        case 11:
            return (char)179;///│
            break;
        case 12:
            return (char)218;///┌
            break;
        case 13:
            return (char)191;///┐
            break;
        case 14:
            return (char)192;///└
            break;
        case 15:
            return (char)217;///┘
            break;
        case 16:
            return (char)195;///├
            break;
        case 17:
            return (char)194;///┬
            break;
        case 18:
            return (char)180;///┤
            break;
        case 19:
            return (char)193;///┴
            break;
        /*case 20:
            return (char)197;///┼
            break;*/
        default:
            return 'E';
        }
    }
}
