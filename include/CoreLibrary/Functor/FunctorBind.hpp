#ifndef FUNCTORBIND_HPP
# define FUNCTORBIND_HPP

#include "Functor.hpp"

template<class FunctorType, typename Bound>
class FunctorBind : public FunctorImpl
  <
    typename FunctorType::ResultType,
    typename FunctorType::ParmList::Tail
  >
{
public:
  typedef typename FunctorType::ResultType			ResultType;

  typedef FunctorBind<FunctorType, Bound> 			FunctorBindType;
  typedef typename FunctorType::ParmList::Tail			ParmList;
  typedef typename TL::TypeAtNotStrict<ParmList, 0>::Result	Parm1;
  typedef typename TL::TypeAtNotStrict<ParmList, 1>::Result	Parm2;
  typedef typename TL::TypeAtNotStrict<ParmList, 2>::Result	Parm3;
  
  explicit FunctorBind(FunctorType const &parent, typename TypeTraits<Bound>::ParameterType bound) : _parent(parent), _bound(bound)
  {
  }
  
  ~FunctorBind()
  {
  }
  
  
  FunctorBind(FunctorBind const &other) : _parent(other._parent), _bound(other._bound)
  {
  }
  
  FunctorBind	&operator=(FunctorBind const &other)
  {
    _parent = other._parent;
    _bound = other._bound;
    return (*this);
  }
  
  FunctorBind	*clone() const
  {
    return new FunctorBind(*this);
  }
  
  ResultType	operator()()
  {
    return _parent(_bound);
  }
  
  ResultType	operator()(typename TypeTraits<Parm1>::ParameterType p1)
  {
    return _parent(_bound, p1);
  }
  
  ResultType	operator()(typename TypeTraits<Parm1>::ParameterType p1,
			   typename TypeTraits<Parm2>::ParameterType p2)
  {
    return _parent(_bound, p1, p2);
  }
  
  ResultType	operator()(typename TypeTraits<Parm1>::ParameterType p1,
			   typename TypeTraits<Parm2>::ParameterType p2,
			   typename TypeTraits<Parm3>::ParameterType p3)
  {
    return _parent(_bound, p1, p2, p3);
  }
  
private:
  FunctorType					_parent;
  Bound						_bound;
};


template<class FunctorType, typename Bound>
Functor
  <
    typename FunctorType::ResultType,
    typename FunctorType::ParmList::Tail,
    typename FunctorType::Function,
    typename FunctorType::FunctorPointerToObj
  >
  Bind(FunctorType const &f1, typename TypeTraits<Bound>::ParameterType bound)
  {
    typedef Functor
		  <
		    typename FunctorType::ResultType,
		    typename FunctorType::ParmList::Tail,
		    typename FunctorType::Function,
		    typename FunctorType::FunctorPointerToObj
		  >	FunctorResult;
    
    typedef FunctorBind<FunctorType, Bound>	FunctorBindType;
    
    return FunctorResult(FunctorBindType(f1, bound));
  }

#endif