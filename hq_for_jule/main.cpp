#include <iostream>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
void HQ_1();
using namespace std;

int main()
{
    HQ_1();//1. Сжать массив, удалив из него все 0 и заполнить освободившиеся справа элементы значениями -1;

    return 0;
}
void HQ_1()
{
    srand(time(0));
    const int M=30;
    int mass[M];
    for (int i=1;i<=M;i++)
    {
        mass[i-1]=rand()%5;
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }
    cout<<endl<<"press key ...\n ";

    //-----------------------------------------------
    int tmp;
    for (int i=0;i<M;i++)
        if(mass[i]==0)
            mass[i]=-1;
    for (int i=0;i<M;i++)
    {
        if (mass[i]!=-1)
        {
            int k=i;
            while ((k>0)&&(mass[k-1]==-1))
            {
                tmp=mass[k-1];
                mass[k-1]=mass[k];
                mass[k]=tmp;
                k--;
            }
            i=k;
        }
    }
    //-------------------------------------------------

    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }
}
