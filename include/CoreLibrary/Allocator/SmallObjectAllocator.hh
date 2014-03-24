#ifndef SMALLOBJECTALLOCATOR_HH
#define SMALLOBJECTALLOCATOR_HH

#include <map>
#include "FixedAllocator.hh"
#include "CoreLibrary/DllExport.h"

/*! \class SmallObjectAllocator SmallObjectAllocator.hpp
 * 
 *	SmallObjectAllocator:
 * 	SmallObjectAllocator contains a map of FixedAllocator with key the block size
 * 	By Default the SmallObjectAllocator use 128 block for chunk
 * 	What is the problem this class resolve
 * 	malloc/new is optimized for medium/big object size
 * 	This allocator is optimized for small object size
 *	It's optimized for fast allocation/deallocation
 */

class EXPORT_DLL SmallObjectAllocator
{
    typedef std::map<std::size_t, FixedAllocator*>  Allocators;

    Allocators                              _pool;
    FixedAllocator                          *_lastAlloc;
    FixedAllocator                          *_lastDealloc;

    SmallObjectAllocator(SmallObjectAllocator const &other);
    SmallObjectAllocator    &operator=(SmallObjectAllocator const &other);

    enum { nbBlock = 128 };

public:
  
  /*!
   * \brief Constructor of SmallObjectAllocator
   * 
   * Constructor of SmallObjectAllocator
   */
    SmallObjectAllocator();
    
    /*!
     * \brief Destructor of SmallObjectAllocator
     */
    ~SmallObjectAllocator();

    /*!
     * \brief Allocate method
     * use to allocate size in internal memory pool
     * 
     * \param size : size to allocate
     * 
     * \return : pointer to the allocate memory
     */
    void    *allocate(std::size_t size);
    
    /*!
     * \brief Deallocate method
     * 
     * use to deallocate a pointer
     * 
     * \param p : a pointer to the memory to free
     * \param size : the size of the memory pointed by the pointer p
     */
    void    deallocate(void *p, std::size_t size);
};

#endif // SMALLOBJECTALLOCATOR_HH
