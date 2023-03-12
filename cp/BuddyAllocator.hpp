#ifndef BUDDYALLOCATOR_H
#define BUDDYALLOCATOR_H
#include <vector>
#include <iostream>
class BuddyAllocator
{
public:
    BuddyAllocator(const size_t allowedSize);
    ~BuddyAllocator();
    void *allocate(size_t mem_size);
    void deallocate(void *ptr);

private:
    std::vector<char *> freeBlocks;
    char *data;
    size_t mem_size;
};
#endif // BUDDYALLOCATOR_H