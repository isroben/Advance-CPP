#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

static int counter = 0;
std::mutex gLock;

void some1(){
    gLock.lock();
    counter = counter + 1;
    gLock.unlock();
}

void some(){
    // lock_guard uses RAII mechanism and destroy's itself after out scopeclear
    
    std::lock_guard<std::mutex> lockGuard(gLock);
    counter++;
}

int main(){
    std::vector<std::thread> threads; // jthread uses RAII
    for(int i=0; i<10; i++){
        threads.push_back(std::thread(some));
    }

    for(int i=0; i<10; i++){
        threads[i].join();
    }

    std::cout << "Counter: " << counter << std::endl;

    return 0;
}