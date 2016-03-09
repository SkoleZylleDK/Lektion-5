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


	for (int i = 0; i < size_; i++)
	{
		this->insert(i);
	}

}

CircularBuffer::~CircularBuffer()
{
	delete[] arrayPtr_;
	arrayPtr_ = nullptr;

}

CircularBuffer & CircularBuffer::insert(int insert)
{
	newestIndex_++;

	if (newestIndex_ == size_)
	{
		newestIndex_ = 0;
	}

	this->arrayPtr_[newestIndex_ ] = insert;

	return *this;
}

double CircularBuffer::meanValue() const
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
	for (int i = 0; i < size_; i++)
	{
		if (newestIndex_ < 0)
		{
			newestIndex_ = (size_ -1);
		}
		cout << arrayPtr_[newestIndex_] << endl;
		newestIndex_--;

	}
}