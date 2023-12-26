#pragma once

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
