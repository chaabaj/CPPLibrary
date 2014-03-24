#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP

#include "CoreLibrary/Type/TypeList.hpp"
#include "FunctorHandler.hpp"
#include "MemberFunctionHandler.hpp"
#include "CoreLibrary/Type/TypeTraits.hpp"

/*!
 * \class Functor
 * 
 * \brief Functor class encapsulate Functor concept and 
 * can create a functor with a another functor, pointer to function
 * and member pointer function
 * 
 * \tparam R : ResultType
 * \tparam TList : TypeList (charla_n love TypeList)
 * \tparam Fun	: The function type(functor, pointer to function, member function pointer)
 * \tparam PointerObj : In case of member function pointer pass the type of obj to use with your member function pointer
 */
template<typename R,
         class TList,
         typename Fun,
         typename PointerToObj = NullType>

class Functor
{
    typedef FunctorImpl<R, TList>   Impl;

    Impl    *_impl;

public:

    typedef R               ResultType;
    typedef TList           ParmList;
    typedef Fun             Function;
    typedef PointerToObj    FunctorPointerToObj;
    typedef typename        TL::TypeAtNotStrict<TList, 0>::Result    Parm1;
    typedef typename        TL::TypeAtNotStrict<TList, 1>::Result    Parm2;
    typedef typename        TL::TypeAtNotStrict<TList, 2>::Result    Parm3;
    typedef typename        TL::TypeAtNotStrict<TList, 3>::Result    Parm4;


    Functor(Fun const &fun)
    {
        _impl = new FunctorHandler<Functor, Fun>(fun);
    }

    Functor(Fun const &fun, PointerToObj pObj)
    {
        _impl = new MemberFunctionHandler<Functor, PointerToObj, Fun>(pObj, fun);
    }

    Functor(Impl const &impl)
    {
        _impl = impl.clone();
    }

    Functor(Functor const &other) : _impl(other._impl->clone())
    {

    }

    Functor<R, Functor, Fun>   &operator=(Functor<R,Functor, Fun> const &other)
    {
        _impl = other._impl->clone();
        return (*this);
    }

    ~Functor()
    {
        delete _impl;
    }

    R   operator()()
    {
        return ((*_impl)());
    }

    R   operator()(typename TypeTraits<Parm1>::ParameterType p1)
    {
        return ((*_impl)(p1));
    }

    R   operator()(typename TypeTraits<Parm1>::ParameterType p1,
                   typename TypeTraits<Parm2>::ParameterType p2)
    {
        return ((*_impl)(p1, p2));
    }

    R   operator()(typename TypeTraits<Parm1>::ParameterType p1,
                   typename TypeTraits<Parm2>::ParameterType p2,
                   typename TypeTraits<Parm3>::ParameterType p3)
    {
        return ((*_impl)(p1, p2, p3));
    }

    R   operator()(typename TypeTraits<Parm1>::ParameterType p1,
                   typename TypeTraits<Parm2>::ParameterType p2,
                   typename TypeTraits<Parm3>::ParameterType p3,
                   typename TypeTraits<Parm4>::ParameterType p4)
    {
        return ((*_impl)(p1, p2, p3, p4));
    }
    
};

#endif // FUNCTOR_HPP
