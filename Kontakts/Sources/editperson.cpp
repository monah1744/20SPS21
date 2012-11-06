#include <Header/contacts.h>

using namespace std;

void EditKontakt (Person **&mod, int index)
{
    char *tmp= new char [255];    
    cls();
	bool check=false;
	do
	{
        cout<<"Name [ \""<<&mod[index]->Name.FirstName<<"\" ] : ";
        cout<<"Name [ \""<<mod[index]->Name.FirstName<<"\" ] : ";
		gets(tmp);
        cout<<endl<<"gets - "<<tmp<<endl;
        cout<<endl<<"lenght - "<<strlen(tmp)<<endl;
        cout<<endl<<"size First - "<<sizeof(mod[index]->Name.FirstName)<<endl;
        cout<<endl<<"lenght Second - "<<strlen(mod[index]->Name.SecondName)<<endl;
        cout<<endl<<"size Second - "<<sizeof(mod[index]->Name.SecondName)<<endl;

        if (strlen(tmp))
        {
            cout<<endl<<"Отработка delete"<<endl;
            delete [] mod[index]->Name.FirstName;
            cout<<endl<<"Отработка New"<<endl;
            mod[index]->Name.FirstName = new char [strlen(tmp)+1];
            cout<<endl<<"Отработка Copy"<<endl;
            strcpy(mod[index]->Name.FirstName,tmp);
        }
        cout<<"second\n";
        //cout<<"Second Name [ \""<<&mod[index]->Name.SecondName<<"\" ] : ";
        //cout<<strlen(mod[index]->Name.SecondName)<<" -strlen ";
        //cout<<"Second Name [ \""<<mod[index]->Name.SecondName<<"\" ] : ";
		//gets(tmp);
        //if (strlen(tmp))
        //{
        //    delete [] mod[index]->Name.SecondName;
        //    mod[index]->Name.SecondName = new char [strlen(tmp)+1];
        //    strcpy(mod[index]->Name.SecondName,tmp);
        //}
        
        
        
        
        
        
        
        
        
        
        
		/*if (strlen(TempPerson->Name.FirstName)==0) 
		{
			check=true;
            cls();
			std::cout<<"\nName Not empty !!!\n";
			continue;
		}
		else check=false;*/
	}
	while (check);
}
