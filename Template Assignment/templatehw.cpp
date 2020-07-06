#include <iostream>

using namespace std;

template<class T>
T addSum(T *array, int arrSize);

int main(int argc, char* argv[])
{
	int intArr[5] = { 1, 2, 3, 4, 5 };
	double doubleArr[10] = { 3.1, 5.0, 7.9, 9.46, 14.2, 5.7, 7.5, 8.0, 6.0, 20.0 };
	cout << addSum(intArr, 5) << endl;
	cout << addSum(doubleArr, 10) << endl;


	return 0;
}

template<class T>
inline T addSum(const T *inputArr, int arrSize)
{
	T sum = 0;

	for (int i = 0; i < arrSize; i++)
	{
		sum = sum + inputArr[i];
	}

	return sum;
}