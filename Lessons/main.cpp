#include <iostream>
#include <locale>
#include <stdlib.h>
#include <math.h>
using namespace std;

void m1();
void m2();
void m3();
void m4();
void m5();
void m6();
void m7();
void m8();

int main()
{
	setlocale(LC_ALL,"rus");
	//m1();
	//m2();
	//m3();
	//m4();
	//m5();
	//m6();
	m7();
}

				//найти максимальный и минимальный елемент в двумерном массиве, 
				//заполненном случайным образом.
void m1()		
{
	srand(time(NULL));
    const int M=4;
	const int N=5;
    int mass[M][N];
    for (int i=1;i<=M;i++)//    Инициализация массива
    {
		for (int k=1;k<=M;k++)
		{
			mass[i-1][k-1]=rand()%21-10;
			cout<<mass[i-1][k-1]<<" \t";
		}
		cout<<endl;
    }
	//======	Решение	======
	cout<<""<<endl;
	int Min=mass[0][0], Max=mass[0][0];
	for (int i=0;i<M;i++)
    {
		for (int k=0;k<M;k++)
		{
			if(mass[i][k]<Min) Min=mass[i][k];
			if(mass[i][k]>Max) Max=mass[i][k];
		}
    }
	//======	Ответ	======
	cout<<"Максимальное значение = "<<Max<<endl;
	cout<<"Минимальное значение = "<<Min<<endl;
}
				//найти максимум и минимум в каждой строке двумерного массива
void m2()		
{
	srand(time(NULL));
    const int M=4;
	const int N=5;
    int mass[M][N];
    for (int i=1;i<=M;i++)//    Инициализация массива
    {
		for (int k=1;k<=M;k++)
		{
			mass[i-1][k-1]=rand()%21-10;
			cout<<mass[i-1][k-1]<<" \t";
		}
		cout<<endl;
    }
	//======	Решение	======
	cout<<""<<endl;
	
	for (int i=0;i<M;i++)
    {
		int Min=mass[i][0], Max=mass[i][0];
		for (int k=0;k<M;k++)
		{
			if(mass[i][k]<Min) Min=mass[i][k];
			if(mass[i][k]>Max) Max=mass[i][k];
		}
		cout<<"Максимальное значение "<<i+1<<" -ой строки = "<<Max<<endl;
		cout<<"Минимальное значение "<<i+1<<" -ой строки = "<<Min<<endl<<endl;
    }
}
				//1.Написать программу, которая вводит по строкам с клавиатуры двумерный массив, 
				//показывает его на экран в табличном виде и вычисляет сумму его элементов по столбцам.
