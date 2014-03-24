#ifndef REGISTRY_HPP
# define REGISTRY_HPP
#include <map>

# include "CoreLibrary/Policies/ThreadingModel/SingleThreaded.hpp"
# include "CoreLibrary/Type/TypeTraits.hpp"

template<
	 class IdentifierType,
	 class ObjectClass,
	 template<class, class>		NotFoundPolicy,
	 class				ObjectLoader = ObjectLoader *(*)(),
	 template<class>		ThreadingModel = SingleThreaded
	>
class Registry
{
  typedef typename ThreadingModel<ObjectClass>::SharedPtr			SharedObjectPtr;
  typedef typename ThreadingModel<ObjectClass>::Lock				Lock;
  typedef typename ThreadingModel<ObjectClass>::WeakPtr			WeakObjectPtr;
  typedef typename ThreadingModel<ObjectClass>::Mutex				Mutex;
  typedef typename std::map<IdentifierType, SharedObjectPtr>::iterator	ObjectMapIterator;

public:
  typedef IdentifierType	RegistryIdentifierType;
  typedef ObjectClass		RegistryObjectClass;

  Registry()
  {
  }

  ~Registry()
  {
  }

  void	registerObject(typename TypeTraits<IdentifierType>::ConstParameterType id, ObjectClass *obj)
  {
    Lock(_mutex);

    _objects[id] = (SharedObjectPtr(obj));
  }

  void	unregisterObject(typename TypeTraits<IdentifierType>::ConstParameterType id)
  {
    ObjectMapIterator	it;

    if ((it = _objects.find(id)) != _objects.end())
      _objects.erase(id);
    else
      NotFoundPolicy<IdentifierType, ObjectLoader>::onUnregisterNotFound(id);
  }

  WeakObjectPtr		getObject(typename TypeTraits<IdentifierType>::ConstParameterType id)
  {
    ObjectClass		*newObj;
    ObjectMapIterator	it;

    if ((it = _objects.find(id)) == _objects.end())
    {
      newObj = NotFoundPolicy<IdentifierType, ObjectLoader>::onKeyNotFound(id);
      if (newObj != NULL)
	_objects[id] = newObj;
    }
    return WeakObjectPtr(_objects[id]->get());
  }

private:

  Mutex								_mutex;
  std::map<IdentifierType, SharedObjectPtr>			_objects;
};

#endif