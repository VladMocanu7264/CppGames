#ifndef ART_H
#define ART_H

class Art
{
    public:
        Art();
        void Draw();
        void PChanges(int X, int Y);
        void BChanges(int x1, int y1, int x2, int y2);
        int Imput();
    protected:
    private:
        int i, j;
};

#endif // ART_H
