#pragma once

namespace tekLib
{
  
  template<bool condition, typename T = void> 
  struct enable_if 
  {  
  };
  
  template<typename T> 
  struct enable_if<true, T>
  {
    typedef T type; 
  };
  
}