#include <iostream>
#include <cstdlib>

using namespace std;

string start, you, hat1, hat2, walk;
string wp[4], waste, description[4];
string MAP[2][42][18] ={ {}, {
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     +", "------", "------", "------", "+     ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", " ,__, ", "      ", "|     ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", "+----+", "      ", "|     ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", "|O__O|", "      ", "|     ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", " ,__, ", "+----+", " ,__, ", "|     ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "+----+", "      ", "+----+", "|     ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "|O__O|", "      ", "|O__O|", "|     ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "+----+", "      ", "+----+", "|     ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     +", "-----+", "      ", "+-----", "+     ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", "|     ", "      ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", "|     ", "      ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", "|     ", "      ", "      ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", "|     ", "      ", "      ", },
        {"      ", "     +", "------", "------", "------", "+     ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", "|     ", "      ", "      ", },
        {"      ", "     |", "      ", "      ", "      ", "|     ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", "|     ", "      ", "      ", },
        {"      ", "     |", "      ", "      ", "      ", "|     ", "      ", "    +-", "------", "-+    ", "      ", "      ", "      ", "     |", "      ", "|     ", "      ", "      ", },
        {"      ", "     |", "      ", "      ", "      ", "+-----", "------", "----+ ", " ,__, ", " +----", "------", "------", "------", "-----+", "      ", "|     ", "      ", "      ", },
        {"      ", "     |", "      ", "      ", "      ", "      ", " ____ ", "      ", "+----+", "      ", " ____ ", "      ", "      ", "      ", "      ", "|     ", "      ", "      ", },
        {"      ", "     |", "      ", "      ", "      ", "      ", "|_[]_|", "      ", "|O__O|", "      ", "|_[]_|", "      ", "      ", "      ", "      ", "|     ", "      ", "      ", },
        {"      ", "     |", "      ", "      ", "      ", "      ", "|____|", "      ", "+----+", "      ", "|____|", "      ", "      ", "      ", "      ", "|     ", "      ", "      ", },
        {"      ", "     |", "      ", "      ", "      ", "+-----", "------", "----+ ", "      ", " +----", "------", "------", "------", "-----+", "      ", "|     ", "      ", "      ", },
        {"      ", "     |", "      ", "      ", "      ", "|     ", "      ", "    +-", "------", "-+    ", "      ", "      ", "      ", "     |", "      ", "|     ", "      ", "      ", },
        {"      ", "     |", "      ", "      ", "      ", "|     ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "     |", "      ", "|     ", "      ", "      ", },
        {"      ", "     +", "------", "------", "------", "+     ", "      ", "      ", "      ", "      ", "      ", "   +--", "------", "-----+", "------", "+-----", "------", "--+   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | +", "------", "-----+", "------", "+-----", "------", "+ |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", " ,__, ", "      ", "      ", "      ", " ,__, ", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "+----+", "      ", " ____ ", "      ", "+----+", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "|O__O|", "      ", "|_[]_|", "      ", "|O__O|", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "+----+", "      ", "|____|", "      ", "+----+", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "      ", " ,__, ", "      ", " ,__, ", "      ", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "      ", "+----+", "      ", "+----+", "      ", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "      ", "|O__O|", "      ", "|O__O|", "      ", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "      ", "+----+", "      ", "+----+", "      ", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "      ", "      ", " ____ ", "      ", "      ", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "      ", "      ", "/_02_\\", "      ", "      ", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "      ", "      ", "|~__O|", "      ", "      ", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | |", "      ", "      ", "+----+", "      ", "      ", "| |   ", },
        {"      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "      ", "   | +", "------", "------", "------", "------", "------", "+ |   ", }
    } };

int charac, okch, okhat, hat, x, y, i, j, n, clas, faction, hpbonus, okkey;
int ii, jj, hpyou, hpyoumax, wpchoice, round, dmgred, choice, sumadmg, dmgredgen, win;
int trg, trgi, trgj, trgok, ammo[4], ammomax[4], trgar[99999], trg1, trg2, trg3, wps[4];
int ultcharge, ult, ulti, ultj, ulttrg[4], shields, bsdmg, bsok, ultchargegen;

struct square
{
    int type;//0-gol 1-soldier 2-tank 3-sniper 4-medic 5-assassin
    int hp;
    int hpmax;
    int atack;
    string app[5];
    string dead[5];
};

square LVL[5][5];

void factionandclasschoice()
{
    system("CLS");

    while(clas!=1 && clas!=2 && clas!=3)
    {
        cout<<endl;
        cout<<endl;
        cout<<"CHOOSE YOUR FACTION:"<<endl;
        cout<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"  1.Special Forces  |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"_____               |                                                       "<<endl;
       cout<<"\\__#/               |                                                       "<<endl;
        cout<<"(~.O)0              |                                                       "<<endl;
        cout<<"   IP=======<       |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<"                    |                                                       "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cin>>clas;
    }
}

void screen()
{
    system("CLS");
    cout<<round<<endl;
    cout<<"   + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- +"<<endl;

    cout<<"                                              ";
    for(jj=1; jj<=3; jj++)
    {
        if(LVL[1][jj].hp!=0)
            cout<<LVL[1][jj].atack;
        else
            cout<<" ";
        for(ii=1; ii<=(13-LVL[1][jj].hpmax)/2-1; ii++)                  cout<<" ";
        for(ii=1; ii<=LVL[1][jj].hp; ii++)                              cout<<"#";
        for(ii=1; ii<=LVL[1][jj].hpmax-LVL[1][jj].hp; ii++)              cout<<"-";
        for(ii=1; ii<=13-(13-LVL[1][jj].hpmax)/2-LVL[1][jj].hpmax; ii++) cout<<" ";
        cout<<" ";
    }
    cout<<endl;
    cout<<"   |             |             |             |";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[1][ii].app[1]<<"|";
    cout<<endl;
    if(sumadmg!=0)
    {
        if(sumadmg<10)
            cout<<" ";
        cout<<"                       -"<<sumadmg<<"                 1  ";
    }
    else
        cout<<"                                           1  ";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[1][ii].app[2]<<" ";
    cout<<endl;
    cout<<"   |             |             |             |";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[1][ii].app[3]<<"|";
    cout<<endl;
    cout<<"                                              ";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[1][ii].app[4]<<" ";
    cout<<endl;

    cout<<"   + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- +"<<endl;

    if(choice==7)
        cout<<"                       "<<hpyou<<"hp     +"<<shields<<" shields  ";
    else
        cout<<"                       "<<hpyou<<"hp                  ";
    if(hpyou<100) cout<<" ";
    if(hpyou<10)  cout<<" ";
    for(jj=1; jj<=3; jj++)
    {
        if(LVL[2][jj].hp!=0)
            cout<<LVL[2][jj].atack;
        else
            cout<<" ";
        for(ii=1; ii<=(13-LVL[2][jj].hpmax)/2-1; ii++)                    cout<<" ";
        for(ii=1; ii<=LVL[2][jj].hp; ii++)                              cout<<"#";
        for(ii=1; ii<=LVL[2][jj].hpmax-LVL[2][jj].hp; ii++)              cout<<"-";
        for(ii=1; ii<=13-(13-LVL[2][jj].hpmax)/2-LVL[2][jj].hpmax; ii++) cout<<" ";
        cout<<" ";
    }
    cout<<endl;
    cout<<"   |             |    "<<hat1<<"   |"<<wp[1]<<"   |";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[2][ii].app[1]<<"|";
    cout<<endl;
    cout<<"                      "<<hat2<<"    "<<wp[2]<<" 2  ";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[2][ii].app[2]<<" ";
    cout<<endl;
    cout<<"   |             |    "<<you<<"   |"<<wp[3]<<"   |";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[2][ii].app[3]<<"|";
    cout<<endl;
    cout<<"                                              ";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[2][ii].app[4]<<" ";
    cout<<endl;

    cout<<"   + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- +"<<endl;

    cout<<"                                              ";
    for(jj=1; jj<=3; jj++)
    {
        if(LVL[3][jj].hp!=0)
            cout<<LVL[3][jj].atack;
        else
            cout<<" ";
        for(ii=1; ii<=(13-LVL[3][jj].hpmax)/2-1; ii++)                    cout<<" ";
        for(ii=1; ii<=LVL[3][jj].hp; ii++)                              cout<<"#";
        for(ii=1; ii<=LVL[3][jj].hpmax-LVL[3][jj].hp; ii++)              cout<<"-";
        for(ii=1; ii<=13-(13-LVL[3][jj].hpmax)/2-LVL[3][jj].hpmax; ii++) cout<<" ";
        cout<<" ";
    }
    cout<<endl;
    cout<<"   |             |             |             |";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[3][ii].app[1]<<"|";
    cout<<endl;
    cout<<"                                           3  ";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[3][ii].app[2]<<" ";
    cout<<endl;
    cout<<"   |             |             |             |";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[3][ii].app[3]<<"|";
    cout<<endl;
    cout<<"                                              ";
    for(ii=1; ii<=3; ii++)
        cout<<LVL[3][ii].app[4]<<" ";
    cout<<endl;

    cout<<"   + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- + -- -- -- -- +"<<endl;
}

void handcannon()
{
    wp[1]="          ";
    wp[2]=" <>===    ";
    wp[3]=" /        ";

    if(ammo[wpchoice]==0)
    {
        screen();
        cout<<endl;
        cout<<"Reloading!"<<endl;
        cout<<endl;
        cin>>waste;

        ammo[wpchoice]=ammomax[wpchoice];

        wp[1]="          ";
        wp[2]="          ";
        wp[3]="          ";
    }
    else
        while(true)
        {
            screen();
            cout<<endl;
            cout<<"Choose your target and press Enter to continue";
            cout<<endl;
            cin>>trg;

            if(trg==1 || trg==2 || trg==3)
            {
                trgok=0;

                for(trgi=1; trgi<=3; trgi++)
                    if(LVL[trg][trgi].hp!=0)
                    {
                        trgok=1;
                        break;
                    }

                if(trgok==1)
                {
                    LVL[trg][trgi].hp-=5;

                    if(LVL[trg][trgi].hp<0)
                        LVL[trg][trgi].hp=0;

                    if(LVL[trg][trgi].hp==0)
                        for(trgj=1; trgj<=4; trgj++)
                            LVL[trg][trgi].app[trgj]=LVL[trg][trgi].dead[trgj];

                    wp[1]="          ";
                    wp[2]=" <>===#   ";
                    wp[3]=" /        ";

                    screen();
                    cout<<endl;
                    cout<<"Press any key and Enter to continue";
                    cout<<endl;
                    cin>>waste;

                    wp[1]="          ";
                    wp[2]="          ";
                    wp[3]="          ";
                    ammo[wpchoice]--;

                    if(LVL[trg][trgi].hp==0)
                    {
                        for(trgj=1; trgj<=4; trgj++)
                        {
                            LVL[trg][trgi].app[trgj]="             ";
                            LVL[trg][trgi].dead[trgj]="             ";
                        }

                        LVL[trg][trgi].atack=0;
                        LVL[trg][trgi].hpmax=0;
                    }

                    break;
                }
            }
        }
}

void rocketlauncher()
{
    wp[1]="          ";
    wp[2]=" <+>{[[[[ ";
    wp[3]=" // [_]   ";

    if(ammo[wpchoice]==0)
    {
        screen();
        cout<<endl;
        cout<<"Reloading!"<<endl;
        cin>>waste;

        ammo[wpchoice]=ammomax[wpchoice];

        wp[1]="          ";
        wp[2]="          ";
        wp[3]="          ";
    }
    else
        while(true)
        {
            screen();
            cout<<endl;
            cout<<"Choose the lane to shoot rocket on and press Enter to continue";
            cout<<endl;
            cin>>trg;

            if(trg==1 || trg==2 || trg==3)
            {
                trgok=0;

                for(trgi=1; trgi<=3; trgi++)
                    if(LVL[trg][trgi].hp!=0)
                    {
                        trgok=1;
                        break;
                    }

                if(trgok==1)
                {
                    LVL[1][trgi].hp-=3;
                    LVL[2][trgi].hp-=3;
                    LVL[3][trgi].hp-=3;

                    if(LVL[1][trgi].hp<0)
                        LVL[1][trgi].hp=0;
                    if(LVL[2][trgi].hp<0)
                        LVL[2][trgi].hp=0;
                    if(LVL[3][trgi].hp<0)
                        LVL[3][trgi].hp=0;

                    if(LVL[1][trgi].hp==0)
                        for(trgj=1; trgj<=4; trgj++)
                            LVL[1][trgi].app[trgj]=LVL[1][trgi].dead[trgj];
                    if(LVL[2][trgi].hp==0)
                        for(trgj=1; trgj<=4; trgj++)
                            LVL[2][trgi].app[trgj]=LVL[2][trgi].dead[trgj];
                    if(LVL[3][trgi].hp==0)
                        for(trgj=1; trgj<=4; trgj++)
                            LVL[3][trgi].app[trgj]=LVL[3][trgi].dead[trgj];

                    wp[1]="          ";
                    wp[2]=" <+>{[[[[#";
                    wp[3]=" // [_]   ";

                    screen();
                    cout<<endl;
                    cout<<"Press any key and Enter to continue";
                    cout<<endl;
                    cin>>waste;

                    wp[1]="          ";
                    wp[2]="          ";
                    wp[3]="          ";
                    ammo[wpchoice]--;

                    if(LVL[1][trgi].hp==0)
                    {
                        for(trgj=1; trgj<=4; trgj++)
                        {
                            LVL[1][trgi].app[trgj]="             ";
                            LVL[1][trgi].dead[trgj]="             ";
                        }

                        LVL[1][trgi].atack=0;
                        LVL[1][trgi].hpmax=0;
                    }
                    if(LVL[2][trgi].hp==0)
                    {
                        for(trgj=1; trgj<=4; trgj++)
                        {
                            LVL[2][trgi].app[trgj]="             ";
                            LVL[2][trgi].dead[trgj]="             ";
                        }

                        LVL[2][trgi].atack=0;
                        LVL[2][trgi].hpmax=0;
                    }
                    if(LVL[3][trgi].hp==0)
                    {
                        for(trgj=1; trgj<=4; trgj++)
                        {
                            LVL[3][trgi].app[trgj]="             ";
                            LVL[3][trgi].dead[trgj]="             ";
                        }

                        LVL[3][trgi].atack=0;
                        LVL[3][trgi].hpmax=0;
                    }

                    break;
                }
            }
        }
}

void autoriffle()
{
    wp[1]="          ";
    wp[2]="  _,____  ";
    wp[3]=" // ||    ";

    if(ammo[wpchoice]==0)
    {
        screen();
        cout<<endl;
        cout<<"Reloading!"<<endl;
        cout<<"Press any key and Enter to continue";
        cin>>waste;

        ammo[wpchoice]=ammomax[wpchoice];

        wp[1]="          ";
        wp[2]="          ";
        wp[3]="          ";
    }
    else
    {
        screen();
        cout<<endl;
        cout<<"Choose your targets(4) and press Enter to continue";
        cout<<endl;
        for(trgi=4; trgi<=7; trgi++)
            cin>>trgar[trgi];

        trgar[trgar[4]]++;
        trgar[trgar[5]]++;
        trgar[trgar[6]]++;
        trgar[trgar[7]]++;

        trgok=0;
        for(trg1=1; trg1<=3; trg1++)
            if(LVL[1][trg1].hp!=0)
            {
                trgok=1;
                break;
            }
        if(trgok==1)
        {
            LVL[1][trg1].hp-=trgar[1];
            if(LVL[1][trg1].hp<0)
                LVL[1][trg1].hp=0;
            if(LVL[1][trg1].hp==0)
                for(trgj=1; trgj<=4; trgj++)
                    LVL[1][trg1].app[trgj]=LVL[1][trg1].dead[trgj];
        }

        trgok=0;
        for(trg2=1; trg2<=3; trg2++)
            if(LVL[2][trg2].hp!=0)
            {
                trgok=1;
                break;
            }
        if(trgok==1)
        {
            LVL[2][trg2].hp-=trgar[2];
            if(LVL[2][trg2].hp<0)
                LVL[2][trg2].hp=0;
            if(LVL[2][trg2].hp==0)
                for(trgj=1; trgj<=4; trgj++)
                    LVL[2][trg2].app[trgj]=LVL[2][trg2].dead[trgj];
        }

        trgok=0;
        for(trg3=1; trg3<=3; trg3++)
            if(LVL[3][trg3].hp!=0)
            {
                trgok=1;
                break;
            }
        if(trgok==1)
        {
            LVL[3][trg3].hp-=trgar[3];
            if(LVL[3][trg3].hp<0)
                LVL[3][trg3].hp=0;
            if(LVL[3][trg3].hp==0)
                for(trgj=1; trgj<=4; trgj++)
                    LVL[3][trg3].app[trgj]=LVL[3][trg3].dead[trgj];
        }

        trgar[1]=0;
        trgar[2]=0;
        trgar[3]=0;
        wp[1]="          ";
        wp[2]="  _,____,'";
        wp[3]=" // ||  ',";

        screen();
        cout<<endl;
        cout<<"Press any key and Enter to continue";
        cout<<endl;
        cin>>waste;

        wp[1]="          ";
        wp[2]="          ";
        wp[3]="          ";
        ammo[wpchoice]-=4;

        if(LVL[1][trg1].hp==0)
        {
            for(trgj=1; trgj<=4; trgj++)
            {
                LVL[1][trg1].app[trgj]="             ";
                LVL[1][trg1].dead[trgj]="             ";
            }

            LVL[1][trg1].atack=0;
            LVL[1][trg1].hpmax=0;
        }
        if(LVL[2][trg2].hp==0)
        {
            for(trgj=1; trgj<=4; trgj++)
            {
                LVL[2][trg2].app[trgj]="             ";
                LVL[2][trg2].dead[trgj]="             ";
            }

            LVL[2][trg2].atack=0;
            LVL[2][trg2].hpmax=0;
        }
        if(LVL[3][trg3].hp==0)
        {
            for(trgj=1; trgj<=4; trgj++)
            {
                LVL[3][trg3].app[trgj]="             ";
                LVL[3][trg3].dead[trgj]="             ";
            }

            LVL[3][trg3].atack=0;
            LVL[3][trg3].hpmax=0;
        }
    }
}

void sword()
{
    wp[1]=" |        ";
    wp[2]=" |        ";
    wp[3]=" T        ";

    while(true)
    {
        screen();
        cout<<endl;
        cout<<"Choose your target and press Enter to continue";
        cout<<endl;
        cin>>trg;

        if(trg==1 || trg==2 || trg==3)
        {
            trgok=0;

            for(trgi=1; trgi<=3; trgi++)
                if(LVL[trg][trgi].hp!=0)
                {
                    trgok=1;
                    break;
                }

            if(trgok==1)
            {
                LVL[trg][trgi].hp-=7;
                hpyou-=LVL[trg][trgi].atack;

                if(LVL[trg][trgi].hp<0)
                    LVL[trg][trgi].hp=0;
                if(LVL[trg][trgi].hp==0)
                    for(trgj=1; trgj<=4; trgj++)
                        LVL[trg][trgi].app[trgj]=LVL[trg][trgi].dead[trgj];

                wp[1]="          ";
                wp[2]=" -|----   ";
                wp[3]="          ";

                screen();
                cout<<endl;
                cout<<"Press any key and Enter to continue";
                cout<<endl;
                cin>>waste;

                wp[1]="          ";
                wp[2]="          ";
                wp[3]="          ";

                if(LVL[trg][trgi].hp==0)
                {
                    for(trgj=1; trgj<=4; trgj++)
                    {
                        LVL[trg][trgi].app[trgj]="             ";
                        LVL[trg][trgi].dead[trgj]="             ";
                    }

                    LVL[trg][trgi].atack=0;
                    LVL[trg][trgi].hpmax=0;
                }

                break;
            }
        }
    }
}

void medkit()
{
    hpyou+=9;
    if(hpyou>hpyoumax)
        hpyou=hpyoumax;

    wp[1]="   _      ";
    wp[2]="  _W_     ";
    wp[3]=" |_+_|    ";

    screen();
    cout<<endl;
    cout<<"Press any key and Enter to continue";
    cout<<endl;
    cin>>waste;

    wp[1]="          ";
    wp[2]="          ";
    wp[3]="          ";
}

void precisemissiles()
{
    ultcharge=0;

    while(true)
    {
        wp[1]="  __      ";
        wp[2]=" K__|     ";
        wp[3]=" //       ";

        screen();
        cout<<endl;
        cout<<"Choose your targets(3) and press Enter to continue"<<endl;
        cout<<"11 12 13"<<endl;
        cout<<"21 22 23"<<endl;
        cout<<"31 32 33"<<endl;
        for(ulti=1; ulti<=3; ulti++)
            cin>>ulttrg[ulti];

        trgok=1;
        for(ulti=1; ulti<=3; ulti++)
            if(ulttrg[ulti]!=11 && ulttrg[ulti]!=21 && ulttrg[ulti]!=31 && ulttrg[ulti]!=12 && ulttrg[ulti]!=22 && ulttrg[ulti]!=32 && ulttrg[ulti]!=13 && ulttrg[ulti]!=23 && ulttrg[ulti]!=33)
            {
                trgok=0;
                break;
            }

        if(trgok==0)
            continue;

        for(ulti=1; ulti<=3; ulti++)
        {
            LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].hp-=3;
            if(LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].hp<0)
                LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].hp=0;

            if(LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].hp==0)
            {
                ultcharge++;
                for(ultj=1; ultj<=4; ultj++)
                    LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].app[ultj]=LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].dead[ultj];
            }
        }

        wp[1]="  __  =>  ";
        wp[2]=" K__|   =>";
        wp[3]=" //    => ";

        screen();
        cout<<endl;
        cout<<"Press any key and Enter to continue"<<endl;
        cout<<endl;
        cin>>waste;

        for(ulti=1; ulti<=3; ulti++)
            if(LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].hp==0)
            {
                for(ultj=1; ultj<=4; ultj++)
                {
                    LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].app[ultj]="             ";
                    LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].dead[ultj]="             ";
                }

                LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].hpmax=0;
                LVL[ulttrg[ulti]/10][ulttrg[ulti]%10].atack=0;
            }

        wp[1]="          ";
        wp[2]="          ";
        wp[3]="          ";

        break;
    }
}

