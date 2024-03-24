#ifndef BALL_H
#define BALL_H

class Ball
{
    public:
        Ball();
        int x();
        int y();
        int Movex(int direction);
        int Movey(int direction);
        void Ricochet();
        void Move();
        void r();
    protected:
    private:
        int xb;
        int yb;
        int dir;
};

#endif // BALL_H
