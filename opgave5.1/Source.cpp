#include "CircularBuffer.h"

int main()
{
	int temp_size;

	cin >> temp_size;

	CircularBuffer test1(temp_size);

	test1.print();
	
	cout << endl << endl;

	cout << test1.meanValue() << endl;
}