/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) 2012 monah1744 <monah1744@gmail.com>
 * 
 * hq_for_jule is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * hq_for_jule is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
	initscr();
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
		refresh();
	}
	cout<<endl<<"press key ... ";
	refresh();
	int x;
	cout<<endl<<getch()<<endl;
	refresh();
	endwin();
	//-----------------------------------------------
	
}