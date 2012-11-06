#include <Header/contacts.h>

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
        cout<<mod->Name.SurName<<"  "<<mod->Name.FirstName<<"  "<<mod->Name.SecondName<<" ";
        if (mod->NumberOfTel>0)
        {
            cout<<"\nTel : \n";
            for (int i=0;i<mod->NumberOfTel;i++)
            {
                cout<<"\t"<<mod->TelNumber[i]<<endl;
            }
        }
        if (mod->Birthday.Day>0||mod->Birthday.Month>0||mod->Birthday.Year>0)
        {
            cout<<"BirthDay : "<<mod->Birthday.Day<<" - "<<mod->Birthday.Month<<" - "<<mod->Birthday.Year<<endl;
        }
        if (strlen(mod->Bussines.Email)>0) cout<<"Email : "<<mod->Bussines.Email<<endl;
        if (strlen(mod->Bussines.ICQ)>0) cout<<"ICQ : "<<mod->Bussines.ICQ<<endl;
        if (strlen(mod->Bussines.Jabber)>0) cout<<"Jabber : "<<mod->Bussines.Jabber<<endl;
        if (strlen(mod->Bussines.Skype)>0) cout<<"Skype : "<<mod->Bussines.Skype<<endl;
    }
}

void ShowTel(Person *&mod)
{
    for (int i=0;i<mod->NumberOfTel;i++)
    {
        cout<<"\t"<<mod->TelNumber[i]<<endl;
    }
}


void SearchPerson (Person **&mod, int &size)
{
    
}

void DeletePerson (Person **&mod, int &size)
{
    
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