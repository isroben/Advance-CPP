#include <iostream>
#include <thread>

void task1(){
    for(int i=0; i<50; i++){
        std::cout << "Task 1: "<< i << std::endl;
    }
}

void task2(){
    for(int i=10; i<150; i++){
        std::cout << "Task 2: " << i << std::endl;
    }
}

int main(){
    // std::cout << "Single Threaded Program: " << std::endl;
    // task1();
    // task2();

    std::cout << "Multi-Threaded Program: " << std::endl;
    std::thread t1(task1); //creating threads --> execution starts immediately after created.
    std::thread t2(task2);


    t1.join(); // asking main::thread to wait until these program finish.
    t2.join();

    // the lifetime of non-main::thread is till completion and ends with main::thread.

    return 0;
}