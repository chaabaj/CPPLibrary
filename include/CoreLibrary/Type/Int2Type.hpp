#ifndef INT2TYPE_HPP
#define INT2TYPE_HPP

template <int v>
struct Int2Type
{
    enum { value = v };
};

#endif // INT2TYPE_HPP
