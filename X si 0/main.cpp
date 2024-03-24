#include <iostream>

using namespace std;

int main()
{
    string l1, l2, l3, l4, l5, l6, l7, l8, l9;
    int nr, ok1, ok2, ok3;
    ok1=0;
    ok2=0;
    ok3=0;

    l1=" ";
    l2=" ";
    l3=" ";
    l4=" ";
    l5=" ";
    l6=" ";
    l7=" ";
    l8=" ";
    l9=" ";

    while(true)
    {
        cout<<1<<" "<<2<<" "<<3<<endl;
        cout<<4<<" "<<5<<" "<<6<<endl;
        cout<<7<<" "<<8<<" "<<9<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<l1<<"|"<<l2<<"|"<<l3<<endl;
        cout<<"-----"<<endl;
        cout<<l4<<"|"<<l5<<"|"<<l6<<endl;
        cout<<"-----"<<endl;
        cout<<l7<<"|"<<l8<<"|"<<l9<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

        cin>>nr;

        if(nr==1)
            l1="X";
        if(nr==2)
            l2="X";
        if(nr==3)
            l3="X";
        if(nr==4)
            l4="X";
        if(nr==5)
            l5="X";
        if(nr==6)
            l6="X";
        if(nr==7)
            l7="X";
        if(nr==8)
            l8="X";
        if(nr==9)
            l9="X";

        if(l1==l2 && l2==l3 && l2!=" ")
        {
            ok1=1;
            break;
        }
        if(l4==l5 && l5==l6 && l5!=" ")
        {
            ok1=1;
            break;
        }
        if(l7==l8 && l8==l9 && l7!=" ")
        {
            ok1=1;
            break;
        }
        if(l1==l4 && l4==l7 && l4!=" ")
        {
            ok1=1;
            break;
        }
        if(l2==l5 && l5==l8 && l5!=" ")
        {
            ok1=1;
            break;
        }
        if(l3==l6 && l6==l9 && l6!=" ")
        {
            ok1=1;
            break;
        }
        if(l1==l5 && l5==l9 && l5!=" ")
        {
            ok1=1;
            break;
        }
        if(l3==l5 && l5==l7 && l5!=" ")
        {
            ok1=1;
            break;
        }

        if(l1!=" " && l2!=" " && l3!=" " && l4!=" " && l5!=" " && l6!=" " && l7!=" " && l8!=" " && l9!=" ")
        {
            ok3=1;
            break;
        }

        cout<<1<<" "<<2<<" "<<3<<endl;
        cout<<4<<" "<<5<<" "<<6<<endl;
        cout<<7<<" "<<8<<" "<<9<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<l1<<"|"<<l2<<"|"<<l3<<endl;
        cout<<"-----"<<endl;
        cout<<l4<<"|"<<l5<<"|"<<l6<<endl;
        cout<<"-----"<<endl;
        cout<<l7<<"|"<<l8<<"|"<<l9<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

        cin>>nr;

        if(nr==1)
            l1="0";
        if(nr==2)
            l2="0";
        if(nr==3)
            l3="0";
        if(nr==4)
            l4="0";
        if(nr==5)
            l5="0";
        if(nr==6)
            l6="0";
        if(nr==7)
            l7="0";
        if(nr==8)
            l8="0";
        if(nr==9)
            l9="0";

        if(l1==l2 && l2==l3 && l2!=" ")
        {
            ok2=1;
            break;
        }
        if(l4==l5 && l5==l6 && l5!=" ")
        {
            ok2=1;
            break;
        }
        if(l7==l8 && l8==l9 && l7!=" ")
        {
            ok2=1;
            break;
        }
        if(l1==l4 && l4==l7 && l4!=" ")
        {
            ok2=1;
            break;
        }
        if(l2==l5 && l5==l8 && l5!=" ")
        {
            ok2=1;
            break;
        }
        if(l3==l6 && l6==l9 && l6!=" ")
        {
            ok2=1;
            break;
        }
        if(l1==l5 && l5==l9 && l5!=" ")
        {
            ok2=1;
            break;
        }
        if(l3==l5 && l5==l7 && l5!=" ")
        {
            ok2=1;
            break;
        }
    }

    if(ok1==1)
    {
        cout<<l1<<"|"<<l2<<"|"<<l3<<endl;
        cout<<"-----"<<endl;
        cout<<l4<<"|"<<l5<<"|"<<l6<<endl;
        cout<<"-----"<<endl;
        cout<<l7<<"|"<<l8<<"|"<<l9<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"Jucatorul 1 a castigat!"<<endl;
    }

    if(ok2==1)
    {
        cout<<l1<<"|"<<l2<<"|"<<l3<<endl;
        cout<<"-----"<<endl;
        cout<<l4<<"|"<<l5<<"|"<<l6<<endl;
        cout<<"-----"<<endl;
        cout<<l7<<"|"<<l8<<"|"<<l9<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"Jucatorul 2 a castigat!"<<endl;
    }
    if(ok3==1)
    {
        cout<<l1<<"|"<<l2<<"|"<<l3<<endl;
        cout<<"-----"<<endl;
        cout<<l4<<"|"<<l5<<"|"<<l6<<endl;
        cout<<"-----"<<endl;
        cout<<l7<<"|"<<l8<<"|"<<l9<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"Egalitate!"<<endl;
    }

    return 0;
}