void assassinate()
{
    ultcharge=0;

    while(true)
    {
        screen();
        cout<<endl;
        cout<<"Choose your hunt target and press Enter to continue"<<endl;
        cout<<"11 12 13"<<endl;
        cout<<"21 22 23"<<endl;
        cout<<"31 32 33"<<endl;
        cin>>trg;

        if(trg!=11 && trg!=21 && trg!=31 && trg!=12 && trg!=22 && trg!=32 && trg!=13 && trg!=23 && trg!=33)
            continue;

        LVL[trg/10][trg%10].hp-=10;
        if(LVL[trg/10][trg%10].hp<0)
            LVL[trg/10][trg%10].hp=0;

        if(LVL[trg/10][trg%10].hp==0)
            ultcharge+=2;

        LVL[trg/10][trg%10].app[1]="  #\\\\##//#   ";
        LVL[trg/10][trg%10].app[2]=" ###\\\\//###  ";
        LVL[trg/10][trg%10].app[3]=" ###//\\\\###  ";
        LVL[trg/10][trg%10].app[4]="  #//##\\\\#   ";

        screen();
        cout<<endl;
        cout<<"Press any key and Enter to continue"<<endl;
        cout<<endl;
        cin>>waste;

        if(LVL[trg/10][trg%10].hp==0)
        {
            for(ultj=1; ultj<=4; ultj++)
            {
                LVL[trg/10][trg%10].app[ultj]="             ";
                LVL[trg/10][trg%10].dead[ultj]="             ";
            }

            LVL[trg/10][trg%10].hpmax=0;
            LVL[trg/10][trg%10].atack=0;
        }
        else
        {
            LVL[trg/10][trg%10].app[1]="   /  ____   ";
            LVL[trg/10][trg%10].app[2]="   | /_02_\\  ";
            LVL[trg/10][trg%10].app[3]="   |=|~__O|  ";
            LVL[trg/10][trg%10].app[4]="   \\ +----+  ";
        }

        wp[1]="          ";
        wp[2]="          ";
        wp[3]="          ";

        break;
    }
}

