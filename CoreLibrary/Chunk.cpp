#include <cassert>
#include <cstdlib>
#include "CoreLibrary/Allocator/Chunk.hh"

void Chunk::init(std::size_t blockSize, unsigned char blocks)
{
    this->data = new unsigned char[blockSize * blocks];
    firstBlockAvailable = 0;
    blocksAvailable = blocks;

    unsigned char *p = this->data;
    for (unsigned char i = 0; i != blocks; p = p + blockSize)
    {
        *p = ++i;
    }
}

void    Chunk::release()
{
  delete [] this->data;
    this->blocksAvailable = 0;
}

void *Chunk::allocate(std::size_t blockSize)
{
    unsigned char   *result;

    if (!blocksAvailable)
        return NULL;

    result = data + (firstBlockAvailable * blockSize);
    firstBlockAvailable = *result;
    --blocksAvailable;
    return (result);
}

void Chunk::deallocate(void *p, std::size_t blockSize)
{
    unsigned char   *toRelease;

    assert(p >= this->data);
    toRelease = static_cast<unsigned char*>(p);
    assert((toRelease - this->data) % blockSize == 0);
    *toRelease = firstBlockAvailable;
    firstBlockAvailable = static_cast<unsigned char>((toRelease - this->data) / blockSize);
    assert(firstBlockAvailable == (toRelease - this->data) / blockSize);
    ++blocksAvailable;
}
