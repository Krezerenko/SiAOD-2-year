#pragma once

#include "TableEntry.h"

#include <ostream>

template<typename T>
class HashTable
{
    TableEntry<T>* m_table;
    unsigned int m_tableSize;
    unsigned int m_takenAmount;
    unsigned int m_deletedAmount;
    unsigned int GetHash(unsigned int key) const;
    unsigned int GetOffset(unsigned int key) const;
public:
    HashTable(unsigned int size);
    HashTable();
    ~HashTable();
    void Insert(unsigned int key, const T& info);
    void Delete(unsigned int key);
    const T* Find(unsigned int key) const;
    void Rehash(unsigned int newSize);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const HashTable<U>& table);
};

#include "HashTable.inl"