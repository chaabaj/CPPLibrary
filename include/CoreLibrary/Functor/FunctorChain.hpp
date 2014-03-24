#ifndef CHAINFUNCTOR_HPP
#define CHAINFUNCTOR_HPP

#include "Functor.hpp"

template<class Fun1, class Fun2>
class FunctorChain : public FunctorImpl
        <
            typename Fun1::ResultType,
            typename Fun1::ParmList
        >
{

private:
    typedef typename Fun2::ResultType ResultType;


    Fun1 _fun1;
    Fun2 _fun2;

public:

    FunctorChain(Fun1 const &fun1, Fun2 const &fun2) : _fun1(fun1), _fun2(fun2)
    {

    }

    ~FunctorChain()
    {

    }

    FunctorChain(FunctorChain const &other) : _fun1(other._fun1), _fun2(other._fun2)
    {

    }

    FunctorChain    &operator=(FunctorChain const &other)
    {
        this->_fun1 = other._fun1;
        this->_fun2 = other._fun2;
        return (*this);
    }

    FunctorChain    *clone() const
    {
        return new FunctorChain(*this);
    }

    ResultType  operator()()
    {
        _fun1();
        return (_fun2());
    }

    ResultType  operator()(typename Fun1::Parm1 p1)
    {
        _fun1(p1);
        return (_fun2(p1));
    }

    ResultType  operator()(typename Fun1::Parm1 p1,
                           typename Fun1::Parm2 p2)
    {
        _fun1(p1, p2);
        return (_fun2(p1, p2));
    }

    ResultType  operator()(typename Fun1::Parm1 p1,
                           typename Fun1::Parm2 p2,
                           typename Fun1::Parm3 p3)
    {
        _fun1(p1, p2, p3);
        return (_fun2(p1, p2, p3));
    }

    ResultType  operator()(typename Fun1::Parm1 p1,
                           typename Fun1::Parm2 p2,
                           typename Fun1::Parm3 p3,
                           typename Fun1::Parm4 p4)
    {
        _fun1(p1, p2, p3, p4);
        return (_fun2(p1, p2, p3, p4));
    }
};

template<class Fun1, class Fun2>
Fun2 chain(Fun1 const &f1, Fun2 const f2)
{
    return Fun2(FunctorChain<Fun1, Fun2>(f1, f2));
}

#endif // CHAINFUNCTOR_HPP
