#pragma once

#include <cstdint>
#include <memory>

#include "common.h"

class IntArray
{
public:
	IntArray();
	~IntArray() noexcept = default;
	explicit IntArray(uint32_t initCapcity);
	IntArray(const IntArray& other);
	IntArray(IntArray&& other) noexcept;
	IntArray& operator=(const IntArray& other);
	IntArray& operator=(IntArray&& other) noexcept;

	int& operator[](uint32_t index);
	const int& operator[](uint32_t index) const;

	uint32_t Size() const
	{
		return m_Size;
	}

	uint32_t Capacity() const
	{
		return m_Capacity;
	}

	bool IsEmpty() const
	{
		return m_Size == 0;
	}

	int At(uint32_t index) const
	{
		ASSERT(index < m_Size)
		return m_StaticArray[index];
	}

	void Append(int value);
	void RemoveAt(uint32_t index);

private:
	void ExpandCapacity(uint32_t newCapacity);

private:
	static int DEFAULT_CAP;

	uint32_t m_Size;
	uint32_t m_Capacity;
	std::unique_ptr<int[]> m_StaticArray;
};
