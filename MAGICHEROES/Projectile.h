#ifndef PROJECTILE_H
#define PROJECTILE_H

extern short int Art[5][61][201];
extern short int HtB[5][61][201];
extern void Explode();

class Projectile
{
    public:
        void SetUp(int layer, int type, int attackdamage, int xi, int yi, int direction);
        void ProjectileUpdate();
        void FastProjectileUpdate();
        void DestroyObject();
        void Reconstruct(int id);
        int x, y, spd, dir, range, maxrange;
        int Type, dmg, contenemies;
        int Appearance[11][11];
        int HitBox[11][11];
        int Max;
        bool existence;
    protected:
    private:
        int Layer;
        int i, j;
        void Rotate(int integer);
};

#endif // PROJECTILE_H
