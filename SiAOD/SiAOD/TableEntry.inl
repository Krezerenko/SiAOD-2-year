#pragma once

#include "TableEntry.h"

#include <ostream>

template <typename T>
TableEntry<T>::TableEntry(unsigned int key, const T& info, bool isTaken, bool isDeleted)
{
    Key = key;
    Info = info;
    IsTaken = isTaken;
    IsDeleted = isDeleted;
}

template <typename T>
TableEntry<T>::TableEntry(unsigned int key, const T& info)
    : TableEntry(key, info, false, false)
{
}

template <typename T>
TableEntry<T>::TableEntry(const TableEntry<T>& table)
    : TableEntry(table.Key, table.Info, table.IsTaken, table.IsDeleted)
{
}

template <typename T>
TableEntry<T>::TableEntry()
    : TableEntry(0, T(), false, false)
{
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const TableEntry<U>& entry)
{
    return os << entry.Key << ", " << entry.Info;
}
