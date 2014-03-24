#include "UnitTest/TestResult.hh"

UnitTest::TestResult::TestResult(bool failed, std::string const &reason, std::string const &testString) :
_failed(failed), _reason(reason), _testString(testString)
{
  
}

UnitTest::TestResult::~TestResult() {}

UnitTest::TestResult::TestResult(UnitTest::TestResult const &other) :
_failed(other._failed), _reason(other._reason), _testString(other._testString)
{
}

UnitTest::TestResult	&UnitTest::TestResult::operator=(UnitTest::TestResult const &other)
{
  _failed = other._failed;
  _reason = other._reason;
  _testString = other._testString;
  return (*this);
}

bool	UnitTest::TestResult::isFailed() const
{
  return _failed;
}

std::string const	&UnitTest::TestResult::getReason() const
{
  return _reason;
}

std::string const	&UnitTest::TestResult::getTestString() const
{
  return _testString;
}