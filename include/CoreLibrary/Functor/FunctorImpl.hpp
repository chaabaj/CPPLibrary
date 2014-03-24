#ifndef FUNCTORIMPL_HPP
#define FUNCTORIMPL_HPP

# include "CoreLibrary/Type/TypeList.hpp"
# include "CoreLibrary/Type/TypeTraits.hpp"

template<typename R, class TList>
class FunctorImpl;

template<typename R>
class FunctorImpl<R, NullType>
{

public:
    virtual R              operator()() = 0;
    virtual FunctorImpl    *clone() const = 0;
    virtual ~FunctorImpl() {}
};

template<typename R, typename P1>
class FunctorImpl<R, TYPELIST_1(P1)>
{

public:
    virtual R                   operator()(typename TypeTraits<P1>::ParameterType) = 0;
    virtual FunctorImpl         *clone() const = 0;
    virtual ~FunctorImpl() {}
};

template<typename R, typename P1, typename P2>
class FunctorImpl<R, TYPELIST_2(P1, P2)>
{

public:
    virtual R             operator()(typename TypeTraits<P1>::ParameterType,
				      typename TypeTraits<P2>::ParameterType) = 0;
    virtual FunctorImpl   *clone() const = 0;
    virtual ~FunctorImpl() {}
};

template<typename R, typename P1, typename P2, typename P3>
class FunctorImpl<R, TYPELIST_3(P1, P2, P3)>
{
  public:
    virtual R               operator()(typename TypeTraits<P1>::ParameterType,
				        typename TypeTraits<P2>::ParameterType, 
				        typename TypeTraits<P3>::ParameterType) const = 0;
    virtual FunctorImpl     *clone() const = 0;
    virtual ~FunctorImpl() {}
};

template<typename R, typename P1, typename P2, typename P3, typename P4>
class FunctorImpl<R, TYPELIST_4(P1, P2, P3, P4)>
{
    public:
    virtual R               operator()(typename TypeTraits<P1>::ParameterType, 
				        typename TypeTraits<P2>::ParameterType, 
				        typename TypeTraits<P3>::ParameterType, 
				        typename TypeTraits<P4>::ParameterType) const = 0;
    virtual FunctorImpl     *clone() const = 0;
    virtual ~FunctorImpl();
};

#endif // FUNCTORIMPL_HPP
