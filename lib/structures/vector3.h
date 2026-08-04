#pragma once
#include <iostream>


class Vector3
{
public:
	Vector3()
	{
		std::cout << "Vector3 ctor (default)\n";
		m_TestMemoryBlock = new int[10];
	}
	~Vector3()
	{
		std::cout << "Vector3 dtor";
		Print();
	}
	Vector3(float scaler)
		: x(scaler), y(scaler), z(scaler)
	{
		std::cout << "Vector3 ctor (scaler=" << scaler << ")\n";
		m_TestMemoryBlock = new int[10];
	}
	Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{
		std::cout << "Vector3 ctor (vector=" << x << "," << y << "," << z << ")\n";
		m_TestMemoryBlock = new int[10];
	}

	Vector3(const Vector3& other) = delete;
	Vector3(Vector3&& other) noexcept
		: x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Vector3 move ctor\n";
		m_TestMemoryBlock = other.m_TestMemoryBlock;
		other.m_TestMemoryBlock = nullptr;
	}

	Vector3& operator=(const Vector3& other) = delete;
	Vector3& operator=(Vector3&& other) noexcept
	{
		std::cout << "Vector3 move assignment\n";

		if (this == &other)
			return *this;

		x = std::move(other.x);
		y = std::move(other.y);
		z = std::move(other.z);

		m_TestMemoryBlock = std::move(other.m_TestMemoryBlock);
		other.m_TestMemoryBlock = nullptr;

		return *this;
	}

	void Print() const
	{
		std::cout << "(" << x << ", " << y << ", " << z << ")\n";
	}

public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

private:
	int* m_TestMemoryBlock = nullptr;
};
