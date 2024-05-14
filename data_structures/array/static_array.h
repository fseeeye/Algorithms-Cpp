#pragma once
#include <iostream>

#include "common.h"

// Ref : std::array
template<typename T, size_t S>
class StaticArray {
public:
	constexpr size_t Size() const { // `constexpr` makes it can be evaluate at compile time
		return S;
	}

	T* Data() {
		return m_Array; 
	}
	const T* Data() const {
		return m_Array; 
	}

	// implement index operator.
	T& operator[](size_t idx)
	{
		if (idx >= S)
			ASSERT(false);
		return m_Array[idx];
	}
	const T& operator[](size_t idx) const
	{
		if (idx >= S)
			ASSERT(false);
		return m_Array[idx];
	}
private:
	T m_Array[S];
};

void test() {
	constexpr int size = 5;
	StaticArray<int, size> array;
	const auto& arrayRef = array;
	static_assert(array.Size() < 10, "size of array is too large.");
	memset(array.Data(), 0, sizeof(int) * array.Size());

	for (int i = 0; i < array.Size(); i++)
	{
		array[i] = i * 2;
		// arrayRef[i] = 0; // error!
		std::cout << array[i] << std::endl;
		std::cout << arrayRef[i] << std::endl;
	}

	// TODO: impl iterator
	// for (auto& elem : array)
	// {
	// 	std::cout << elem << std::endl;
	// }
}