#pragma once

#include "HashTable.h"
#include "Global.h"

#include <ostream>

template<typename T>
HashTable<T>::HashTable(unsigned int size)
{
    if (size <= 1) size = 2;
    m_tableSize = size;
    m_table = new TableEntry<T>[m_tableSize];
    m_deletedAmount = 0;
    m_takenAmount = 0;
}

template<typename T>
HashTable<T>::HashTable()
    : HashTable(2)
{
}

template<typename T>
HashTable<T>::~HashTable()
{
    delete[] m_table;
}

template<typename T>
unsigned int HashTable<T>::GetHash(const unsigned int key) const
{
    return key % m_tableSize;
}

template <typename T>
unsigned int HashTable<T>::GetOffset(unsigned int key) const
{
    if ((key / m_tableSize) % m_tableSize == 0) return 1;
    return key / m_tableSize;
}

template<typename T>
void HashTable<T>::Insert(const unsigned int key, const T& info)
{
    unsigned int i = GetHash(key);
    while (m_table[i].IsTaken)
    {
        if (m_table[i].Key == key) return;
        i = GetHash(i + GetOffset(key));
    }
    m_table[i].Key = key;
    m_table[i].Info = info;
    m_table[i].IsTaken = true;
    ++m_takenAmount;
    if (m_table[i].IsDeleted)
    {
        m_table[i].IsDeleted = false;
        --m_deletedAmount;
    }
    if (static_cast<float>(m_takenAmount + m_deletedAmount) / m_tableSize <= 0.75f) return;

    Rehash(GetNextPrime(m_tableSize * 2));
}

template<typename T>
void HashTable<T>::Delete(const unsigned int key)
{
    unsigned int hash = GetHash(key);
    while (m_table[hash].IsTaken || m_table[hash].IsDeleted)
    {
        if (m_table[hash].Key == key)
        {
            m_table[hash].IsTaken = false;
            --m_takenAmount;
            m_table[hash].IsDeleted = true;
            ++m_deletedAmount;
            return;
        }
        hash = GetHash(hash + GetOffset(key));
    }
}

template<typename T>
const T* HashTable<T>::Find(unsigned int key) const
{
    unsigned int hash = GetHash(key);
    while (m_table[hash].IsTaken || m_table[hash].IsDeleted)
    {
        if (m_table[hash].Key == key && !m_table[hash].IsDeleted)
        {
            return &m_table[hash].Info;
        }
        hash = GetHash(hash + GetOffset(key));
    }
    return nullptr;
}

template <typename T>
void HashTable<T>::Rehash(unsigned int newSize)
{
    TableEntry<T>* newTable = new TableEntry<T>[newSize];
    TableEntry<T>* temp = m_table;
    unsigned int tempSize = m_tableSize;
    m_table = newTable;
    m_tableSize = newSize;
    m_takenAmount = 0;
    m_deletedAmount = 0;
    for (unsigned int i = 0; i < tempSize; ++i)
    {
        if (temp[i].IsTaken)
        {
            Insert(temp[i].Key, temp[i].Info);
        }
    }

    delete[] temp;
}


template<typename U>
std::ostream& operator<<(std::ostream& os, const HashTable<U>& table)
{
    for (unsigned int i = 0; i < table.m_tableSize; ++i)
    {
        //if (!table.m_table[i].IsTaken) continue;
        os << table.m_table[i] << '\n';
    }
    return os;
}
