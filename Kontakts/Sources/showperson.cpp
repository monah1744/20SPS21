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
        cout<<mod->Name.SurName<<"  "<<mod->Name.FirstName<<"  ";
        if (mod->NumberOfTel>0) cout<<mod->TelNumber[0]<<"\n";
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
    int tmp;
    cout<<"Введите индекс контакта : ";
    cin>>tmp;
    cin.ignore();
    if ((tmp>0)||(tmp<=size))
    {
        return (tmp-1);
    }
    else 
    {
        cls();
        cout<<"Такого индекса не существует";
        return Index(size);
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
