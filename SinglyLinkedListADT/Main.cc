#include <iostream>

#include "LinkedList.h"

void FillLinkedList(LinkedList<int32_t> &linkedList)
{
     // 43 -> NULL
    linkedList.InsertHead(43);

    // 76 -> 43 -> NULL
    linkedList.InsertHead(76);

    // 76 -> 43 -> 15 -> NULL
    linkedList.InsertTail(15);

    // 76 -> 43 -> 15 -> 44 -> NULL
    linkedList.InsertTail(44);

    // 76 -> 43 -> 15 -> 44 -> 100 ->NULL
    linkedList.Insert(4, 100);

    // 76 -> 43 -> 15 -> 48 -> 44 -> 100 ->NULL
    linkedList.Insert(3, 48);

    // 22 -> 76 -> 43 -> 15 -> 48 -> 44 -> 100 ->NULL
    linkedList.Insert(0, 22);

    linkedList.Print();
}

void GetValue(const LinkedList<int32_t> &linkedList, const int32_t index)
{
    Node<int32_t> * getResult = linkedList.Get(2);

    if(getResult == NULL)
    {
        std::cout << "Found value:" << getResult->Value << "\r\n";
    }
    else
    {
        std::cout << "404 NOT FOUND for index: " << index << "\r\n";
    }
}

void Search(const LinkedList<int32_t> &linkedList, const int32_t value)
{
    int32_t index = linkedList.Search(value);
    std::cout << "Index of element: " << value << " is " << index << "\r\n";
}

void RemoveAtSelectedIndex(LinkedList<int32_t> &linkedList, const int32_t index)
{
    linkedList.Remove(index);
    linkedList.Print();
}

void RemoveHead(LinkedList<int32_t> &linkedList)
{
    linkedList.RemoveHead();
    linkedList.Print();
}

void RemoveTail(LinkedList<int32_t> &linkedList)
{
    linkedList.RemoveTail();
    linkedList.Print();
}

void GetHead(const LinkedList<int32_t> &linkedList)
{
    Node<int32_t> * head = linkedList.GetHead();
    std::cout << "Head: " << head->Value << "\r\n";
}

void GetTail(const LinkedList<int32_t> &linkedList)
{
    Node<int32_t> * tail = linkedList.GetTail();
    std::cout << "Tail: " << tail->Value << "\r\n";
}

int main()
{
    LinkedList<int32_t> linkedList;
    FillLinkedList(linkedList);

    GetValue(linkedList, 2);
    Search(linkedList, 15);

    RemoveAtSelectedIndex(linkedList, 0);
    RemoveAtSelectedIndex(linkedList, 5);

    RemoveHead(linkedList);
    RemoveTail(linkedList);

    GetHead(linkedList);
    GetTail(linkedList);
}
