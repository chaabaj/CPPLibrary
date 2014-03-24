#ifndef THREADFUNCTOR_HPP
#define THREADFUNCTOR_HPP

#include "AThread.hpp"


template<class FunctorType>
tekLib::AThread *makeThread(FunctorType const &functor)
{
    class FunctorThreadLocal : public tekLib::AThread
    {
    public:
        FunctorThreadLocal(FunctorType const &functor) : _functor(functor)
        {

        }

        ~FunctorThreadLocal()
        {

        }

    protected:
        void    run()
        {
            _functor();
        }

    private:

	FunctorThreadLocal(FunctorThreadLocal const &other) 
	{
		this->_functor = other._functor;
	}

	FunctorThreadLocal  &operator=(FunctorThreadLocal const &other) 
	{
		this->_functor = other._functor;
		return *this;
	}

        FunctorType _functor;
    };

    return new FunctorThreadLocal(functor);
}

#endif // THREADFUNCTOR_HPP
