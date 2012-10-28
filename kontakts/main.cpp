#include <iostream>
#include <time.h>
#include <locale>
#include "contacs.h"

using namespace std;

void main ()
{
	setlocale(LC_ALL,"rus");
	srand(time(NULL));

	Person **mas;
	int size=0;
	AddPerson(mas, size);
	cout<<mas[0]->Name.ThirdName<<"\t";
	cout<<mas[0]->Name.FirstName<<"\t";
	cout<<mas[0]->Name.SecondName<<"\t";
}