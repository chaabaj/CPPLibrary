#ifndef ASSERT_HH_
# define ASSERT_HH_

# include "TestResult.hh"


# define ASSERT_TRUE(condition) if (!condition) { return UnitTest::TestResult(true, "condition is false", #condition); }
# define ASSERT_FALSE(condition) if (condition) { return UnitTest::TestResult(true, "condition is true", #condition); }
# define ASSERT_EQ(p1, p2) if (p1 != p2) { return UnitTest::TestResult(true, "Two value are different", #p1 " != " #p2); }
# define ASSERT_LEQ(p1, p2) if (p1 > p2) { return UnitTest::TestResult(true, #p1 " are greater than " #p2, #p1 " <= " #p2); }
# define ASSERT_GEQ(p1, p2) if (p1 < p2) { return UnitTest::TestResult(true, #p1 " are lower than " #p2, #p1 " >= " #p2); }
# define ASSERT_LOW(p1, p2) if (p1 >= p2) { return UnitTest::TestResult(true, #p1 " are greater or equal than " #p2, #p1 " < " #p2); }
# define ASSERT_GR(p1, p2) if (p1 <= p2) { return UnitTest::TestResult(true, #p1 " are lower or equal than " #p2, #p1, " > " # p2); }

#endif