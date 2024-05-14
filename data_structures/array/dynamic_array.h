#pragma once

#include <cstdint>
#include <memory>

#include "common.h"
#include "static_array.h"

class IntDynamicArray
{
public:
	IntDynamicArray();
	~IntDynamicArray() noexcept = default;
	explicit IntDynamicArray(uint32_t initCapcity);
	IntDynamicArray(const IntDynamicArray& other);
	IntDynamicArray(IntDynamicArray&& other) noexcept;
	IntDynamicArray& operator=(const IntDynamicArray& other);
	IntDynamicArray& operator=(IntDynamicArray&& other) noexcept;

	int& operator[](uint32_t index);
	const int& operator[](uint32_t index) const;

	FORCEINLINE uint32_t Size() const
	{
		return m_Size;
	}

	FORCEINLINE uint32_t Capacity() const
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

	void Append(int value);
	void RemoveAt(uint32_t index);

private:
	void ExpandCapacity();

private:
	static int DEFAULT_CAP;

	uint32_t m_Size;
	uint32_t m_Capacity;
	std::unique_ptr<int[]> m_StaticArray;
};
