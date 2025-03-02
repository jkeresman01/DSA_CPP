#include "Node.h"

#include <cstdint>

template <typename T>
class LinkedList
{
    public:
        LinkedList();
        
        Node<T> * Get(const int32_t index) const;

        void InsertHead(const T value);
        void InsertTail(const  T value);
        void Insert(const int32_t index, const T value);

        int32_t Search(const T value) const;

        void RemoveHead();
        void RemoveTail();
        void Remove(const int32_t index);

        int32_t GetCount() const;
        void Print() const;

        Node<T> * GetHead() const;
        Node<T> * GetTail() const;

    private:
        Node<T> * m_Head;
        Node<T> * m_Tail;

        int32_t m_Count;
};