void omg360noscope()
{
    wp[1]="  0    ,  ";
    wp[2]=" <#>===== ";
    wp[3]=" //'  /\\  ";
    ultcharge=0;

    while(true)
    {
        screen();
        cout<<endl;
        cout<<"Choose your target and press Enter to 360 no scope";
        cout<<endl;
        cin>>trg;

        if(trg==1 || trg==2 || trg==3)
        {
            trgok=0;

            for(trgi=1; trgi<=3; trgi++)
                if(LVL[trg][trgi].hp!=0)
                {
                    trgok=1;
                    break;
                }

            if(trgok==1)
            {
                LVL[trg][trgi].hp=0;
                ultcharge+=2;

                for(trgj=1; trgj<=4; trgj++)
                        LVL[trg][trgi].app[trgj]=LVL[trg][trgi].dead[trgj];

                wp[1]="  0    ,  ";
                wp[2]=" <#>=====#";
                wp[3]=" //'  /\\  ";

                screen();
                cout<<endl;
                cout<<"Press any key and Enter to continue";
                cout<<endl;
                cin>>waste;

                wp[1]="          ";
                wp[2]="          ";
                wp[3]="          ";

                for(trgj=1; trgj<=4; trgj++)
                {
                    LVL[trg][trgi].app[trgj]="             ";
                    LVL[trg][trgi].dead[trgj]="             ";
                }

                LVL[trg][trgi].atack=0;
                LVL[trg][trgi].hpmax=0;

                break;
            }
        }
    }
}

