#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
    public:
        void healthbar();
        void damaged(int x);
        void death();
        virtual void AnimationMoveUp();
        virtual void AnimationMoveRight();
        virtual void AnimationMoveDown();
        virtual void AnimationMoveLeft();
        virtual void AnimationAttackUp();
        virtual void AnimationAttackRight();
        virtual void AnimationAttackDown();
        virtual void AnimationAttackLeft();
        virtual void Bullet();
    protected:
        int maxhealth;
        int health;
        int attackdmg;
        int firerate;
        int speed;
    private:
        int i;
};

#endif // ENEMY_H
