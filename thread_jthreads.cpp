#include <iostream>
#include <thread>
#include <vector>

void some(int x){
    std::cout << "Hello from thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "Argument passed: " << x << std::endl;
}

int main(){
    std::vector<std::jthread> jthreads;
    for(int i=0; i<10; i++){
        jthreads.push_back(std::jthread(some, i));
    }

    return 0;
}