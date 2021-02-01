#include "Stack.h"

int Stack::getLength()
{
	return length;
}

void Stack::push(Volume* volume)
{
	if (volume->getData() == '\\') return;
	if (surface)
	{
		volume->setUnder(surface);
	}
	surface = volume;
	length++;
}

char Stack::pop()
{
	Volume* temp = surface;

	if (surface->getUnder())
	{
		surface = surface->getUnder();
	}
	length--;
	return temp->getData();
}