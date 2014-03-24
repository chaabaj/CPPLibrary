#ifndef MEMBERFUNCTIONHANDLER_HPP
#define MEMBERFUNCTIONHANDLER_HPP

# include "FunctorImpl.hpp"
# include "CoreLibrary/Type/TypeTraits.hpp"

template<
         class ParentFunctor,
         class PointerToObj,
         class PointerToMemFun
        >
class MemberFunctionHandler : public FunctorImpl
        <
            typename ParentFunctor::ResultType,
            typename ParentFunctor::ParmList
        >
{
    typedef typename ParentFunctor::ResultType  ResultType;
    typedef typename ParentFunctor::Parm1	Parm1;
    typedef typename ParentFunctor::Parm2	Parm2;
    typedef typename ParentFunctor::Parm3	Parm3;
    typedef typename ParentFunctor::Parm4	Parm4;

    PointerToObj    _pObj;
    PointerToMemFun _pMemFun;

public:
    MemberFunctionHandler(PointerToObj pobj,
                          PointerToMemFun memFun) : _pObj(pobj), _pMemFun(memFun)
    {

    }

    ~MemberFunctionHandler()
    {

    }

    MemberFunctionHandler(MemberFunctionHandler const &other) : _pObj(other._pObj), _pMemFun(other._pMemFun)
    {

    }

    MemberFunctionHandler   &operator=(MemberFunctionHandler const &other)
    {
        _pObj = other._pObj;
        _pMemFun = other._pMemFun;
        return (*this);
    }

    MemberFunctionHandler   *clone() const
    {
        return (new MemberFunctionHandler<ParentFunctor, PointerToObj, PointerToMemFun>(*this));
    }

    ResultType  operator()()
    {
        return ((*_pObj).*_pMemFun)();
    }

    ResultType  operator()(typename TypeTraits<Parm1>::ParameterType p1)
    {
        return ((*_pObj).*_pMemFun)(p1);
    }

    ResultType  operator()(typename TypeTraits<Parm1>::ParameterType p1,
			    typename TypeTraits<Parm2>::ParameterType p2)
    {
        return ((*_pObj).*_pMemFun)(p1, p2);
    }

    ResultType  operator()(typename TypeTraits<Parm1>::ParameterType p1,
			    typename TypeTraits<Parm2>::ParameterType p2,
			    typename TypeTraits<Parm3>::ParameterType p3)
    {
        return ((*_pObj).*_pMemFun)(p1, p2, p3);
    }

    ResultType  operator()(typename TypeTraits<Parm1>::ParameterType p1,
			    typename TypeTraits<Parm2>::ParameterType p2,
			    typename TypeTraits<Parm3>::ParameterType p3,
			    typename TypeTraits<Parm4>::ParameterType p4)
    {
        return ((*_pObj).*_pMemFun)(p1, p2, p3, p4);
    }
};

#endif // MEMBERFUNCTIONHANDLER_HPP
