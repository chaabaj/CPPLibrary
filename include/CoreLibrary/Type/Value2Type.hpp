#ifndef VALUE2TYPE_HPP
#define VALUE2TYPE_HPP

template<class T>
struct Value2Type
{
    template<T val>
    struct Type
    {
        typedef T	Result;
    };
};

#endif // VALUE2TYPE_HPP
