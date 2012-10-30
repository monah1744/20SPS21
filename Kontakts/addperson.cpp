#include <contacts.h>
void AddKon(Person **&mod, int &size, Person *TempPerson);

void AddKontakt (Person **&mod, int &size)
{
	Person *TempPerson;
	char *tmp= new char [255];
	TempPerson=new Person;
    TempPerson->NumberOfTel=0;
    cls();
	bool check=false;
	do
	{
		std::cout<<"Input Name : ";
		if (!gets(tmp)) exit(-1);
		TempPerson->Name.FirstName = new char [strlen(tmp)+1];
		strcpy(TempPerson->Name.FirstName,tmp);
		if (strlen(TempPerson->Name.FirstName)==0) 
		{
			check=true; 
			std::cout<<"\nName Not empty !!!\n";
			continue;
		}
		else check=false;
	}
	while (check);

    cls();
	check=false;
	do
	{
		std::cout<<"Input Second Name [] : ";
		if (!gets(tmp)) exit(-1);
		TempPerson->Name.SecondName = new char [strlen(tmp)+1];
		strcpy(TempPerson->Name.SecondName,tmp);
	}
	while (check);

    cls();
	check=false;
	do
	{
		std::cout<<"Input Surname [] : ";
		if (!gets(tmp)) exit(-1);
		TempPerson->Name.SurName = new char [strlen(tmp)+1];
		strcpy(TempPerson->Name.SurName,tmp);
	}
	while (check);
    
    cls();
	check=false;
	do
	{
		std::cout<<"Input Telefon [] : ";
		if (!gets(tmp)) exit(-1);
        TempPerson->NumberOfTel++;
        TempPerson->TelNumber = new char *[TempPerson->NumberOfTel];
        TempPerson->TelNumber[TempPerson->NumberOfTel-1] = new char [strlen(tmp)+1];
		strcpy(TempPerson->TelNumber[TempPerson->NumberOfTel-1],tmp);
	}
	while (check);
    
	//============================================================
	check = true;
    int Key;
    cls();
    do
    {
        ShowKontakt(TempPerson);
        std::cout<<"1 - Apply\n2 - Apply & Advanced\n3 - Cancel\nInput Numder : ";
        Key = getchar();
        std::cin.ignore();
        if ((Key>48)&&(Key<52)) check=false;
        else
        {
            cls();
            std::cout<<"Error Input Number !\nTry Again...\n";
            check=true;
        }
    }
    while (check);
    switch (Key)
    {
    case 49 :   // 49 - "1"
    {
        AddKon(mod,size,TempPerson);
        break;
    }
    case 50 :   // 50 - "2"
    {
        AddKon(mod,size,TempPerson);
        EditKontakt (mod,size);
        break;
    }
    case 51 :   // 51 - "3"
    {
        break;
    }
    default :
        break;
    };

	
}
void AddKon(Person **&mod, int &size, Person *TempPerson)
{
    size++;
    if (size==1)
    {
        mod = new Person *[size];
    }
    else
    {
        Person **tmpmod = new Person *[size];
        for (int i=0; i<size-1; i++)
            tmpmod[i]=mod[i];
        delete [] mod;
        mod = tmpmod;
    }
    mod[size-1]=TempPerson;    
}
