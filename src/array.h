#pragma once

// a basic static-size stack (staticly) allocated array
template <typename dataType, size_t S>
class Array
{
private:
	dataType m_arr[S];

public:
	dataType& operator[] (size_t index);
	const dataType& operator[] (size_t index) const;

	dataType* Data();
	const dataType* Data() const;

	constexpr int Size() const;

	void PrintArr();
};

// a basic static-size heap (dynamically) allocated array
template <typename dataType>
class Arr
{
private:
	dataType* m_arr{ nullptr };
	int m_num{ -1 };

public:
	// delete default constructor
	Arr() = delete;

	// constructor : allocates memory based on datatype, store in m_arr and returns pointer
	Arr<dataType>(int num);

	// override brackets operator to access the array that is part of this object
	dataType* operator[] (int pos);

	// print to test
	void PrintArr();

	// destructor : free memory at pointer m_arr
	~Arr();
};
