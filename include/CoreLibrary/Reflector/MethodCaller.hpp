#ifndef METHOD_CALLER_HPP
# define METHOD_CALLER_HPP

# define CALL_METHOD(OBJ, METHOD, ...) OBJ.METHOD(__VA_ARGS__)
# define CALL_METHOD_PTR(OBJ, METHOD, ...) OBJ->METHOD(__VA_ARGS__)

# include <string>
# include "CoreLibrary/Type/TypeList.hpp"
# include "CoreLibrary/Type/TypeTraits.hpp"
#include <CoreLibrary/Type/Int2Type.hpp>




/*template<class InstanceClass, class ResultType, char *MethodName, typename ... Args>
class MethodCaller
{ 
public:
  typedef typename TypeTraits<InstanceClass>::ParameterType ParameterType;
  
  static ResultType	call(ParameterType pclass, Args ... parameters)
  {
    return call(pclass, TypeTraits<ParameterType>::isPointer,  parameters...);
  }
  
private:
  static ResultType	call(ParameterType pclass, Int2Type<0>, Args ... parameters)
  { 
    return CALL_METHOD(pclass, MethodName, parameters...);
  }
  
  static ResultType	call(InstanceClass *pclass, Int2Type<1>, Args ...parameters)
  {
    return CALL_METHOD_PTR(pclass, MethodName, parameters...);
  }

};*/



#endif