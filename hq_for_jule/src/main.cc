/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) monah1744 2012 <monah1744@gmail.com>
 * 
HQ_For_Jule is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * HQ_For_Jule is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <stdlib.h>
#include <locale>
void HQ_1();
using namespace std;

int main()
{
	HQ_1();//1. Сжать массив, удалив из него все 0 и заполнить освободившиеся справа элементы значениями -1;
	
	return 0;
}
void HQ_1()
{
	const int M=20;
	int mass[M];
	for (i=1;i<=M;i++)
	{
		cout<<"Введите "<<i<<"-й"<<" елемент массива : ";
		cin>>mass[i-1];
	}
	//-----------------------------------------------
	
}
