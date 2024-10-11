#pragma once
#include <ostream>

template<typename T>
struct TableEntry
{
    unsigned int Key;
    T Info;
    bool IsTaken;
    bool IsDeleted;
    TableEntry<T>(unsigned int key, const T& info, bool isTaken, bool isDeleted);
    TableEntry<T>(unsigned int key, const T& info);
    TableEntry<T>(const TableEntry<T>& table);
    TableEntry<T>();

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const TableEntry<U>& entry);
};

#include "TableEntry.inl"
