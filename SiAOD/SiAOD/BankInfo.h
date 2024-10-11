#pragma once
#include <string>

#include <ostream>

struct BankInfo
{
    std::string Name;
    std::string Address;
    BankInfo(const std::string& name, const std::string& address);
    BankInfo();

    friend std::ostream& operator<<(std::ostream& os, const BankInfo& info);
};
