#ifndef TEST_SUITE_HH_
# define TEST_SUITE_HH_

# include <vector>
# include "CoreLibrary/SmartPointer/SharedPtr.hpp"
# include "TestCase.hpp"

namespace UnitTest
{
  class TestSuite
  {
  public:
    TestSuite();
    ~TestSuite();
    
    void	addTest(ITestCase *test);
    void	run();
    void	showStat() const;
    
  private:
    TestSuite(TestSuite const &other);
    TestSuite	&operator=(TestSuite const &other);
    
    std::vector<ITestCase*>	_tests;
    unsigned int		_passed;
    unsigned int		_failed;
  };
}

#endif