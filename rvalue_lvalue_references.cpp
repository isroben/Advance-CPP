#include <iostream>

int main(){
    int i = 10; // i is lvalue and 10 is prvalue

    // int& a = 10; // throws error because we cannot get reference of constants

    int&& a = 10; // valid rvalue reference

    // & --> lvalue reference i.e reference of a lvalue
    // && --> rvalue reference i.e reference of a rvalue which is stored in memory temporarily and lifetime depends on the scope of ref variable.

    // lvaue --> such values whom we can take reference (pointable memory address)
    // rvalue --> such values which we can't point (temporary or stored nowhere)


    return 0;
}