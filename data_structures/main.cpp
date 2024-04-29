#include <iostream>

#include "int_array.h"

int main()
{
    std::cout << "[-] Testing DynamicArray.\n";
    auto arr = IntArray(3);
    arr.Append(0);
    arr.Append(1);
    arr.Append(2);
    arr.Append(3);
    arr.Append(4);
    arr.Append(5);
    arr.Append(6);
    arr.RemoveAt(1);
    ASSERT(arr[1] == 2)
    ASSERT(arr.Size() == 6)
    ASSERT(arr.Capacity() == 12)
    arr.RemoveAt(1);
    ASSERT(arr[1] == 3)
    ASSERT(arr.Size() == 5)
    ASSERT(arr.Capacity() == 12)

    std::cout << "[-] Done.\n";

    return 0;
}