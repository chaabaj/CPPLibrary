#ifndef GRAPHICS_ENGINE_HH
# define GRAPHICS_ENGINE_HH

#include "CoreLibrary/SmartPointer/SharedPtr.hpp"
#include "CoreLibrary/SmartPointer/WeakPtr.hpp"
#include "CoreLibrary/Container/Container.hpp"
#include "CoreLibrary/Container/Policies/RejectInvalidIndex.hpp"

#include <vector>

namespace Graphics
{

  template<
	    class 				WindowClass,
	    class 				SceneManagerClass,
	    class 				EventClass,
	    template<class> class 		ThreadingModel = SingleThreaded
	   >
  class GraphicsEngine
  {
    typedef GraphicsEngine<WindowClass, SceneManagerClass, EventClass, ThreadingModel>		GraphicsEngineClass;

  public:

    typedef typename ThreadingModel<WindowClass>::WeakPtr					WeakWindowPtr;
    typedef typename ThreadingModel<EventClass>::WeakPtr					WeakEventPtr;
    typedef typename ThreadingModel<WindowClass>::SharedPtr					SharedWindowPtr;
    typedef typename ThreadingModel<EventClass>::SharedPtr					SharedEventPtr;
    typedef Container<SharedWindowPtr, std::vector, RejectInvalidIndex, ThreadingModel>	WindowContainer;
    typedef Container<SharedEventPtr, std::vector, RejectInvalidIndex, ThreadingModel>	EventContainer;


    GraphicsEngine()
    {
    }

    ~GraphicsEngine()
    {
    }

    bool	run()
    {
		for (unsigned int i = 0; i < _windows.size(); ++i)
		{
			_events[i]->update((*_windows[i]));
		}
      return (_sceneManager.template run<GraphicsEngineClass>(*this));
    }

    SceneManagerClass		&getSceneManager()
    {
      return _sceneManager;
    }

    const SceneManagerClass &getSceneManager() const
    {
        return _sceneManager;
    }

    WeakWindowPtr	getWindow(unsigned int index)
    {
      return WeakWindowPtr(_windows[index].get());
    }

    WeakEventPtr	getEventHandler(unsigned int index)
    {
      return WeakEventPtr(_events[index].get());
    }

    void		pushWindow(SharedWindowPtr window)
    {
      _windows.push_back(window);
      _events.push_back(SharedEventPtr(new EventClass()));
    }

  private:
    SceneManagerClass			_sceneManager;

    WindowContainer			_windows;
    EventContainer			_events;
    GraphicsEngine(GraphicsEngine const &other);
    GraphicsEngineClass		&operator=(GraphicsEngineClass const &other);

  };
}

#endif
