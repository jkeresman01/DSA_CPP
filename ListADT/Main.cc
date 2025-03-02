#include "ListADT.h"

#include <iostream>

void FillList(List &list)
{
    list.Insert(0, 10);
    list.Insert(1, 23);
    list.Insert(2, -23);
    list.Insert(3, 34);
    list.Insert(4, 100);
}

void PrintList(const List &list)
{
    for(std::size_t i = 0; i < list.Count(); ++i)
    {
        std::cout << "Elem: " << list.Get(i) << "\r\n";
    }

    std::cout << "\r\n";
}

void InsertMiddle(List &list)
{
    uint32_t middle = list.Count() / 2;

    list.Insert(middle, 500);
    list.Insert(middle + 1, 501);
}

void Search(const List &list, int32_t element)
{
    int32_t result = list.Search(element);

    if(result == -1)
    {
        std::cout << "No can do for element: " << element << "\r\n";
    }
    else
    {
        std::cout << "Element " << element << " exists" << "\r\n";
    }
}

void RemoveElement(List &list, int32_t index)
{
    std::cout << "Removing element at index: " << index << "\r\n";
    list.Remove(index);
    std::cout << "Element at index: " << index << " is removed" << "\r\n";
    std::cout << "\r\n";
}

int main()
{
    List list;

    FillList(list);
    PrintList(list);

    InsertMiddle(list);
    PrintList(list);

    Search(list, 23);
    PrintList(list);

    RemoveElement(list, 1);
    PrintList(list);

    PrintList(list);
    Search(list, 23);
}
