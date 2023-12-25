#pragma once

class Arr
{
	void* m_arr;

	// constructor : allocates memory based on datatype, store in m_arr and returns pointer
	template <typename dataType>
	dataType* Arr(int size);

	// delete default constructor
	Arr() = delete;

	// destructor : free memory at pointer m_arr
	~Arr();
};