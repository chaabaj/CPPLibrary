#ifndef TYPEINFO_H
#define TYPEINFO_H

#include <typeinfo>
#include <string>

#include "CoreLibrary/DllExport.h"

class EXPORT_DLL  TypeInfo
{
    const std::type_info  *_info;

public:
    TypeInfo();
    TypeInfo(const std::type_info&);
    TypeInfo(const TypeInfo&);

    bool            before(const TypeInfo&) const;
    std::string     name() const;

    bool            operator==(const TypeInfo&) const;
    bool            operator>=(const TypeInfo&) const;
    bool            operator<=(const TypeInfo&) const;
    bool            operator<(const TypeInfo&) const;
    bool            operator>(const TypeInfo&) const;
    bool            operator!=(const TypeInfo&) const;
};

#endif // TYPEINFO_H
