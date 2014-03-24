#ifndef NEWCREATOR_HPP
#define NEWCREATOR_HPP

template<class T>
class NewCreator
{
public:
    static T    *create()
    {
        return new T;
    }

    static void destroy(T *obj)
    {
        delete obj;
    }
};

#endif // NEWCREATOR_HPP
