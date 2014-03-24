#ifndef FACTORY_HPP
# define FACTORY_HPP

#include <map>

template<class                      AbstractObject,
     typename                       IdentifierType,
     template<class, class>	class	FactoryErrorPolicy,
     typename                       ObjectCreator = AbstractObject *(*)()>
class Factory
{
public:
  typedef Factory<AbstractObject, IdentifierType, FactoryErrorPolicy, ObjectCreator>	FactoryType;
  typedef IdentifierType								FactoryIdentifierType;
  typedef ObjectCreator									FactoryObjectCreator;

  Factory<AbstractObject, IdentifierType, FactoryErrorPolicy, ObjectCreator>()
  {
  }

  ~Factory<AbstractObject, IdentifierType, FactoryErrorPolicy, ObjectCreator>()
  {
  }

  AbstractObject		*create(IdentifierType id) const
  {
    typename std::map<IdentifierType, ObjectCreator>::const_iterator	it;

    if ((it = _creators.find(id)) == _creators.end())
      return FactoryErrorPolicy<IdentifierType, AbstractObject>::onUnknownId(id);
    return it->second();
  }

  FactoryType	&registerCreator(IdentifierType id, ObjectCreator creator)
  {
    _creators[id] = creator;
    return (*this);
  }

  FactoryType	&erase(IdentifierType id)
  {
    _creators.erase(id);
    return (*this);
  }

  bool	exist(IdentifierType id)
  {
    return _creators.find(id) != _creators.end();
  }

private:
  Factory(FactoryType const &other);

  FactoryType	&operator=(FactoryType const &other);

  std::map<IdentifierType, ObjectCreator>	_creators;
};


#endif
