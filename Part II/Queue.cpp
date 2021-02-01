#include "Queue.h"


int Queue::getLength()
{
	return length;
}

void Queue::push_front(Volume* volume)
{
	if (volume->getData() == '\\') return;
	if (last)
	{
		Volume* prev = last;
		while (prev->getUnder())
		{
			prev = prev->getUnder();
		}
		prev->setUnder(volume);
		length++;
	}
	else
	{
		last = volume;
		length++;
	}
}

char Queue::pop_back()
{
	Volume* temp = last;

	if (last->getUnder())
	{
		last = temp->getUnder();
	}
	length--;
	return temp->getData();
}