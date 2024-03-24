#ifndef FILEMANAGING_H
#define FILEMANAGING_H

class FileManaging
{
    public:
        int slvls;
        int sAbLvl1[7], sAbLvl2[7], sAbLvl3[7];
        void Extract();
        void Save();
        void Delete();
    private:
        int i;
};

#endif // FILEMANAGING_H
