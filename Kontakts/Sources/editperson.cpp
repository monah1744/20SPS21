#include <Header/contacts.h>

using namespace std;

void EditKontakt (Person **&mod, int index)
{
    char *tmp= new char [255];    
    cls();
	bool check;
    int Key;
    do
    {
      cls();
      do
      {
          ShowKontakt(mod[index]);
          std::cout<<"1 - Add telefon\t2 - Edit fields\t3 - Exit\nInput Numder : ";
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
      
      check=true;
      switch (Key)
      {
      case 49 :   // 49 - "1"
      {
          cls();
          AddTel(mod[index]->TelNumber,mod[index]->NumberOfTel);
          check=true;
          break;
      }
      case 50 :   // 50 - "2"
      {
          cls();
          cout<<"Name [ \""<<mod[index]->Name.FirstName<<"\" ] : ";
          gets(tmp);
          if (strlen(tmp))
          {
              delete [] mod[index]->Name.FirstName;
              mod[index]->Name.FirstName = new char [strlen(tmp)+1];
              strcpy(mod[index]->Name.FirstName,tmp);
          }
          cout<<"Second Name [ \""<<mod[index]->Name.SecondName<<"\" ] : ";
          gets(tmp);
          if (strlen(tmp))
          {
              delete [] mod[index]->Name.SecondName;
              mod[index]->Name.SecondName = new char [strlen(tmp)+1];
              strcpy(mod[index]->Name.SecondName,tmp);
          }
          cout<<"SurName [ \""<<mod[index]->Name.SurName<<"\" ] : ";
          gets(tmp);
          if (strlen(tmp))
          {
              delete [] mod[index]->Name.SurName;
              mod[index]->Name.SurName = new char [strlen(tmp)+1];
              strcpy(mod[index]->Name.SurName,tmp);
          }
          if (mod[index]->NumberOfTel)
          {
              for (int i=0;i<mod[index]->NumberOfTel;i++)
              {
                  cout<<"Tel ("<<i+1<<")  ["<<mod[index]->TelNumber[i]<<"] : ";
                  gets(tmp);
                  if (strlen(tmp))
                  {
                      delete [] mod[index]->TelNumber[i];
                      mod[index]->TelNumber[i] = new char [strlen(tmp)+1];
                      strcpy(mod[index]->TelNumber[i],tmp);
                  }
              }
          }
          if(mod[index]->Birthday.Day||mod[index]->Birthday.Month||mod[index]->Birthday.Year)
          {
              cout<<"Day of Birhtday ["<<mod[index]->Birthday.Day<<"] : ";
              gets(tmp);
              if (strlen(tmp))
              {
                  mod[index]->Birthday.Day=atoi(tmp);
                  if (mod[index]->Birthday.Day==0) mod[index]->Birthday.Day=-1;
              }

              cout<<"Month of Birhtday ["<<mod[index]->Birthday.Month<<"] : ";
              
              cin>>mod[index]->Birthday.Month;
              cout<<"Year of Birhtday ["<<mod[index]->Birthday.Year<<"] : ";
              
              cin>>mod[index]->Birthday.Year;
          }
          else
          {
              cout<<"Day of Birhtday [] : ";
              cin>>mod[index]->Birthday.Day;
              cout<<"Month of Birhtday [] : ";
              cin>>mod[index]->Birthday.Month;
              cout<<"Year of Birhtday [] : ";
              cin>>mod[index]->Birthday.Year;
          }
          check=true;
          break;
      }
      case 51 :   // 51 - "3"
      {
          cls();
          check=false;
          break;
      }
      default :
          cls();
          check=true;
          break;
      };
    }    
    while (check);
}