/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) 2012 monah1744 <monah1744@gmail.com>
 * 
 * rabbit is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * rabbit is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
void IncD(int *step,int pos,int M, int St);
void coutD(int *step,int M);
int SumD(int *step, int M);
int main()
{
	int St,Mst,temp;
	long Comb=0;
	cout<< "Введите количество ступенек : ";
	cin>>St;
	cout<<"Введите максимальный шаг : ";
	cin>>Mst;
	int *Step=new int [St+1];
	for (int i=0;i<St+1;i++)
	{
		Step[i]=0;
	}
	temp=St%Mst;
	temp++;
	for (int i=0;i<temp;i++)
	{
		Step[St+1-i]=Mst;
	}
	//-------------------------------Основной цикл перебора
	do
	{
		if (SumD(Step,St)==St)
		{
			coutD (Step,St);
			Comb++;
		}
		IncD(Step,St,Mst,St);
	}
	while(Step[0]<1);
	//------------------------------------
	
	cout<<endl<<Comb<<endl;
	delete[]Step;
}


void IncD(int *step, int pos, int M, int St)
{
	if (step[pos]==M)
	{
		step[pos]=1;
		IncD (step,pos-1,M,St);
	}
	else
	{
		step[pos]=step[pos]+1;
	}
}


int SumD(int *step, int M)
{
	int Sum=0;
	for (int i=1;i<M+1;i++)
		Sum=Sum+*(step+i);
	return Sum;
}


void coutD(int *step,int M)
{
	for (int i=1;i<M+1;i++)
		cout<<*(step+i);
	cout<<"\t"<<" = "<<SumD(step,M)<<endl;
}