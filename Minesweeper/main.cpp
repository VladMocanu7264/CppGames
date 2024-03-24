#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int ok[999][999];
string u[1000][1000], a[999][999], op;
int x, y, i, j, poz, pozmine, nrb, latura, nrmine, win;

int main()
{
    while(op!="1")
    {
        system("CLS");

        cout<<endl;
        cout<<"MINESWEEPER v.1.1"<<endl;
        cout<<endl;
        cout<<"1.Play"<<endl;
        cout<<"2.Instructions"<<endl;
        cout<<"3.Credits"<<endl;
        cout<<endl;
        cout<<"Press 1, 2 or 3 and Enter"<<endl;
        cin>>op;

        if(op=="2")
        {
            system("CLS");

            cout<<endl;
            cout<<"Instructions"<<endl;
            cout<<endl;
            cout<<"-Use w/s/a/d to move your O around the map."<<endl;
            cout<<"-To dig a tile press e. The tile will be dug and you will"<<endl;
            cout<<" be able to see the number under if you move your O."<<endl;
            cout<<"-To flag a tile press q. A P will appear at the place,"<<endl;
            cout<<" marking the position of a bomb."<<endl;
            cout<<"-The game ends if you dig all tiles except the bombs or"<<endl;
            cout<<" if you hit one of them."<<endl;
            cout<<endl;
            cout<<"Press any character key and Enter to get back to the main menu"<<endl;
            cin>>op;
            op="0";
        }

        if(op=="3")
        {
            system("CLS");

            cout<<"MINESWEEPER version 1.1"<<endl;
            cout<<endl;
            cout<<"Produced by FuturisticHunter indie company"<<endl;
            cout<<endl;
            cout<<"Idea: Mocanu Vlad"<<endl;
            cout<<"Development: Mocanu Vlad"<<endl;
            cout<<"Graphics: Mocanu Vlad"<<endl;
            cout<<"Sound: no one, this game has no sounds"<<endl;
            cout<<endl;
            cout<<"And Thanks Pascu Alexandra for being the alpha tester!"<<endl;
            cout<<endl;
            cout<<"Press any character key and Enter to get back to the main menu"<<endl;
            cin>>op;
            op="0";
        }
    }

    op="0";

    while(op!="1" && op!="2" && op!="3" && op!="4")
    {
        system("CLS");

        cout<<endl;
        cout<<"Choose difficulty:"<<endl;
        cout<<endl;
        cout<<"1.Easy (9x9,10 mines)"<<endl;
        cout<<"2.Medium (16x16,40 mines)"<<endl;
        cout<<"3.Hard (20x20, 100 mines)"<<endl;
        cout<<"4.Custom"<<endl;
        cout<<endl;
        cin>>op;

        system("CLS");
    }

    if(op=="1")
    {
        latura=9;
        nrmine=10;
    }else if(op=="2")
    {
        latura=16;
        nrmine=40;
    }else if(op=="3")
    {
        latura=20;
        nrmine=100;
    }else if(op=="4")
    {
        while(nrmine>=latura*latura)
        {
            cout<<endl;
            cout<<"Enter square size and number of mines:"<<endl;
            cout<<endl;
            cin>>latura;
            cin>>nrmine;

            system("CLS");
        }
    }

    for(i=1; i<=latura; i++)
        for(j=1; j<=latura; j++)
            a[i][j]="#";
    for(i=0; i<=latura+1; i++)
        for(j=0; j<=latura+1; j++)
            u[i][j]=" ";

    srand(time(0));

    for(i=1; i<=nrmine; i++)
    {
        pozmine=rand() % (latura*latura) +1;

        if(pozmine%latura==0)
        {
            x=pozmine/latura;
            y=latura;
        }
        else
        {
            x=pozmine/latura+1;
            y=pozmine%latura;
        }

        if(u[x][y]!="@")
            u[x][y]="@";
        else
            i--;
    }

    for(i=1; i<=latura; i++)
        for(j=1; j<=latura; j++)
            if(u[i][j]==" ")
            {
                if(u[i-1][j-1]=="@")
                    nrb++;
                if(u[i][j-1]=="@")
                    nrb++;
                if(u[i+1][j-1]=="@")
                    nrb++;
                if(u[i-1][j]=="@")
                    nrb++;
                if(u[i+1][j]=="@")
                    nrb++;
                if(u[i-1][j+1]=="@")
                    nrb++;
                if(u[i][j+1]=="@")
                    nrb++;
                if(u[i+1][j+1]=="@")
                    nrb++;

                if(nrb>0)
                {
                    if(nrb==1)
                        u[i][j]="1";
                    if(nrb==2)
                        u[i][j]="2";
                    if(nrb==3)
                        u[i][j]="3";
                    if(nrb==4)
                        u[i][j]="4";
                    if(nrb==5)
                        u[i][j]="5";
                    if(nrb==6)
                        u[i][j]="6";
                    if(nrb==7)
                        u[i][j]="7";
                    if(nrb==8)
                        u[i][j]="8";
                }

                nrb=0;
            }

    x=latura/2+1;
    y=latura/2+1;

    while(true)
    {
        a[x][y]="O";

        for(i=1; i<=latura; i++)
        {
            for(j=1; j<=latura; j++)
                cout<<a[i][j];

            cout<<endl;
        }

        cin>>op;

        if(op=="a" && y!=1)
        {
            if(ok[x][y]==0)
                a[x][y]="#";
            else if(ok[x][y]==2)
                a[x][y]="P";
            else
                a[x][y]=u[x][y];

            y--;
        }
        if(op=="d" && y!=latura)
        {
            if(ok[x][y]==0)
                a[x][y]="#";
            else if(ok[x][y]==2)
                a[x][y]="P";
            else
                a[x][y]=u[x][y];

            y++;
        }
        if(op=="w" && x!=1)
        {
            if(ok[x][y]==0)
                a[x][y]="#";
            else if(ok[x][y]==2)
                a[x][y]="P";
            else
                a[x][y]=u[x][y];

            x--;
        }
        if(op=="s" && x!=latura)
        {
            if(ok[x][y]==0)
                a[x][y]="#";
            else if(ok[x][y]==2)
                a[x][y]="P";
            else
                a[x][y]=u[x][y];

            x++;
        }

        if(op=="q" && ok[x][y]==2)
        {
            ok[x][y]=0;
            a[x][y]="#";
        }
        else if(op=="q" && ok[x][y]==0)
        {
            ok[x][y]=2;
            a[x][y]="P";
        }

        if(op=="e" && u[x][y]!="@")
        {
            a[x][y]=u[x][y];
            ok[x][y]=1;
        }
        if(op=="e" && u[x][y]=="@")
        {
            system("CLS");

            for(i=1; i<=latura; i++)
            {
                for(j=1; j<=latura; j++)
                {
                    if(u[i][j]=="@")
                        cout<<"@";
                    else
                        cout<<a[i][j];
                }

                cout<<endl;
            }
            cout<<endl;
            cout<<"GAME OVER";
            cout<<endl;
            break;
        }
        if(op=="e" && u[x][y]==" ")
        {
            //sus
            i=x;

            while(i>1 && u[i][y]==" ")
            {
                a[i][y]=u[i][y];
                ok[i][y]=1;

                j=y+1;

                while(u[i][j]==" " && j<latura)
                {
                    a[i][j]=u[i][j];
                    ok[i][j]=1;
                    j++;
                }

                a[i][j]=u[i][j];
                ok[i][j]=1;

                i--;
            }

            a[i][y]=u[i][y];
            ok[i][y]=1;

            j=y+1;

            while(u[i][j]==" " && j<latura)
            {
                a[i][j]=u[i][j];
                ok[i][j]=1;
                j++;
            }

            a[i][j]=u[i][j];
            ok[i][j]=1;

            //jos
            i=x;

            while(i<latura && u[i][y]==" ")
            {
                a[i][y]=u[i][y];
                ok[i][y]=1;

                j=y-1;

                while(u[i][j]==" " && j>1)
                {
                    a[i][j]=u[i][j];
                    ok[i][j]=1;
                    j--;
                }

                a[i][j]=u[i][j];
                ok[i][j]=1;

                i++;
            }

            a[i][y]=u[i][y];
            ok[i][y]=1;

            j=y-1;

            while(u[i][j]==" " && j>1)
            {
                a[i][j]=u[i][j];
                ok[i][j]=1;
                j--;
            }

            a[i][j]=u[i][j];
            ok[i][j]=1;

            //dreapta

            j=y;

            while(j<latura && u[x][j]==" ")
            {
                a[x][j]=u[x][j];
                ok[x][j]=1;

                i=x+1;

                while(u[i][j]==" " && i<latura)
                {
                    a[i][j]=u[i][j];
                    ok[i][j]=1;
                    i++;
                }

                a[i][j]=u[i][j];
                ok[i][j]=1;

                j++;
            }

            a[x][j]=u[x][j];
            ok[x][j]=1;

            i=x+1;

            while(u[i][j]==" " && i<latura)
            {
                a[i][j]=u[i][j];
                ok[i][j]=1;
                i++;
            }

            a[i][j]=u[i][j];
            ok[i][j]=1;

            //stanga

            j=y;

            while(j>1 && u[x][j]==" ")
            {
                a[x][j]=u[x][j];
                ok[x][j]=1;

                i=x-1;

                while(u[i][j]==" " && i>1)
                {
                    a[i][j]=u[i][j];
                    ok[i][j]=1;
                    i--;
                }

                a[i][j]=u[i][j];
                ok[i][j]=1;

                j--;
            }

            a[x][j]=u[x][j];
            ok[x][j]=1;

            i=x-1;

            while(u[i][j]==" " && i>1)
            {
                a[i][j]=u[i][j];
                ok[i][j]=1;
                i--;
            }

            a[i][j]=u[i][j];
            ok[i][j]=1;
        }

        for(i=1; i<=latura; i++)
            for(j=1; j<=latura; j++)
                if((ok[i][j]==0 || ok[i][j]==2) && u[i][j]!="@")
                    win=1;

        if(win==0)
        {
            cout<<endl;
            cout<<"YOU WON!!!"<<endl;
            cout<<endl;

            return 0;
        }
        else
            win=0;

        system("CLS");
    }

    return 0;
}
