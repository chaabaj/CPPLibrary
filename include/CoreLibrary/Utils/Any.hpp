#ifndef ANY_HH_
# define ANY_HH_

# include <stdexcept>

class IValue
{
public:
  virtual ~IValue() {}
  virtual IValue	*clone() const = 0;
};

template<typename Type>
class Value : public IValue
{
public:
  Value(Type &val) : _val(val)
  {
  }
  ~Value()
  {
  }

  Type	&get()
  {
    return _val;
  }

  IValue	*clone() const
  {
	  return new Value<Type>(_val);
  }

  Type const &get() const
  {
    return _val;
  }

private:
  Type	&_val;
};

class Any
{

public:
  template<typename Type>
  Any(Type &val) : _value(new Value<Type>(val))
  {
  }
  ~Any()
  {
    delete _value;
  }

  Any(Any const &other) : _value(other._value->clone())
  {

  }

  Any	operator=(Any const &other)
  {
	  _value = other._value->clone();
	  return (*this);
  }

  template<typename Type>
  Type	&any_cast()
  {
    Value<Type>	*ptr;

    ptr = dynamic_cast<Value<Type>*>(_value);
    if (ptr != NULL)
      return ptr->get();
    throw std::runtime_error("Invalid cast");
  }


  template<typename Type>
  Type const	&any_cast() const
  {
    const Value<Type>	*ptr;

    ptr = dynamic_cast<const Value<Type>*>(_value);
    if (ptr != NULL)
      return ptr->get();
    throw std::runtime_error("Invalid cast");
  }

private:
  IValue	*_value;
};

#endif