void firestrike()
{
    ultcharge=0;
    wp[1]=" 0        ";
    wp[2]=" |        ";
    wp[3]=" |        ";

    while(true)
    {
        screen();
        cout<<endl;
        cout<<"Choose lane to send firestrike"<<endl;
        cout<<endl;
        cin>>ult;
        if(ult!=1 && ult!=2 && ult!=3)
            continue;

        for(ulti=1; ulti<=3; ulti++)
            if(LVL[ult][ulti].hp!=0)
            {
                LVL[ult][ulti].hp-=4;

                if(LVL[ult][ulti].hp<0)
                    LVL[ult][ulti].hp=0;

                if(LVL[ult][ulti].hp==0)
                {
                    for(ultj=1; ultj<=4; ultj++)
                        LVL[ult][ulti].app[ultj]=LVL[ult][ulti].dead[ultj];

                    ultcharge++;
                }
            }

        break;
    }

    wp[1]="   0      ";
    wp[2]="  /       ";
    wp[3]=" /        ";

    screen();
    cout<<endl;
    cout<<"Press any key and Enter to continue"<<endl;
    cout<<endl;
    cin>>waste;

    for(ulti=1; ulti<=3; ulti++)
        if(LVL[ult][ulti].hp==0)
        {
            for(ultj=1; ultj<=4; ultj++)
                LVL[ult][ulti].app[ultj]="             ";

            LVL[ult][ulti].hpmax=0;
            LVL[ult][ulti].atack=0;
        }

    wp[1]="          ";
    wp[2]="          ";
    wp[3]="          ";
}

void strangeartefact()
{
    ultcharge=0;
    wp[1]="  \\|/     ";
    wp[2]=" --@--    ";
    wp[3]="  /|\\     ";

    screen();
    cout<<endl;
    cout<<"The Artefact heales you and protects you!"<<endl;
    cout<<endl;
    cout<<"Press any key and Enter to continue"<<endl;
    cout<<endl;
    cin>>waste;

    dmgred=50;
    hpyou+=20;
    if(hpyou>hpyoumax)
        hpyou=hpyoumax;

    wp[1]="          ";
    wp[2]="          ";
    wp[3]="          ";
}

void spiritcurse()
{
    ultcharge=0;
    wp[1]=" /\\  -  - ";
    wp[2]=" |[[[ -   ";
    wp[3]=" \\/  - -  ";

    for(ulti=1; ulti<=3; ulti++)
        for(ultj=1; ultj<=3; ultj++)
            if(LVL[ulti][ultj].hp!=0)
            {
                LVL[ulti][ultj].hp-=3;

                if(LVL[ulti][ultj].hp<0)
                    LVL[ulti][ultj].hp=0;

                if(LVL[ulti][ultj].hp==0)
                {
                    for(trg=1; trg<=4; trg++)
                        LVL[ulti][ultj].app[trg]=LVL[ulti][ultj].dead[trg];

                    ultcharge++;
                }
            }

    hpyou-=3;

    screen();
    cout<<endl;
    cout<<"Bad spirits have passed through!"<<endl;
    cout<<endl;
    cout<<"Press any key and Enter to continue"<<endl;
    cout<<endl;
    cin>>waste;

    for(ulti=1; ulti<=3; ulti++)
        for(ultj=1; ultj<=3; ultj++)
            if(LVL[ulti][ultj].hp==0)
            {
                for(trg=1; trg<=4; trg++)
                    LVL[ulti][ultj].app[trg]="             ";

                LVL[ulti][ultj].hpmax=0;
                LVL[ulti][ultj].atack=0;
            }

    for(ulti=1; ulti<=3; ulti++)
        for(ultj=1; ultj<=3; ultj++)
            if(LVL[ulti][ultj].hp!=0)
                LVL[ulti][ultj].hp+=2;

    hpyou+=2;
    wp[1]=" /\\  +  + ";
    wp[2]=" |[[[ +   ";
    wp[3]=" \\/  + +  ";

    screen();
    cout<<endl;
    cout<<"Good spirits have passed through!"<<endl;
    cout<<endl;
    cout<<"Press any key and Enter to continue"<<endl;
    cout<<endl;
    cin>>waste;

    wp[1]="          ";
    wp[2]="          ";
    wp[3]="          ";
}

