#include "vector.h"

template <typename dataType>
size_t Vector<dataType>::Size()
{
	return m_cur_size;
}

template <typename dataType>
size_t Vector<dataType>::Capacity()
{
	return m_total_size;
}

template <typename dataType>
Vector<dataType>::Vector()
{
	Reserve(2);
}

template <typename dataType>
Vector<dataType>::Vector(size_t init_size)
{
	Reserve(init_size);
}

template <typename dataType>
Vector<dataType>::~Vector()
{
	delete[] m_data;
}

template <typename dataType>
const dataType& Vector<dataType>::operator[] (size_t index) const
{
	if ((index + 1) > m_cur_size)
		m_cur_size = index + 1;
	return m_data[index];
}

template <typename dataType>
dataType& Vector<dataType>::operator[] (size_t index)
{
	if (index > (m_cur_size-1))
		m_cur_size = index + 1;
	return m_data[index];
}

template <typename dataType>
void Vector<dataType>::Reserve(size_t size, bool copyOldData)
{
	if (m_data == nullptr)
		m_data = new dataType[size], m_total_size = size;
	else
	{
		dataType* temp = m_data;

		// expand the vector
		m_data = new dataType[m_cur_size + size];

		// copy over old data | TO DO : use move instead!
		if (copyOldData)
			for (size_t i = 0; i < m_cur_size; i++)
				m_data[i] = temp[i];

		// free old mem
		delete[] temp;

		// update total size;
		m_total_size = m_cur_size + size;
	}
}

template <typename dataType>
void Vector<dataType>::push_back(const dataType &new_elem)
{
	if (m_total_size <= m_cur_size && m_total_size > 0)
		Reserve(m_cur_size); // double vector size
	else if (m_total_size == 0)
		Reserve(sizeof(dataType) * 2); // initialize size of 2 elements

	// set the next element and increment current size
	m_data[m_cur_size++] = new_elem;
}