#pragma once
#include "Volume.h"

class Stack
{
	int length;
	Volume* surface = nullptr;
public:
	int getLength();
	void push(Volume* volume);
	char pop();
};