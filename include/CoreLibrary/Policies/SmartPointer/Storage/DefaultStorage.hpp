#ifndef DEFAULTSTORAGE_HH_
# define DEFAULTSTORAGE_HH_

template<typename T>
class DefaultStorage
{

  
public:
  typedef const T*	ReturnConstPointerType;
  typedef const T&	ReturnConstReferenceType;
  typedef T*		ReturnPointerType;
  typedef T&		ReturnReferenceType;
  typedef T*		PointerType;
  
  
  DefaultStorage<T>() : _data(NULL)
  {
  }

  DefaultStorage<T>(PointerType data) : _data(data)
  {

  }
  
  DefaultStorage<T>(DefaultStorage<T> const &other) : _data(other._data)
  {
  }
  
  DefaultStorage<T>	&operator=(DefaultStorage<T> const &other)
  {
    _data = other._data;
    return (*this);
  }
  
  virtual ~DefaultStorage()
  {
  }
  
  ReturnConstPointerType	operator->() const
  {
    return _data;
  }
  
  ReturnConstReferenceType	operator*() const
  {
    return *_data;
  }
  
  ReturnPointerType		operator->()
  {
    return _data;
  }
  
  ReturnReferenceType		operator*()
  {
    return (*_data);
  }
  

  void	destroy()
  {
    delete _data;
  }
  
protected:
  PointerType	_data;
};

#endif
