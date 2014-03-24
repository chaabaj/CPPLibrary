#ifndef TEST_RESULT_HH_
# define TEST_RESULT_HH_

# include <string>

namespace UnitTest
{
  class TestResult
  {
  public:
    explicit TestResult(bool failed, std::string const &reason, std::string const &testString);
    ~TestResult();
    TestResult(TestResult const &other);
    TestResult	&operator=(TestResult const &other);
    
    bool		isFailed() const;
    std::string const	&getReason() const;
    std::string const	&getTestString() const;
    
  private:
    bool		_failed;
    std::string		_reason;
    std::string		_testString;
  };
}

#endif