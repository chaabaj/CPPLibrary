#ifndef CLONEFACTORY_HPP
# define CLONEFACTORY_HPP
#include <map>

template<
	 class 							AbstractObject,
	 typename 						IdentifierType,
	 template<class, class> class	FactoryErrorPolicy
		>
class CloneFactory
{
public:

  CloneFactory()
  {
  }

  ~CloneFactory()
  {
  }

  AbstractObject	*clone(IdentifierType id) const
  {
    typename std::map<IdentifierType, AbstractObject*>::const_iterator	it;

    if ((it = _clonableObjects.find(id)) == _clonableObjects.end())
      return FactoryErrorPolicy<IdentifierType, AbstractObject>::onUnknownId(id);
    return it->second->clone();
  }

 void registerObject(IdentifierType id, AbstractObject *obj)
  {
    _clonableObjects[id] = obj;
  }

  void	unregisterObject(IdentifierType id)
  {
    _clonableObjects.erase(id);
  }

  bool	exist(IdentifierType id)
  {
    return _clonableObjects.find(id) != _clonableObjects.end();
  }

private:

  CloneFactory(CloneFactory const &other)
  {
	  (void)other;
  }

  CloneFactory	&operator=(CloneFactory const &other)
  {
	  (void)other;
	  return (*this);
  }

  std::map<IdentifierType, AbstractObject*>	_clonableObjects;
};

#endif