void shield()
{
    ultcharge=0;
    wp[1]="  \\\\\\     ";
    wp[2]="  ||||    ";
    wp[3]="  ///     ";
    shields+=25;

    screen();
    cout<<endl;
    cout<<"Deploying shields!";
    cout<<endl;
    cout<<"Press any key and Enter to continue"<<endl;
    cout<<endl;
    cin>>waste;
}

void revenge()
{
    wp[1]="          ";
    wp[2]="          ";
    wp[3]="          ";
    ultcharge=0;

    while(true)
    {
        screen();
        cout<<endl;
        cout<<"Choose the target to unleash your fury on and press Enter to continue";
        cout<<endl;
        cin>>trg;

        if(trg==1 || trg==2 || trg==3)
        {
            trgok=0;

            for(trgi=1; trgi<=3; trgi++)
                if(LVL[trg][trgi].hp!=0)
                {
                    trgok=1;
                    break;
                }

            if(trgok==1)
            {
                if(hpyou>hpyoumax/2)
                    LVL[trg][trgi].hp-=5;
                if(hpyou<hpyoumax/2 && hpyou>hpyoumax/4)
                    LVL[trg][trgi].hp-=10;
                if(hpyou<hpyoumax/4)
                    LVL[trg][trgi].hp-=15;

                if(LVL[trg][trgi].hp<0)
                    LVL[trg][trgi].hp=0;

                if(LVL[trg][trgi].hp==0)
                    for(trgj=1; trgj<=4; trgj++)
                        LVL[trg][trgi].app[trgj]=LVL[trg][trgi].dead[trgj];

                screen();
                cout<<endl;
                cout<<"Press any key and Enter to continue";
                cout<<endl;
                cin>>waste;

                if(LVL[trg][trgi].hp==0)
                {
                    ultcharge+=2;

                    for(trgj=1; trgj<=4; trgj++)
                    {
                        LVL[trg][trgi].app[trgj]="             ";
                        LVL[trg][trgi].dead[trgj]="             ";
                    }

                    LVL[trg][trgi].atack=0;
                    LVL[trg][trgi].hpmax=0;
                }

                break;
            }
        }
    }
}

void battleshout()
{
    ultcharge=0;
    bsdmg++;
    trgok=0;

    for(ulti=1; ulti<=3; ulti++)
        for(ultj=1; ultj<=3; ultj++)
            if(LVL[ulti][ultj].atack!=0)
                LVL[ulti][ultj].atack--;

    for(ultj=1; ultj<=3 && trgok==0; ultj++)
        for(ulti=1; ulti<=3; ulti++)
            if(LVL[ulti][ultj].hp!=0)
            {
                trgok=1;
                break;
            }
    ultj--;

    for(ulti=1; ulti<=3; ulti++)
        if(LVL[ulti][ultj].hp!=0)
        {
            LVL[ulti][ultj].hp-=bsdmg;

            if(LVL[ulti][ultj].hp<0)
                LVL[ulti][ultj].hp=0;

            if(LVL[ulti][ultj].hp==0)
            {
                for(trg=1; trg<=4; trg++)
                    LVL[ulti][ultj].app[trg]=LVL[ulti][ultj].dead[trg];

                ultcharge++;
            }
        }

    screen();
    cout<<endl;
    cout<<"AAAAAAAAATTTTTTTTTTTAAAAAAAAAACCCCCCCCCCCKKKKKKKKKKK!"<<endl;
    cout<<endl;
    cout<<"Press any key and Enter to continue"<<endl;
    cout<<endl;
    cin>>waste;

    for(ulti=1; ulti<=3; ulti++)
        if(LVL[ulti][ultj].hp==0)
        {
            for(trg=1; trg<=4; trg++)
                LVL[ulti][ultj].app[trg]="             ";

            LVL[ulti][ultj].hpmax=0;
            LVL[ulti][ultj].atack=0;
        }

    bsok=1;
}

void tank_2()
{
    if(round%10==0)
        LVL[ii][jj].hp+=5;

    if(LVL[ii][jj].hp>11)
        LVL[ii][jj].hp=11;
}

void sniper_3()
{
    if(round%5==0)
        hpyou-=5;
}

void healer_4()
{
    if(LVL[ii][jj-1].hp!=0)
        LVL[ii][jj-1].hp+=2;

    if(LVL[ii][jj-1].hp>LVL[ii][jj-1].hpmax)
        LVL[ii][jj-1].hp=LVL[ii][jj-1].hpmax;
}

void assassin_5()
{
    if((jj==1 && LVL[ii][2].hp==0 && LVL[ii][3].hp==0)||(jj==2 && LVL[ii][1].hp==0 && LVL[ii][3].hp==0)||(jj==3 && LVL[ii][2].hp==0 && LVL[ii][1].hp==0))
        LVL[ii][jj].atack*=2;
}

