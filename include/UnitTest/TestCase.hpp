#ifndef TESTCASE_HPP_
# define TESTCASE_HPP_

# include <iostream>
# include <sstream>
# include "TestResult.hh"
# include "CoreLibrary/Type/NullType.hpp"
# include "CoreLibrary/Utils/SearchMostDerivated.hpp"

namespace UnitTest
{
  class	ITestCase
  {
  public:
    virtual TestResult		launch() = 0;
    virtual ~ITestCase() {}
  };
  
  template<typename Function = TestResult (*)(), class ExceptionList = NullType>
  class TestCase : public ITestCase
  {
    enum { exceptionListSize = TL::Length<ExceptionList>::value };
    
  public:
    TestCase(Function function) : _function(function), _exceptionCaught(false) {}
    ~TestCase() {}
    
    TestResult	launch()
    { 
      TestResult	result(false, "Success", "");
      
      try
      {
	result = _function();
      }
      catch (std::exception &e)
      {
	std::stringstream	stream;
	std::string		classname;
	TypeInfo		classInfo;
 
	_exceptionCaught = true;
	classInfo = SearchMostDerivated<std::exception, ExceptionList>::find(e, sizeof(e), false);
	classname = classInfo.name();
	if (!this->isNullType(classInfo))
	  std::cout << "Throwed a : " << classname << std::endl;
	else
	{
	  stream << "A exception throwed but not in ExceptionList ";
	  stream << classname << " with message : " << e.what() << std::endl;
	  return TestResult(true, stream.str() , classname);
	}
      }
      if (exceptionListSize > 0 && !_exceptionCaught && !result.isFailed())
	return TestResult(true, "No exception in exception list was throw", "");
      return result;
    }
    

  private:
    
    bool	isNullType(TypeInfo const &classInfo) const
    {
      return classInfo == TypeInfo(typeid(NullType()));
    }
    
    TestCase(TestCase const &other);
    TestCase	&operator=(TestCase const &other);
    
    Function	_function;
    bool	_exceptionCaught;
  };
}

#endif