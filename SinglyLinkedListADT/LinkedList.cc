#include "LinkedList.h"

#include <cstddef>
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() : m_Count(0)
{
    m_Head = NULL;
    m_Tail = NULL;
}
        
template <typename T>
Node<T> * LinkedList<T>::Get(const int32_t index) const
{
    if(index < 0 || index > m_Count)
    {
        return NULL;
    }

    Node<T> * node = m_Head;

    for(std::size_t i = 0; i < index; ++i)
    {
        node = node->Next;
    }
    
    return node;
}

template <typename T>
void LinkedList<T>::InsertHead(const T value)
{
    Node<T> * node = new Node<T>(value);
    node->Next = m_Head;

    m_Head = node;

    if(m_Count == 0)
    {
        m_Tail = m_Head;
    }

    m_Count++;
}

template <typename T>
void LinkedList<T>::InsertTail(const T value)
{
    if(m_Count == 0)
    {
        InsertHead(value);
        return;
    }

    Node<T> * node = new Node<T>(value);

    m_Tail->Next = node;

    m_Tail = node;

    m_Count++;
}

template <typename T>
void LinkedList<T>::Insert(const int32_t index, const T value)
{
   if(index < 0 || index > m_Count)
   {
        return;
   }

   if(index == 0)
   {
        InsertHead(value);
        return;
   }

   if(index == m_Count)
   {
        InsertTail(value);
        return;
   }

   Node<T> * previous = m_Head;

   for(std::size_t i = 0; i < index; ++i)
   {
       previous = previous->Next;
   }

   Node<T> * nextNode = previous->Next;

   Node<T> * node = new Node<T>(value);

   node->Next = nextNode;
   previous->Next = node;

   m_Count++;
}

template <typename T>
int32_t LinkedList<T>::Search(const T value) const
{
    if(m_Count == 0)
    {
        return -1;
    }

    int32_t index = 0;

    Node<T> * node = m_Head;

    while(node->Value != value)
    {
        index++;
        node = node->Next;

        if(node == NULL)
        {
            return -1;
        }
    }

    return index;
}


template <typename T>
void LinkedList<T>::RemoveHead()
{
    if(m_Count == 0)
    {
        return;
    }

    Node<T> * node = m_Head;

    m_Head = m_Head->Next;

    delete node;
}

template <typename T>
void LinkedList<T>::RemoveTail()
{
    if(m_Count == 0)
    {
        return;
    }

    if(m_Count == 1)
    {
        RemoveHead();
        return;
    }

    Node<T> * previous = m_Head;

    Node<T> * node = m_Head->Next;

    while(node->Next != NULL)
    {
        previous = previous->Next;
        node = node->Next;
    }

    previous->Next = NULL;
    m_Tail = previous;

    delete node;

    m_Count--;
}

template <typename T>
void LinkedList<T>::Remove(const int32_t index)
{
    if(m_Count == 0)
    {
        return;
    }

    if(index < 0 || index > m_Count)
    {
        return;
    }

    if(index == 1)
    {
        RemoveHead();
        return;
    }

    if(index == m_Count - 1)
    {
        RemoveTail();
        return;
    }

    Node<T> * previous = m_Head;

    for(std::size_t i = 0; i < index - 1; ++i)
    {
        previous = previous->Next;
    }

    Node<T> * node = previous->Next;
    Node<T> * nexNode = node->Next;
    previous->Next = nexNode;

    delete node;

    m_Count--;
}

template <typename T>
int32_t LinkedList<T>::GetCount() const
{
    return m_Count;
}

template <typename T>
Node<T> * LinkedList<T>::GetHead() const
{
    return m_Head;
}

template <typename T>
Node<T> * LinkedList<T>::GetTail() const
{
    return m_Tail;
}

template <typename T>
void LinkedList<T>::Print() const
{
    Node<T> * node = m_Head;

    while(node != NULL)
    {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }

    std::cout << "NULL" << "\r\n";
}
