#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "my_array.h"

typedef double Type;
using namespace std;
int main ()
{
    int M=7;
    srand(time(NULL));
    cout <<"начало  ---\n";
    Type *a = new Type[M];

    for (int i=0;i<M;i++)
        a[i]=Type(rand()%100);
    cout<<endl<<"---continue---"<<endl;
    int Mexit=0;
    do
    {
        cout<<"Выберите Действие :\n1 - Увеличение массива,\n2 - Уменьшение массива,\n3 - Вывод массива\n0 - Выход\n";
        cin>>Mexit;
        switch (Mexit)
        {
        case (1) : {
            int Pos;
            Type Num;
            cout<<"Введите значение вставляемой переменной : ";
            cin>>Num;
            cout<<"Введите позицию вставляемой переменной (Нулевой елемент является первым !!!) : ";
            cin>>Pos;
            a=ArrayInc(a,&M,Pos,Num);
            break;
        }
        case (2) : {
            int Pos;
            cout<<"Введите позицию удаляемой переменной (Нулевой елемент является первым !!!) : ";
            cin>>Pos;
            a=ArrayDec(a,&M,Pos);
            break;
        }
        case (3) :
        {
            ArrayShow(a,&M);
            break;
        }
        case (0) :
        {
            exit(0);
        }
        default :
        {
            cout<<"Значение не определено. Повторите еще раз...\n";
        }
        }
    }
    while(Mexit!=0);
}
