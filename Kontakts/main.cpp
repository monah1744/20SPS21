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
        cout<<"1 - Show\t2 - Add\t\t3 - Edit\t4 - Search\t5 - Delete\t9 - Exit\nInput Number : ";
        Key = getchar();
        cls();
        cin.ignore();
        switch (Key)
        {
            case 49 : // 49 - 1
            {
                ShowPerson (mas, size);
                break;
            }
            case 50 : // 50 - 2
            {
                AddKontakt (mas, size);
                cls();
                break;
            }
            case 51 : // 51 - 3
            {
                EditKontakt (mas, Index(size));
                cls();
                break;
            }
            case 52 : // 52 - 4
            {
                SearchPerson (mas, size);
                cls();
                break;
            }        
            case 53 : // 53 - 5
            {
                DeletePerson (mas, size);
                cls();
                break;
            }   
            case 57 : // 57 - 9
            {
                chck=false;
                cls();
                break;
            }
        };
    }
    while (chck);
    //------------------------------------------------------------
}
