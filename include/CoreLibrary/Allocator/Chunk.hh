#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <cstddef>
#include "CoreLibrary/DllExport.h"

/*! \struct Chunk Chunk.hpp
 * 
 *
 *	Chunk represent a memory chunk :
 *	POD Type (C Structure type)
 *	A Chunk can contain 255 continue block
 *	Don't use this structure is used in internal of FixedAllocator
 */
struct EXPORT_DLL Chunk
{
    void       init(std::size_t size, unsigned char blocks);
    void       release();
    void       *allocate(std::size_t blockSize);
    void       deallocate(void *p, std::size_t blockSize);

    unsigned char   *data;
    unsigned char   firstBlockAvailable;
    unsigned char   blocksAvailable;
};

#endif // CHUNK_HPP