void level(int c, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int b1, int b2, int b3)
{
    LVL[1][1].type=a1;
    LVL[1][2].type=a2;
    LVL[1][3].type=a3;
    LVL[2][1].type=a4;
    LVL[2][2].type=a5;
    LVL[2][3].type=a6;
    LVL[3][1].type=a7;
    LVL[3][2].type=a8;
    LVL[3][3].type=a9;
    choice=c;
    wps[1]=b1;
    wps[2]=b2;
    wps[3]=b3;
    dmgred=dmgredgen;
    hpyou=hpyoumax;
    round=0;
    ultcharge=ultchargegen;
    shields=0;
    wp[1]="          ";
    wp[2]="          ";
    wp[3]="          ";

    for(ii=1; ii<=3; ii++)
        for(jj=1; jj<=3; jj++)
        {
            if(LVL[ii][jj].type==0)
            {
                LVL[ii][jj].app[1]="             ";
                LVL[ii][jj].app[2]="             ";
                LVL[ii][jj].app[3]="             ";
                LVL[ii][jj].app[4]="             ";
                LVL[ii][jj].atack=0;
                LVL[ii][jj].hp=0;
                LVL[ii][jj].hpmax=0;
                LVL[ii][jj].dead[1]="             ";
                LVL[ii][jj].dead[2]="             ";
                LVL[ii][jj].dead[3]="             ";
                LVL[ii][jj].dead[4]="             ";
            }
            else if(LVL[ii][jj].type==1)
            {
                LVL[ii][jj].app[1]="       ,__,  ";
                LVL[ii][jj].app[2]="      +----+ ";
                LVL[ii][jj].app[3]="###(1)|O__O| ";
                LVL[ii][jj].app[4]="    \\\\+----+ ";
                LVL[ii][jj].atack=3;
                LVL[ii][jj].hpmax=7;
                LVL[ii][jj].hp=7;
                LVL[ii][jj].dead[1]="       ,__,  ";
                LVL[ii][jj].dead[2]="      +----+ ";
                LVL[ii][jj].dead[3]="      |X__X| ";
                LVL[ii][jj].dead[4]="      +----+ ";
            }
            else if(LVL[ii][jj].type==2)
            {
                LVL[ii][jj].app[1]="   /  ____   ";
                LVL[ii][jj].app[2]="   | /_02_\\  ";
                LVL[ii][jj].app[3]="   |=|~__O|  ";
                LVL[ii][jj].app[4]="   \\ +----+  ";
                LVL[ii][jj].atack=2;
                LVL[ii][jj].hp=11;
                LVL[ii][jj].hpmax=11;
                LVL[ii][jj].dead[1]="      ____   ";
                LVL[ii][jj].dead[2]="     /_02_\\  ";
                LVL[ii][jj].dead[3]="     |X__X|  ";
                LVL[ii][jj].dead[4]="     +----+  ";
            }
            else if(LVL[ii][jj].type==3)
            {
                LVL[ii][jj].app[1]="      ____   ";
                LVL[ii][jj].app[2]="     ,\\03/   ";
                LVL[ii][jj].app[3]=" ____|^__0|  ";
                LVL[ii][jj].app[4]=" ^^^^^^^^\\/  ";
                LVL[ii][jj].atack=5;
                LVL[ii][jj].hpmax=5;
                LVL[ii][jj].hp=5;
                LVL[ii][jj].dead[1]="      ____   ";
                LVL[ii][jj].dead[2]="     ,\\03/   ";
                LVL[ii][jj].dead[3]="     |X__X|  ";
                LVL[ii][jj].dead[4]="     +----+  ";
            }
            else if(LVL[ii][jj].type==4)
            {
                LVL[ii][jj].app[1]="        _    ";
                LVL[ii][jj].app[2]="   _ +-|+|+  ";
                LVL[ii][jj].app[3]="  |4||O__O|  ";
                LVL[ii][jj].app[4]="   ^ +----+  ";
                LVL[ii][jj].atack=1;
                LVL[ii][jj].hp=9;
                LVL[ii][jj].hpmax=9;
                LVL[ii][jj].dead[1]="        _    ";
                LVL[ii][jj].dead[2]="     +-|+|+  ";
                LVL[ii][jj].dead[3]="     |X__X|  ";
                LVL[ii][jj].dead[4]="     +----+  ";
            }
            else if(LVL[ii][jj].type==5)
            {
                LVL[ii][jj].app[1]="        _    ";
                LVL[ii][jj].app[2]="      /|5|\\  ";
                LVL[ii][jj].app[3]="===|=|<><>|  ";
                LVL[ii][jj].app[4]="     +\\__/+  ";
                LVL[ii][jj].atack=4;
                LVL[ii][jj].hp=6;
                LVL[ii][jj].hpmax=6;
                LVL[ii][jj].dead[1]="       _     ";
                LVL[ii][jj].dead[2]="     /|5|\\   ";
                LVL[ii][jj].dead[3]="    |X  X|   ";
                LVL[ii][jj].dead[4]="    +\\__/+   ";
            }
        }

    for(ii=1; ii<=3; ii++)
    {
        if(wps[ii]==0)
        {
            description[ii]="empty ";
            ammo[ii]=0;
            ammomax[ii]=0;
        }
        if(wps[ii]==1)
        {
            description[ii]="handcannon (single target, 5 dmg) ";
            ammo[ii]=4;
            ammomax[ii]=4;
        }
        else if(wps[ii]==2)
        {
            description[ii]="autorifle (4 targets, 1 dmg) ";
            ammo[ii]=20;
            ammomax[ii]=20;
        }
        else if(wps[ii]==3)
        {
            description[ii]="rocketlauncher (send a rocket down a line and deal 3 damage to all enemies in the colomn) ";
            ammo[ii]=2;
            ammomax[ii]=2;
        }
        else if(wps[ii]==4)
        {
            description[ii]="sword (single target, 7 dmg but you're damaged based on the attack of your target) ";
            ammo[ii]=0;
            ammomax[ii]=0;
        }
        else if(wps[ii]==5)
        {
            description[ii]="medkit (you, 5 heal) ";
            ammo[ii]=0;
            ammomax[ii]=0;
        }
    }

    while(true)
    {
        round++;
        dmgred=dmgredgen;
        if(ultcharge<5)
            ultcharge++;

        screen();
        cout<<endl;
        cout<<"Choose your weapon:"<<endl;
        cout<<endl;
        cout<<"1. "<<description[1]<<ammo[1]<<"/"<<ammomax[1]<<endl;
        cout<<"2. "<<description[2]<<ammo[2]<<"/"<<ammomax[2]<<endl;
        cout<<"3. "<<description[3]<<ammo[3]<<"/"<<ammomax[3]<<endl;
        cout<<endl;
        cout<<"0. Ultimate ";
        for(ii=1; ii<=ultcharge; ii++)
            cout<<"#";
        for(ii=ultcharge+1; ii<=5; ii++)
            cout<<"-";
        cout<<endl;
        cout<<endl;
        cin>>wpchoice;

        if((wpchoice>0 && wpchoice<4) || (wpchoice==0 && ultcharge==5))
        {
            if(wpchoice==0)
            {
                if(choice==1)
                    precisemissiles();
                if(choice==2)
                    assassinate();
                if(choice==3)
                    omg360noscope();
                if(choice==4)
                    firestrike();
                if(choice==5)
                    strangeartefact();
                if(choice==6)
                    spiritcurse();
                if(choice==7)
                    shield();
                if(choice==8)
                    revenge();
                if(choice==9)
                    battleshout();
            }
            else if(wps[wpchoice]==0)
            {
                round--;
                ultcharge--;
                continue;
            }
            if(wps[wpchoice]==1)
                handcannon();
            if(wps[wpchoice]==2)
                autoriffle();
            if(wps[wpchoice]==3)
                rocketlauncher();
            if(wps[wpchoice]==4)
                sword();
            if(wps[wpchoice]==5)
                medkit();
        }
        else
        {
            round--;
            ultcharge--;
            continue;
        }

        if(LVL[1][1].hp==0 && LVL[1][2].hp==0 && LVL[1][3].hp==0 && LVL[2][1].hp==0 && LVL[2][2].hp==0 && LVL[2][3].hp==0 && LVL[3][1].hp==0 && LVL[3][2].hp==0 && LVL[3][3].hp==0)
        {
            cout<<endl;
            cout<<endl;
            cout<<"                                            \\ /  +-+  | |    |      |  +-+  |\\  |"<<endl;
            cout<<"                                             |   | |  | |    |  /\\  |  | |  | \\ |"<<endl;
            cout<<"                                             |   +-+  +-+     \\/  \\/   +-+  |  \\|"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"                                                            "<<hat1<<endl;
            cout<<"                                                            "<<hat2<<endl;
            cout<<"                                                            "<<you<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"   Reward:"<<endl;
            cout<<endl;
            cout<<"   +"<<hpbonus<<"hp"<<endl;
            cout<<endl;
            cout<<"   Press any character key and Enter to continue"<<endl;
            cout<<endl;
            cin>>waste;

            system("CLS");

            win=1;

            break;
        }

        for(ii=1; ii<=3; ii++)
            for(jj=1; jj<=3; jj++)
                if(LVL[ii][jj].hp!=0)
                {
                    if(LVL[ii][jj].type==2)
                        tank_2();
                    if(LVL[ii][jj].type==3)
                        sniper_3();
                    if(LVL[ii][jj].type==4)
                        healer_4();
                    if(LVL[ii][jj].type==5)
                        assassin_5();
                }

        for(ii=1; ii<=3; ii++)
            for(jj=1; jj<=3; jj++)
                sumadmg+=LVL[ii][jj].atack;
        if(shields==0)
            hpyou-=(dmgred*sumadmg/100);
        else
            shields-=(sumadmg*dmgred/100);

        if(shields<0)
            shields=0;

        if(hpyou<0)
            hpyou=0;

        if(hpyou==0)
        {
            cout<<endl;
            cout<<endl;
            cout<<"                                         /`\\  /\\  |\\    /| ---   +-+ |  | --- |\\"<<endl;
            cout<<"                                        | _  |__| | \\  / | |__   | | |  | |__ |/"<<endl;
            cout<<"                                         \\,/ |  | |  \\/  | |__   +-+  \\/  |__ |\\"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"                                                            "<<hat1<<endl;
            cout<<"                                                            "<<hat2<<endl;
            cout<<"                                                            "<<you<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"   Press any character key and Enter to come back to the main area"<<endl;
            cout<<endl;
            cin>>waste;

            win=0;

            break;
        }

        screen();
        cout<<endl;
        cout<<"Press any key and Enter to continue"<<endl;
        cout<<endl;
        cin>>waste;

        sumadmg=0;
        if(bsok==1)
        {
            for(ulti=1; ulti<=3; ulti++)
                for(ultj=1; ultj<=3; ultj++)
                    LVL[ulti][ultj].atack++;

            bsok=0;
        }
    }
}

