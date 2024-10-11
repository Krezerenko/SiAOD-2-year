#include "BankInfo.h"

#include <ostream>


BankInfo::BankInfo(const std::string& name, const std::string& address)
{
    Name = name;
    Address = address;
}

BankInfo::BankInfo()
    : BankInfo("None", "None")
{
}

std::ostream& operator<<(std::ostream& os, const BankInfo& info)
{
    return os << info.Name + ", " + info.Address;
}
