#include <Header/contacts.h>
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
            cls();
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
        AddTel(TempPerson->TelNumber,TempPerson->NumberOfTel);
	}
	while (check);
    
	//============================================================
    TempPerson->Name.SecondName = new char [1];
    strcpy(TempPerson->Name.SecondName,"");
    TempPerson->Bussines.Email = new char [1];
    strcpy(TempPerson->Bussines.Email,"");
    TempPerson->Bussines.ICQ = new char [1];
    strcpy(TempPerson->Bussines.ICQ,"");
    TempPerson->Bussines.Jabber = new char [1];
    strcpy(TempPerson->Bussines.Jabber,"");
    TempPerson->Bussines.Skype = new char [1];
    strcpy(TempPerson->Bussines.Skype,"");
    TempPerson->Birthday.Day=-1;
    TempPerson->Birthday.Month=-1;
    TempPerson->Birthday.Year=-1;
    //============================================================


    check = true;
    int Key;
    cls();
    do
    {
        ShowKontakt(TempPerson);
        std::cout<<"1 - Apply\t2 - Apply & Advanced\t3 - Cancel\nInput Numder : ";
        Key = getchar();
        std::cin.ignore();
        if ((Key>48)&&(Key<52)) check=false;
        else
        {
            cls();
            std::cout<<"Error Input Number !\tTry Again...\n";
            check=true;
        }
    }
    while (check);
    switch (Key)
    {
    case 49 :   // 49 - "1"
    {
        cls();
        AddKon(mod,size,TempPerson);
        break;
    }
    case 50 :   // 50 - "2"
    {
        cls();
        AddKon(mod,size,TempPerson);
        EditKontakt (mod,size-1);
        break;
    }
    case 51 :   // 51 - "3"
    {
        cls();
        break;
    }
    default :
        cls();
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
void AddTel(char **&TelNumber, int &Numberoftel)
{
    char *tmp = new char [255];
    std::cout<<"Input Telefon [] : ";
    gets(tmp);
    Numberoftel++;
    if (Numberoftel==1)
    {
        char **TempNum = new char *[Numberoftel];
        TempNum[Numberoftel-1] = new char [strlen(tmp)+1];
        strcpy(TempNum[Numberoftel-1],tmp);
        //delete [] TelNumber;
        TelNumber = TempNum;
    }
    else
    {

        char **TempNum = new char *[Numberoftel];
        for (int i=0;i<(Numberoftel-1);i++)
            TempNum[i]=TelNumber[i];
        TempNum[Numberoftel-1] = new char [strlen(tmp)+1];
        strcpy(TempNum[Numberoftel-1],tmp);
        delete [] TelNumber;
        TelNumber = TempNum;
    }
}