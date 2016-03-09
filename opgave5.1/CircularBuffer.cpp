#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int size)
{
	newestIndex_ = 0;

	if (size > 0)
	{
		size_ = size;
	}
	else
	{
		size_ = 8;
	}
	this->arrayPtr_ = new int[size_];
	
	for (size_t i = 0; i < size_; i++)
	{
		this->insert(0);
	}
	this->arrayPtr_[1] = 0;

}

CircularBuffer::~CircularBuffer()
{
	delete[] arrayPtr_;
	arrayPtr_ = nullptr;

}

CircularBuffer & CircularBuffer::insert(int insert = 0)
{
	arrayPtr_[newestIndex_] = insert;

	newestIndex_++;
	if (newestIndex_ >= size_)
	{
		newestIndex_ = 0;
	}

	return *this;
}

double CircularBuffer::meanValue()
{
	double temp = 0;

	for (size_t i = 0; i < size_; i++)
	{
		temp += arrayPtr_[i];
	}

	return temp / size_;
}

void CircularBuffer::print()
{
	for (size_t i = 0; i < size_; i++)
	{
		cout << arrayPtr_[newestIndex_] << endl;
		newestIndex_--;
		if (newestIndex_ < 0)
		{
			newestIndex_ = size_;
		}
	}
}