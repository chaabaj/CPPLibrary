#ifndef SCENEMANAGER_HPP
# define SCENEMANAGER_HPP

# include <iostream>
# include <algorithm>
# include "CoreLibrary/Utils/Any.hpp"
# include "CoreLibrary/Type/TypeTraits.hpp"
# include "CoreLibrary/Policies/Singleton/SingleThreaded.hpp"
# include <string>
# include <deque>

namespace Graphics
{

  template
  <
    class SceneImpl,
    class FactoryClass,
    template<class> class ThreadingModel = SingleThreaded
  >
  class SceneManager
  {

  public:
    typedef typename ThreadingModel<SceneImpl>::SharedPtr    		SharedScenePtr;
    typedef typename FactoryClass::FactoryIdentifierType		IdentifierType;

  private:
    typedef typename FactoryClass::FactoryObjectCreator  		ObjectCreator;
    typedef SceneManager<SceneImpl, FactoryClass, ThreadingModel>	SceneManagerClass;



    FactoryClass					_factory;
    std::deque<SharedScenePtr>		_scenes;

  public:


    void		registerScene(IdentifierType id,
				      ObjectCreator creator)
    {
      _factory.registerCreator(id, creator);
    }

    template<class DerivedClass, class ... T>
    void		pushScene(IdentifierType id, T ... args)
    {
      SceneImpl		*scene;
      DerivedClass	*derivedScene;

      scene = _factory.create(id);
      derivedScene = (dynamic_cast<DerivedClass*>(scene));
      derivedScene->initialize(args...);
      _scenes.push_back(scene);
    }

    void	play()
    {
		if (_scenes.size() > 0)
		{
			_scenes.back()->setPlayed();
		}
    }

    void	pause()
    {
		if (_scenes.size() > 0)
		{
			_scenes.back()->setPaused();
		}
    }

    template<class GraphicsEngineClass>
    bool		run(GraphicsEngineClass &engine)
    {
      Any		anyEngine(engine);
      SharedScenePtr	current;

	  if (_scenes.size() == 0)
		  return false;
	  current = _scenes.back();
	  if (current != NULL && !current->isFinished()
		  && !current->isPaused())
	  {
		  current->run(anyEngine);
	  }
	  else if (current != NULL && current->isFinished())
	  {
		  _scenes.pop_back();
	  }
	  else if (current != NULL)
	  {
		  current->pause(anyEngine);
	  }
	  std::for_each(_scenes.begin(), _scenes.end() - 1, [&](SharedScenePtr &scene)
	  {
		scene->pause(anyEngine);
	  });
	  return true;
    }
  };

}

#endif
