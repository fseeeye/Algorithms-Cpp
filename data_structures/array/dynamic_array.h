#pragma once

#include "common.h"

#include <cstdint>

template<typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray() noexcept;
	explicit DynamicArray(size_t initCapcity);
	DynamicArray(const DynamicArray& other);
	DynamicArray(DynamicArray&& other) noexcept;
	DynamicArray& operator=(const DynamicArray& other);
	DynamicArray& operator=(DynamicArray&& other) noexcept;

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	FORCEINLINE size_t Size() const
	{
		return m_Size;
	}

	FORCEINLINE size_t Capacity() const
	{
		return m_Capacity;
	}

	FORCEINLINE bool IsEmpty() const
	{
		return m_Size == 0;
	}

	FORCEINLINE int At(uint32_t index) const
	{
		ASSERT(index < m_Size)
		return m_StaticArray[index];
	}

	void PushBack(const T& value);
	void PushBack(T&& value);

	template<typename... Args>
	T& EmplaceBack(Args&&... args);

	void PopBack();
	void Clear();

	void RemoveAt(uint32_t index);

private:
	/**
	 * grow or shrink capacity.
	 */
	void ReAlloc();

	void DestroyElements();
	void DeleteMemorys() const;
	T* AllocMemorys();

private:
	static size_t DEFAULT_CAP;

	size_t m_Size = 0;
	size_t m_Capacity = 0;
	// we also can use smart pointer like : `std::unique_ptr<int[]> m_StaticArray;`
	T* m_StaticArray = nullptr;
};

void TestDynamicArray();
