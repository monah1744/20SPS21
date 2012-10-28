#include <stdlib.h>
#include <string.h>

struct fio {
	char * FirstName;
	char * SecondName;
	char * ThirdName;
};
struct Date {
	int Day;
	int Month;
	int Year;
};
struct Net {
	char * Email;
	char * ICQ;
	char * Skype;
	char * Jabber;
};
struct Person {
	fio Name;
	Date Birthday;
	Net Bussines;
	char **Tel;
};

void AddPerson(Person **&mod, int &size)
{
	Person *TempPerson;
	char *tmp= new char [255];
	TempPerson=new Person;
	system("cls");
	bool check=false;
	do
	{
		std::cout<<"Введите Имя : ";
		if (!gets(tmp)) exit(-1);
		TempPerson->Name.FirstName = new char [strlen(tmp)+1];
		strcpy(TempPerson->Name.FirstName,tmp);
		if (strlen(TempPerson->Name.FirstName)==0) 
		{
			check=true; 
			std::cout<<"\nИмя не может быть пустым !!!\n";
			continue;
		}
		else check=false;
	}
	while (check);

	system("cls");
	check=false;
	do
	{
		std::cout<<"Введите Отчество [] : ";
		if (!gets(tmp)) exit(-1);
		TempPerson->Name.ThirdName = new char [strlen(tmp)+1];
		strcpy(TempPerson->Name.ThirdName,tmp);
	}
	while (check);

	system("cls");
	check=false;
	do
	{
		std::cout<<"Введите Фамилию [] : ";
		if (!gets(tmp)) exit(-1);
		TempPerson->Name.SecondName = new char [strlen(tmp)+1];
		strcpy(TempPerson->Name.SecondName,tmp);
	}
	while (check);

	//============================================================
	
	size++;
	if (size==1)
	{
		std::cout<<"База пустая. Попытка создать ..."<<std::endl;
		mod = new Person *[size];
		std::cout<<"Успешно :)"<<std::endl;
	}
	else
	{
		std::cout<<"Попытка добавить ..."<<std::endl;
		Person **tmpmod = new Person *[size];
		for (int i=0; i<size-1; i++)
			tmpmod[i]=mod[i];
		delete [] mod;
		mod = tmpmod;
	}
	mod[size-1]=TempPerson;
	std::cout<<"Добавление успешно :)"<<std::endl;
}