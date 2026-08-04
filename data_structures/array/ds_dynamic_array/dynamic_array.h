#pragma once

#include <algorithm>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <utility>

namespace AlgoCpp::Template::DataStructure::DynamicArray
{

template<typename T>
class DynamicArray
{
public:
	explicit DynamicArray(std::size_t initialCapacity = 2)
		: m_Capacity(initialCapacity),
		  m_Data(initialCapacity == 0 ? nullptr : std::make_unique<T[]>(initialCapacity))
	{
	}

	DynamicArray(const DynamicArray& other)
		: m_Size(other.m_Size),
		  m_Capacity(other.m_Capacity),
		  m_Data(other.m_Capacity == 0 ? nullptr : std::make_unique<T[]>(other.m_Capacity))
	{
		std::copy_n(other.m_Data.get(), m_Size, m_Data.get());
	}

	DynamicArray(DynamicArray&& other) noexcept
		: m_Size(std::exchange(other.m_Size, 0)),
		  m_Capacity(std::exchange(other.m_Capacity, 0)),
		  m_Data(std::move(other.m_Data))
	{
	}

	DynamicArray& operator=(DynamicArray other) noexcept
	{
		Swap(other);
		return *this;
	}

	T& operator[](std::size_t index) { return m_Data[index]; }
	const T& operator[](std::size_t index) const { return m_Data[index]; }

	T& At(std::size_t index)
	{
		if (index >= m_Size) throw std::out_of_range("DynamicArray index out of range");
		return m_Data[index];
	}

	const T& At(std::size_t index) const
	{
		if (index >= m_Size) throw std::out_of_range("DynamicArray index out of range");
		return m_Data[index];
	}

	[[nodiscard]] std::size_t Size() const noexcept { return m_Size; }
	[[nodiscard]] std::size_t Capacity() const noexcept { return m_Capacity; }
	[[nodiscard]] bool IsEmpty() const noexcept { return m_Size == 0; }

	void PushBack(const T& value)
	{
		EnsureCapacity();
		m_Data[m_Size++] = value;
	}

	void PushBack(T&& value)
	{
		EnsureCapacity();
		m_Data[m_Size++] = std::move(value);
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		EnsureCapacity();
		m_Data[m_Size] = T(std::forward<Args>(args)...);
		return m_Data[m_Size++];
	}

	void PopBack()
	{
		if (m_Size > 0) {
			--m_Size;
			m_Data[m_Size] = T{};
		}
	}

	void Clear()
	{
		for (std::size_t index = 0; index < m_Size; ++index) m_Data[index] = T{};
		m_Size = 0;
	}

	void RemoveAt(std::size_t index)
	{
		if (index >= m_Size) throw std::out_of_range("DynamicArray index out of range");
		std::move(m_Data.get() + index + 1, m_Data.get() + m_Size, m_Data.get() + index);
		PopBack();
	}

	void Swap(DynamicArray& other) noexcept
	{
		using std::swap;
		swap(m_Size, other.m_Size);
		swap(m_Capacity, other.m_Capacity);
		swap(m_Data, other.m_Data);
	}

private:
	void EnsureCapacity()
	{
		if (m_Size < m_Capacity) return;
		const std::size_t newCapacity = m_Capacity == 0 ? 2 : m_Capacity * 2;
		auto newData = std::make_unique<T[]>(newCapacity);
		if (m_Size > 0) std::move(m_Data.get(), m_Data.get() + m_Size, newData.get());
		m_Data = std::move(newData);
		m_Capacity = newCapacity;
	}

	std::size_t m_Size = 0;
	std::size_t m_Capacity = 0;
	std::unique_ptr<T[]> m_Data;
};

} // namespace AlgoCpp::Template::DataStructure::DynamicArray
