#include <fstream>
using namespace std;

ifstream fin("sudoku.in");
ofstream fout("sudoku.out");

short int a[10][10], cont;
bool fl[10][10], fc[10][10], fp[10][10];
struct ceva{
    short int x, y;
}ll[82];

void afisare(){
    int i, j;
    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++)
            fout<<a[i][j]<<' ';
        fout<<endl;
    }
}

bool corect(short int x, short int y, short int val)
{
    if(fl[x][val]==1)
        return 0;
    if(fc[y][val]==1)
        return 0;
    if(fp[((x-1)/3)*3+(y-1)/3+1][val]==1)
        return 0;
    return 1;
}

void bkt(short int k)
{
    short int i;
    for(i=1; i<=9; i++)
        if(corect(ll[k].x, ll[k].y, i)==1){
            a[ll[k].x][ll[k].y]=i;
            fl[ll[k].x][i]=1;
            fc[ll[k].y][i]=1;
            fp[((ll[k].x-1)/3)*3+(ll[k].y-1)/3+1][i]=1;

            if(k==cont)
                afisare();
            else
                bkt(k+1);

            fl[ll[k].x][i]=0;
            fc[ll[k].y][i]=0;
            fp[((ll[k].x-1)/3)*3+(ll[k].y-1)/3+1][i]=0;
        }
}

int main()
{
    int i, j;
    for(i=1; i<=9; i++)
        for(j=1; j<=9; j++){
            fin>>a[i][j];
            if(a[i][j]==0){
                ll[++cont].x=i;
                ll[cont].y=j;
            }
            else{
                fl[i][a[i][j]]=1;
                fc[j][a[i][j]]=1;
                fp[((i-1)/3)*3+(j-1)/3+1][a[i][j]]=1;
            }
        }

    bkt(1);

    return 0;
}
