#include <QCoreApplication>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <Header/contacts.h>

using namespace std;
int main(int argc, char *argv[])
{
        
    //------------------------------------------------------------
    srand(time(NULL));

    cls();
	Person **mas;
	int size=0;
    int Key;
    bool chck=true;
    do
    {
        cout<<"1 - Show\t2 - Add\t\t3 - Edit\t4 - Search\t5 - Details\t6 - Delete\t7 - Birthday\t9 - Quit\nInput Number : ";
        Key = getchar();
        cin.ignore();
        switch (Key)
        {
            case 49 : // 49 - 1
            {
                cls();
                ShowPerson (mas, size);
                break;
            }
            case 50 : // 50 - 2
            {
                AddKontakt (mas, size);
                break;
            }
            case 51 : // 51 - 3
            {
                EditKontakt (mas, Index(size));
                break;
            }
            case 52 : // 52 - 4
            {
                SearchPerson (mas, size);
                break;
            }        
            case 53 : // 53 - 5
            {
                DetailsPerson (mas, size);
                break;
            }
            case 54 :   //54 - 6
            {
                DeletePerson (mas, size);
                break;
            }
            case 55 :   //55 - 7
            {
                BirthdayPerson(mas, size);
                break;
            }
            case 57 : // 57 - 9
            {
                chck=false;
                if (size>0) delete [] mas;
                break;
            }
            default :
            {
                cls();
            }
        }
    }
    while (chck);
    //------------------------------------------------------------
}
