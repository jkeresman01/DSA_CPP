#pragma once

#include <cstdint>

class List
{
    public:
        List();
        virtual ~List();

        int32_t Get(uint32_t index) const;
        void Insert(uint32_t index, int32_t value);
        int32_t Search(int32_t value) const;
        void Remove(uint32_t index);
        uint32_t Count() const;
        
    private:
        uint32_t m_Count;
        int32_t* m_Items;
};
