#include <iostream>

using namespace std;

class CircularBuffer
{
public:
	CircularBuffer(int);
	~CircularBuffer();
	CircularBuffer &insert(int);
	double meanValue();
	void print();

private:
	int size_;
	int newestIndex_;
	int *arrayPtr_;
};