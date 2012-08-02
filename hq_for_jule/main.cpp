#include <iostream>
#include <stdlib.h>
#include <math.h>

void HQ_1();
void HQ_2();
void HQ_3();
void HQ_4();
void HQ_5();
void HQ_6();
void HQ_7();

using namespace std;

int main()
{
    HQ_1(); // 1. Сжать массив, удалив из него все 0 и заполнить освободившиеся справа элементы значениями -1;
    HQ_2(); // 2. Дан массив ненулевых целых чисел.
            //      Определить, сколько раз элементы при просмотре от его начала меняют знак.
            //      Например, 10, -4, 12, 56, -4, -89 3 раза.
    HQ_3(); // 3. Дан массив из N целых чисел. Необходимо подсчитать у=х1*(х1+х2)*(х1+х2+х3)*...*(x1+....+xN).
    HQ_4(); // 4. Дан массив,сложить все эл-ты между первым и последним отрицательным
    HQ_5(); // 5.дан массив. выстроить эл-ты в порядке чет-нечет
    HQ_6(); //  6. Написать программу, которая выводит содержимое массива наоборот.
    HQ_7(); //  7.Написать программу, которая находит сумму четных и сумму нечетных элементов массива.
    return 0;
}


void HQ_1()//1. Сжать массив, удалив из него все 0 и заполнить освободившиеся справа элементы значениями -1;
{
    srand(time(0));
    const int M=30;
    int mass[M];
    for (int i=1;i<=M;i++)//    Инициализация массива
    {
        mass[i-1]=rand()%10;
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }
    cout<<endl<<"begin ...\n ";
    int tmp;
    for (int i=0;i<M;i++)//Присвоение всем нулевым елементам значение (-1)
        if(mass[i]==0)
            mass[i]=-1;
    for (int i=0;i<M;i++)//Пробег по всему массиву
    {
        if (mass[i]!=-1)//Если елемент НЕ (-1) (то есть не бывший ноль!!!), то данный елемент массива сдвигаем до блишайшего
                        //положительного елемента
        {
            int k=i;
            while ((k>0)&&(mass[k-1]==-1)) //данное условие контролирует положительный елемент И границы массива
            {
                tmp=mass[k-1];
                mass[k-1]=mass[k];
                mass[k]=tmp;
                k--;
            }
            i=k;    //нужное присвоение для дополнительной проверки пройденных елементов... Подумываю, что это - НЕОБЯЗАТЕЛЬНО
        }
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }
    cout<<endl<<"======================"<<endl;
}


void HQ_2() //2. Дан массив ненулевых целых чисел.
            //  Определить, сколько раз элементы при просмотре от его начала меняют знак.
            //  Например, 10, -4, 12, 56, -4, -89 3 раза.
{
    srand(time(0));
    const int M=30;
    int mass[M];
    for (int i=0;i<M;i++) //Инициализация массива с отрицательными числами и исключением нулей
    {
        mass[i]=rand()%10;
        if ((rand()%10)%2==0)
            mass[i]=mass[i];
        else
            mass[i]=mass[i]*(-1);
        if (mass[i]==0)
            mass[i]++;
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }
    cout<<endl;
    int Count=0; //Счетчик изменений
    bool tmp, tmp2; //Переменные счета "положительный/отрицательный" :)
    if (sqrt(mass[0]*mass[0])==mass[0]) //формула числа по модулю и задание стартового значения счета "положительный/отрицательный"
        tmp=1;
    else
        tmp=0;
    for (int i=0;i<M;i++)//Пробег по всему массиву
    {
        if (sqrt(mass[i]*mass[i])==mass[i])
            tmp2=1;
        else
            tmp2=0;
        if (tmp2!=tmp)//Если число по модулю не равно числу, то произошла смена знака (tmp не равно tmp2), увеличиваем счетчик
                        // и меняем переменную счета "положительный/отрицательный" (tmp)
        {
            Count++;
            tmp=tmp2;
        }
    }
    cout<<endl<<Count<<endl<<"======================="<<endl;
}


