#include "dynamic_array.h"
#include "vector3.h"

#include <iostream>

template <typename T>
size_t DynamicArray<T>::DEFAULT_CAP = 2;

template <typename T>
DynamicArray<T>::DynamicArray()
	: DynamicArray(DEFAULT_CAP)
{
}

template <typename T>
DynamicArray<T>::~DynamicArray() noexcept
{
	std::cout << "[-] DynamicArray dtor\n";

	// DestroyElements();
	// DeleteMemorys();
	ASSERT(m_StaticArray != nullptr);
	delete[] m_StaticArray;
	m_StaticArray = nullptr;
	m_Size = 0;
	m_Capacity = 0;
}

template <typename T>
DynamicArray<T>::DynamicArray(size_t initCapcity)
	: m_Size(0),
	m_Capacity(initCapcity),
	m_StaticArray(new T[initCapcity])
{
	std::cout << "[-] DynamicArray ctor\n";
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
	: m_Size(other.m_Size),
	m_Capacity(other.m_Capacity),
	m_StaticArray(std::make_unique<int[]>(other.Capacity()))
{
	std::copy_n(other.m_StaticArray.get(), other.m_Size, m_StaticArray.get());
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray&& other) noexcept
	: m_Size(other.m_Size),
	m_Capacity(other.m_Capacity),
	m_StaticArray(std::move(other.m_StaticArray))
{
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
	if (this == &other)
		return *this;

	m_Size = other.m_Size;
	m_Capacity = other.m_Capacity;
	m_StaticArray = std::make_unique<int[]>(other.Capacity());
	std::copy_n(other.m_StaticArray.get(), other.m_Size, m_StaticArray.get());

	return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray&& other) noexcept
{
	if (this == &other)
		return *this;

	m_Size = other.m_Size;
	m_Capacity = other.m_Capacity;
	m_StaticArray = std::move(other.m_StaticArray);

	return *this;
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index)
{
	ASSERT(index < m_Size)
		return m_StaticArray[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const
{
	ASSERT(index < m_Size)
		return m_StaticArray[index];
}

template <typename T>
void DynamicArray<T>::PushBack(const T& value)
{
	if (m_Size >= m_Capacity)
	{
		ReAlloc();
	}
	m_StaticArray[m_Size++] = value;
}

template <typename T>
void DynamicArray<T>::PushBack(T&& value)
{
	if (m_Size >= m_Capacity)
	{
		ReAlloc();
	}
	m_StaticArray[m_Size++] = std::move(value);
}

template <typename T>
template <typename ... Args>
T& DynamicArray<T>::EmplaceBack(Args&&... args)
{
	if (m_Size >= m_Capacity)
	{
		ReAlloc();
	}
	new (&m_StaticArray[m_Size]) T(std::forward<Args>(args)...);
	return m_StaticArray[m_Size++];
}

template <typename T>
void DynamicArray<T>::PopBack()
{
	if (m_Size > 0)
	{
		// call destructor, but don't free memory
		m_StaticArray[--m_Size].~T();
	}
}

template <typename T>
void DynamicArray<T>::Clear()
{
	DestroyElements();
	m_Size = 0;
}

template <typename T>
void DynamicArray<T>::RemoveAt(const uint32_t index)
{
	ASSERT(index < m_Size);
	std::move(m_StaticArray + index + 1, m_StaticArray + m_Size, m_StaticArray + index);
	--m_Size;
}

template <typename T>
void DynamicArray<T>::ReAlloc()
{
	ASSERT(m_StaticArray != nullptr);

	// 0. determine the new capacity
	size_t newCapacity = DEFAULT_CAP;
	if (m_Capacity > 0)
	{
		// Refs: DefaultCalculateSlackGrow() in UE5
#ifdef AGGRESSIVE_MEMORY_SAVING
		newCapacity = m_Size + m_Size / 4;
#else
		newCapacity = m_Size + 3 * m_Size / 8 + 16;
#endif
	}
	std::cout << "[-] DynamicArray::ReAlloc: grow/shrink array from " << m_Capacity << " to " << newCapacity << "\n";

	// 1. allocate a new block of memory (DO NOT call constructor!)
	// T* newArray = static_cast<T*>(::operator new(newCapacity * sizeof(T)));
	T* newArray = new T[newCapacity];

	// 2. copy/move the old elements into new block. (use operator= to hit copy constructor, instead of memory copy)
	size_t moveSize = std::min(m_Size, newCapacity);
	for (size_t i = 0; i < moveSize; i++)
	{
		newArray[i] = std::move(m_StaticArray[i]);
	}

	// 3. delete the old block.
	// DestroyElements();
	// DeleteMemorys();
	delete[] m_StaticArray;
	m_StaticArray = nullptr;

	// 4. set the new data and capacity
	m_StaticArray = newArray;
	m_Capacity = newCapacity;
	std::cout << "[-] DynamicArray::ReAlloc: done.\n";
}

template <typename T>
void DynamicArray<T>::DestroyElements()
{
	for (size_t i = 0; i < m_Size; i++)
	{
		// call destructor, but don't free memory
		m_StaticArray[i].~T();
	}
}

template <typename T>
void DynamicArray<T>::DeleteMemorys() const
{
	::operator delete(m_StaticArray, m_Capacity * sizeof(T));
}

template <typename T>
T* DynamicArray<T>::AllocMemorys()
{
	return static_cast<T*>(::operator new(m_Capacity * sizeof(T)));
}

void TestDynamicArray()
{
	std::cout << "[-] Testing DynamicArray.\n";
	auto arr = DynamicArray<Vector3>();
	auto ele0 = Vector3(6.0f);
	arr.EmplaceBack();
	arr.EmplaceBack(1.0f);
	arr.EmplaceBack(2.0f, 3.0f, 4.0f);
	arr.EmplaceBack(Vector3(5.0f));
	arr.PushBack(Vector3(6.0f));
	arr.RemoveAt(1);
	arr.PopBack();
	ASSERT(arr.Size() == 3);

	arr.Clear();
	arr.EmplaceBack(2.0f);
	arr.EmplaceBack(3.0f);
	ASSERT(arr.Size() == 2);

	std::cout << "[-] Final Array:";
	for (size_t i = 0; i < arr.Size(); i++)
	{
		std::cout << "(" << arr[i].x << "," << arr[i].y << "," << arr[i].z << ") ";
	}
	std::cout << "\n";

	std::cout << "[-] Done.\n";
}
