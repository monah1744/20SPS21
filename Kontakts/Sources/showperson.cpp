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
    cout<<"Введите индекс контакта "<<size<<" : ";
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
        cout<<"Такого индекса не существует";
        return (Index(size));
    }
}

void cls()
{
#ifdef linux
    //system("clear");
#endif
#ifdef windows
    system("cls");
#endif
}
