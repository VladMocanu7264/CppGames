#include <iostream>
#include <stdlib.h>///system("CLS");
#include <conio.h>/// kbhit(), getch()

using namespace std;

int i, nrl, contor, gameover;
char v[20], wrnglt[7], letter;
char word[20]={'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'};
string bodypart[7]={" ", "()", "[]", "/", "\\", "/", "\\"};
bool okbody[7], ok;

void art_and_input()
{
    system("CLS");

    cout<<" +----"<<endl;
    cout<<" |   |"<<endl;
    cout<<" |   "<<(okbody[1]==1?bodypart[1]:"  ")<<endl;
    cout<<" |  "<<(okbody[3]==1?bodypart[3]:" ")<<(okbody[2]==1?bodypart[2]:"  ")<<(okbody[4]==1?bodypart[4]:" ")<<endl;
    cout<<" |   "<<(okbody[5]==1?bodypart[5]:" ")<<(okbody[6]==1?bodypart[6]:" ")<<endl;
    cout<<"-+--"<<endl;
    cout<<endl;
    for(i=1; i<=nrl; i++)
        cout<<word[i];
    cout<<endl;
    cout<<endl;
    cout<<"Wrong letters: ";
    for(i=1; i<=6; i++)
        cout<<wrnglt[i]<<" ";
    cout<<endl;
    cout<<endl;
    cout<<"Enter a letter: ";
    letter=getch();
}

void check()
{
    gameover=2;///win

    for(i=1; i<=nrl; i++)
        if(v[i]!=word[i])
            gameover=0;

    if(contor==6)
        gameover=1;///lose

    if(gameover!=0)
    {
        system("CLS");

        cout<<endl;
        cout<<endl;
        if(gameover==1)
            cout<<"GAME OVER"<<endl;
        else
            cout<<"YOU WIN"<<endl;
        cout<<"Word: ";
        for(i=1; i<=nrl; i++)
            cout<<v[i];
        cout<<endl;
        cout<<endl;
    }
}

int main()
{
    i=1;
    cout<<"Thank you for volunteering for our beta test."<<endl;
    cout<<"Type your word, letter by letter:"<<endl;
    cout<<"(End your word with a .)"<<endl;
    cin>>v[i];
    do
    {
        i++;
        cin>>v[i];
    }while(v[i]!='.' && i<20);

    nrl=i-1;
    word[1]=v[1];

    while(true)
    {
        art_and_input();

        if(letter<='z' && letter>='a')
        {
            ok=0;

            for(i=1; i<=nrl; i++)
                if(letter==v[i])
                {
                    ok=1;
                    break;
                }

            if(ok==0)
            {
                wrnglt[++contor]=letter;
                okbody[contor]=1;
            }
            else
                for(i=1; i<=nrl; i++)
                    if(letter==v[i])
                        word[i]=letter;
        }

        check();
        if(gameover!=0)
            break;
    }

    return 0;
}
