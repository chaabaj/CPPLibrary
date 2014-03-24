#ifndef FUNCTORHANDLER_HPP
#define FUNCTORHANDLER_HPP

#include "FunctorImpl.hpp"
# include "CoreLibrary/Type/TypeTraits.hpp"

template<class ParentFunctor, typename Fun>
class FunctorHandler : public FunctorImpl
        <
            typename ParentFunctor::ResultType,
            typename ParentFunctor::ParmList
        >
{
    typedef typename ParentFunctor::ResultType ResultType;
    typedef typename ParentFunctor::Parm1	Parm1;
    typedef typename ParentFunctor::Parm2	Parm2;
    typedef typename ParentFunctor::Parm3	Parm3;
    typedef typename ParentFunctor::Parm4	Parm4;

    Fun   _fun;

public:
    FunctorHandler(Fun const &fun) : _fun(fun)
    {

    }

    FunctorHandler(FunctorHandler const &other) : _fun(other._fun)
    {

    }

    FunctorHandler  &operator=(FunctorHandler const &other)
    {
        (void)other;
        return (*this);
    }

    FunctorHandler  *clone() const
    {
        return (new FunctorHandler(*this));
    }

    ~FunctorHandler()
    {

    }

    ResultType  operator()()
    {
        return (_fun());
    }

    ResultType  operator()(typename TypeTraits<Parm1>::ParameterType p1)
    {
        return (_fun(p1));
    }

    ResultType  operator()(typename TypeTraits<Parm1>::ParameterType p1,
			    typename TypeTraits<Parm2>::ParameterType p2)
    {
        return (_fun(p1, p2));
    }

    ResultType  operator()(typename TypeTraits<Parm1>::ParameterType p1,
			    typename TypeTraits<Parm2>::ParameterType p2,
			    typename TypeTraits<Parm3>::ParameterType p3)
    {
        return (_fun(p1, p2, p3));
    }

    ResultType  operator()(typename TypeTraits<Parm1>::ParameterType p1,
			    typename TypeTraits<Parm2>::ParameterType p2,
			    typename TypeTraits<Parm3>::ParameterType p3,
			    typename TypeTraits<Parm4>::ParameterType p4)
    {
        return (_fun(p1, p2, p3, p4));
    }
};

#endif // FUNCTORHANDLER_HPP
