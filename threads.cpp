#include <iostream>
#include <thread>
#include <chrono>

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
    // auto start = std::chrono::high_resolution_clock::now();
    // std::cout << "Single Threaded Program: " << std::endl;
    // task1();
    // task2();

    // auto end = std::chrono::high_resolution_clock::now();
    // output --> 458 micro-seconds


    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Multi-Threaded Program: " << std::endl;
    std::thread t1(task1); //creating threads --> execution starts immediately after created.
    std::thread t2(task2);


    t1.join(); // asking main::thread to wait until these program finish.
    t2.join();

    auto end = std::chrono::high_resolution_clock::now();
    // output --> 672 micro-second

    // the lifetime of non-main::thread is till completion and ends with main::thread.



    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Execution time: "
         << duration.count() << " microseconds\n";

    return 0;
}