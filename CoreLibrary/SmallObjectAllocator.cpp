#include <algorithm>
#include <cassert>
#include <iostream>
#include "CoreLibrary/Allocator/SmallObjectAllocator.hh"

SmallObjectAllocator::SmallObjectAllocator() : _lastAlloc(NULL), _lastDealloc(NULL)
{
}

SmallObjectAllocator::~SmallObjectAllocator()
{
    Allocators::iterator    it;

    for (it = _pool.begin(); it != _pool.end(); ++it)
        delete (it->second);
}

void    *SmallObjectAllocator::allocate(std::size_t size)
{
    if (_lastAlloc == NULL || _pool.find(size) == _pool.end())
    {
        _pool[size] = new FixedAllocator(size, SmallObjectAllocator::nbBlock);
        _lastAlloc = _pool[size];
    }
    else if (_lastAlloc->getBlockSize() != size)
        _lastAlloc = _pool[size];
    return _lastAlloc->allocate();
}

void    SmallObjectAllocator::deallocate(void *p, std::size_t size)
{
    assert(_pool.find(size) != _pool.end());
    if (!_lastDealloc)
        _lastDealloc = _pool[size];
    _lastDealloc->deallocate(p);
}
