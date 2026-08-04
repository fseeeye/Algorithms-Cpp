#pragma once

#include <cstddef>
#include <stdexcept>

namespace AlgoCpp::Template::DataStructure::StaticArray
{

template<typename T, std::size_t SizeValue>
class StaticArray
{
public:
	[[nodiscard]] constexpr std::size_t Size() const noexcept { return SizeValue; }
	T* Data() noexcept { return m_Data; }
	const T* Data() const noexcept { return m_Data; }

	T& operator[](std::size_t index) noexcept { return m_Data[index]; }
	const T& operator[](std::size_t index) const noexcept { return m_Data[index]; }

	T& At(std::size_t index)
	{
		if (index >= SizeValue) throw std::out_of_range("StaticArray index out of range");
		return m_Data[index];
	}

	const T& At(std::size_t index) const
	{
		if (index >= SizeValue) throw std::out_of_range("StaticArray index out of range");
		return m_Data[index];
	}

private:
	T m_Data[SizeValue == 0 ? 1 : SizeValue]{};
};

} // namespace AlgoCpp::Template::DataStructure::StaticArray
