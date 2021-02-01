#pragma once
#include "Course.h"

class LinkedCourse
{
	Course *head;
	uint32_t ID = 0;
public:
	LinkedCourse();

	uint32_t getNextID();

	void insert(Course *Course);

	bool remove(int pos);

	Course *search(int pos);

	int getSize();
};