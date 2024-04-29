#include <iostream>

#include "int_array.h"

int main()
{
    std::cout << "[-] Testing DynamicArray.\n";
    auto arr = IntArray();
    arr.Append(0);
    arr.Append(1);
    arr.Append(2);
    arr.Append(3);
    arr.Append(4);
    arr.RemoveAt(1);
    ASSERT(arr[1] == 2)
    ASSERT(arr.Size() == 4)

    std::cout << "[-] Done.\n";

    return 0;
}