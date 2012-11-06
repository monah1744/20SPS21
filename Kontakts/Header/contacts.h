#ifndef CONTACTS_H
#define CONTACTS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fio {
	char * FirstName;
	char * SecondName;
	char * SurName;
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
    int NumberOfTel;
	char **TelNumber;
};

void AddKontakt (Person **&mod, int &size);
void AddTel(char **&TelNumber, int &Numberoftel);
void ShowPerson (Person **&mod, int &size);
void ShowKontakt (Person *&mod);
void EditKontakt (Person **&mod, int index);
void SearchPerson (Person **&mod, int &size);
void DeletePerson (Person **&mod, int &size);
void cls();
int Index(int size);

#endif // CONTACTS_H