void m3()
{
	const int M=4;
	const int N=5;
    int mass[M][N];
	int Sum[N]={0};
    for (int i=1;i<=M;i++)//    Инициализация массива
    {
		for (int k=1;k<=M;k++)
		{
			cout<<"Введите елемент ["<<i<<"] ["<<k<<"] : ";
			cin>>mass[i-1][k-1];
			Sum[k-1]=Sum[k-1]+mass[i-1][k-1];
		}
		cout<<endl;
    }
	//======	Решение	======
	for (int i=0;i<M;i++)
	{
		for (int k=0;k<M;k++)
			cout<<mass[i][k]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	for (int i=0;i<M;i++)
		cout<<"Сумма "<<i+1<<" строки = "<<Sum[i]<<endl;
}
				//2.В двумерном массиве порядка N поменяйте местами первый и последний столбцы, второй и предпоследний и т.д. 
void m4()		
{
	srand(time(NULL));
    const int N=5;
    int mass[N][N];
    for (int i=1;i<=N;i++)//    Инициализация массива
    {
		for (int k=1;k<=N;k++)
		{
			mass[i-1][k-1]=rand()%21-10;
			cout<<mass[i-1][k-1]<<" \t";
		}
		cout<<endl;
    }
	//======	Решение	======
	cout<<"--------------"<<endl;
	int tmp=0;
	for (int i=0;i<N;i++)
    {
		for (int k=0;k<int (N/2);k++)
		{
			tmp=mass[i][k];
			mass[i][k]=mass[i][N-k-1];
			mass[i][N-k-1]=tmp;
		}
    }
	//======	Ответ	======
	for (int i=0;i<N;i++)
    {
		for (int k=0;k<N;k++)
		{
			cout<<mass[i][k]<<"\t";
		}
		cout<<endl;
    }
}
				//3.	Подсчитать количество локальных минимумов (максимумов) заданной матрицы 
				//		(локальный минимум - элемент, который строго меньше своих соседей).
void m5()		
{
	srand(time(NULL));
    const int N=5;
	const int M=6;
    int mass[N][M];
    for (int i=1;i<=N;i++)//    Инициализация массива
    {
		for (int k=1;k<=M;k++)
		{
			mass[i-1][k-1]=rand()%21-10;
			cout<<mass[i-1][k-1]<<" \t";
		}
		cout<<endl;
    }
	//======	Решение	======
	cout<<"-----------"<<endl;
	int Col=0;
	bool Check;
	for (int i=0;i<N;i++)
	{
		for (int k=0;k<M;k++)
		{
			Check=true;
			//++
			if((mass[i-1][k+1]<=mass[i][k])&&((i-1)>=0)&&((k+1)<M)) Check=false; //Верхний справа
			if((mass[i][k+1]<=mass[i][k])&&((k+1)<M)) Check=false;				//Справа
			if((mass[i+1][k+1]<=mass[i][k])&&((i+1)<N)&&((k+1)<M)) Check=false;	//Нижний справа
			if((mass[i+1][k]<=mass[i][k])&&((i+1)<N)) Check=false;				//Нижний
			if((mass[i+1][k-1]<=mass[i][k])&&((i+1)<N)&&((k-1)>=0)) Check=false;	//Нижний слева
			if((mass[i][k-1]<=mass[i][k])&&((k-1)>=0)) Check=false;				//Слева
			if((mass[i-1][k-1]<=mass[i][k])&&((i-1)>=0)&&((k-1)>=0)) Check=false;//Верхний слева
			if((mass[i-1][k]<=mass[i][k])&&((i-1)>=0)) Check=false;
			//--
			if(Check)
			{
				Col++;
				cout<<"mass ["<<i+1<<"] ["<<k+1<<"] - минимум"<<endl;
			}
		}
	}
	cout<<"Колличество локальных минимумов = "<<Col<<endl;
}
				//4.	Определить индексы всех седловых точек матрицы, т.е. таких элементов, 
				//		которые являются наименьшими в своей строке и одновременно наибольшими в своем столбце.  
void m6()		
{
	srand(time(NULL));
    const int N=3;
	const int M=4;
	int mass[N][M]={{2,3,5,2},
					{2,4,6,2},
					{-2,7,2,0}};
    for (int i=1;i<=N;i++)//    Инициализация массива
    {
		for (int k=1;k<=M;k++)
		{
			//mass[i-1][k-1]=rand()%4;
			cout<<mass[i-1][k-1]<<" \t";
		}
		cout<<endl;
    }
	//======	Решение	======
	cout<<"------------"<<endl;
	bool CheckN;
	bool CheckM;
	for (int i=0;i<N;i++)
	{
		for (int k=0;k<M;k++)
		{
			//++
			CheckN=true;
			CheckM=true;
			for (int x=0;x<M;x++)
			{
				if((mass[i][x]<mass[i][k]))
				{
					CheckN=false;
					break;
				}
			}
			if (CheckN)
				for (int x=0;x<N;x++)
				{
					if((mass[x][k]>mass[i][k]))
					{
						CheckM=false;
						break;
					}
				}
			//--
			if ((CheckN)&&(CheckM))
			{
				cout<<"mass ["<<i+1<<"] ["<<k+1<<"] = "<<mass[i][k]<<endl;
			}
		}
	}
}
				//5.	Заполните двумерный массив порядка N значениями, возрастающими по улитке.
void m7()
{
	const int N=8;
	int mass[N][N];
	//======	Решение	======
	bool Check=false;
	int Left=0, Right=N-1;
	int Up=0, Down=N-1;
	int x=0, y=0;
	int Col=N*N;
	int Z=1;
	while (Col>0)
	{
		while(y<Right)
		{
			mass[x][y]=Z;
			Z++;
			Col--;
			y++;
			Check=true;
		}
		if (Check){Up++;Check=false;}
		while(x<Down)
		{
			mass[x][y]=Z;
			Z++;
			Col--;
			x++;
			Check=true;
		}
		if (Check){Right--;Check=false;}
		while(y>Left)
		{
			mass[x][y]=Z;
			Z++;
			Col--;
			y--;
			Check=true;
		}
		if (Check){Down--;Check=false;}
		while(x>Up)
		{
			mass[x][y]=Z;
			Z++;
			Col--;
			x--;
			Check=true;
		}
		if (Check){Left++;Check=false;}
        if ((!Check)&&(Col==1))
        {
            mass[x][y]=Z;
            Col--;
        }
	}
	//======	ответ ======
	for (int i=1;i<=N;i++)
    {
		for (int k=1;k<=N;k++)
		{
			cout<<mass[i-1][k-1]<<" \t";
		}
		cout<<endl;
    }
}
				//функция меняет параметры местами
void m8()
{
}