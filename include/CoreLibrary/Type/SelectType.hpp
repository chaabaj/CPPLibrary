#ifndef SELECTTYPE_H
#define SELECTTYPE_H

template <bool flag, typename T, typename U>
struct SelectType
{
    typedef T Result;
};

template <typename T, typename U>
struct SelectType<false, T, U>
{
    typedef U Result;
};

#endif // SELECTTYPE_H
