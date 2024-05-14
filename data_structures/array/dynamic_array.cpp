#include "dynamic_array.h"

#include <iostream>

int IntDynamicArray::DEFAULT_CAP = 4;

IntDynamicArray::IntDynamicArray()
	: IntDynamicArray(DEFAULT_CAP)
{
}

IntDynamicArray::IntDynamicArray(uint32_t initCapcity)
	: m_Size(0),
	  m_Capacity(initCapcity),
	  m_StaticArray(std::make_unique<int[]>(initCapcity))
{
}

IntDynamicArray::IntDynamicArray(const IntDynamicArray& other)
	: m_Size(other.m_Size),
	  m_Capacity(other.m_Capacity),
	  m_StaticArray(std::make_unique<int[]>(other.Capacity()))
{
	std::copy_n(other.m_StaticArray.get(), other.m_Size, m_StaticArray.get());
}

IntDynamicArray::IntDynamicArray(IntDynamicArray&& other) noexcept
	: m_Size(other.m_Size),
	  m_Capacity(other.m_Capacity),
	  m_StaticArray(std::move(other.m_StaticArray))
{
}

IntDynamicArray& IntDynamicArray::operator=(const IntDynamicArray& other)
{
	if (this == &other)
		return *this;

	m_Size = other.m_Size;
	m_Capacity = other.m_Capacity;
	m_StaticArray = std::make_unique<int[]>(other.Capacity());
	std::copy_n(other.m_StaticArray.get(), other.m_Size, m_StaticArray.get());

	return *this;
}

IntDynamicArray& IntDynamicArray::operator=(IntDynamicArray&& other) noexcept
{
	if (this == &other)
		return *this;

	m_Size = other.m_Size;
	m_Capacity = other.m_Capacity;
	m_StaticArray = std::move(other.m_StaticArray);

	return *this;
}

int& IntDynamicArray::operator[](uint32_t index)
{
	ASSERT(index < m_Size)
	return m_StaticArray[index];
}

const int& IntDynamicArray::operator[](uint32_t index) const
{
	ASSERT(index < m_Size)
	return m_StaticArray[index];
}

void IntDynamicArray::Append(const int value)
{
	if (m_Size + 1 >= m_Capacity)
	{
		ExpandCapacity();
	}
	m_StaticArray[m_Size++] = value;
}

void IntDynamicArray::RemoveAt(const uint32_t index)
{
	ASSERT(index < m_Size)
	std::move(m_StaticArray.get() + index + 1, m_StaticArray.get() + m_Size, m_StaticArray.get() + index);
	--m_Size;
}

void IntDynamicArray::ExpandCapacity()
{
	uint32_t newCapacity = DEFAULT_CAP;
	if (m_Capacity > 0)
	{
		// Refs: DefaultCalculateSlackGrow() in UE5
#ifdef AGGRESSIVE_MEMORY_SAVING
		newCapacity = m_Size + m_Size / 4;
#else
		newCapacity = m_Size + 3 * m_Size / 8 + 16;
#endif
	}
	std::cout << "IntArray::ExpandCapacity: expand array from " << m_Capacity << " to " << newCapacity << "\n";

	auto newArray = std::make_unique<int[]>(newCapacity);
	std::copy_n(m_StaticArray.get(), m_Size, newArray.get());
	m_StaticArray = std::move(newArray);
	m_Capacity = newCapacity;
}
