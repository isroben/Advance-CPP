#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

/*
Synchronization means coordinating threads so they access shared resources in a safe, controlled order. Without it, threads touching the same data cause data races (the counter++ problem from before). A mutex is the most basic synchronization tool.
*/

/*
Mutex = mutual exclusion. It is a lock that only one thread can hold at a time. The code between "lock" and "unlock" is called the critical section, and only one thread can be inside it at once.
*/

int counter = 0;
std::mutex m;

void work(){
    for(int i=0; i<100000; i++){
        m.lock();
        counter++;
        m.unlock();
    }
}

int main(){

    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(work);
    std::thread t2(work);

    t1.join();
    t2.join();

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << counter << std::endl;

    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Execution time: "
         << duration.count() << " microseconds\n";

    // output time without mutex --> 441 micro-seconds
    // output time with mutex --> 3859 micro-seconds

    return 0;
}