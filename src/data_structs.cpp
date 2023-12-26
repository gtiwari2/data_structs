#include <iostream>
#include "array.cpp"

void array_test()
{
	std::cout << "running array test:\n";

	int size = 5;
	Arr<int> testArr(size);

	for (int i = 0; i < size; i++)
		*testArr[i] = (i + 5) * 3;

	testArr.PrintArr();

	std::cout << "\n array test complete.";	
}

int main()
{
	std::cout << "hello world!";

	array_test();
}
