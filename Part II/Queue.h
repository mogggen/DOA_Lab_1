#pragma once
#include "Volume.h"

class Queue
{
	int length;
	Volume* last = nullptr;
public:
	int getLength();
	void push_front(Volume* volume);
	char pop_back();
};