#include <iostream>
#include "UnitTest/TestSuite.hh"

UnitTest::TestSuite::TestSuite() : _passed(0), _failed(0)
{
}

UnitTest::TestSuite::~TestSuite()
{
  std::vector<ITestCase*>::iterator	it;

  for (it = _tests.begin(); it != _tests.end(); ++it)
    delete (*it);
}

void	UnitTest::TestSuite::addTest(ITestCase *test)
{
  _tests.push_back(test);
}

void	UnitTest::TestSuite::showStat() const
{
  std::cout << "Passed : " << _passed << std::endl;
  std::cout << "Failed : " << _failed << std::endl;
}

void	UnitTest::TestSuite::run()
{
  unsigned int				currentTest;
  std::vector<ITestCase*>::iterator	it;
  std::vector<ITestCase*>::iterator	endIt;

  it = _tests.begin();
  endIt = _tests.end();
  currentTest = 0;
  while (it != endIt)
  {
    TestResult result = (*it)->launch();
    if (result.isFailed())
    {
      std::cout << "Test n° " << currentTest << " : ";
      std::cout << result.getTestString() << " : " << result.getReason() << std::endl;
      ++_failed;
      currentTest++;
    }
    else
      ++_passed;

    ++it;
  }

}