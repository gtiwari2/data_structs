#pragma once

// dynamic sized, heap (dynamically) allocated array
template <typename dataType>
class Vector
{
private:
	dataType* m_data { nullptr };
	size_t m_cur_size{ 0 }, m_total_size{ 0 };

public:
	// initializes a vector with size of 2 (elements)
	Vector();

	// initializes a vector with a given size (reserves some space)
	Vector(size_t init_size);

	// frees allocated memory
	~Vector();
	
	// returns currently used size
	size_t Size();

	size_t Capacity();

	// access the vector to read and write, respectively
	const dataType& operator[] (size_t index) const;
	dataType& operator[] (size_t index);

	// reserve some space beyond the current size
	// copies over old data by default!
	void Reserve(size_t size, bool copyOldData = true);

	// add a new element to the vector
	// expands vector by 2x if full
	void push_back(const dataType &new_elem);
};