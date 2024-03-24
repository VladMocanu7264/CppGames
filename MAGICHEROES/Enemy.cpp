#include <iostream>
#include "Enemy.h"
#include "Soldier.h"

using namespace std;

void Enemy::healthbar()
{
    if(health>0)
        for(i=1; i<=maxhealth/25; i++)
        {
            if(i<=health/25)
                cout<<"#";
            else
                cout<<"-";
        }
    (health==0)?cout<<" ":(health/10==0)?cout<<" ":(health/100)==0?cout<<" ":cout<<flush;
    if(health>0) cout<<health;
}

void Enemy::damaged(int x)
{
    health-=x;
    if(health<=0)
    {
        health=0;
        Enemy::death();
    }
}

void Enemy::death()
{
    cout<<endl<<"Death";
}

