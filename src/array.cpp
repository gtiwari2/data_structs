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