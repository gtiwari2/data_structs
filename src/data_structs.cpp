#include <iostream>
#include "array.cpp"
#include "vector.cpp"

void array_test()
{
	std::cout << "running array test:\n";

	int size = 5;
	Arr<int> testArr(size);

	Array<int, 5> testArray;

	for (size_t i = 0; i < size; i++)
		*testArr[i] = (int(i) + 5) * 3, testArray[i] = 7 * int(i);

	testArr.PrintArr();
	testArray.PrintArr();

	memset(&testArray[0], 0, testArray.Size() * sizeof(int));

	testArray.PrintArr();

	std::cout << testArray.Size() << std::endl;

	std::cout << "\n array test complete.";	
}

void vector_test()
{
	std::cout << "\nbeginning vector test\n\n";

	Vector<int> testVec(5);

	testVec[0] = 10;
	testVec[1] = 28;
	testVec[2] = 234;
	testVec[3] = 8534;
	testVec[4] = -123;

	std::cout << "\ncur size: " << testVec.Size();

	testVec.push_back(43);

	std::cout << "\nsize after pushback: " << testVec.Size() << std::endl;

	for (int i = 0; i < testVec.Size(); i++)
		std::cout << testVec[i] << ' ';

	std::cout << "\nvector test complete" << std::endl;
}

int main()
{
	std::cout << "hello world!\n";

	array_test();

	vector_test();
}
