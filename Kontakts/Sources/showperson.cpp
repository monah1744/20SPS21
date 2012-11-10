#include <Header/contacts.h>

#include <string.h>

using namespace std;
void ShowPerson (Person **&mod,int &size)
{
    for (int i=0; i<size; i++)
    {
        cout<<i+1<<"  "<<mod[i]->Name.SurName<<"  "<<mod[i]->Name.FirstName<<"  ";
        if (mod[i]->NumberOfTel>0) cout<<mod[i]->TelNumber[0]<<"\n";
    }
}

void ShowKontakt (Person *&mod)
{
    {
        cout<<mod->Name.SurName<<"  "<<mod->Name.FirstName<<"  "<<mod->Name.SecondName<<" \n";
        if (mod->NumberOfTel>0)
        {
            cout<<"Tel : \n";
            ShowTel(mod->TelNumber,mod->NumberOfTel);
        }
        if (mod->Birthday.Day>0||mod->Birthday.Month>0||mod->Birthday.Year>0)
        {
            cout<<"BirthDay : "<<mod->Birthday.Day<<"."<<mod->Birthday.Month<<"."<<mod->Birthday.Year<<endl;
        }
        if (strlen(mod->Bussines.Email)>0) cout<<"Email : "<<mod->Bussines.Email<<endl;
        if (strlen(mod->Bussines.ICQ)>0) cout<<"ICQ : "<<mod->Bussines.ICQ<<endl;
        if (strlen(mod->Bussines.Jabber)>0) cout<<"Jabber : "<<mod->Bussines.Jabber<<endl;
        if (strlen(mod->Bussines.Skype)>0) cout<<"Skype : "<<mod->Bussines.Skype<<endl;
    }
}

void ShowTel(char **&TelNumber, int &Numberoftel)
{
    for (int i=0;i<Numberoftel;i++)
    {
        cout<<"\t"<<i+1<<" -\t"<<TelNumber[i]<<endl;
    }
}

void SearchPerson (Person **&mod, int &size)
{
    cls();
    cout<<"Input part of (Name, Surname) : ";
    char *tmp= new char [255];
    gets(tmp);
    int ch=0;
    for (int i=0;i<size;i++)
    {
        if (strstr(mod[i]->Name.FirstName,tmp)||strstr(mod[i]->Name.SurName,tmp))
        {
            cout<<i+1<<" -\t"<<mod[i]->Name.SurName<<" "<<mod[i]->Name.FirstName<<" ";
            if (mod[i]->NumberOfTel) cout<<mod[i]->TelNumber[0];
            ch++;
            cout<<endl;
        }
    }
    if (ch)
        cout<<"Found "<<ch<<" results"<<endl;
    else
        cout<<"Not results"<<endl;
}

void DetailsPerson (Person **&mod, int &size)
{
    cls();
    ShowKontakt(mod[Index(size)]);
}

void BirthdayPerson(Person **&mod, int &size)
{
    cls();
    int month;
    cout<<"Input Month : ";
    cin>>month;
    cin.ignore();
    if (month>0&&month<13)
    for (int i=0;i<size;i++)
    {
        if (mod[i]->Birthday.Month==month)
        {
            cout<<i+1<<" -\t"<<mod[i]->Name.SurName<<" "<<mod[i]->Name.FirstName<<" -\t";
            cout<<mod[i]->Birthday.Day<<"."<<mod[i]->Birthday.Month<<"."<<mod[i]->Birthday.Year;
            cout<<endl;
        }
    }
    else
        cout<<"Out of range"<<endl;
}

int Index(int size)
{
    int N;
    cout<<"Enter index "<<size<<" : ";
    cin>>N;
    cin.ignore();
    if ((N>0)&&(N<=size))
    {
        N--;
        return N;
    }
    else 
    {
        cls();
        cout<<"Not real Index !!!";
        return (Index(size));
    }
}

void cls()
{
#ifdef linux
    system("clear");
#endif
#ifdef windows
    system("cls");
#endif
}
