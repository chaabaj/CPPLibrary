#ifndef MALLOCCREATOR_HPP
#define MALLOCCREATOR_HPP

#include <cstdlib>

template<class T>
class MallocCreator
{
public:
    static T *create()
    {
        T   *buf;

        buf = std::malloc(sizeof(T));
        return new (buf)T;
    }

    static T    *destroy(T *obj)
    {
        delete obj;
    }

};

#endif // MALLOCCREATOR_HPP
