#include "mck-k.hpp"

McKKAllocator::McKKAllocator(int pagesAmount, std::vector<int>& pagesFragments){

    freeBlocksLists = std::vector<std::list<char*>>(powsOf2.size());
    data = (char*)malloc(pagesAmount * PAGE_SIZE);
    char* curPageStart = data;
    char* curPageEnd = curPageStart + (PAGE_SIZE - 1);
    kMemSize = std::vector<Page>(pagesAmount);

    for(int i = 0; i < pagesAmount; ++i){
        kMemSize[i].blockSize = pagesFragments[i];
        kMemSize[i].start = curPageStart;
        kMemSize[i].end = curPageEnd;
        curPageStart += PAGE_SIZE;
        curPageEnd += PAGE_SIZE;
    }

    for (int i = 0; i < kMemSize.size(); ++i){
        int index = -1;
        for(int j = 0; j < powsOf2.size(); ++j){
            if(kMemSize[i].blockSize == powsOf2[j]){
                index = j;
                break;
            }
        }
        char* curBlockStart = kMemSize[i].start;
        for(int j = 0; j < PAGE_SIZE / kMemSize[i].blockSize; ++j){
            freeBlocksLists[index].push_back(curBlockStart);
            curBlockStart += kMemSize[i].blockSize;
        }
        
    }
}

void* McKKAllocator::allocate(int bytesAmount){
    if (bytesAmount == 0){
        return nullptr;
    }

    int index = -1;
    for (int i = 0; i < freeBlocksLists.size(); ++i){
        if (bytesAmount <= powsOf2[i] && !freeBlocksLists[i].empty()){ // if requested amount of bytes is fit and such block exists
            index = i;
            break;
        }
    }
    if (index == -1){
        std::cout << "There isn't memory\n";
    }

    char* memory = freeBlocksLists[index].front();
    freeBlocksLists[index].pop_front();
    return (void*)memory;
}

void McKKAllocator::deallocate(void* ptr){
    char *chPtr = (char*)ptr;

    int indPage = -1;
    for(int i = 0; i < kMemSize.size(); ++i){
        if(kMemSize[i].start <= chPtr && chPtr <= kMemSize[i].end){
            indPage = i;
            break;
        }
    }

    int indBlock = -1;
    for(int j = 0; j < powsOf2.size(); ++j){
        if(kMemSize[indPage].blockSize == powsOf2[j]){
            indBlock = j;
            break;
        }
    }

    freeBlocksLists[indBlock].push_back(chPtr);
}

McKKAllocator::~McKKAllocator(){
    free(data);
}