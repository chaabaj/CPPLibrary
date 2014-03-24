#ifndef STATIC_ASSERT_HPP
# define STATIC_ASSERT_HPP

# define STATIC_ASSERT(expr, msg) \
{ \
  class ERROR_##msg{}; \
  StaticAssert<((expr) != 0)>(ERROR_##msg()); \
}

template<bool>
class StaticAssert
{
  StaticAssert(...);
};

template<>
class StaticAssert<false> {};

#endif