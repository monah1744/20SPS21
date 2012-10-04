#ifndef MY_ARRAY_H
#define MY_ARRAY_H

//======================================================================

template <typename Tarr, typename Def> Tarr* ArrayInc (Tarr *arr, int* Index, int Pos, Def Num)
{
    *Index=*Index+1;
    Tarr *arr1 = new Tarr[*Index];
    for (int i=0;i<*Index-1;i++)
        *(arr1+i)=*(arr+i);
    delete [] arr;
    for (int i=*Index-1;i>Pos;i--)
        *(arr1+i)=*(arr1+i-1);
    *(arr1+Pos)=Num;
    return arr1;
}

template <typename Tarr> Tarr* ArrayDec (Tarr *arr, int* Index, int Pos)
{
    for (int i=Pos;i<*Index-1;i++)
        *(arr+i)=*(arr+i+1);
    *Index=*Index-1;

    Tarr *arr1 = new Tarr[*Index];
    for (int i=0;i<*Index;i++)
        *(arr1+i)=*(arr+i);
    delete [] arr;
    return arr1;
}

template <typename Tarr> void ArrayShow (Tarr *arr, int* Index)
{
    for (int i=0;i<*Index;i++)
        std::cout<<*(arr+i)<<"\t";
}

#endif // MY_ARRAY_H
