#ifndef FIXEDALLOCATOR_H
#define FIXEDALLOCATOR_H

#include <cstddef>
#include <vector>
#include "Chunk.hh"
#include "CoreLibrary/DllExport.h"

/*! \class FixedAllocator FixedAllocator.hpp
 * 
 *	FixedAllocator is a allocator with fixed block size :
 *	It's optimized for fast allocation/deallocation
 *	It's used in internal by SmallObjectAllocator
 */

class EXPORT_DLL FixedAllocator
{
public:
  /*!
   *  \brief Constructor
   *
   *  Constructor of FixedAllocator
   *
   *  \param size : size of block
   *  \param numBlocks : number of block per chunk
   */
    FixedAllocator(std::size_t size, unsigned char numBlocks);
    
    /*!
     * \brief Destructor
     * 
     * Destructor of FixedAllocator
     */
    ~FixedAllocator();

    
    /*!
     * \brief Allocate method
     * 
     * This method allocate a new block
     * 
     */
    void    *allocate();
    
    /*!
     * \brief Deallocate method
     * 
     * This method deallocate the pointer and remove the chunk
     * 
     * \param p : a valid pointer
     */
    void    deallocate(void *p);

    
    /*!
     * \brief getter for block size
     * 
     * Get Block size of the allocator
     * 
     * \return block size of the allocator
     */
    std::size_t getBlockSize() const;



private:

    typedef void    (FixedAllocator::*MethodEraseChunk)(Chunk&);

    FixedAllocator(FixedAllocator const &other);
    FixedAllocator  &operator=(FixedAllocator const &other);

    void    removeEmptyChunk(Chunk &chunk);
    void    removeDoublons();

    typedef std::vector<Chunk>  Chunks;

    std::size_t     _blockSize;
    unsigned char   _numBlock;
    Chunks          _chunks;
    Chunk           *_allocChunk;
    Chunk           *_deallocChunk;
};

#endif // FIXEDALLOCATOR_H
