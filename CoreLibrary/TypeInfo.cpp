#include "CoreLibrary/Type/TypeInfo.hpp"

TypeInfo::TypeInfo() : _info(NULL)
{

}

TypeInfo::TypeInfo(const std::type_info &info) : _info(&info)
{

}

TypeInfo::TypeInfo(const TypeInfo &info) : _info(info._info)
{

}

bool    TypeInfo::before(const TypeInfo &info) const
{
    return this->_info->before(*info._info);
}

std::string TypeInfo::name() const
{
    return std::string(_info->name());
}

bool    TypeInfo::operator!=(const TypeInfo &info) const
{
    return (*_info != *info._info);
}

bool    TypeInfo::operator<(const TypeInfo &info) const
{
    return this->before(info);
}

bool    TypeInfo::operator>(const TypeInfo &info) const
{
    return !(this->before(info));
}

bool    TypeInfo::operator>=(const TypeInfo &info) const
{
    return (*this == info || *this > info);
}

bool    TypeInfo::operator<=(const TypeInfo &info) const
{
    return (*this == info || *this < info);
}

bool    TypeInfo::operator==(const TypeInfo &info) const
{
    return (_info == info._info);
}