void HQ_3() //3. Дан массив из N целых чисел. Необходимо подсчитать у=х1*(х1+х2)*(х1+х2+х3)*...*(x1+....+xN).
{
    srand(time(0));
    const int M=5;
    int mass[M];
    for (int i=0;i<M;i++)
    {
        mass[i]=rand()%3+1;
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }
    cout<<endl<<"begin\n";
    int Sum=mass[0];        //переменная подсчета (х1+х2)...(х1+х2+х3)...(x1+....+xN)
    //cout<<"Sum[0]="<<Sum<<"\t";
    unsigned long long Res=mass[0];        //переменная подсчета x1*Sum[2]...*Sum[N]
    //cout<<"Res[0]="<<Res<<endl;
    for (int i=1;i<M;i++)   //Перебор по всему массиву
    {
        Sum=Sum+mass[i];
        //cout<<"Sum["<<i<<"]="<<Sum<<"\t";   //Просто поясняющий вывод :) можно удалить
        Res=Res*Sum;
        //cout<<"Res["<<i<<"]="<<Res<<endl;   //Просто поясняющий вывод :) можно удалить
    }
    cout<<Res<<endl<<"======================="<<endl;
}


void HQ_4() //4. Дан массив,сложить все эл-ты между первым и последним отрицательным
{
    srand(time(0));
    const int M=10;
    int mass[M];
    for (int i=0;i<M;i++) //Инициализация массива с отрицательными числами и исключением нулей
    {
        mass[i]=rand()%10;
        if ((rand()%30)%2==0)
            mass[i]=mass[i];
        else
            mass[i]=mass[i]*(-1);
        if (mass[i]==0)
            mass[i]++;
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }
    cout<<endl<<"begin\n";
    int OBegin=0;
    int OEnd=M-1;
    while ((mass[OBegin]>0)&&(OBegin<=OEnd))
        OBegin++;
    while ((mass[OEnd]>0)&&(OEnd>=OBegin))
        OEnd--;
    long long Sum=0;
    for (int i=OBegin;i<=OEnd;i++)
        Sum=Sum+mass[i];
    cout<<"Сумма = "<<Sum<<endl<<"=============================="<<endl;
}


void HQ_5() // 5.дан массив. выстроить эл-ты в порядке чет-нечет
{
    srand(time(0));
    const int M=30;
    int mass[M];
    int mass1[M];
    for (int i=1;i<=M;i++)//    Инициализация массива
    {
        mass[i-1]=rand()%10+1;
        mass1[i-1]=0;
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }

    cout<<endl<<"begin ...\n ";

    int Sch1=0;
    int Sch2=0;
    int Sch0=0;
    int tmp=0;
    bool Chet;
    Chet=true;
    for (Sch0;Sch0<M;)
    {
        if (Chet)
        {           //алгоритм для четных
            tmp=Sch2;
            while ((mass[Sch2]%2!=0)&&(Sch2<M))
            {
                Sch2++;
            }
            if (Sch2==M)
            {
                Chet=!Chet;
                Sch2=tmp;
            }
            else
            {
                mass1[Sch0]=mass[Sch2];
                Sch2++;
                Sch0++;
                Chet=!Chet;
            }
        }
        else
        {           //алгоритм для нечетных
            tmp=Sch1;
            while ((mass[Sch1]%2==0)&&(Sch1<M))
            {
                Sch1++;
            }
            if (Sch1==M)
            {
                Chet=!Chet;
                Sch1=tmp;
            }
            else
            {
                mass1[Sch0]=mass[Sch1];
                Sch1++;
                Sch0++;
                Chet=!Chet;
            }
        }
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass1[i-1]<<" ";
    }
    cout<<endl<<"=============================="<<endl;
}


void HQ_6() //  6. Написать программу, которая выводит содержимое массива наоборот.
{
    srand(time(0));
    const int M=30;
    int mass[M];
    for (int i=1;i<=M;i++)//    Инициализация массива
    {
        mass[i-1]=rand()%10+1;
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }
    cout<<endl<<"begin ...\n ";
    for (int i=M;i>0;i--)
    {
        cout<<mass[i-1]<<" ";
    }
    cout<<endl<<"=============================="<<endl;
}


void HQ_7() //  7.Написать программу, которая находит сумму четных и сумму нечетных элементов массива.
{
    srand(time(0));
    const int M=30;
    int mass[M];
    for (int i=1;i<=M;i++)//    Инициализация массива
    {
        mass[i-1]=rand()%10+1;
    }
    for (int i=1;i<=M;i++)
    {
        cout<<mass[i-1]<<" ";
    }
    cout<<endl<<"begin ...\n ";

    int Sch1=0;
    int Sch2=0;
    int Sch0=0;
    for (Sch0;Sch0<M;Sch0++)
    {
        if (mass[Sch0]%2==0)
        {           //алгоритм для четных
            Sch2++;
        }
        else
        {           //алгоритм для нечетных
        Sch1++;
        }
    }
    cout<<"Кол-во четных = "<<Sch2<<"\tКол-во нечетных = "<<Sch1;
    cout<<endl<<"=============================="<<endl;
}

