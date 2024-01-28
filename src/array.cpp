#include "array.h"
#include <stdlib.h>
#include <iostream>

template<typename dataType>
Arr<dataType>::Arr(int num)
{
	m_num = num, m_arr = (dataType *) malloc(sizeof(dataType) * num);
}

template<typename dataType>
dataType* Arr<dataType>::operator[] (int pos)
{
	if (pos < m_num)
		return &m_arr[pos];
	else
		return nullptr;
}

template<typename dataType>
void Arr<dataType>::PrintArr()
{
	std::cout << "\n";

	for (int i = 0; i < m_num; i++)
		std::cout << m_arr[i] << " ";

	std::cout << std::endl;
}

template<typename dataType>
Arr<dataType>::~Arr()
{
	free(m_arr);
}

template<typename dataType, size_t S>
constexpr int Array<dataType, S>::Size() const
{
	return S;
}

template <typename dataType, size_t S>
dataType& Array <dataType, S>::operator[] (size_t index) 
{
	return m_arr[index];
}

template <typename dataType, size_t S>
const dataType& Array <dataType, S>::operator[] (size_t index) const 
{
	return m_arr[index];
}

template<typename dataType, size_t S>
dataType* Array<dataType, S>::Data()
{
	return m_arr;
}

template<typename dataType, size_t S>
const dataType* Array<dataType, S>::Data() const
{
	return m_arr;
}

template <typename dataType, size_t S>
void Array<dataType, S>::PrintArr() {
	for (auto x : m_arr)
		std::cout << x << ' ';

	std::cout << std::endl;
}