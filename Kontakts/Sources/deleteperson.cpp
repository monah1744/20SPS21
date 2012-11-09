#include <Header/contacts.h>

void DeletePerson (Person **&mod, int &size)
{
    if (size)
    {
    ShowPerson (mod,size);
    int index;
    index = Index(size);
    bool check;
    int Key;
    do
    {
        cls();
        ShowKontakt(mod[index]);
        std::cout<<"You want delete this Kontakt ?\n";
        std::cout<<"1 - Yes\t2 - No\n";
        Key = getchar();
        std::cin.ignore();
        if ((Key>48)&&(Key<51)) check=false;
        else
        {
            cls();
            std::cout<<"Error Input Number !\tTry Again...\n";
            check=true;
        }
    }
    while(check);
    switch (Key)
    {
    case 49 :   //49 - "1"
    {
        Person **Tempmod = new Person *[size-1];
        int i=0;
        int k=0;
        while (i<(size-1))
        {
            if (i==index) i++;
            Tempmod[k]=mod[i];
            i++;
            k++;
        }
        size--;
        delete [] mod;
        mod = Tempmod;
        break;
    }
    case 50 :   //50 - "2"
    {
        break;
    }
    default :
    {
        cls();
        break;
    }
    }
    }
    else
    {
        std::cout<<"Data Of Kontakts - Empty !\n";
        sleep(2);
    }

}





void DeleteTel (char **&TelNumber, int &Numberoftel)
{
    if (Numberoftel)
    {
    ShowTel(TelNumber,Numberoftel);
    int index;
    index = Index(Numberoftel);
    bool check;
    int Key;
    do
    {
        cls();
        std::cout<<"You want delete Tel ["<<TelNumber[index]<<"] ?\n";
        std::cout<<"1 - Yes\t2 - No\n";
        Key = getchar();
        std::cin.ignore();
        if ((Key>48)&&(Key<51)) check=false;
        else
        {
            cls();
            std::cout<<"Error Input Number !\tTry Again...\n";
            check=true;
        }
    }
    while(check);
    switch (Key)
    {
    case 49 :   //49 - "1"
    {
        char **TempNum = new char *[Numberoftel-1];
        int i=0;
        int k=0;
        while (i<(Numberoftel-1))
        {
            if (i==index) i++;
            TempNum[k]=TelNumber[i];
            i++;
            k++;
        }
        Numberoftel--;
        delete [] TelNumber;
        TelNumber = TempNum;
        break;
    }
    case 50 :   //50 - "2"
    {
        break;
    }
    default :
    {
        cls();
        break;
    }
    }
    }
    else
    {
        std::cout<<"Data Of tel - Empty !\n";
        sleep(3);
    }
}
