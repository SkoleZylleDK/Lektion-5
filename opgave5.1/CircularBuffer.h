#include <iostream>

using namespace std;

class CircularBuffer
{
public:
	CircularBuffer(int);
	~CircularBuffer();
	CircularBuffer & insert(int);
	double meanValue() const;
	void print() const;

private:
	int size_;
	int newestIndex_;
	int *arrayPtr_;
};