#ifndef SIMPLE_EVENT_CHECK_HPP
# define SIMPLE_EVENT_CHECK_HPP


template<class WindowClass>
class SimpleEventClass
{
public:
  void	update(WindowClass &window)
  {
    (void)window;
  }
};

#endif