#include <algorithm>
#include <cassert>
#include "CoreLibrary/Functor/Functor.hpp"
#include "CoreLibrary/Allocator/FixedAllocator.hh"

FixedAllocator::FixedAllocator(std::size_t size, unsigned char numBlock) : _blockSize(size), _numBlock(numBlock),
    _allocChunk(NULL), _deallocChunk(NULL)
{
}

void    FixedAllocator::removeEmptyChunk(Chunk &chunk)
{
    chunk.release();
}

std::size_t FixedAllocator::getBlockSize() const
{
    return _blockSize;
}

FixedAllocator::~FixedAllocator()
{
    MethodEraseChunk    eraser = &FixedAllocator::removeEmptyChunk;
    Functor<void, TYPELIST_1(Chunk), MethodEraseChunk, FixedAllocator*> functor(eraser, this);

    std::for_each(_chunks.begin(), _chunks.end(), functor);
}

void    *FixedAllocator::allocate()
{
    if (!_allocChunk || !_allocChunk->blocksAvailable)
    {
        Chunks::iterator  it;
        Chunks::iterator  endIt;

        endIt = _chunks.end();
        for (it = _chunks.begin(); it != endIt; ++it)
        {

            if (it->blocksAvailable)
            {
                _allocChunk = &(*it);
                break;
            }
        }
        if (it == endIt)
        {
            Chunk   newChunk;

            newChunk.init(_blockSize, _numBlock);
            _chunks.push_back(newChunk);
            _allocChunk = &_chunks.back();
            _deallocChunk = &_chunks.back();
        }
    }
    return (_allocChunk->allocate(_blockSize));
}

void    FixedAllocator::removeDoublons()
{
    //TODO
}

void    FixedAllocator::deallocate(void *p)
{
    unsigned char   *toRelease;

    assert(_deallocChunk != NULL && p != NULL);
    toRelease = static_cast<unsigned char*>(p);
    if (_deallocChunk->blocksAvailable == _numBlock
            || toRelease < _deallocChunk->data
            || toRelease >= _deallocChunk->data + (_blockSize * _numBlock))
    {
        Chunks::iterator  it;
        Chunks::iterator  endIt;

        endIt = _chunks.begin();
        for (it = _chunks.begin(); it != endIt; ++it)
        {
            if (toRelease >= _deallocChunk->data
                    && toRelease < _deallocChunk->data + (_blockSize * _numBlock))
            {
                _deallocChunk = &_chunks.back();
                break;
            }
        }
        assert(it != endIt);
    }
    _deallocChunk->deallocate(p, _blockSize);
    this->removeDoublons();
}
