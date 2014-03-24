#ifndef ARRAYSTORAGE_HPP
# define ARRAYSTORAGE_HPP

# include "DefaultStorage.hpp"

template<typename T>
class ArrayStorage : public DefaultStorage<T>
{

  
public:
  typedef const T*	ReturnConstPointerType;
  typedef const T&	ReturnConstReferenceType;
  typedef T*		ReturnPointerType;
  typedef T&		ReturnReferenceType;
  typedef T*		PointerType;
  
  ArrayStorage<T>() : DefaultStorage<T>()
  {
  }

  ArrayStorage<T>(PointerType data) : DefaultStorage<T>(data)
  {
    _data = data;
  }
  
  ArrayStorage<T>(ArrayStorage<T> const &other) : DefaultStorage<T>(other)
  {
  }
  
  ArrayStorage<T>	operator=(ArrayStorage<T> const &other)
  {
    _data = other._data;
    return (*this);
  }
  
  ~ArrayStorage()
  {
  }
  
  ReturnConstReferenceType	operator[](unsigned long i) const
  {
      return _data[i];
  }
  
  ReturnReferenceType		operator[](unsigned long i)
  {
    return _data[i];
  }
  
protected:
  void	destroy()
  {
    delete[] _data;
  }
  
  PointerType _data;
  
};

#endif
