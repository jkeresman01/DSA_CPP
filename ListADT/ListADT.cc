#include "ListADT.h"

List::List() : m_Count(0)
{
    m_Items = new int32_t[m_Count];
}

List::~List()
{
    if(m_Items)
    {
        delete []m_Items;
    }
}

int32_t List::Get(uint32_t index) const
{
    if(index < 0 or index > m_Count)
    {
        return -1;
    }

    return m_Items[index];
}

void List::Insert(uint32_t index, int32_t value)
{
    if(index < 0 or index > m_Count)
    {
        return;
    }
    
    int32_t* oldArray = m_Items;

    m_Items = new int32_t[++m_Count];

    for(std::size_t i = 0, j = 0; i < m_Count; ++i)
    {
        if(index == i)
        {
            m_Items[i] = value;
        }
        else
        {
            m_Items[i] = oldArray[j++];
        }
    }

    delete []oldArray;
}

int32_t List::Search(int32_t value) const
{
    for(std::size_t i = 0; i < m_Count; ++i)
    {
        if(m_Items[i] == value)
        {
            return i;
        }
    }

    return -1;
}

void List::Remove(uint32_t index)
{
    if(index < 0 || index > m_Count)
    {
        return;
    }

    int32_t *oldArray = m_Items;

    m_Items = new int32_t[--m_Count];

    for(std::size_t i = 0, j = 0; i < m_Count; ++i, ++j)
    {
        if(index == j)
        {
            ++j;
        }

        m_Items[i] = oldArray[j];
    }

    delete []oldArray;
}

uint32_t List::Count() const
{
    return m_Count;
}
