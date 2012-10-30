#include <QCoreApplication>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <contacts.h>

using namespace std;
int main(int argc, char *argv[])
{
        
    //------------------------------------------------------------
    srand(time(NULL));

	Person **mas;
	int size=0;
    int Key;
    bool chck=true;
    do
    {
        cout<<"1 - Show\n2 - Add\n3 - Edit\n4 - Search\n5 - Delete\n9 - Exit\n Input Number : ";
        Key = getchar();
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
                DeletePerson (mas, size);
                break;
            }   
            case 57 : // 57 - 9
            {
                chck=false;
                break;
            }
        };
    }
    while (chck);
    //------------------------------------------------------------
}