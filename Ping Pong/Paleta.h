#ifndef PALETA_H
#define PALETA_H


class Paleta
{
    public:
        Paleta(int a);
        void Move(int b);
        void R(int a);
        int x();
        int y();
    protected:
    private:
        int xp;
        int yp;
};

#endif // PALETA_H
