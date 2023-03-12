#include <iostream>
#include <chrono>

#include "BuddyAllocator.hpp"
#include "mck-k.hpp"

int main()
{
    using namespace std::chrono;
    
    std::cout << "First test, allocator initialization:" << std::endl;

    int pagesAmount = 10;
    std::vector<int> pagesFragments = {32, 128, 256, 1024, 512, 256, 256, 1024, 16, 256};

    steady_clock::time_point mcKKAllocatorInitStart = steady_clock::now();
    McKKAllocator mcKKAllocator(pagesAmount, pagesFragments);
    steady_clock::time_point mcKKAllocatorInitEnd = steady_clock::now();

    std::cout << "McKusick-Karels: " << std::chrono::duration_cast<std::chrono::nanoseconds>(mcKKAllocatorInitEnd - mcKKAllocatorInitStart).count() << " ns" << std::endl;

    steady_clock::time_point buddyAllocatorInitStart = steady_clock::now();
    BuddyAllocator buddyAllocator(4096);
    steady_clock::time_point buddyAllocatorInitEnd = steady_clock::now();

    std::cout << "Buddy: " << std::chrono::duration_cast<std::chrono::nanoseconds>(buddyAllocatorInitEnd - buddyAllocatorInitStart).count() << " ns";
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Second test, allocate 10 char[256], deallocate 5 of them, allocate 5 char[128]:\n";

    std::vector<char *> pointers2(10, 0);
    steady_clock::time_point mcKKTest1Start = steady_clock::now();
    for (int i = 0; i < 10; ++i){
        pointers2[i] = (char *)mcKKAllocator.allocate(256);
    }
    for (int i = 5; i < 10; ++i){
        mcKKAllocator.deallocate(pointers2[i]);
    }
    for (int i = 5; i < 10; ++i){
        pointers2[i] = (char *)mcKKAllocator.allocate(128);
    }
    steady_clock::time_point mcKKTest1End = steady_clock::now();
    std::cerr << "McKusick-Karels: " << std::chrono::duration_cast<std::chrono::microseconds>(mcKKTest1End - mcKKTest1Start).count() << " microseconds" << std::endl;


    BuddyAllocator allocator(8192);
    std::vector<char *> pointers(1000, 0);
    steady_clock::time_point buddyTestStart = steady_clock::now();
    for (int i = 0; i < 10; ++i){
        pointers[i] = (char *)allocator.allocate(256);
    }
    for (int i = 5; i < 10; ++i){
        allocator.deallocate(pointers[i]);
    }
    for (int i = 5; i < 10; ++i){
        pointers[i] = (char *)allocator.allocate(128);
    }
    steady_clock::time_point buddyTestEnd = steady_clock::now();
    std::cerr << "Buddy: " << std::chrono::duration_cast<std::chrono::microseconds>(buddyTestEnd - buddyTestStart).count() << " microseconds" << std::endl;
    for(int i = 0; i < 10; ++i){
        allocator.deallocate(pointers[i]);
    }

    std::cout << std::endl;

    for (int i = 0; i < 10; ++i){
        mcKKAllocator.deallocate(pointers2[i]);
    }

    std::cerr << "Third test, Allocate and free 15 20 bytes arrays:\n";
    pagesAmount = 15;
    std::vector<int> pagesFragment2 = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
    
    McKKAllocator allocator2(pagesAmount, pagesFragment2);

    std::vector<char *> pointer2(15, 0);
    steady_clock::time_point alloc_start = steady_clock::now();
    for (int i = 0; i < 15; ++i){
        pointer2[i] = (char *)allocator2.allocate(20);
    }
    steady_clock::time_point alloc_end = steady_clock::now();
    for (int i = 0; i < 15; ++i){
        allocator2.deallocate(pointer2[i]);
    }
    steady_clock::time_point test_end = steady_clock::now();
    std::cerr << "McKusick-Karels allocation: " << duration_cast<std::chrono::microseconds>(alloc_end - alloc_start).count() << " microseconds"<< "\n"
              << "McKusick-Karels deallocation: " << duration_cast<std::chrono::microseconds>(test_end - alloc_end).count() << " microseconds "<< "\n";

    std::cout << std::endl;

    BuddyAllocator allocator3(32000);
    std::vector<char *> pointers3(150, 0);
    alloc_start = steady_clock::now();
    for (int i = 0; i < 15; ++i){
        pointers3[i] = (char *)allocator3.allocate(20);
    }
    alloc_end = steady_clock::now();
    for (int i = 0; i < 15; ++i){
        allocator3.deallocate(pointers3[i]);
    }
    test_end = steady_clock::now();
    std::cerr << "Buddy allocation: " << duration_cast<std::chrono::microseconds>(alloc_end - alloc_start).count() << " microseconds"<< "\n"
              << "Buddy deallocation: " << duration_cast<std::chrono::microseconds>(test_end - alloc_end).count() << " microseconds"<< "\n";

    std::cout << std::endl;
    
    std::cout << "Fout test, allocate 100 char[128], deallocate 100 of them, allocate 100 char[256]:\n";

    int pagesmout = 100;
    std::vector<int> pageragmens;
    
    for(int i = 0; i < 100; ++i){
        pageragmens.push_back(1024);
    }
    


    McKKAllocator cKKAllocatr(pagesmout, pageragmens);


    std::vector<char *> pointers5(100, 0);

    steady_clock::time_point mcKKTest5Start = steady_clock::now();
    for (int i = 0; i < 100; ++i){
        pointers5[i] = (char *)cKKAllocatr.allocate(128);
    }
    for (int i = 0; i < 100; ++i){
        cKKAllocatr.deallocate(pointers5[i]);
    }
    for (int i = 0; i < 100; ++i){
        pointers5[i] = (char *)cKKAllocatr.allocate(256);
    }
    steady_clock::time_point mcKKTest5End = steady_clock::now();
    std::cerr << "McKusick-Karels: " << std::chrono::duration_cast<std::chrono::microseconds>(mcKKTest5End - mcKKTest5Start).count() << " microseconds" << std::endl;


    BuddyAllocator allocator5(1048576);
    std::vector<char *> pointers5_b(100, 0);
    
    steady_clock::time_point buddyTest5Start = steady_clock::now();
    for (int i = 0; i < 100; ++i){
        pointers5_b[i] = (char *)allocator5.allocate(120);
    }
    
    for (int i = 0; i < 100; ++i){
        allocator5.deallocate(pointers5_b[i]);
    }
    
    for (int i = 0; i < 100; ++i){
        pointers5_b[i] = (char *)allocator5.allocate(256);
    }
    steady_clock::time_point buddyTest5End = steady_clock::now();
    
    std::cerr << "Buddy: " << std::chrono::duration_cast<std::chrono::microseconds>(buddyTest5End - buddyTest5Start).count() << " microseconds" << std::endl;
    for(int i = 0; i < 100; ++i){
        allocator5.deallocate(pointers5_b[i]);
    }
    std::cout << std::endl;

    for (int i = 0; i < 100; ++i){
        cKKAllocatr.deallocate(pointers5[i]);
    }

    std::cout << "Five test, allocate 100 char[20], deallocate 100 of them, allocate 100 char[40]:\n";

    int pagesmout6 = 100;
    std::vector<int> pageragmens6;
    
    for(int i = 0; i < 100; ++i){
        pageragmens6.push_back(1024);
    }
    


    McKKAllocator cKKAllocatr6(pagesmout6, pageragmens6);


    std::vector<char *> pointers6(100, 0);

    steady_clock::time_point mcKKTest6Start = steady_clock::now();
    for (int i = 0; i < 100; ++i){
        pointers6[i] = (char *)cKKAllocatr6.allocate(20);
    }
    for (int i = 0; i < 100; ++i){
        cKKAllocatr6.deallocate(pointers6[i]);
    }
    for (int i = 0; i < 100; ++i){
        pointers6[i] = (char *)cKKAllocatr6.allocate(40);
    }
    steady_clock::time_point mcKKTest6End = steady_clock::now();
    std::cerr << "McKusick-Karels: " << std::chrono::duration_cast<std::chrono::microseconds>(mcKKTest6End - mcKKTest6Start).count() << " microseconds" << std::endl;


    BuddyAllocator allocator6(1048576);
    std::vector<char *> pointers6_b(100, 0);
    
    steady_clock::time_point buddyTest6Start = steady_clock::now();
    for (int i = 0; i < 100; ++i){
        pointers6_b[i] = (char *)allocator6.allocate(20);
    }
    
    for (int i = 0; i < 100; ++i){
        allocator6.deallocate(pointers6_b[i]);
    }
    
    for (int i = 0; i < 100; ++i){
        pointers6_b[i] = (char *)allocator6.allocate(40);
    }
    steady_clock::time_point buddyTest6End = steady_clock::now();
    
    std::cerr << "Buddy: " << std::chrono::duration_cast<std::chrono::microseconds>(buddyTest6End - buddyTest6Start).count() << " microseconds" << std::endl;
    for(int i = 0; i < 100; ++i){
        allocator6.deallocate(pointers6_b[i]);
    }
    std::cout << std::endl;

    for (int i = 0; i < 100; ++i){
        cKKAllocatr6.deallocate(pointers6[i]);
    }

    return 0;
    
    
}