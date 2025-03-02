#include "Node.h"

#include <cstdint>

template <typename T>
class LinkedList
{
    public:
        LinkedList();
        
        Node<T> * Get(int32_t index) const;

        void InsertHead(T value);
        void InsertTail(T value);
        void Insert(int32_t index, T value);

        int32_t Search(T value) const;

        void RemoveHead();
        void RemoveTail();
        void Remove(int32_t index);

        int32_t Count() const;
        void Print() const;

        Node<T> * GetHead() const;
        Node<T> * GetTail() const;

    private:
        Node<T> * m_Head;
        Node<T> * m_Tail;

        int32_t m_Count;
};