void chest1()
{
    system("CLS");

    cout<<endl;
    cout<<"                                      \\ /  +-+  | |   --- +-+ | | |\\  | |\\"<<endl;
    cout<<"                                       |   | |  | |   |__ | | | | | \\ | | |"<<endl;
    cout<<"                                       |   +-+  +-+   |   +-+ +-+ |  \\| |/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" ()Revolver (-5, single target) 4 ammo"<<endl;
    cout<<endl;
    cout<<"   <>==="<<endl;
    cout<<"   /"<<endl;
    cout<<endl;
    cout<<" ()A note:"<<endl;
    cout<<endl;

    cout<<"   +-----------------------------------+"<<endl;
    cout<<"   | Specimen 1 (soldier)              |"<<endl;
    cout<<"   |        ,__,                       |"<<endl;
    cout<<"   |       +----+                      |"<<endl;
    cout<<"   | ###(1)|O__O|                      |"<<endl;
    cout<<"   |     \\\\+----+                      |"<<endl;
    cout<<"   |                                   |"<<endl;
    cout<<"   | HP: 7                             |"<<endl;
    cout<<"   |                                   |"<<endl;
    cout<<"   | Damage: 3                         |"<<endl;
    cout<<"   |                                   |"<<endl;
    cout<<"   | Special abilities: None           |"<<endl;
    cout<<"   +-----------------------------------+"<<endl;
    cout<<endl;
    cout<<"   Press any character key and Enter to continue"<<endl;
    cout<<endl;
    cin>>waste;

    MAP[n][21][6]="      ";
    MAP[n][22][6]="      ";
    MAP[n][23][6]="      ";
}

void chest2()
{
    system("CLS");

    cout<<endl;
    cout<<"                                      \\ /  +-+  | |   --- +-+ | | |\\  | |\\"<<endl;
    cout<<"                                       |   | |  | |   |__ | | | | | \\ | | |"<<endl;
    cout<<"                                       |   +-+  +-+   |   +-+ +-+ |  \\| |/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" ()Auto rifle (-1, 4 targets) 30 ammo"<<endl;
    cout<<endl;
    cout<<"    _,____"<<endl;
    cout<<"   //  ||"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"   Press any character key and Enter to continue"<<endl;
    cout<<endl;
    cin>>waste;

    MAP[n][21][10]="      ";
    MAP[n][22][10]="      ";
    MAP[n][23][10]="      ";
}

void chest3()
{
    system("CLS");

    cout<<endl;
    cout<<"                                      \\ /  +-+  | |   --- +-+ | | |\\  | |\\"<<endl;
    cout<<"                                       |   | |  | |   |__ | | | | | \\ | | |"<<endl;
    cout<<"                                       |   +-+  +-+   |   +-+ +-+ |  \\| |/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" ()Medkit(+9hp, you)"<<endl;
    cout<<endl;
    cout<<"     _ "<<endl;
    cout<<"    _W_"<<endl;
    cout<<"   |_+_|"<<endl;
    cout<<endl;
    cout<<" ()A key"<<endl;
    cout<<endl;
    cout<<"   <>==F"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"   Press any character key and Enter to continue"<<endl;
    cout<<endl;
    cin>>waste;

    MAP[1][21][10]="      ";
    MAP[1][22][10]="      ";
    MAP[1][23][10]="      ";
}

int main()
{
    while(start!="Start")
    {
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"                                                       Welcome to"<<endl;
        cout<<endl;
        cout<<"                                       |  | ---   /\\  |\\  |      |  /\\  |\\ --- "<<endl;
        cout<<"                                       |--| |__  |--| | | |  /\\  | |--| |/ |__ "<<endl;
        cout<<"                                       |  | |__  |  | |/   \\/  \\/  |  | |\\  __|"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"                                                                        _                 "<<endl;
        cout<<"                                   ___,_  \\|||/           _           _|_|_ <+>{[[[[[    "<<endl;
        cout<<"                                    || \\\\ (@_@)   ===<>  /_\\__<>===   (*O*) //  [_]     "<<endl;
        cout<<"                                                      \\ (-_-) /                          "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"   Type ""Start"" to start"<<endl;
        cout<<endl;
        cout<<"   "<<flush;
        cin>>start;

        system("CLS");
    }

    while(okch==0)
    {
        okch=1;

        cout<<endl;
        cout<<"  Choose your character:"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"    (n_n)           (._.)           (-_-)"<<endl;
        cout<<endl;
        cout<<"   1.Smile      2.Ah...sorry   3.Yes, I careee..."<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"    (@_@)           (>_<)           (^_^)"<<endl;
        cout<<endl;
        cout<<"   4.Dizzy         5.Ouch!         6.Happy"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"    (X.X)           (*O*)           (o_o)"<<endl;
        cout<<endl;
        cout<<"   7.Dead       8.Incredible!    9.Seriously?"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"    (>o<)          (9_9)            (u_u)"<<endl;
        cout<<endl;
        cout<<"  10.Yuck!      11.No sleep        12.Sad"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cin>>charac;

        if(charac==1)
            you="(n_n) ";
        else if(charac==2)
            you="(._.) ";
        else if(charac==3)
            you="(-_-) ";
        else if(charac==4)
            you="(@_@) ";
        else if(charac==7)
            you="(X.X) ";
        else if(charac==8)
            you="(*O*) ";
        else if(charac==9)
            you="(o_o) ";
        else if(charac==10)
            you="(>o<) ";
        else if(charac==5)
            you="(>_<) ";
        else if(charac==6)
            you="(^_^) ";
        else if(charac==11)
            you="(9_9) ";
        else if(charac==12)
            you="(u_u) ";
        else
            okch=0;

        system("CLS");
    }

    while(okhat==0)
    {
        okhat=1;

        cout<<endl;
        cout<<"  Choose your hat:"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"       _                _   "<<endl;
        cout<<"      /_\\__           _|_|_ "<<endl;
        cout<<"     "<<you<<"           "<<you<<endl;
        cout<<endl;
        cout<<"     1.Cap       2.Fancy tophat"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"                       ___     "<<endl;
        cout<<"     \\\\|//            /_0_\\ "<<endl;
        cout<<"     "<<you<<"           "<<you<<endl;
        cout<<endl;
        cout<<"  3.Crazy hair       4.Miner"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"     _____            _____"<<endl;
        cout<<"     \\__#/            \\\\@//"<<endl;
        cout<<"     "<<you<<"           "<<you<<endl;
        cout<<endl;
        cout<<"   5.Captain      6.Strange hat"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cin>>hat;

        if(hat==1)
        {
            hat1="  _   ";
            hat2=" /_\\__";
        }else if(hat==2)
        {
            hat1="  _   ";
            hat2="_|_|_ ";
        }else if(hat==3)
        {
            hat1="      ";
            hat2="\\\\|// ";
        }else if(hat==5)
        {
            hat1="_____ ";
            hat2="\\__#/ ";
        }else if(hat==4)
        {
            hat1=" ___  ";
            hat2="/_0_\\ ";
        }else if(hat==6)
        {
            hat1="_____ ";
            hat2="\\\\@// ";
        }else
        {
            okhat=0;
        }

        system("CLS");
    }

    dmgredgen=100;
    bsdmg=2;
    hpyoumax=20;
    hpbonus=10;
    x=22;
    y=3;
    n=1;

    while(true)
    {
        system("CLS");

        cout<<endl;
        cout<<"   Level "<<n<<"/1"<<endl;
        cout<<endl;
        cout<<"  +------------------------------+"<<endl;
        cout<<"  |"<<MAP[n][x-7][y-2]<<MAP[n][x-7][y-1]<<MAP[n][x-7][y]<<MAP[n][x-7][y+1]<<MAP[n][x-7][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x-6][y-2]<<MAP[n][x-6][y-1]<<MAP[n][x-6][y]<<MAP[n][x-6][y+1]<<MAP[n][x-6][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x-5][y-2]<<MAP[n][x-5][y-1]<<MAP[n][x-5][y]<<MAP[n][x-5][y+1]<<MAP[n][x-5][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x-4][y-2]<<MAP[n][x-4][y-1]<<MAP[n][x-4][y]<<MAP[n][x-4][y+1]<<MAP[n][x-4][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x-3][y-2]<<MAP[n][x-3][y-1]<<MAP[n][x-3][y]<<MAP[n][x-3][y+1]<<MAP[n][x-3][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x-2][y-2]<<MAP[n][x-2][y-1]<<MAP[n][x-2][y]<<MAP[n][x-2][y+1]<<MAP[n][x-2][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x-1][y-2]<<MAP[n][x-1][y-1]<<hat1<<MAP[n][x-1][y+1]<<MAP[n][x-1][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x][y-2]<<MAP[n][x][y-1]<<hat2<<MAP[n][x][y+1]<<MAP[n][x][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x+1][y-2]<<MAP[n][x+1][y-1]<<you<<MAP[n][x+1][y+1]<<MAP[n][x+1][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x+2][y-2]<<MAP[n][x+2][y-1]<<MAP[n][x+2][y]<<MAP[n][x+2][y+1]<<MAP[n][x+2][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x+3][y-2]<<MAP[n][x+3][y-1]<<MAP[n][x+3][y]<<MAP[n][x+3][y+1]<<MAP[n][x+3][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x+4][y-2]<<MAP[n][x+4][y-1]<<MAP[n][x+4][y]<<MAP[n][x+4][y+1]<<MAP[n][x+4][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x+5][y-2]<<MAP[n][x+5][y-1]<<MAP[n][x+5][y]<<MAP[n][x+5][y+1]<<MAP[n][x+5][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x+6][y-2]<<MAP[n][x+6][y-1]<<MAP[n][x+6][y]<<MAP[n][x+6][y+1]<<MAP[n][x+6][y+2]<<"|"<<endl;
        cout<<"  |"<<MAP[n][x+7][y-2]<<MAP[n][x+7][y-1]<<MAP[n][x+7][y]<<MAP[n][x+7][y+1]<<MAP[n][x+7][y+2]<<"|"<<endl;
        cout<<"  +------------------------------+"<<endl;
        cout<<endl;
        cout<<"          w"<<endl;

        if(MAP[n][x-3][y]=="|O__O|")
            cout<<"        Fight!"<<endl;
        else if(MAP[n][x-3][y]=="|_[]_|")
            cout<<"    Open chest"<<endl;
        else
            cout<<endl;

            cout<<"    a           d"<<endl;

        if(MAP[n][x][y-1]=="|O__O|")
            cout<<"  Fight!  "<<flush;
        else if(MAP[n][x][y-1]=="|_[]_|")
            cout<<"Open chest"<<flush;
        else
            cout<<"          "<<flush;

        if(MAP[n][x][y+1]=="|O__O|")
            cout<<"    Fight!  "<<endl;
        else if(MAP[n][x][y+1]=="|_[]_|")
            cout<<"  Open chest"<<endl;
        else
            cout<<"            "<<endl;

        cout<<"          s"<<endl;

        if(MAP[n][x+3][y]=="|O__O|")
            cout<<"        Fight!"<<endl;
        else if(MAP[n][x+3][y]=="|_[]_|")
            cout<<"    Open chest"<<endl;
        else
            cout<<endl;

        cout<<endl;
        cout<<endl;

        cin>>walk;

        if(walk=="w" && MAP[n][x-2][y]=="      " && MAP[n][x-3][y]=="      " && MAP[n][x-4][y]=="      ")
            x=x-3;
        else if(walk=="s" && MAP[n][x+2][y]=="      " && MAP[n][x+3][y]=="      " && MAP[n][x+4][y]=="      ")
            x=x+3;
        else if(walk=="a" && MAP[n][x][y-1]=="      ")
            y=y-1;
        else if(walk=="d" && MAP[n][x][y+1]=="      ")
            y++;
        else if(n==1)
        {
            if(x==22 && y==5 && walk=="d")
            chest1();
            else if(x==22 && y==7 && walk=="d")
            {
                level(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0);

                if(win==1)
                {
                    MAP[n][20][8]="      ";
                    MAP[n][21][8]="      ";
                    MAP[n][22][8]="      ";
                    MAP[n][23][8]="      ";

                    hpyoumax+=hpbonus;
                    win=0;
                }
            }
            else if(x==22 && y==9 && walk=="d")
                chest2();
            else if(x==10 && y==14 && walk!="s" && MAP[n][7][14]=="|O__O|")
            {
                level(1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 2, 0);

                if(win==1)
                {
                    MAP[n][5][14]="      ";
                    MAP[n][6][14]=" ____ ";
                    MAP[n][7][14]="|_[]_|";
                    MAP[n][8][14]="|____|";

                    MAP[n][8][13]="      ";
                    MAP[n][9][13]="      ";
                    MAP[n][10][13]="      ";
                    MAP[n][11][13]="      ";

                    MAP[n][8][15]="      ";
                    MAP[n][9][15]="      ";
                    MAP[n][10][15]="      ";
                    MAP[n][11][15]="      ";

                    hpyoumax+=hpbonus;
                    win=0;
                }
            }
            else if(((x==10 && y==14 && walk=="w")||(x==7 && y==13 && walk=="d")||(x==7 && y==15 && walk=="a")) && MAP[n][7][14]=="|_[]_|")
                chest3();
        }

    }

    return 0;
}
